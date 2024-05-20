/*
 * LvTable.cpp
 *
 */

#include "LvTable.h"

namespace lvglpp {

LvTable::LvTable() : LvTable(NULL) {
}

LvTable::LvTable(LvObj* Parent) : LvObj(Parent) {
	if(Parent)
		cObj.reset(lv_table_create(Parent->raw()));
	else
		cObj.reset(lv_table_create(lv_scr_act()));

	setUserData(this);
}

LvTable::~LvTable() {
}
LvTable& LvTable::setCellValue(uint32_t row, uint32_t col, const char *txt){
	lv_table_set_cell_value(cObj.get(),row,col,txt);
	return *this;
}

LvTable& LvTable::setRowCnt(uint32_t row_cnt){
	lv_table_set_row_count(cObj.get(),row_cnt);
	return *this;
}
LvTable& LvTable::setColCnt(uint32_t col_cnt){
	lv_table_set_column_count(cObj.get(),col_cnt);
	return *this;
}
LvTable& LvTable::setColWidth(uint32_t col_id, lv_grid_align_t w){
	lv_table_set_column_width(cObj.get(),col_id,w);
	return *this;
}
LvTable& LvTable::addCellCtrl(uint32_t row, uint32_t col, lv_table_cell_ctrl_t ctrl){
	lv_table_add_cell_ctrl(cObj.get(),row,col,ctrl);
	return *this;
}
LvTable& LvTable::clearCellCtrl(uint32_t row, uint32_t col, lv_table_cell_ctrl_t ctrl){
	lv_table_clear_cell_ctrl(cObj.get(),row,col,ctrl);
	return *this;
}
const char *LvTable::getCellValue(uint32_t row, uint32_t col) const noexcept {
	return lv_table_get_cell_value(cObj.get(),row,col);
	
}
uint32_t LvTable::getRowCnt() const noexcept {
	return lv_table_get_row_count(cObj.get());
	
}
uint32_t LvTable::getColCnt() const noexcept {
	return lv_table_get_column_count(cObj.get());
	
}
int32_t LvTable::getColWidth(uint32_t col) const noexcept {
	return lv_table_get_column_width(cObj.get(),col);
	
}
bool LvTable::hasCellCtrl(uint32_t row, uint32_t col, lv_table_cell_ctrl_t ctrl){
	return lv_table_has_cell_ctrl(cObj.get(),row,col,ctrl);
	
}
LvTable& LvTable::getSelectedCell(uint32_t *row, uint32_t *col){
	lv_table_get_selected_cell(cObj.get(),row,col);
	return *this;
}

} /* namespace lvglpp */
