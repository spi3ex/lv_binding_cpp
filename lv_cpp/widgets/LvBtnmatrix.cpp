/*
 * LvBtnmatrix.cpp
 *
 */

#include "LvBtnmatrix.h"

namespace lvglpp {

LvBtnmatrix::LvBtnmatrix() : LvBtnmatrix(NULL) {
}

LvBtnmatrix::LvBtnmatrix(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_buttonmatrix_create(Parent->raw()));
	else
		cObj.reset(lv_buttonmatrix_create(lv_scr_act()));

	setUserData(this);
}

LvBtnmatrix::~LvBtnmatrix() {
}
LvBtnmatrix& LvBtnmatrix::setMap(const char *map[]){
	lv_buttonmatrix_set_map(cObj.get(),map);
	return *this;
}
LvBtnmatrix& LvBtnmatrix::setCtrlMap(const lv_buttonmatrix_ctrl_t ctrl_map[]){
	lv_buttonmatrix_set_ctrl_map(cObj.get(),ctrl_map);
	return *this;
}
// LvBtnmatrix& LvBtnmatrix::setSelectedBtn(uint32_t btn_id){
// 	lv_button_matrix_set_selected_button(cObj.get(),btn_id);
// 	return *this;
// }
LvBtnmatrix& LvBtnmatrix::setBtnCtrl(uint32_t btn_id, lv_buttonmatrix_ctrl_t ctrl){
	lv_buttonmatrix_set_button_ctrl(cObj.get(),btn_id,ctrl);
	return *this;
}
LvBtnmatrix& LvBtnmatrix::clearBtnCtrl(uint32_t btn_id, lv_buttonmatrix_ctrl_t ctrl){
	lv_buttonmatrix_clear_button_ctrl(cObj.get(),btn_id,ctrl);
	return *this;
}
LvBtnmatrix& LvBtnmatrix::setBtnCtrlAll(lv_buttonmatrix_ctrl_t ctrl){
	lv_buttonmatrix_set_button_ctrl_all(cObj.get(),ctrl);
	return *this;
}
LvBtnmatrix& LvBtnmatrix::clearBtnCtrlAll(lv_buttonmatrix_ctrl_t ctrl){
	lv_buttonmatrix_clear_button_ctrl_all(cObj.get(),ctrl);
	return *this;
}
LvBtnmatrix& LvBtnmatrix::setBtnWidth(uint32_t btn_id, uint8_t width){
	lv_buttonmatrix_set_button_width(cObj.get(),btn_id,width);
	return *this;
}
LvBtnmatrix& LvBtnmatrix::setOneChecked(bool en){
	lv_buttonmatrix_set_one_checked(cObj.get(),en);
	return *this;
}
const char **LvBtnmatrix::getMap() const noexcept {
	return lv_buttonmatrix_get_map(cObj.get());
	
}
uint32_t LvBtnmatrix::getSelectedBtn() const noexcept {
	return lv_buttonmatrix_get_selected_button(cObj.get());
	
}
const char *LvBtnmatrix::getBtnText(uint32_t btn_id) const noexcept {
	return lv_buttonmatrix_get_button_text(cObj.get(),btn_id);
	
}
bool LvBtnmatrix::hasBtnCtrl(uint32_t button_id, lv_buttonmatrix_ctrl_t ctrl){
	return lv_buttonmatrix_has_button_ctrl(cObj.get(),button_id,ctrl);
	
}
bool LvBtnmatrix::getOneChecked() const noexcept {
	return lv_buttonmatrix_get_one_checked(cObj.get());
	
}

} /* namespace lvglpp */
