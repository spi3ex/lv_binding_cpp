/*
 * LvSpinner.cpp
 *
 */

#include "LvSpinner.h"

namespace lvglpp {

LvSpinner::LvSpinner() : LvSpinner(NULL) {
}

LvSpinner::LvSpinner(LvObj* Parent) :  LvSpinner(Parent,0,100){
}

LvSpinner::LvSpinner(LvObj* Parent,uint32_t time ,uint32_t arc_length) : LvObj(Parent) {
	if(Parent){
		cObj.reset(lv_spinner_create(lv_screen_active()));
		lv_obj_center(cObj.get());
		lv_spinner_set_anim_params(cObj.get(), time, arc_length);
	} else {
		cObj.reset(lv_spinner_create(NULL));
        lv_obj_center(cObj.get());
        lv_spinner_set_anim_params(cObj.get(), time, arc_length);
    }
}

LvSpinner::~LvSpinner() {
}

} /* namespace lvglpp */
