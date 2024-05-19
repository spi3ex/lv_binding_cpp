/*
 * LvImg.cpp
 *
 */

#include "LvImg.h"

namespace lvglpp {

LvImg::LvImg() : LvImg(NULL) {
}

LvImg::LvImg(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_image_create(Parent->raw()));
	else
		cObj.reset(lv_image_create(lv_scr_act()));

	setUserData(this);
}

LvImg::~LvImg() {
}
LvImg& LvImg::setSrc(const void *src){
	lv_image_set_src(cObj.get(),src);
	return *this;
}
LvImg& LvImg::setOffsetX(lv_grid_align_t x){
	lv_image_set_offset_x(cObj.get(),x);
	return *this;
}
LvImg& LvImg::setOffsetY(lv_grid_align_t y){
	lv_image_set_offset_y(cObj.get(),y);
	return *this;
}
LvImg& LvImg::setAngle(int16_t angle){
	lv_image_set_angle(cObj.get(),angle);
	return *this;
}
LvImg& LvImg::setPivot(lv_grid_align_t x, lv_grid_align_t y){
	lv_image_set_pivot(cObj.get(),x,y);
	return *this;
}
LvImg& LvImg::setZoom(uint16_t zoom){
	lv_image_set_zoom(cObj.get(),zoom);
	return *this;
}
LvImg& LvImg::setAntialias(bool antialias){
	lv_image_set_antialias(cObj.get(),antialias);
	return *this;
}
const void *LvImg::getSrc() const noexcept {
	return lv_image_get_src(cObj.get());
	
}
int32_t LvImg::getOffsetX() const noexcept {
	return lv_image_get_offset_x(cObj.get());
	
}
int32_t LvImg::getOffsetY() const noexcept {
	return lv_image_get_offset_y(cObj.get());
	
}
uint16_t LvImg::getAngle() const noexcept {
	return lv_image_get_angle(cObj.get());
	
}
LvImg& LvImg::getPivot(lv_point_t *pivot){
	lv_image_get_pivot(cObj.get(),pivot);
	return *this;
}
uint16_t LvImg::getZoom() const noexcept {
	return lv_image_get_zoom(cObj.get());
	
}
bool LvImg::getAntialias() const noexcept {
	return lv_image_get_antialias(cObj.get());
	
}

} /* namespace lvglpp */
