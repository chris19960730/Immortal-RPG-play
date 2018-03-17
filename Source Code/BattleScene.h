#pragma once
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include "Prop.h"
using namespace cocos2d;
using namespace cocos2d::ui;

extern int winwhich;

class BattleScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(BattleScene);
	void UsingProp(Ref * psender, ui::Widget::TouchEventType type);
	void UsingSkill(Ref * psender, ui::Widget::TouchEventType type);
	void Using1skill(Ref * psender, ui::Widget::TouchEventType type);
	void Using2skill(Ref * psender, ui::Widget::TouchEventType type);
	void Using3skill(Ref * psender, ui::Widget::TouchEventType type);
	void EnemyAttack(int num);            //参数为当前队列的人数
	void State_Layer();
	void onEnterTransitionDidFinish();
	bool exist(Prop* prop);
	void ShowItemBtn();
	void ShowLayer();
	void ShowXLLabel();
	void ShowDLLabel();
	void ShowXXLabel();
	void ShowDXLabel();
	void ShowAll();
	Layer* Ret_bagLayer();
	void  PopSceneToGame(Ref * psender ,TouchEventType  Type);
	void  PopSceneToMain(Ref * psender, TouchEventType  Type);
	int DamageCal(int AttackValue, int BasicValue, int DeffenceValue);
public:
	bool  Whether_End = false;        //判断战斗是否结束
	MenuItemImage* XXBtn;
	MenuItemImage* XLBtn;
	MenuItemImage* DXBtn;
	MenuItemImage* DLBtn;
	Label* XXnum;
	Label* XLnum;
	Label* DXnum;
	Label* DLnum;
	Sprite* background;
	Layer* bagLayer;
	Menu* bagmenu;
	int run_num=0;           //当前活动的成员编号
	bool Survive[4] = {false};
	int object = 0;         //敌人攻击目标
};

