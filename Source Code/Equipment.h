#pragma once
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
using namespace cocos2d::ui;
using namespace cocos2d;
#include<string>
#include<vector>
#include<iostream>
using namespace  std;


class Weapon;
class Armors;
class Equipment;
class EquipmentBag;
extern Weapon TieJian;
extern Weapon QiongLie;
extern Weapon TiLu;
extern Weapon EMeiCi;
extern Weapon XuanGuang;
extern Weapon DiaoHuaQin;
extern Weapon LengYueXuanHua;
extern Armors JinPao;
extern Armors TianShiDaoPao;
extern Armors HuangJinJia;
extern Armors MingGuangKai;
extern Armors NiChangYuYi;
extern Armors JiangNanJinYi;
extern EquipmentBag Weapon_bag;
extern EquipmentBag Armors_bag;

//装备类
class Equipment
{
public:
	Equipment();
	Equipment(string name, int healthm_up, int magicm_up,
		int attack_up, int defence_up, string filename, string information, bool exist);
	~Equipment();
	string retName();
	int retHealthmUp();
	int retMagicmUp();
	int retAttackUp();
	int retDefenceUp();
	Sprite*  retSurrender();
	string retFilename();
	string retInformation();
	void changeExist();
	void bindInfomation();

	Sprite* Information;
private:
	string Name;                        //装备名称
	int Healthm_up;                     //气血值上限提升值
	int Magicm_up;                      //内力上限提升值
	int Attack_up;                      //攻击提升值
	int Defence_up;                     //韧性提升值
	string Filename;                    //装备图片文件名
	string infile;                      //信息文件名
	bool Exist;
};

//定义武器类型
enum weaponType
{
	sword, knife, spear, harp        //四种武器类型:剑，刀，枪，琴
};

//武器类，继承于装备类
class Weapon :public Equipment
{
public:
	Weapon();
	Weapon(string name, int healthm_up, int magicm_up, int attack_up, int defence_up,
		string filename, string information, weaponType weapontype, bool exist);
	enum weaponType retWeapontype();
private:
	weaponType WeaponType;                 //武器类型
};


enum armorsType
{
	hero1, hero2, heroine1, heroine2
};

//防具类
class Armors :public Equipment
{
public:
	Armors();
	Armors(string name, int healthm_up, int magicm_up, int attack_up, int defence_up,
		string filename, string information, armorsType armorstype, bool exist);             //构造函数
	enum armorsType retArmorstype();
private:
	armorsType ArmorsType;
};

//定义一个装备类背包
class EquipmentBag
{
public:
	EquipmentBag(int i);
	EquipmentBag();
	void deleteEquipment(Equipment * equipment);                  //删除指定装备
	void pushEquipment(Equipment * equipment);                    //添加指定装备
	Equipment * retEquipment(int i);                              //得到第i个装备的信息
	Sprite* createExplanation(string filename);                   //
	int bagSize();
	vector<Equipment*> E;                                         //存储装备的容器
};