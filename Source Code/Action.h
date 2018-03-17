#pragma once
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
using namespace cocos2d::ui;
using namespace cocos2d;
#include<string>
#include<iostream>
using namespace  std;

class Activity;

extern Activity  ZhugeYibin_act;
extern Activity  TaoLingyuan_act;
extern Activity  DaHan_act;
extern Activity  NiuYao_act;
extern Activity GaoDieNie_act;
extern Activity  GuShe_act;
extern Activity  JiaFei_act;

class Activity
{
public:
	Activity();
	Activity(string  name , int number , string sname);
	~Activity();
	void  Attack_action(Sprite* sprite );
	Sprite * Stand_action();
	void CopyAct(Activity & act);
//private:
	string a_filename;                    //攻击动作资源文件名
	string s_filename;                    //站立图片
	int num;                            //资源图片张数

};