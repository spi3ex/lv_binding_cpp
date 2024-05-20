/*
 * LvLine.h
 *
 */

#ifndef LVLINE_H_
#define LVLINE_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvLine: public LvObj {
public:
	LvLine();
	LvLine(LvObj* Parent);
	virtual ~LvLine() override;
	LvLine& setPoints(const lv_point_precise_t points[], uint32_t point_num);
	LvLine& setYInvert(bool en);
	bool getYInvert() const noexcept ;
};

} /* namespace lvglpp */

#endif /* LVLINE_H_ */
