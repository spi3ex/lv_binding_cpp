/*
 * LvStyle.h
 *
 */

#ifndef LVSTYLE_H_
#define LVSTYLE_H_

#include "../core/lvglpp.h"


namespace lvglpp {

class LvStyle {
private:
	
	LvPointer<lv_style_t, lv_free> cObj;
public:
	LvStyle();
	virtual ~LvStyle();
	lv_style_t* raw();
	lv_res_t getPropInlined(lv_style_prop_t prop, lv_style_value_t *value) const noexcept ;
	LvStyle& setPadAll(lv_grid_align_t value);
	LvStyle& setPadHor(lv_grid_align_t value);
	LvStyle& setPadVer(lv_grid_align_t value);
	LvStyle& setPadGap(lv_grid_align_t value);
	LvStyle& setSize(lv_style_t * style, int32_t width, int32_t height);
	LvStyle& init();
	LvStyle& reset();
	bool removeProp(lv_style_prop_t prop);
	LvStyle& setProp(lv_style_prop_t prop, lv_style_value_t value);
	lv_res_t getProp(lv_style_prop_t prop, lv_style_value_t *value) const noexcept ;
	bool isEmpty();
	LvStyle& setWidth(lv_grid_align_t value);
	LvStyle& setMinWidth(lv_grid_align_t value);
	LvStyle& setMaxWidth(lv_grid_align_t value);
	LvStyle& setHeight(lv_grid_align_t value);
	LvStyle& setMinHeight(lv_grid_align_t value);
	LvStyle& setMaxHeight(lv_grid_align_t value);
	LvStyle& setX(lv_grid_align_t value);
	LvStyle& setY(lv_grid_align_t value);
	LvStyle& setAlign(lv_align_t value);
	LvStyle& setTransformWidth(lv_grid_align_t value);
	LvStyle& setTransformHeight(lv_grid_align_t value);
	LvStyle& setTranslateX(lv_grid_align_t value);
	LvStyle& setTranslateY(lv_grid_align_t value);
	LvStyle& setTransformZoom(lv_grid_align_t value);
	LvStyle& setTransformAngle(lv_grid_align_t value);
	LvStyle& setPadTop(lv_grid_align_t value);
	LvStyle& setPadBottom(lv_grid_align_t value);
	LvStyle& setPadLeft(lv_grid_align_t value);
	LvStyle& setPadRight(lv_grid_align_t value);
	LvStyle& setPadRow(lv_grid_align_t value);
	LvStyle& setPadColumn(lv_grid_align_t value);
	LvStyle& setRadius(lv_grid_align_t value);
	LvStyle& setClipCorner(bool value);
	LvStyle& setOpa(lv_opa_t value);
	LvStyle& setColorFilterDsc(const lv_color_filter_dsc_t *value);
	LvStyle& setColorFilterOpa(lv_opa_t value);
	LvStyle& setAnimTime(uint32_t value);
	LvStyle& setAnimSpeed(uint32_t value);
	LvStyle& setTransition(const lv_style_transition_dsc_t *value);
	LvStyle& setBlendMode(lv_blend_mode_t value);
	LvStyle& setLayout(uint16_t value);
	LvStyle& setBaseDir(lv_base_dir_t value);
	LvStyle& setBgColor(lv_color_t value);
	LvStyle& setBgColorFiltered(lv_color_t value);
	LvStyle& setBgOpa(lv_opa_t value);
	LvStyle& setBgGradColor(lv_color_t value);
	LvStyle& setBgGradColorFiltered(lv_color_t value);
	LvStyle& setBgGradDir(lv_grad_dir_t value);
	LvStyle& setBgMainStop(lv_grid_align_t value);
	LvStyle& setBgGradStop(lv_grid_align_t value);
	LvStyle& setBgImgSrc(const void *value);
	LvStyle& setBgImgOpa(lv_opa_t value);
	LvStyle& setBgImgRecolor(lv_color_t value);
	LvStyle& setBgImgRecolorFiltered(lv_color_t value);
	LvStyle& setBgImgRecolorOpa(lv_opa_t value);
	LvStyle& setBgImgTiled(bool value);
	LvStyle& setBorderColor(lv_color_t value);
	LvStyle& setBorderColorFiltered(lv_color_t value);
	LvStyle& setBorderOpa(lv_opa_t value);
	LvStyle& setBorderWidth(lv_grid_align_t value);
	LvStyle& setBorderSide(lv_border_side_t value);
	LvStyle& setBorderPost(bool value);
	LvStyle& setTextColor(lv_color_t value);
	LvStyle& setTextColorFiltered(lv_color_t value);
	LvStyle& setTextOpa(lv_opa_t value);
	LvStyle& setTextFont(const lv_font_t *value);
	LvStyle& setTextLetterSpace(lv_grid_align_t value);
	LvStyle& setTextLineSpace(lv_grid_align_t value);
	LvStyle& setTextDecor(lv_text_decor_t value);
	LvStyle& setTextAlign(lv_text_align_t value);
	LvStyle& setImgOpa(lv_opa_t value);
	LvStyle& setImgRecolor(lv_color_t value);
	LvStyle& setImgRecolorFiltered(lv_color_t value);
	LvStyle& setImgRecolorOpa(lv_opa_t value);
	LvStyle& setOutlineWidth(lv_grid_align_t value);
	LvStyle& setOutlineColor(lv_color_t value);
	LvStyle& setOutlineColorFiltered(lv_color_t value);
	LvStyle& setOutlineOpa(lv_opa_t value);
	LvStyle& setOutlinePad(lv_grid_align_t value);
	LvStyle& setShadowWidth(lv_grid_align_t value);
	LvStyle& setShadowOfsX(lv_grid_align_t value);
	LvStyle& setShadowOfsY(lv_grid_align_t value);
	LvStyle& setShadowSpread(lv_grid_align_t value);
	LvStyle& setShadowColor(lv_color_t value);
	LvStyle& setShadowColorFiltered(lv_color_t value);
	LvStyle& setShadowOpa(lv_opa_t value);
	LvStyle& setLineWidth(lv_grid_align_t value);
	LvStyle& setLineDashWidth(lv_grid_align_t value);
	LvStyle& setLineDashGap(lv_grid_align_t value);
	LvStyle& setLineRounded(bool value);
	LvStyle& setLineColor(lv_color_t value);
	LvStyle& setLineColorFiltered(lv_color_t value);
	LvStyle& setLineOpa(lv_opa_t value);
	LvStyle& setArcWidth(lv_grid_align_t value);
	LvStyle& setArcRounded(bool value);
	LvStyle& setArcColor(lv_color_t value);
	LvStyle& setArcColorFiltered(lv_color_t value);
	LvStyle& setArcOpa(lv_opa_t value);
	LvStyle& setArcImgSrc(const void *value);
	LvStyle& setFlexFlow(lv_flex_flow_t value);
	LvStyle& setFlexMainPlace(lv_flex_align_t value);
	LvStyle& setFlexCrossPlace(lv_flex_align_t value);
	LvStyle& setFlexTrackPlace(lv_flex_align_t value);
	LvStyle& setFlexGrow(uint8_t value);
	LvStyle& setGridRowDscArray(const int32_t value[]);
	LvStyle& setGridColumnDscArray(const int32_t value[]);
	LvStyle& setGridRowAlign(lv_grid_align_t value);
	LvStyle& setGridColumnAlign(lv_grid_align_t value);
	LvStyle& setGridCellColumnPos(lv_grid_align_t value);
	LvStyle& setGridCellColumnSpan(lv_grid_align_t value);
	LvStyle& setGridCellRowPos(lv_grid_align_t value);
	LvStyle& setGridCellRowSpan(lv_grid_align_t value);
	LvStyle& setGridCellXAlign(lv_grid_align_t value);
	LvStyle& setGridCellYAlign(lv_grid_align_t value);
};

} /* namespace lvglpp */

#endif /* LVSTYLE_H_ */
