#pragma once
#include<iostream>
#include"cocos2d.h"
USING_NS_CC;
using namespace std;


//layer 600*400   x,y
//skill 100*100   1 2      1 -50,+70   2 +45,+70
//                3 4      3 -50,-90   4 +45,-90
//skillbtn 150*30   x-300+75 , y+200-15     x'+150
//head 100*150   x-230,y
//closeBtn 41*70 x+320.5,y+175
class RoleSkill
{
public:
	RoleSkill();
	void init(Layer* scene);

	//绑定
	void bindSprite(string file,string** skillfile,string* headfile);
	void bindSkillBtn(string* begin,string* end);
	void bindBtn();
	//重绑定
	void rebindSkill(int numi, int numj, string file);
	
	bool layerIsVisible();

	//显示
	void showLayer(int num);
	void showSkillLayer(bool bset);

	//添加
	void addBtnTo(Layer* scene, int tag);
	void addLayerTo(Layer* scene, int tag);

	//设置位置
	void setSkillLayerPosition(int x, int y);

	MenuItemImage* closeBtn;
	
private:
	Sprite* layer;           //基层
	Sprite* skill[4][4];     //技能图标
	Sprite* head[4];         //人物头像

	//技能按钮
	Menu* skillMenu;
	MenuItemImage* skillBtn[4];
	
	bool _layerIsVisible;
};

