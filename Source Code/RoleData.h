#pragma once
#include"cocos2d.h"
#include"Role.h"
USING_NS_CC;
using namespace std;

//人物出现状态(是否出现)
extern bool Nan1show;
extern bool Nan2show;
extern bool Nv1show;
extern bool Nv2show;

//layer 400*560
//head 100*150
//roleBtn 100*30
//closeBtn 41*70
//layer[i]->setPosition(x, y);
//head[i]->setPosition(x - 200 + 72.14, y - 280 + 427.78);
class RoleData
{
public:
	RoleData();
	void init(Layer* scene);
	void bindAllChild();                                    //绑定所有的子节点
	void bindSprite(string* file, string* headfile);        //新建头像，layer
	void bindRoleBtn(string begin, string end, int rolenum);//新建roleBtn
	void bindBtn();                                         //绑定所有的Btn
	void bindHead(string* file);                            //新建头像


	//添加到父节点
	void addHeadTo(Layer* scene, int tag);   //头像
	void addBtnTo(Layer* scene, int tag);    //按钮
	void addLayerTo(Layer* scene, int tag);  //基层

	MenuItemImage* retCloseBtn();
	Sprite* retLayer(int num);

	//设置位置、尺寸、Tag，visible
	void setLayerPosition(int x, int y);      //设置层的位置
	void setCloseBtnPosition(int x, int y);   //设置close按钮位置
	void setBtnScale(float x, float y);       //设置roleBtn的scale
	void setLayerTag(int tag);                //设置层Tag
	void setLayerVisible(bool bset);          //设置layer的visible
	void setCloseBtnVisible(bool bset);       //设置close按钮visible
	
	bool layerIsVisible();     //返回层是否可见
	void showLayer(int num);   //显示层

	//close按钮
	MenuItemImage* closeBtn;

private:
	Sprite* roledataLayer;//基层
	Sprite* layer[4];     //四个基层(没用了)
	Sprite* head[4];      //头像

	Menu* roleMenu;
	MenuItemImage* roleBtn[4];//人物按钮

	int _layerTag;
	bool _layerIsVisible;
};