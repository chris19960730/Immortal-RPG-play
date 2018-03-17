#pragma once
#include"Role.h"

class RoleSequence               //����ģʽ���
{
private:
	RoleSequence();
    ~RoleSequence();
	vector<Role *>  seq;             //��Ŷ�Ա������
	int num;                       //��������
	static RoleSequence * instance;//ʵ������
public:
	static RoleSequence *  getInstance();
	void join(Role * man);         //��������Ӷ���
	int  retNumber();             //��ö�������
	Role * retRole(int num);               //��ȡ����
	void  getExpAll(int xp);       //ȫ�ӻ�ȡ����
	void  popRole();
};
