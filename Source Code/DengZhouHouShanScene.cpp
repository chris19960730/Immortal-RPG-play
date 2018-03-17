#include"Dialog.h"
#include"DengZhouHouShanScene.h"
#include"Enemy.h"
#include"MainMap.h"
#include"Sequence.h"
#include"SimpleAudioEngine.h"
#include"Count.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
//#include"Prop.h"
#define SheYaoGetPropDXue 3
#define SheYaoGetPropDLan 2
#define SheYaoGetMoney 500

#define JiaFeiGetPropDXue 5
#define JiaFeiGetPropDLan 5
#define JiaFeiGetMoney 1000

bool NpcBtn1DengZhou = true;
bool NpcBtn2DengZhou = false;

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* DengZhouHouShanScene::createScene()
{

	auto scene = Scene::create();

	auto layer = DengZhouHouShanScene::create();

	scene->addChild(layer);

	// return the scene
	return scene;
}

void DengZhouHouShanScene::bang(float dt)
{
	auto* m_frameCache = SpriteFrameCache::getInstance();
	m_frameCache->addSpriteFramesWithFile("xie.plist", "xie.png");
	Vector<SpriteFrame*> frameArray;
	for (int i = 1; i < 5; i++)
	{
		auto* frame =
			m_frameCache->getSpriteFrameByName(String::createWithFormat
				("xie%d.png", i)->getCString());
		frameArray.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frameArray);
	animation->setLoops(1);
	animation->setDelayPerUnit(0.1f);
	auto* action = Animate::create(animation);
	xie->runAction(action);
}

