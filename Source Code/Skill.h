#pragma  once
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
using namespace cocos2d::ui;
using namespace cocos2d;
#include<string>
#include<iostream>
using namespace  std;
using namespace cocostudio::timeline;

class Skill;

extern Skill JianYan;
extern Skill ChangKong23;
extern Skill YuanLingGuiXin;
extern Skill HanBingZhenQi;
extern Skill WuYingLianCi;
extern Skill CanYunQiangFa;
extern Skill DaoKan;
extern Skill QianDuWanShi;

//技能的释放对象
enum SkillObject
{
	Enemy,Friend
};

class Skill
{
public:
	Skill();
	Skill(int num,int changeh , int changem , int changea ,
		int changed , string filen ,SkillObject object, string intro_name);
	~Skill();
	int retHealthc();       //返回生命改变量
	int retMagicc();        //返回内力改变量
	int retAttackc();       //返回攻击力改变量
	int retDefencec();      //返回防御力改变量
	float retTime();        //返回技能时间
	string    retFilename();   //返回动画文件名
	SkillObject  retObject();  //返回技能释放目标
	string  retIntroduction(); //返回技能介绍文件名
	void skill( Node  *   lay);    //释放技能，参数为背景图层
	void enemySkill1(Node  *   lay);    //敌人释放技能，位置与我方技能不同
	void enemySkill2(Node  *   lay);    //敌人释放技能，位置与我方技能不同
	void enemySkill3(Node  *   lay);    //敌人释放技能，位置与我方技能不同
	void enemySkill4(Node  *   lay);    //敌人释放技能，位置与我方技能不同
private:
	int  changeHealth;      //生命改变量
	int  changeMagic;       //内力改变量
	int  changeAttack;      //攻击改变量
	int  changeDefence;     //韧性改变量
	string  fileName;        //动画文件名
	SkillObject  object;     //技能的释放目标，敌人还是己方
	int  number;             //技能图片张数
	string introductionName;    //技能介绍的图片文件名

};

