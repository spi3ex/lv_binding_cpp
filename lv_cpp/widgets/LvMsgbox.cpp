/*
 * LvMsgbox.cpp
 *
 */

#include "LvMsgbox.h"

namespace lvglpp {

const char * btn_txts_def = {"OK"};

LvMsgbox::LvMsgbox() : LvMsgbox(NULL) {
}

LvMsgbox::LvMsgbox(LvObj* Parent) : LvMsgbox(Parent,"Message","Text",btn_txts_def,true)  {
}

LvMsgbox::LvMsgbox(LvObj* Parent,const char * title, const char * txt, const char * btn_txts, bool add_close_btn) : LvObj(Parent) {

	if(Parent){
		cObj.reset(lv_msgbox_create(lv_screen_active()));
		lv_msgbox_add_title(cObj.get(),title);
		lv_msgbox_add_text(cObj.get(),btn_txts);
		lv_msgbox_add_close_button(cObj.get());
	} else {
		cObj.reset(lv_msgbox_create(NULL));
		lv_msgbox_add_title(cObj.get(),title);
		lv_msgbox_add_text(cObj.get(),btn_txts);
		lv_msgbox_add_close_button(cObj.get());
	}
}

LvMsgbox::~LvMsgbox() {
}

} /* namespace lvglpp */
