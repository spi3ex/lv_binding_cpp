/*
 * LvTable.h
 *
 */

#ifndef LVTABLE_H_
#define LVTABLE_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvTable: public LvObj {
public:
	LvTable();
	LvTable(LvObj* Parent);
	virtual ~LvTable() override;
	LvTable& setCellValue(uint32_t row, uint32_t col, const char *txt);
	
	template <typename... ArgsT>
	LvTable& setCellValueFmt(uint32_t row, uint32_t col, const char *fmt, ArgsT... args){
	lv_table_set_cell_value_fmt(cObj.get(),row,col,fmt,args...);
	return *this;
};
	LvTable& setRowCnt(uint32_t row_cnt);
	LvTable& setColCnt(uint32_t col_cnt);
	LvTable& setColWidth(uint32_t col_id, lv_grid_align_t w);
	LvTable& addCellCtrl(uint32_t row, uint32_t col, lv_table_cell_ctrl_t ctrl);
	LvTable& clearCellCtrl(uint32_t row, uint32_t col, lv_table_cell_ctrl_t ctrl);
	const char *getCellValue(uint32_t row, uint32_t col) const noexcept ;
	uint32_t getRowCnt() const noexcept ;
	uint32_t getColCnt() const noexcept ;
	int32_t getColWidth(uint32_t col) const noexcept ;
	bool hasCellCtrl(uint32_t row, uint32_t col, lv_table_cell_ctrl_t ctrl);
	LvTable& getSelectedCell(uint32_t *row, uint32_t *col);
};

} /* namespace lvglpp */

#endif /* LVTABLE_H_ */
