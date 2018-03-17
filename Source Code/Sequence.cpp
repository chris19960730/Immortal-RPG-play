#include"Sequence.h"

RoleSequence * RoleSequence::instance = NULL;

RoleSequence::RoleSequence(void)
{
	num = 0;
}
RoleSequence::~RoleSequence()
{
	if (instance != NULL)
	{
		delete instance;
	}
}
RoleSequence *  RoleSequence::getInstance()
{
	if (instance == NULL)
	{
		instance = new RoleSequence();
	}
	return  instance;
}
void RoleSequence::join(Role * man)
{
	seq.push_back(man);
	num++;
}

int RoleSequence::retNumber()
{
	return num;
}
Role * RoleSequence::retRole(int num)
{
	return seq[num];
}
void  RoleSequence::getExpAll(int xp)
{
	for (int i = 0; i <= seq.size() - 1; i++)
	{
		seq[i]->getExp(xp);
	}
}

void RoleSequence::popRole()
{
	seq.pop_back();
	num--;

}