#include"Equipment.h"


EquipmentBag Weapon_bag(1);
EquipmentBag Armors_bag(0);


Weapon TieJian("����", 0, 0, 30, 10, "TieJian.jpg", "TieJianInformation.png", sword, 0);
Weapon QiongLie("��ҽ�", 0, 0, 100, 100, "QiongLie.jpg", "QiongLieInformation.png", sword, 0);
Weapon TiLu("��¯ǹ", 0, 0, 70, 120, "TiLu.jpg", "TiLuInformation.png", spear, 0);
Weapon EMeiCi("��ü��", 0, 0, 40, 0, "EMeiCi.jpg", "EMeiCiInformation.png", knife, 0);
Weapon XuanGuang("������", 0, 0, 200, 0, "XuanGuang.jpg", "XuanGuangRenInformation.png", knife, 0);
Weapon DiaoHuaQin("����", 0, 0, 10, 20, "DiaoHuaQin.jpg", "DiaoHuaQinInformation.png", harp, 0);
Weapon LengYueXuanHua("��������", 0, 0, 50, 200, "LengYueXuanHua.jpg", "LengYueXuanHuaInformation.png", harp, 0);

Armors JinPao("����", 0, 0, 0, 40, "JinPao.jpg", "JinPaoInformation.png", hero1, 0);
Armors TianShiDaoPao("��ʦ����", 0, 0, 50, 200, "TianShiDaoPao.jpg", "TianShiInformation.png", hero1, 0);
Armors HuangJinJia("�ƽ��", 0, 0, 0, 50, "HuangJinJia.jpg", "HuangJinJiaInformation.png", hero2, 0);
Armors MingGuangKai("������", 0, 0, 0, 100, "MingGuangKai.jpg", "MingGuangInformation.png", hero2, 0);
Armors NiChangYuYi("��������", 0, 0, 0, 40, "NiChangYuYi.jpg", "YuYiInformation.png", heroine1, 0);
Armors JiangNanJinYi("���Ͻ���", 0, 0, 0, 30, "JiangNanJinYi.jpg", "JinYiInformation.png", heroine2, 0);


void Equipment::bindInfomation()
{
	Information = Sprite::create(infile);
	Information->setVisible(false);
	Information->setPosition(185, 405);
	Information->setTag(20);
}


Equipment::Equipment()
{}

Armors::Armors()
{}

Weapon::Weapon()
{}


//װ���๹�캯��
Equipment::Equipment(string name, int healthm_up, int magicm_up, int attack_up, int defence_up, string filename, string information, bool exist)
	:Name(name), Filename(filename)
{
	Healthm_up = healthm_up;
	Magicm_up = magicm_up;
	Attack_up = attack_up;
	Defence_up = defence_up;
	infile = information;
	Exist = exist;
}
//��������
Equipment::~Equipment()
{
}
//װ������ַ��غ���
string Equipment::retName()
{
	return Name;
}

int Equipment::retHealthmUp()
{
	return Healthm_up;
}

int Equipment::retMagicmUp()
{
	return Magicm_up;
}

int Equipment::retAttackUp()
{
	return Attack_up;
}

int  Equipment::retDefenceUp()
{
	return Defence_up;
}


Sprite * Equipment::retSurrender()
{
	Sprite * surrender = Sprite::create(infile);
	return surrender;
}

string Equipment::retFilename()
{
	return Filename;
}

string Equipment::retInformation()
{
	return infile;
}

void Equipment::changeExist()
{
	if (Exist == true)
		Exist = false;
	else
		Exist = true;
}









//�����๹�캯��
Weapon::Weapon(string name, int healthm_up, int magicm_up, int attack_up, int defence_up,
	string filename, string information, weaponType weapontype, bool exist)
	:Equipment(name, healthm_up, magicm_up, attack_up, defence_up, filename, information, exist)
{
	WeaponType = weapontype;
}

//�����෵�����ͺ���
enum weaponType Weapon::retWeapontype()
{
	return WeaponType;
}

Armors::Armors(string name, int healthm_up, int magicm_up, int attack_up, int defence_up,
	string filename, string information, armorsType armorstype, bool exist)
	:Equipment(name, healthm_up, magicm_up, attack_up, defence_up, filename, information, exist)
{
	ArmorsType = armorstype;
}

enum armorsType Armors::retArmorstype()
{
	return ArmorsType;
}


EquipmentBag::EquipmentBag(int i)
{
	if (i == 1)
	{
		this->pushEquipment(&TieJian);
		//this->PushEquipment(&EMeiCi);
	}
	else
	{
		this->pushEquipment(&JinPao);
	}
}


EquipmentBag::EquipmentBag()
{
	log("fuck");
}

void EquipmentBag::deleteEquipment(Equipment * equipment)
{
	vector<Equipment*>::iterator it = E.begin();
	for (; it != E.end(); it++)
		if ((*it)->retName() == equipment->retName())
		{
			it = E.erase(it);
			it--;
		}
}

void EquipmentBag::pushEquipment(Equipment * equipment)
{
	E.push_back(equipment);
}

Equipment* EquipmentBag::retEquipment(int i)
{
	if (i <= E.size())
		return E[i];
}

Sprite* EquipmentBag::createExplanation(string filename)
{
	Sprite* exp = Sprite::create(filename);
	return exp;
}

int EquipmentBag::bagSize()
{
	return E.size();
}