#pragma once
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
using namespace cocos2d::ui;
using namespace cocos2d;
#include<string>
#include<iostream>
using namespace  std;

class Prop;
class PropBag;

extern PropBag Propbag;
extern Prop XiaoLan;
extern Prop DaLan;
extern Prop XiaoXue;
extern Prop DaXue;

//道具类
class Prop
{
	friend class PropBag;
public:
	Prop();
	Prop(string name, int health_up, int magic_up,
		int prop_num, int prop_price, string filename,string infile, string _effectfile);

	string retName();                         //返回道具名称
	int retHealthUp();                        //返回气血提升值
	int retMagicUp();                         //返回内力提升值
	int retPropNum();                         //返回道具数量
	Sprite * retSurrender();
	void changeNum(int num);                  //改变道具数量
	int retPrice();
	Label* getLabel();                        
	void bindLabel();                         //绑定道具数量Label
	string retFilename();                     //返回文件名
	void bindInformation();                   //绑定信息框
	void bindEffectAction(Layer* scene);      //绑定使用道具效果

	Sprite* Information;
	Sprite* effect;
private:
	string Name;                              //道具名字
	int Health_up;                            //气血提升值                             
	int Magic_up;                             //内力提升值
	string Filename;                          //道具图片名称
	int Prop_num;                             //道具数量
	int Prop_price;                           //道具价格
	Label* propLabel;
	string informationFile;
	string effectfile;
};

class PropBag
{
public:
	PropBag();
	PropBag(int money);
	void bindAllLabel();
	void useProp(Prop * prop);                         //使用道具函数，参数为道具类
	void useProp(int i);                               //使用第i个道具
	Prop * retProp(int i);                             //得到第i个道具的信息
	void pushProp(Prop* prop,int number);              //添加道具函数
	void changeMoney(int num);                         //改变现有金币的函数
	int retMoney();                                    //返回当前金币数
	bool changeProp(string propName, int num);         //改变道具的数量
	int searchProp(Prop* prop);                        //某道具的位置

	vector<Prop*> P;                     //存储道具的容器
	bool _refresh;                       //背包是否需要刷新
	
	
private:
	int Money;                                         //拥有金币数量
};
