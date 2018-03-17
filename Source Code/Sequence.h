#pragma once
#include"Role.h"

class RoleSequence               //单例模式设计
{
private:
	RoleSequence();
    ~RoleSequence();
	vector<Role *>  seq;             //存放队员的容器
	int num;                       //队友数量
	static RoleSequence * instance;//实例对象
public:
	static RoleSequence *  getInstance();
	void join(Role * man);         //队列中添加队友
	int  retNumber();             //获得队友数量
	Role * retRole(int num);               //获取队友
	void  getExpAll(int xp);       //全队获取经验
	void  popRole();
};
