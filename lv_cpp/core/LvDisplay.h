/*
 * LvDisplay.h
 *
 *  created on: sep 29, 2020
 *      author: fstuffdev
 */

#ifndef LVDISPLAY_H_
#define LVDISPLAY_H_

#include <lv_drv_conf.h>
#include "lvglpp.h"
#include "../../lvgl/src/display/lv_display_private.h"
#include "../../lvgl/src/display/lv_display.h"

#ifndef LV_DISP_BUFFER_STATIC
#define LV_DISP_BUFFER_STATIC 1
#endif

namespace lvglpp {

class LvDisplay {
private:
	LvPointer<lv_draw_buf_t,lv_free> disp_buf1;
	LvPointer<lv_draw_buf_t,lv_free> disp_buf2;
	LvPointer<lv_display_t,lv_free> disp_drv;

#if !LV_DISP_BUFFER_STATIC
	LvPointer<lv_color_t,lv_free> buf1_1;
	LvPointer<lv_color_t,lv_free> buf1_2;
#endif
	LvPointer<lv_display_t,lv_free> disp;
public:
	LvDisplay();
	LvDisplay(lv_display_t *drv);
	LvDisplay(lv_display_t *drv, int32_t hres, int32_t vres);

	LvDisplay& Rotate();
	LvDisplay& Rotate(int32_t deg);
	int32_t getWidth();
	int32_t getHeight();

	virtual ~LvDisplay();
};

} /* namespace lvGL */

#endif /* LVDISPLAY_H_ */
