#pragma once
#include"cocos2d.h"
#include"Role.h"
USING_NS_CC;
using namespace std;

//�������״̬(�Ƿ����)
extern bool Nan1show;
extern bool Nan2show;
extern bool Nv1show;
extern bool Nv2show;

//layer 400*560
//head 100*150
//roleBtn 100*30
//closeBtn 41*70
//layer[i]->setPosition(x, y);
//head[i]->setPosition(x - 200 + 72.14, y - 280 + 427.78);
class RoleData
{
public:
	RoleData();
	void init(Layer* scene);
	void bindAllChild();                                    //�����е��ӽڵ�
	void bindSprite(string* file, string* headfile);        //�½�ͷ��layer
	void bindRoleBtn(string begin, string end, int rolenum);//�½�roleBtn
	void bindBtn();                                         //�����е�Btn
	void bindHead(string* file);                            //�½�ͷ��


	//��ӵ����ڵ�
	void addHeadTo(Layer* scene, int tag);   //ͷ��
	void addBtnTo(Layer* scene, int tag);    //��ť
	void addLayerTo(Layer* scene, int tag);  //����

	MenuItemImage* retCloseBtn();
	Sprite* retLayer(int num);

	//����λ�á��ߴ硢Tag��visible
	void setLayerPosition(int x, int y);      //���ò��λ��
	void setCloseBtnPosition(int x, int y);   //����close��ťλ��
	void setBtnScale(float x, float y);       //����roleBtn��scale
	void setLayerTag(int tag);                //���ò�Tag
	void setLayerVisible(bool bset);          //����layer��visible
	void setCloseBtnVisible(bool bset);       //����close��ťvisible
	
	bool layerIsVisible();     //���ز��Ƿ�ɼ�
	void showLayer(int num);   //��ʾ��

	//close��ť
	MenuItemImage* closeBtn;

private:
	Sprite* roledataLayer;//����
	Sprite* layer[4];     //�ĸ�����(û����)
	Sprite* head[4];      //ͷ��

	Menu* roleMenu;
	MenuItemImage* roleBtn[4];//���ﰴť

	int _layerTag;
	bool _layerIsVisible;
};