#pragma once
#include"cocos2d.h"
#include<iostream>
#include"Prop.h"
#include"Equipment.h"
#include"Role.h"
#include"RoleData.h"
#include<vector>

using namespace std;
USING_NS_CC;

extern int whichBag; //第一个背包栏是0
extern int _bagNum;  //第一个背包栏是0
extern int _itemNum; //第一个道具是0

//layer 390*470 x,y
//bagbtn 130*30 x-130,y+220
//itembtn 100*100 x-120,y+125
//close 41*70 x+215.5,y+200
//money 360*20 x,y-205
class BagData
{
public:
	BagData();
	void init(Layer* scene);   //背包初始化
	void propBagInit();        //道具包初始化
	void equipmentInit();      //装备包初始化
	void propBagRefresh();     //道具包刷新

	void showItemBtn(int num, bool bset);                        //显示道具(0)、武器(1)、防具(2)的图标按钮
	void showLayer(int num);                                     //显示道具(0)、武器(1)、防具(2)栏
	void showBagLayer(bool bset);                                //显示背包
	void showLabel(int num, bool bset);                          //显示数量Label
	void showUseBtn(bool bset);                                  //显示使用按钮
	void showPropInformation(int num, bool bset);                //显示道具信息栏
	void showEquipmentInformation(int num, bool bset, int which);//显示装备信息栏，武器(1)、防具(0)
	void showShop(bool bset);                                    //显示商店界面

	void addLayerTo(Layer* scene, int tag);        //添加主Layer到scene
	void addBtnTo(Layer* scene, int tag);          //添加背包按钮到scene
	void addPropLabelTo(Layer* scene, int tag);    //添加道具数量Label到scene
	void addMoneyLabelTo(Layer* scene, int tag);   //添加金币Label到scene
	void addAllItemBtn(Layer* scene);             //绑定所有的itemBtn到scene

	void bindBtn();                                //绑定基础按钮到menu
	void bindSprite(string file, string moneyfile);//绑定主layer和金币层
	void bindBagBtn(string* begin, string* end);   //绑定背包按钮
	void bindUseBtn(string begin, string end);     //绑定使用按钮
	
	void bindMainScene(Layer* scene);              //绑定主场景
	void setItem(int bagNum, int itemNum);         //设置当前使用的item
	void setPosition(float x, float y);            //设置背包层的位置
	void setAllBtnEnable(bool bset);               //设置所有按钮可用/不可用
	void setWhichBag(int num);

	bool useBtnIsVisible();                        //使用按钮usebtn是否可见

	bool getMoney(int num);                        //获得金币，有正负之分
	void getWeapon(Equipment* weapon);             //获得武器
	void getArmors(Equipment* armors);             //获得防具
	void getProp(Prop* prop, int num);             //获得道具

	Layer* retMainScene();
	int retItemNum();

private:
	//绑定的场景
	Layer* mainscene;

	//基础背包层
	Sprite* layer;

	//背包按钮：使用按钮、背包栏切换按钮
	Menu* bagMenu;
	MenuItemImage* bagBtn[3];
	MenuItemImage* useBtn;

	//物品按钮
	Menu* itemMenu;
	vector<MenuItemImage*> itemBtn[3];
	vector<Label*> label[3];

	//金币层
	Label* moneyLabel;
	Sprite* money;

	//记录当前使用的道具
	

	//使用道具选择人物界面
	Sprite* useChoose;
	Menu* chooseMenu;    //使用道具时选择人物界面的人物按钮
	MenuItemImage* choose[4];

	//商店界面
	Sprite* shopLayer;

	Menu* shopMenu;      //背包界面商店按钮
	MenuItemImage* shopBtn;

	Menu* shopMenuMax;   //商店界面购买按钮、返回按钮
	MenuItemImage* shopPropBtn[4];
	MenuItemImage* shopCloseBtn;

public:
	MenuItemImage* closeBtn;//关闭按钮
	           //记录调用的背包
	
};