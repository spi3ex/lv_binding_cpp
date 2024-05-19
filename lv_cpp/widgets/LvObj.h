/*
 * LvObj.h
 *
 *  Created on:
 *      Author: fstuffdev
 */

#ifndef LVOBJ_H_
#define LVOBJ_H_

#include <list>
#include "lvglpp.h"
#include "LvEvent.h"
#include "../misc/LvStyle.h"


namespace lvglpp {

class LvObj {
protected:
	LvPointer<lv_obj_t, lv_obj_del> cObj;
public:

	/* Creation and deletion */
	LvObj();
	LvObj(LvObj *Parent);
	virtual ~LvObj();

	lv_obj_t* raw();
	LvObj& setCObj(lv_obj_t* _cObj);
	LvObj& setUserData(void *user_data);
	void *getUserData() const noexcept ;
	lv_grid_align_t dpx(lv_grid_align_t n);
	LvObj& del();
	LvObj& clean();
	LvObj& delDelayed(int32_t delay_ms);
	LvObj& delAsync();
	LvObj& setParent(LvObj *parent);
	LvObj& moveToIndex(int32_t index);
	lv_obj_t *getScreen() const noexcept ;
	lv_disp_t *getDisp() const noexcept ;
	lv_obj_t *getParent() const noexcept ;
	lv_obj_t *getChild(int32_t id) const noexcept ;
	int32_t getChildCnt() const noexcept ;
	int32_t getIndex() const noexcept ;
	LvObj& moveForeground();
	LvObj& moveBackground();
	lv_flex_flow_t getStyleFlexFlow(int32_t part) const noexcept ;
	lv_flex_align_t getStyleFlexMainPlace(int32_t part) const noexcept ;
	lv_flex_align_t getStyleFlexCrossPlace(int32_t part) const noexcept ;
	lv_flex_align_t getStyleFlexTrackPlace(int32_t part) const noexcept ;
	uint8_t getStyleFlexGrow(int32_t part) const noexcept ;
	const lv_grid_align_t *getStyleGridRowDscArray(int32_t part) const noexcept ;
	const lv_grid_align_t *getStyleGridColumnDscArray(int32_t part) const noexcept ;
	lv_grid_align_t getStyleGridRowAlign(int32_t part) const noexcept ;
	lv_grid_align_t getStyleGridColumnAlign(int32_t part) const noexcept ;
	lv_grid_align_t getStyleGridCellColumnPos(int32_t part) const noexcept ;
	lv_grid_align_t getStyleGridCellColumnSpan(int32_t part) const noexcept ;
	lv_grid_align_t getStyleGridCellRowPos(int32_t part) const noexcept ;
	lv_grid_align_t getStyleGridCellRowSpan(int32_t part) const noexcept ;
	lv_grid_align_t getStyleGridCellXAlign(int32_t part) const noexcept ;
	lv_grid_align_t getStyleGridCellYAlign(int32_t part) const noexcept ;
	lv_theme_t *getTheme() const noexcept;
	struct lv_event_dsc_t *addEventCb(lv_event_cb_t event_cb, lv_event_code_t filter, void *user_data);
	bool removeEventCb(lv_event_cb_t event_cb);
	bool removeEventCbWithUserData(lv_event_cb_t event_cb, const void *user_data);
	bool removeEventDsc(struct lv_event_dsc_t *event_dsc);
	LvObj& classInitObj();
	LvObj& destruct();
	bool isEditable();
	bool isGroupDef();
	LvObj& addFlag(lv_obj_flag_t f);
	LvObj& clearFlag(lv_obj_flag_t f);
	LvObj& addState(lv_state_t state);
	LvObj& clearState(lv_state_t state);
	bool hasFlag(lv_obj_flag_t f);
	bool hasFlagAny(lv_obj_flag_t f);
	lv_state_t getState() const noexcept ;
	bool hasState(lv_state_t state);
	void *getGroup() const noexcept ;
	LvObj& allocateSpecAttr();
	bool checkType(const lv_obj_class_t *class_p);
	bool hasClass(const lv_obj_class_t *class_p);
	const lv_obj_class_t *getClass() const noexcept ;
	bool isValid();
	LvObj& setScrollbarMode(lv_scrollbar_mode_t mode);
	LvObj& setScrollDir(lv_dir_t dir);
	LvObj& setScrollSnapX(lv_scroll_snap_t align);
	LvObj& setScrollSnapY(lv_scroll_snap_t align);
	lv_scrollbar_mode_t getScrollbarMode() const noexcept ;
	lv_dir_t getScrollDir() const noexcept ;
	lv_scroll_snap_t getScrollSnapX() const noexcept ;
	lv_scroll_snap_t getScrollSnapY() const noexcept ;
	int32_t getScrollX() const noexcept ;
	int32_t getScrollY() const noexcept ;
	int32_t getScrollTop() const noexcept ;
	int32_t getScrollBottom() const noexcept ;
	int32_t getScrollLeft() const noexcept ;
	int32_t getScrollRight() const noexcept ;
	LvObj& scrollBy(int32_t x, int32_t y, lv_anim_enable_t anim_en);
	LvObj& scrollTo(int32_t x, int32_t y, lv_anim_enable_t anim_en);
	LvObj& scrollToX(int32_t x, lv_anim_enable_t anim_en);
	LvObj& scrollToY(int32_t y, lv_anim_enable_t anim_en);
	LvObj& scrollToView(lv_anim_enable_t anim_en);
	LvObj& scrollToViewRecursive(lv_anim_enable_t anim_en);
	bool isScrolling();
	LvObj& updateSnap(lv_anim_enable_t anim_en);
	LvObj& getScrollbarArea(lv_area_t *hor_area, lv_area_t *ver_area);
	LvObj& scrollbarInvalidate();
	LvObj& readjustScroll(lv_anim_enable_t anim_en);
	lv_obj_t *lvIndevSearchObj(lv_point_t *point);
	LvObj& lvGroupRemoveObj();
	LvObj& lvGroupFocusObj();
	LvObj& setPos(lv_grid_align_t x, lv_grid_align_t y);
	LvObj& setX(lv_grid_align_t x);
	LvObj& setY(lv_grid_align_t y);
	bool refrSize();
	LvObj& setSize(lv_grid_align_t w, lv_grid_align_t h);
	LvObj& setWidth(lv_grid_align_t w);
	LvObj& setHeight(lv_grid_align_t h);
	LvObj& setContentWidth(lv_grid_align_t w);
	LvObj& setContentHeight(lv_grid_align_t h);
	LvObj& setLayout(int32_t layout);
	bool isLayoutPositioned();
	LvObj& markLayoutAsDirty();
	LvObj& updateLayout();
	LvObj& setAlign(lv_align_t align);
	LvObj& align(lv_align_t align, lv_grid_align_t x_ofs, lv_grid_align_t y_ofs);
	LvObj& alignTo(const lv_obj_t *base, lv_align_t align, lv_grid_align_t x_ofs, lv_grid_align_t y_ofs);
	LvObj& getCoords(lv_area_t *coords);
	lv_grid_align_t getX() const noexcept ;
	lv_grid_align_t getX2() const noexcept ;
	lv_grid_align_t getY() const noexcept ;
	lv_grid_align_t getY2() const noexcept ;
	lv_grid_align_t getWidth() const noexcept ;
	lv_grid_align_t getHeight() const noexcept ;
	lv_grid_align_t getContentWidth() const noexcept ;
	lv_grid_align_t getContentHeight() const noexcept ;
	LvObj& getContentCoords(lv_area_t *area);
	lv_grid_align_t getSelfWidth() const noexcept ;
	lv_grid_align_t getSelfHeight() const noexcept ;
	bool refreshSelfSize();
	LvObj& refrPos();
	LvObj& moveTo(lv_grid_align_t x, lv_grid_align_t y);
	LvObj& moveChildrenBy(lv_grid_align_t x_diff, lv_grid_align_t y_diff, bool ignore_floating);
	LvObj& invalidateArea(const lv_area_t *area);
	LvObj& invalidate();
	bool areaIsVisible(lv_area_t *area);
	bool isVisible();
	LvObj& setExtClickArea(int32_t size);
	LvObj& getClickArea(lv_area_t *area);
	bool hitTest(const lv_point_t *point);
	LvObj& addStyle(LvStyle *style, lv_style_selector_t selector);
	LvObj& removeStyle(LvStyle *style, lv_style_selector_t selector);
	LvObj& refreshStyle(lv_style_selector_t selector, lv_style_prop_t prop);
	lv_style_value_t getStyleProp(lv_part_t part, lv_style_prop_t prop) const noexcept ;
	LvObj& setLocalStyleProp(lv_style_prop_t prop, lv_style_value_t value, lv_style_selector_t selector);
	lv_res_t getLocalStyleProp(lv_style_prop_t prop, lv_style_value_t *value, lv_style_selector_t selector) const noexcept ;
	bool removeLocalStyleProp(lv_style_prop_t prop, lv_style_selector_t selector);
	LvObj& styleCreateTransition(lv_part_t part, lv_state_t prev_state, lv_state_t new_state, const _lv_obj_style_transition_dsc_t *tr_dsc);
	_lv_style_state_cmp_t styleStateCompare(lv_state_t state1, lv_state_t state2);
	LvObj& fadeIn(int32_t time, int32_t delay);
	LvObj& fadeOut(int32_t time, int32_t delay);
	LvObj& initDrawRectDsc(int32_t part, lv_draw_rect_dsc_t *draw_dsc);
	LvObj& initDrawLabelDsc(int32_t part, lv_draw_label_dsc_t *draw_dsc);
	LvObj& initDrawImgDsc(int32_t part, lv_draw_image_dsc_t *draw_dsc);
	LvObj& initDrawLineDsc(int32_t part, lv_draw_line_dsc_t *draw_dsc);
	LvObj& initDrawArcDsc(int32_t part, lv_draw_arc_dsc_t *draw_dsc);
	LvObj&  calculateExtDrawSize(int32_t part);
	LvObj& refreshExtDrawSize();
	int32_t  getExtDrawSize() const noexcept ;
	LvObj& setFlexFlow(lv_flex_flow_t flow);
	LvObj& setFlexAlign(lv_flex_align_t main_place, lv_flex_align_t cross_place, lv_flex_align_t track_place);
	LvObj& setFlexGrow(uint8_t grow);
	LvObj& setStyleFlexFlow(lv_flex_flow_t value, lv_style_selector_t selector);
	LvObj& setStyleFlexMainPlace(lv_flex_align_t value, lv_style_selector_t selector);
	LvObj& setStyleFlexCrossPlace(lv_flex_align_t value, lv_style_selector_t selector);
	LvObj& setStyleFlexTrackPlace(lv_flex_align_t value, lv_style_selector_t selector);
	LvObj& setStyleFlexGrow(uint8_t value, lv_style_selector_t selector);
	LvObj& setGridDscArray(const int32_t col_dsc[], const int32_t row_dsc[]);
	LvObj& setGridAlign(lv_grid_align_t column_align, lv_grid_align_t row_align);
	LvObj& setGridCell(lv_grid_align_t x_align, uint8_t col_pos, uint8_t col_span, lv_grid_align_t y_align, uint8_t row_pos, uint8_t row_span);
	LvObj& setStyleGridRowDscArray(const int32_t value[], lv_style_selector_t selector);
	LvObj& setStyleGridColumnDscArray(const int32_t value[], lv_style_selector_t selector);
	LvObj& setStyleGridRowAlign(lv_grid_align_t value, lv_style_selector_t selector);
	LvObj& setStyleGridColumnAlign(lv_grid_align_t value, lv_style_selector_t selector);
	LvObj& setStyleGridCellColumnPos(lv_grid_align_t value, lv_style_selector_t selector);
	LvObj& setStyleGridCellColumnSpan(lv_grid_align_t value, lv_style_selector_t selector);
	LvObj& setStyleGridCellRowPos(lv_grid_align_t value, lv_style_selector_t selector);
	LvObj& setStyleGridCellRowSpan(lv_grid_align_t value, lv_style_selector_t selector);
	LvObj& setStyleGridCellXAlign(lv_grid_align_t value, lv_style_selector_t selector);
	LvObj& setStyleGridCellYAlign(lv_grid_align_t value, lv_style_selector_t selector);

	/* Cpp Event Management*/
	typedef struct {
		lv_event_code_t evCode;
		LvEvent* evCallback;
	}eventBind_t;

	/* List of registered events */
	std::list<eventBind_t> eventRegister;
	static void EventDispatcher(lv_event_t* e);
	LvObj& setCallback(lv_event_code_t code,LvEvent* Cb);

};

} /* namespace lvglpp */

#endif /* LVOBJ_H_ */