// on "init" you need to initialize your instance
bool DengZhouHouShanScene::init()
{

	

	Size visibleSize = Director::getInstance()->getVisibleSize();

	if (!Layer::init())
	{
		return false;
	}

	//获取基础按钮
	roleBtn = MenuItemImage::create("role.png", "roleend.png",
		CC_CALLBACK_1(DengZhouHouShanScene::roleCallBack, this));
	bagBtn = MenuItemImage::create("bag.png", "bagend.png",
		CC_CALLBACK_1(DengZhouHouShanScene::bagCallBack, this));
	skillBtn = MenuItemImage::create("skill.png", "skillend.png",
		CC_CALLBACK_1(DengZhouHouShanScene::skillCallBack, this));
	closeBtn = MenuItemImage::create("exit.png", "exitend.png",
		CC_CALLBACK_1(DengZhouHouShanScene::closeCallBack, this));
	saveBtn = MenuItemImage::create("save.png", "saveend.png",
		CC_CALLBACK_1(DengZhouHouShanScene::saveCallBack, this));
	setBtn = MenuItemImage::create("set.png", "setend.png",
		CC_CALLBACK_1(DengZhouHouShanScene::setCallBack, this));
	mapBtn = MenuItemImage::create("map.png", "mapend.png",
		CC_CALLBACK_1(DengZhouHouShanScene::mapCallBack, this));
	//获取选择按钮
	seBtn = MenuItemImage::create("what.png", "what.png",
		CC_CALLBACK_1(DengZhouHouShanScene::seCallBack, this));

	xie = Sprite::create("xie1.png");
	addChild(xie, 2);
	xie->setPosition(760 + 130, 50);

	//设置基础按钮、选择按钮的位置
	seBtn->setPosition(760 + 130, 50);
	roleBtn->setPosition(400 + 120, 50);
	bagBtn->setPosition(400 + 240, 50);
	skillBtn->setPosition(400 + 240, 50);
	skillBtn->setVisible(false);
	closeBtn->setPosition(400 + 360, 50);
	mapBtn->setPosition(90, 550);
	saveBtn->setPosition(960 - 50 - 15, 140);
	setBtn->setPosition(960 - 50 - 15, 140 + 90);

	//获取背景，设置背景位置
	backGround = Sprite::create("bg.jpg");
	backGround->setPosition(480, 320);
	addChild(backGround, 0);

	//close按钮
	roleData = new RoleData;
	roleData->closeBtn = MenuItemImage::create("return.png", "returnend.png",
		CC_CALLBACK_1(DengZhouHouShanScene::roleCloseCallBack, this));
	roleData->setCloseBtnPosition(700.5, 565);

	//人物信息图层初始化
	/*string layerFile[4] = { "data1.jpg","data2.jpg","data3.jpg","data4.jpg" };
	string headFile[4] = { "head1.png","head2.png" ,"head3.png" ,"head4.png" };
	roleData->bindSprite(layerFile,headFile);*/
	roleData->bindAllChild();
	roleData->addLayerTo(this, 2);
	//Nan1->addAllTo(roleData->layer[0]);
	roleData->setLayerPosition(480, 320);

	//基础按钮绑定
	menu = Menu::create(roleBtn, bagBtn, skillBtn, closeBtn, saveBtn, setBtn, NULL);
	//人物信息关闭按钮绑定
	menuRole = Menu::create(roleData->closeBtn, NULL);
	//选择按钮、地图绑定，总是可见
	menuSe = Menu::create(seBtn, mapBtn, NULL);

	//按钮初始化
	menu->setVisible(false);
	menuRole->setVisible(false);

	menu->setPosition(0, 0);
	menuSe->setPosition(0, 0);
	menuRole->setPosition(0, 0);

	//添加到父容器
	addChild(menu, 1);
	addChild(menuSe, 1);
	addChild(menuRole, 2);

	//人物选择按钮初始化
	string num[4] = { "1","2","3","4" };
	for (int i = 0; i < 4; i++)
	{
		roleData->bindRoleBtn("rolebtn" + num[i] + ".png", "rolebtn" + num[i] + "end.png", i);
	}
	roleData->addBtnTo(this, 4);

	//技能框初始化
	roleSkill = new RoleSkill;
	roleSkill->closeBtn = MenuItemImage::create("return.png", "returnend.png",
		CC_CALLBACK_1(DengZhouHouShanScene::skillCloseCallBack, this));
	roleSkill->init(this);

	//背包初始化
	bagData = new BagData;
	bagData->closeBtn = MenuItemImage::create("return.png", "returnend.png",
		CC_CALLBACK_1(DengZhouHouShanScene::bagCloseCallBack, this));
	bagData->init(this);
	//获取背景，设置背景位置
	backGround = Sprite::create("dengzhouhoushan.jpg");
	backGround->setPosition(480, 320);
	addChild(backGround, 0);
	// NPC
	NpcBtn1 = MenuItemImage::create("xiangqianzou.png", "xiangqianzou.png", this, menu_selector(DengZhouHouShanScene::Npc1CallBack));
	NpcBtn1->setPosition(200, 200);
	NpcBtn2 = MenuItemImage::create("xiangqianzou.png", "xiangqianzou.png", this, menu_selector(DengZhouHouShanScene::Npc2CallBack));
	NpcBtn2->setPosition(350, 200);
	NpcBtn1->setVisible(NpcBtn1DengZhou);
	NpcBtn2->setVisible(NpcBtn2DengZhou);
	auto menu1 = Menu::create(NpcBtn1, NpcBtn2, NULL);
	menu1->setPosition(Point(0, 0));
	this->addChild(menu1);

	
	//剧情线~~~~~~~~~~~~~~~~~

	Count * pt = Count::Getinstance();
	if (pt->retNumber() != 7)
	{
		NpcBtn1->setVisible(false);
		mapBtn->setVisible(true);
	}

	return true;
}


void DengZhouHouShanScene::setAllEnabled(bool T)
{
	menu->setEnabled(T);
	menuSe->setEnabled(T);
}


void DengZhouHouShanScene::roleCallBack(Ref* sender)
{
	if (!roleData->layerIsVisible())
	{
		roleData->init(this);
		roleData->setLayerVisible(true);
		menuRole->setVisible(true);
		setAllEnabled(false);
	}
	else
	{
		roleData->setLayerVisible(false);
		menuRole->setVisible(false);
	}

}

void DengZhouHouShanScene::bagCallBack(Ref* sender)
{
	bagData->showBagLayer(true);
	setAllEnabled(false);
	bagData->setWhichBag(0);
}

void DengZhouHouShanScene::skillCallBack(Ref* sender)
{
	if (!roleSkill->layerIsVisible())
	{
		roleSkill->showSkillLayer(true);
		setAllEnabled(false);
	}
	log("skill");
}

