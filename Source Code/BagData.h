#pragma once
#include"cocos2d.h"
#include<iostream>
#include"Prop.h"
#include"Equipment.h"
#include"Role.h"
#include"RoleData.h"
#include<vector>

using namespace std;
USING_NS_CC;

extern int whichBag; //��һ����������0
extern int _bagNum;  //��һ����������0
extern int _itemNum; //��һ��������0

//layer 390*470 x,y
//bagbtn 130*30 x-130,y+220
//itembtn 100*100 x-120,y+125
//close 41*70 x+215.5,y+200
//money 360*20 x,y-205
class BagData
{
public:
	BagData();
	void init(Layer* scene);   //������ʼ��
	void propBagInit();        //���߰���ʼ��
	void equipmentInit();      //װ������ʼ��
	void propBagRefresh();     //���߰�ˢ��

	void showItemBtn(int num, bool bset);                        //��ʾ����(0)������(1)������(2)��ͼ�갴ť
	void showLayer(int num);                                     //��ʾ����(0)������(1)������(2)��
	void showBagLayer(bool bset);                                //��ʾ����
	void showLabel(int num, bool bset);                          //��ʾ����Label
	void showUseBtn(bool bset);                                  //��ʾʹ�ð�ť
	void showPropInformation(int num, bool bset);                //��ʾ������Ϣ��
	void showEquipmentInformation(int num, bool bset, int which);//��ʾװ����Ϣ��������(1)������(0)
	void showShop(bool bset);                                    //��ʾ�̵����

	void addLayerTo(Layer* scene, int tag);        //�����Layer��scene
	void addBtnTo(Layer* scene, int tag);          //��ӱ�����ť��scene
	void addPropLabelTo(Layer* scene, int tag);    //��ӵ�������Label��scene
	void addMoneyLabelTo(Layer* scene, int tag);   //��ӽ��Label��scene
	void addAllItemBtn(Layer* scene);             //�����е�itemBtn��scene

	void bindBtn();                                //�󶨻�����ť��menu
	void bindSprite(string file, string moneyfile);//����layer�ͽ�Ҳ�
	void bindBagBtn(string* begin, string* end);   //�󶨱�����ť
	void bindUseBtn(string begin, string end);     //��ʹ�ð�ť
	
	void bindMainScene(Layer* scene);              //��������
	void setItem(int bagNum, int itemNum);         //���õ�ǰʹ�õ�item
	void setPosition(float x, float y);            //���ñ������λ��
	void setAllBtnEnable(bool bset);               //�������а�ť����/������
	void setWhichBag(int num);

	bool useBtnIsVisible();                        //ʹ�ð�ťusebtn�Ƿ�ɼ�

	bool getMoney(int num);                        //��ý�ң�������֮��
	void getWeapon(Equipment* weapon);             //�������
	void getArmors(Equipment* armors);             //��÷���
	void getProp(Prop* prop, int num);             //��õ���

	Layer* retMainScene();
	int retItemNum();

private:
	//�󶨵ĳ���
	Layer* mainscene;

	//����������
	Sprite* layer;

	//������ť��ʹ�ð�ť���������л���ť
	Menu* bagMenu;
	MenuItemImage* bagBtn[3];
	MenuItemImage* useBtn;

	//��Ʒ��ť
	Menu* itemMenu;
	vector<MenuItemImage*> itemBtn[3];
	vector<Label*> label[3];

	//��Ҳ�
	Label* moneyLabel;
	Sprite* money;

	//��¼��ǰʹ�õĵ���
	

	//ʹ�õ���ѡ���������
	Sprite* useChoose;
	Menu* chooseMenu;    //ʹ�õ���ʱѡ�������������ﰴť
	MenuItemImage* choose[4];

	//�̵����
	Sprite* shopLayer;

	Menu* shopMenu;      //���������̵갴ť
	MenuItemImage* shopBtn;

	Menu* shopMenuMax;   //�̵���湺��ť�����ذ�ť
	MenuItemImage* shopPropBtn[4];
	MenuItemImage* shopCloseBtn;

public:
	MenuItemImage* closeBtn;//�رհ�ť
	           //��¼���õı���
	
};