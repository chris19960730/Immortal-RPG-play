#pragma once
class Count
{
public:
	void numberPlus();
	int retNumber();
	static Count * Getinstance();
	void RestartNumber();
private:int GlobalNumber;
		Count();
		~Count();
		static	Count * instance;    //ÊµÀı¶ÔÏó

};

