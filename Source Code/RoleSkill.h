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

	//��
	void bindSprite(string file,string** skillfile,string* headfile);
	void bindSkillBtn(string* begin,string* end);
	void bindBtn();
	//�ذ�
	void rebindSkill(int numi, int numj, string file);
	
	bool layerIsVisible();

	//��ʾ
	void showLayer(int num);
	void showSkillLayer(bool bset);

	//���
	void addBtnTo(Layer* scene, int tag);
	void addLayerTo(Layer* scene, int tag);

	//����λ��
	void setSkillLayerPosition(int x, int y);

	MenuItemImage* closeBtn;
	
private:
	Sprite* layer;           //����
	Sprite* skill[4][4];     //����ͼ��
	Sprite* head[4];         //����ͷ��

	//���ܰ�ť
	Menu* skillMenu;
	MenuItemImage* skillBtn[4];
	
	bool _layerIsVisible;
};

