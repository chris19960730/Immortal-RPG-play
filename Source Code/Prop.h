#pragma once
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
using namespace cocos2d::ui;
using namespace cocos2d;
#include<string>
#include<iostream>
using namespace  std;

class Prop;
class PropBag;

extern PropBag Propbag;
extern Prop XiaoLan;
extern Prop DaLan;
extern Prop XiaoXue;
extern Prop DaXue;

//������
class Prop
{
	friend class PropBag;
public:
	Prop();
	Prop(string name, int health_up, int magic_up,
		int prop_num, int prop_price, string filename,string infile, string _effectfile);

	string retName();                         //���ص�������
	int retHealthUp();                        //������Ѫ����ֵ
	int retMagicUp();                         //������������ֵ
	int retPropNum();                         //���ص�������
	Sprite * retSurrender();
	void changeNum(int num);                  //�ı��������
	int retPrice();
	Label* getLabel();                        
	void bindLabel();                         //�󶨵�������Label
	string retFilename();                     //�����ļ���
	void bindInformation();                   //����Ϣ��
	void bindEffectAction(Layer* scene);      //��ʹ�õ���Ч��

	Sprite* Information;
	Sprite* effect;
private:
	string Name;                              //��������
	int Health_up;                            //��Ѫ����ֵ                             
	int Magic_up;                             //��������ֵ
	string Filename;                          //����ͼƬ����
	int Prop_num;                             //��������
	int Prop_price;                           //���߼۸�
	Label* propLabel;
	string informationFile;
	string effectfile;
};

class PropBag
{
public:
	PropBag();
	PropBag(int money);
	void bindAllLabel();
	void useProp(Prop * prop);                         //ʹ�õ��ߺ���������Ϊ������
	void useProp(int i);                               //ʹ�õ�i������
	Prop * retProp(int i);                             //�õ���i�����ߵ���Ϣ
	void pushProp(Prop* prop,int number);              //��ӵ��ߺ���
	void changeMoney(int num);                         //�ı����н�ҵĺ���
	int retMoney();                                    //���ص�ǰ�����
	bool changeProp(string propName, int num);         //�ı���ߵ�����
	int searchProp(Prop* prop);                        //ĳ���ߵ�λ��

	vector<Prop*> P;                     //�洢���ߵ�����
	bool _refresh;                       //�����Ƿ���Ҫˢ��
	
	
private:
	int Money;                                         //ӵ�н������
};
