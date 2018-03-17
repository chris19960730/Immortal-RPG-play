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
	swordsman, assassin, accompanist, ranger               //四个职业，剑客，刺客，琴师，游侠,对应四个主角，拥有不同的装备与
														   //成长值
};


class Role
{
	friend class Enemy;
	friend class Role;
	friend class BattleScene;
public:
	Role();
	//构造函数
	Role(int level, int xp, string name, int health, int healthm, int magic, int magicm, int attack, int defence,
		int healthup, int magicup, int attackup, int defenceup, Job MyJob, string filename, Activity act, int skill_num , Weapon myweapon , Armors myarmors, string headfile);
	~Role();
	void Role::operator=(const Role role);
	//返回各项参数的函数
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
	//等级提升函数
	void Level_Up();
	//获取经验值函数
	/*等级与当前等级升级所需经验
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
	//气血，内力，攻击，韧性的改变,改变值为正为增加
	bool changeWeapon(Weapon myweapon);         //更换武器
	bool changeArmors(Armors myarmors);         //更换防具
	void changeAttack(int change);              //更改攻击力
	void changeDefence(int change);             //更改防御力
	void changeHealth(int change);              //更改生命值
	void changeMagic(int change);               //更改内力
	//将一个role所有信息复制到此中
	void copyf(Role rolec); 
	static Role* createNewRole(Job ItsJob , string ItsName,string filename , Activity act, string headfile);       //创建一个新角色，可决定其职业与姓名
	void addSkill(Skill askill);        //添加技能到技能容器
	void popSkill();
	Skill  retSkill(int num);           //返回第num个技能
	void useProp(Prop* prop);           //人物使用道具

	//绑定信息到人物信息框
	void addAllTo(Sprite* scene);
	void removeAll(Sprite* scene);

protected:
	int Level;               //修为，也就是等级
	int Exp;                 //经验值
	string	Name;            //姓名
	int Health;              //气血值
	int HealthMax;           //气血上限
	int Magic;               //内力
	int MagicMax;            //内力上限
	int Attack;              //攻击
	int Defence;             //韧性
	int HealthUp;            //生命成长值
	int MagicUp;             //内力成长值
	int AttackUp;            //攻击成长值
	int DefenceUp;           //防御成长值
	string filename;         //头像文件名
	Job MyJob;               //职业
	Activity  myActivity;        //各种动作
	void setValue(int healthm ,int magicm,int attack,int defence,
		int healthup , int magicup , int attackup , int defenceup);         //设置一个角色的生命与内力上限，攻防以及各项成长值
	vector <Skill>  vec;                                                    //技能容器
	int    skillnum ;                                                    //技能数量
	Weapon   My_Weapon;                                                   //装备武器
	Armors   My_Armors;                                                   //装备防具

	//人物信息框的label和sprite
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