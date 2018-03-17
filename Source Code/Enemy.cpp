#include"Enemy.h"
//1

OurEnemy::OurEnemy(int level, int xp, string name, int health, int healthm, int magic, int magicm, int attack, int defence,
int healthup, int magicup, int attackup, int defenceup, Job MyJob, string filename, Activity act, int skill_num,string headfile)
:Role(level, xp, name, health, healthm, magic, magicm, attack, defence,
healthup, magicup, attackup, defenceup, MyJob, filename, act, skill_num, TieJian, JinPao,headfile)
{

}
OurEnemy::~OurEnemy()
{
if (instance != NULL)
{
delete instance;
}
}
OurEnemy * OurEnemy::instance = NULL;
OurEnemy *  OurEnemy::Getinstance()
{
if (instance == NULL)
{
instance = new OurEnemy(1, 0, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, swordsman, "", ZhugeYibin_act, 0,"");
}
return  instance;
}
void OurEnemy::createEnemy(Role &role,int num)
{
instance->Level = role.retLevel();
instance->Attack = role.retAttack();
instance->AttackUp = role.retAttackup();
instance->Defence = role.retDefence();
instance->DefenceUp = role.retDefenceup();
instance->Health = role.retHealth()*num;
instance->HealthUp = role.retHealthup();
instance->HealthMax = role.retHealthmax()*num;
instance->filename = role.retFilename();
instance->Magic = role.retMagic();
instance->MagicMax = role.retMagicmax();
instance->MagicUp = role.retMagicup();
instance->MyJob = role.retJob();
instance->Exp = role.retExp();
instance->Name = role.retName();
instance->myActivity = role.retActivity();
}