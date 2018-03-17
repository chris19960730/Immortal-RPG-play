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
	string   filename;                //�ļ���
	Node * node;  //��ӳ���
	Vector<SpriteFrame *>  vec;            //�Ի�ͼƬ������
										   //Sprite *sp;
										   //Button * but;
	int      totalnum;                //�ܹ�ͼƬ��
	int      nownum;                  //��ǰͼƬ��
	bool    whetherBattle;          //�ڴ˶Ի�֮���Ƿ���ս��
	Dialog * pt;                     //��һ�Ի�ָ��
	int changeNum;                   //�ڵڼ����л�ս������
	Vector<SpriteFrame*> ::const_iterator it;
};