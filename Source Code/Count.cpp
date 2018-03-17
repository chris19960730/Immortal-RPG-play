#include"Count.h"
Count* Count::instance = nullptr;
Count::Count()
{
	GlobalNumber = -1;
}
Count::~Count()
{

}
void Count::numberPlus()
{
	GlobalNumber++;
}

int Count::retNumber()
{
	return GlobalNumber;
}
Count * Count::Getinstance()
{
	if (instance == nullptr)
	{
		instance = new Count();
	}
	return (instance);
}

void Count::RestartNumber()
{
	GlobalNumber =0;
}