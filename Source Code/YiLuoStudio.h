#pragma once
#include "cocos2d.h"
#include"RoleData.h"
#include"RoleSkill.h"
#include"BagData.h"
USING_NS_CC;
//1

class YiLuoStudioScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(YiLuoStudioScene);
	void onEnterTransitionDidFinish();
	void roleCallBack(Ref* sender);
	void bagCallBack(Ref* sender);
	void skillCallBack(Ref* sender);
	void setCallBack(Ref* sender);
	void saveCallBack(Ref* sender);
	void closeCallBack(Ref* sender);
	void mapCallBack(Ref* sender);
	void seCallBack(Ref* sender);
	void roleCloseCallBack(Ref* sender);
	void skillCloseCallBack(Ref* sender);
	void bagCloseCallBack(Ref* sender);
	void QunZongCallBack(Ref* sender, ui::Widget::TouchEventType type);
	void TianZongCallBack(Ref* sender, ui::Widget::TouchEventType type);
	void YangZongCallBack(Ref* sender, ui::Widget::TouchEventType type);
	void ZhangZongCallBack(Ref* sender, ui::Widget::TouchEventType type);


	//���û�����ť
	void setAllEnabled(bool T);
	Sprite* xie;
	void bang(float dt);
private:
	//��ť
	MenuItemImage* roleBtn;
	MenuItemImage* bagBtn;
	MenuItemImage* skillBtn;
	MenuItemImage* setBtn;
	MenuItemImage* saveBtn;
	MenuItemImage* closeBtn;
	MenuItemImage* mapBtn;
	MenuItemImage* seBtn;

	//��������ť
	Menu* menu;
	Menu* menuRole;
	Menu* menuSe;
	//������Ϣ
	RoleData* roleData;
	//skill
	RoleSkill* roleSkill;
	//bag
	BagData* bagData;



};


