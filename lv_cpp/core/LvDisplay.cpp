/*
 * LvDisplay.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: fstuffdev
 */

#include "LvDisplay.h"

#if (USE_MONITOR + USE_FBDEV ) > 1
#error "You cannot specify more than one display driver"
#endif

/* Input */
#if USE_MONITOR
#include <lv_drivers/display/monitor.h>
#include <SDL2/SDL.h>
#endif

#if USE_FBDEV
#include <lv_drivers/display/fbdev.h>
#endif

namespace lvglpp {

LvDisplay::LvDisplay() :
		LvDisplay(NULL) {
}

LvDisplay::LvDisplay(lv_display_t *drv) :
#if USE_MONITOR
				LvDisplay(drv, MONITOR_HOR_RES, MONITOR_VER_RES)
#endif

#if USE_FBDEV
	LvDisplay(drv, 480, 320)
#endif
{

}

LvDisplay::LvDisplay(lv_display_t *drv, int32_t hres, int32_t vres) {

	disp_drv.reset(lv_display_create(hres, vres));
	disp_buf1.reset((lv_draw_buf_t*)lv_malloc(sizeof(lv_draw_buf_t)));
	disp_buf2.reset((lv_draw_buf_t*)lv_malloc(sizeof(lv_draw_buf_t)));

	int32_t w = 0;
	int32_t h = 0;
	lv_display_render_mode_t render_mode = LV_DISP_RENDER_MODE_FULL;

#if USE_MONITOR
	monitor_init();
	disp_drv->flush_cb = monitor_flush;
	w = MONITOR_HOR_RES;
	h = MONITOR_VER_RES;

#if LV_DISP_BUFFER_STATIC
#endif

#endif

#if USE_FBDEV

	fbdev_init();
	fbdev_get_sizes(&w, &h);

	disp_drv->flush_cb = fbdev_flush;

#if LV_DISP_BUFFER_STATIC
#define MONITOR_HOR_RES 640
#endif

#endif

#if !LV_DISP_BUFFER_STATIC
	buf1_1.reset((lv_color_t*)lv_malloc(h * 100));
	buf1_2.reset((lv_color_t*)lv_malloc(h * 100));
	lv_display_set_buffers(disp_drv.get(), buf1_1, buf1_2, w * 100,render_mode);
#else
	static lv_color_t buf1_1[MONITOR_HOR_RES * 100];
	static lv_color_t buf1_2[MONITOR_HOR_RES * 100];
	lv_display_set_buffers(disp_drv.get(), buf1_1, buf1_2, MONITOR_HOR_RES * 100,render_mode);
#endif

	/* Initialize with basic configuration*/
	if (!drv) {
		/*Create a display*/
		disp_drv->buf_1 = disp_buf1.get();
		disp_drv->buf_2 = disp_buf2.get();
		disp_drv->antialiasing = 1;
		disp_drv->sw_rotate = 1;
		disp_drv->hor_res = w;
		disp_drv->ver_res = h;
		disp_drv->rotation = LV_DISPLAY_ROTATION_0;
	} else
	   //memcpy(disp_drv.get(), drv, sizeof(lv_display_t));
	   // disp.reset(lv_display_get_default());
	void(0);
}


LvDisplay::~LvDisplay() {

}

LvDisplay& LvDisplay::Rotate() {

	lv_display_rotation_t rot = LV_DISPLAY_ROTATION_0;
	lv_display_rotation_t future_rot = LV_DISPLAY_ROTATION_0;
	rot = lv_disp_get_rotation(disp.get());

	switch (rot) {
	case LV_DISPLAY_ROTATION_0:
		future_rot = LV_DISPLAY_ROTATION_90;
		break;

	case LV_DISPLAY_ROTATION_90:
		future_rot = LV_DISPLAY_ROTATION_180;
		break;

	case LV_DISPLAY_ROTATION_180:
		future_rot = LV_DISPLAY_ROTATION_270;
		break;

	case LV_DISPLAY_ROTATION_270:
		future_rot = LV_DISPLAY_ROTATION_0;
		break;
	}

	lv_disp_set_rotation(disp.get(), future_rot);

	return *this;

}

LvDisplay& LvDisplay::Rotate(int32_t deg) {

	int32_t rotstep = 1;

	if (deg % 90 == 0) {
		rotstep = deg / 90;
		for (int i = 0; i < rotstep; i++)
			Rotate();
	}

	return *this;

}

int32_t LvDisplay::getWidth() {
	return disp_drv->hor_res;
}

int32_t LvDisplay::getHeight() {
	return disp_drv->ver_res;
}



} /* namespace lvGL */