void DengZhouHouShanScene::setCallBack(Ref* sender)
{
	log("set");
}

void DengZhouHouShanScene::closeCallBack(Ref* sender)
{
	log("close");
	Director::getInstance()->end();
}

void DengZhouHouShanScene::saveCallBack(Ref* sender)
{
	log("save");
}

void DengZhouHouShanScene::mapCallBack(Ref* sender)
{
	Director::getInstance()->pushScene(MainMap::createScene());
}

void DengZhouHouShanScene::seCallBack(Ref* sender)
{
	scheduleOnce(schedule_selector(DengZhouHouShanScene::bang), 0.1f);
	if (!menu->isVisible())
	{
		menu->setVisible(true);
	}
	else
	{
		menu->setVisible(false);
	}


	log("se");
}

void DengZhouHouShanScene::roleCloseCallBack(Ref* sender)
{
	menuRole->setVisible(false);
	roleData->setLayerVisible(false);
	setAllEnabled(true);
}

void DengZhouHouShanScene::skillCloseCallBack(Ref* sender)
{
	roleSkill->showSkillLayer(false);
	setAllEnabled(true);
}

void DengZhouHouShanScene::bagCloseCallBack(Ref* sender)
{
	bagData->showBagLayer(false);
	setAllEnabled(true);/*
	bagData->moneyLabel->setVisible(false);
	bagData->money->setVisible(false);
	bagData->useBtn->setVisible(false);
	bagData->showPropInformation(0, false);
	bagData->showEquipmentInformation(0, false, 0);
	bagData->showEquipmentInformation(0, false, 1);
	bagData->showShop(false);*/

}
void DengZhouHouShanScene::Npc1CallBack(Ref*pSender)


{
	NpcBtn1->setVisible(false);
	NpcBtn1DengZhou = false;
	auto enemy = OurEnemy::Getinstance();
	enemy->createEnemy(*GuShe, 10);
	OurEnemy::Getinstance()->popSkill();
	enemy->addSkill(QianDuWanShi);
	Dia_DengZhouHouShan1.dialogBegin(this);
	NpcBtn2->setVisible(true);
	NpcBtn2DengZhou = true;
	Count * pt = Count::Getinstance();
	pt->numberPlus();   //8
	mapBtn->setVisible(true);
	// 对话，战斗
}


void DengZhouHouShanScene::Npc2CallBack(Ref*pSender)
{
	NpcBtn2->setVisible(false);
	NpcBtn2DengZhou = false;
	Button123Fif = false;
	auto enemy = OurEnemy::Getinstance();
	enemy->createEnemy(*JiaFei, 14);
	Count * pt = Count::Getinstance();
	pt->numberPlus();   //10
	OurEnemy::Getinstance()->popSkill();
	enemy->addSkill(CanYunQiangFa);
	Dia_DengZhouHouShan2.dialogBegin(this);
}

void DengZhouHouShanScene::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("dengzhouhoushan.mp3");
	Count * pt = Count::Getinstance();
	if (pt->retNumber() == 8)
	{
		bagData->getArmors(&HuangJinJia);
		bagData->getArmors(&MingGuangKai);
		bagData->getArmors(&TianShiDaoPao);
		Nan1->changeArmors(TianShiDaoPao);
		Nan2->changeArmors(MingGuangKai);
		bagData->getProp(&DaXue, SheYaoGetPropDXue);
		bagData->getProp(&DaLan, SheYaoGetPropDLan);
		bagData->getMoney(SheYaoGetMoney);
		//RoleSequence::Getinstance()->Get_Xp_All(300);
		Nan1->getExp(600);
		Nv1->getExp(600);
		Nan2->getExp(600);
		Nan2show = true;
		pt->numberPlus();   //9

	}
	if (pt->retNumber() == 10)
	{
		//RoleSequence::Getinstance()->Get_Xp_All(300);
		pt->numberPlus();   //11
		//bagData->getArmors(&TianShiDaoPao);
		bagData->getProp(&DaXue, JiaFeiGetPropDXue);
		bagData->getProp(&DaLan, JiaFeiGetPropDLan);
		bagData->getMoney(JiaFeiGetMoney);
		Nan1->getExp(1000);
		Nv1->getExp(1000);
		Nan2->getExp(1000);
	}

}

