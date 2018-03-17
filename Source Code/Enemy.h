#pragma once
#include"Role.h"
class OurEnemy :public Role
{
public:
	static OurEnemy *  Getinstance();
	void createEnemy(Role &role , int num);
private:
	OurEnemy(int level, int xp, string name, int health, int healthm, int magic, int magicm, int attack, int defence,
		int healthup, int magicup, int attackup, int defenceup, Job MyJob, string filename, Activity act, int skill_num,string headfile);
	~OurEnemy();
	static OurEnemy * instance;

};
