/*
 * LvCanvas.h
 *
 */

#ifndef LVCANVAS_H_
#define LVCANVAS_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvCanvas: public LvObj {
public:
	LvCanvas();
	LvCanvas(LvObj* Parent);
	virtual ~LvCanvas() override;
	LvCanvas& setBuffer(void *buf, int32_t w, int32_t h, lv_color_format_t cf);
	LvCanvas& setPx(int32_t x, int32_t y, lv_color_t c, lv_opa_t opa);
	LvCanvas& setPalette(uint8_t id, lv_color32_t c);
	lv_color32_t getPx(int32_t x, int32_t y) const noexcept ;
	lv_image_dsc_t *getImg() const noexcept ;
	LvCanvas& copyBuf(const lv_area_t * canvas_area, lv_draw_buf_t * dest_buf, const lv_area_t * dest_area);
	LvCanvas& transform(lv_image_dsc_t *img, int16_t angle, uint16_t zoom, lv_grid_align_t offset_x, lv_grid_align_t offset_y, int32_t pivot_x, int32_t pivot_y, bool antialias);
	LvCanvas& blurHor(const lv_area_t *area, uint16_t r);
	LvCanvas& blurVer(const lv_area_t *area, uint16_t r);
	LvCanvas& fillBg(lv_color_t color, lv_opa_t opa);
	LvCanvas& drawRect(lv_grid_align_t x, lv_grid_align_t y, lv_grid_align_t w, lv_grid_align_t h, const lv_draw_rect_dsc_t *draw_dsc);
	LvCanvas& drawText(lv_grid_align_t x, lv_grid_align_t y, lv_grid_align_t max_w, lv_draw_label_dsc_t *draw_dsc, const char *txt);
	LvCanvas& drawImg(lv_grid_align_t x, lv_grid_align_t y, const void *src, const lv_draw_image_dsc_t *draw_dsc);
	LvCanvas& drawLine(const lv_point_t points[], uint32_t point_cnt, const lv_draw_line_dsc_t *draw_dsc);
	LvCanvas& drawPolygon(const lv_point_t points[], uint32_t point_cnt, const lv_draw_rect_dsc_t *draw_dsc);
	LvCanvas& drawArc(lv_grid_align_t x, lv_grid_align_t y, lv_grid_align_t r, int32_t start_angle, int32_t end_angle, const lv_draw_arc_dsc_t *draw_dsc);
};

} /* namespace lvglpp */

#endif /* LVCANVAS_H_ */
