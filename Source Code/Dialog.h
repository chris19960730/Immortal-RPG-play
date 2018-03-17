#pragma once
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include"BattleScene.h"
using namespace cocos2d::ui;
using namespace cocos2d;
#include<string>
#include<iostream>
using namespace  std;
using namespace cocostudio::timeline;
#define    SPTAG 80
#define    BUTAG 81

class Dialog;
class BarrierLayer;

extern Dialog ShuShan1;
extern Dialog Dia_WuChangChaGuan;
extern Dialog Dia_YingZhouKeZhan;
extern Dialog Dia_YingZhouJiaoWai;
extern Dialog Dia_DengZhou1;
extern Dialog Dia_DengZhou2;
extern Dialog Dia_DengZhouHouShan1;
extern Dialog Dia_DengZhouHouShan2;
extern Dialog Dia_DengZhouLast;
extern Dialog Dia_YangZong;
extern Dialog Dia_QunZong1;
extern Dialog Dia_QunZong2;
extern Dialog Dia_TianZong1;
extern Dialog Dia_TianZong2;
extern Dialog Dia_ZhangZong1;
extern Dialog Dia_ZhangZong2;
extern Dialog Dia_ZhangZong3;
extern Dialog Dia_ZhangZong4;
extern Dialog Dia_ZhangZong5;
extern Dialog Dia_ZhangZong6;
extern bool  QunZongClose;



class BarrierLayer : public Layer
{
public:
	bool init();
	CREATE_FUNC(BarrierLayer);


};

class Dialog
{
public:
	Dialog(string s, int numt, bool whether_b, int numn = 0, Dialog * nextdia = NULL, int change = 0);
	~Dialog();
	void dialogBegin(Node * node);
	void dialogContinue(Ref* sender, ui::Widget::TouchEventType type);

private:
	string   filename;                //文件名
	Node * node;  //添加场景
	Vector<SpriteFrame *>  vec;            //对话图片的容器
										   //Sprite *sp;
										   //Button * but;
	int      totalnum;                //总共图片数
	int      nownum;                  //当前图片数
	bool    whetherBattle;          //在此对话之后是否还有战斗
	Dialog * pt;                     //下一对话指针
	int changeNum;                   //在第几张切换战斗场景
	Vector<SpriteFrame*> ::const_iterator it;
};