/*
 * LvImgbtn.cpp
 *
 */

#include "LvImgbtn.h"

namespace lvglpp {

LvImgbtn::LvImgbtn() : LvImgbtn(NULL) {
}

LvImgbtn::LvImgbtn(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_imagebutton_create(Parent->raw()));
	else
		cObj.reset(lv_imagebutton_create(lv_scr_act()));

	setUserData(this);
}

LvImgbtn::~LvImgbtn() {
}
LvImgbtn& LvImgbtn::setSrc(lv_imagebutton_state_t state, const void *src_left, const void *src_mid, const void *src_right){
	lv_imagebutton_set_src(cObj.get(),state,src_left,src_mid,src_right);
	return *this;
}
const void *LvImgbtn::getSrcLeft(lv_imagebutton_state_t state) const noexcept {
	return lv_imagebutton_get_src_left(cObj.get(),state);
	
}
const void *LvImgbtn::getSrcMiddle(lv_imagebutton_state_t state) const noexcept {
	return lv_imagebutton_get_src_middle(cObj.get(),state);
	
}
const void *LvImgbtn::getSrcRight(lv_imagebutton_state_t state) const noexcept {
	return lv_imagebutton_get_src_right(cObj.get(),state);
	
}

} /* namespace lvglpp */
