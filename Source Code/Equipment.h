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

//װ����
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
	string Name;                        //װ������
	int Healthm_up;                     //��Ѫֵ��������ֵ
	int Magicm_up;                      //������������ֵ
	int Attack_up;                      //��������ֵ
	int Defence_up;                     //��������ֵ
	string Filename;                    //װ��ͼƬ�ļ���
	string infile;                      //��Ϣ�ļ���
	bool Exist;
};

//������������
enum weaponType
{
	sword, knife, spear, harp        //������������:��������ǹ����
};

//�����࣬�̳���װ����
class Weapon :public Equipment
{
public:
	Weapon();
	Weapon(string name, int healthm_up, int magicm_up, int attack_up, int defence_up,
		string filename, string information, weaponType weapontype, bool exist);
	enum weaponType retWeapontype();
private:
	weaponType WeaponType;                 //��������
};


enum armorsType
{
	hero1, hero2, heroine1, heroine2
};

//������
class Armors :public Equipment
{
public:
	Armors();
	Armors(string name, int healthm_up, int magicm_up, int attack_up, int defence_up,
		string filename, string information, armorsType armorstype, bool exist);             //���캯��
	enum armorsType retArmorstype();
private:
	armorsType ArmorsType;
};

//����һ��װ���౳��
class EquipmentBag
{
public:
	EquipmentBag(int i);
	EquipmentBag();
	void deleteEquipment(Equipment * equipment);                  //ɾ��ָ��װ��
	void pushEquipment(Equipment * equipment);                    //���ָ��װ��
	Equipment * retEquipment(int i);                              //�õ���i��װ������Ϣ
	Sprite* createExplanation(string filename);                   //
	int bagSize();
	vector<Equipment*> E;                                         //�洢װ��������
};