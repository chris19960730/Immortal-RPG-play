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

//���ܵ��ͷŶ���
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
	int retHealthc();       //���������ı���
	int retMagicc();        //���������ı���
	int retAttackc();       //���ع������ı���
	int retDefencec();      //���ط������ı���
	float retTime();        //���ؼ���ʱ��
	string    retFilename();   //���ض����ļ���
	SkillObject  retObject();  //���ؼ����ͷ�Ŀ��
	string  retIntroduction(); //���ؼ��ܽ����ļ���
	void skill( Node  *   lay);    //�ͷż��ܣ�����Ϊ����ͼ��
	void enemySkill1(Node  *   lay);    //�����ͷż��ܣ�λ�����ҷ����ܲ�ͬ
	void enemySkill2(Node  *   lay);    //�����ͷż��ܣ�λ�����ҷ����ܲ�ͬ
	void enemySkill3(Node  *   lay);    //�����ͷż��ܣ�λ�����ҷ����ܲ�ͬ
	void enemySkill4(Node  *   lay);    //�����ͷż��ܣ�λ�����ҷ����ܲ�ͬ
private:
	int  changeHealth;      //�����ı���
	int  changeMagic;       //�����ı���
	int  changeAttack;      //�����ı���
	int  changeDefence;     //���Ըı���
	string  fileName;        //�����ļ���
	SkillObject  object;     //���ܵ��ͷ�Ŀ�꣬���˻��Ǽ���
	int  number;             //����ͼƬ����
	string introductionName;    //���ܽ��ܵ�ͼƬ�ļ���

};

