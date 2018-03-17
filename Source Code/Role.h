#pragma once
#include "Equipment.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include"Skill.h"
#include"Action.h"
#include"Prop.h"
using namespace cocos2d::ui; 
using namespace cocos2d;
#include<string>
#include<iostream>
using namespace  std;

class Role;

extern Role* Nan1;
extern Role* Nan2;
extern Role* Nv1;
extern Role* Nv2;
extern Role* Dahan;
extern Role* NiuYao;
extern Role * GuShe;
extern Role * JiaFei;


enum Job
{
	swordsman, assassin, accompanist, ranger               //�ĸ�ְҵ�����ͣ��̿ͣ���ʦ������,��Ӧ�ĸ����ǣ�ӵ�в�ͬ��װ����
														   //�ɳ�ֵ
};


class Role
{
	friend class Enemy;
	friend class Role;
	friend class BattleScene;
public:
	Role();
	//���캯��
	Role(int level, int xp, string name, int health, int healthm, int magic, int magicm, int attack, int defence,
		int healthup, int magicup, int attackup, int defenceup, Job MyJob, string filename, Activity act, int skill_num , Weapon myweapon , Armors myarmors, string headfile);
	~Role();
	void Role::operator=(const Role role);
	//���ظ�������ĺ���
	int retLevel();
	int retExp();
	string retName();
	int retHealth();
	int retHealthmax();
	int retMagic();
	int retMagicmax();
	int retAttack();
	int retDefence();
	int retHealthup();
	int retMagicup();
	int retDefenceup();
	int retAttackup();
	int retSkillNum();
	Weapon retWeapon();
	Armors retArmors();
	Activity  retActivity();
	enum Job retJob();
	string  retFilename();
	//�ȼ���������
	void Level_Up();
	//��ȡ����ֵ����
	/*�ȼ��뵱ǰ�ȼ��������辭��
	    1   10
	    2   50
		3   150
		4   300
		5   500
		6   750
		7   1100
		8   1800
		9   2400
		10  999999
		*/
	void getExp(int addXp);
	//��Ѫ�����������������Եĸı�,�ı�ֵΪ��Ϊ����
	bool changeWeapon(Weapon myweapon);         //��������
	bool changeArmors(Armors myarmors);         //��������
	void changeAttack(int change);              //���Ĺ�����
	void changeDefence(int change);             //���ķ�����
	void changeHealth(int change);              //��������ֵ
	void changeMagic(int change);               //��������
	//��һ��role������Ϣ���Ƶ�����
	void copyf(Role rolec); 
	static Role* createNewRole(Job ItsJob , string ItsName,string filename , Activity act, string headfile);       //����һ���½�ɫ���ɾ�����ְҵ������
	void addSkill(Skill askill);        //��Ӽ��ܵ���������
	void popSkill();
	Skill  retSkill(int num);           //���ص�num������
	void useProp(Prop* prop);           //����ʹ�õ���

	//����Ϣ��������Ϣ��
	void addAllTo(Sprite* scene);
	void removeAll(Sprite* scene);

protected:
	int Level;               //��Ϊ��Ҳ���ǵȼ�
	int Exp;                 //����ֵ
	string	Name;            //����
	int Health;              //��Ѫֵ
	int HealthMax;           //��Ѫ����
	int Magic;               //����
	int MagicMax;            //��������
	int Attack;              //����
	int Defence;             //����
	int HealthUp;            //�����ɳ�ֵ
	int MagicUp;             //�����ɳ�ֵ
	int AttackUp;            //�����ɳ�ֵ
	int DefenceUp;           //�����ɳ�ֵ
	string filename;         //ͷ���ļ���
	Job MyJob;               //ְҵ
	Activity  myActivity;        //���ֶ���
	void setValue(int healthm ,int magicm,int attack,int defence,
		int healthup , int magicup , int attackup , int defenceup);         //����һ����ɫ���������������ޣ������Լ�����ɳ�ֵ
	vector <Skill>  vec;                                                    //��������
	int    skillnum ;                                                    //��������
	Weapon   My_Weapon;                                                   //װ������
	Armors   My_Armors;                                                   //װ������

	//������Ϣ���label��sprite
	Label* hpLabel;
	Label* mpLabel;
	Label* attackLabel;
	Label* defenceLabel;
	Label* expLabel;
	Label* levelLabel;
	Sprite* weapromSprite;
	Sprite* armorsSprite;
	Sprite* headSprite;
	string headFile;
};