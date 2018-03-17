#include "WuChangScene.h"
#include"BattleScene.h"
#include"Dialog.h"
#include"Enemy.h"
#include"MainMap.h"
#include"Sequence.h"
#include"SimpleAudioEngine.h"
#include"Count.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
//#include"Prop.h"
#define WuChangGetPropXXue 5
#define WuChangGetPropXLan 5
#define WuChangGetMoney 200

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* WuChangScene::createScene()
{

	auto scene = Scene::create();

	auto layer =WuChangScene::create();

	scene->addChild(layer);

	// return the scene
	return scene;
}

void WuChangScene::bang(float dt)
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
bool WuChangScene::init()
{

	
	Size visibleSize = Director::getInstance()->getVisibleSize();

	if (!Layer::init())
	{
		return false;
	}

	//获取基础按钮
	roleBtn = MenuItemImage::create("role.png", "roleend.png",
		CC_CALLBACK_1(WuChangScene::roleCallBack, this));
	bagBtn = MenuItemImage::create("bag.png", "bagend.png",
		CC_CALLBACK_1(WuChangScene::bagCallBack, this));
	skillBtn = MenuItemImage::create("skill.png", "skillend.png",
		CC_CALLBACK_1(WuChangScene::skillCallBack, this));
	closeBtn = MenuItemImage::create("exit.png", "exitend.png",
		CC_CALLBACK_1(WuChangScene::closeCallBack, this));
	saveBtn = MenuItemImage::create("save.png", "saveend.png",
		CC_CALLBACK_1(WuChangScene::saveCallBack, this));
	setBtn = MenuItemImage::create("set.png", "setend.png",
		CC_CALLBACK_1(WuChangScene::setCallBack, this));
	mapBtn = MenuItemImage::create("map.png", "mapend.png",
		CC_CALLBACK_1(WuChangScene::mapCallBack, this));
	//获取选择按钮
	seBtn = MenuItemImage::create("what.png", "what.png",
		CC_CALLBACK_1(WuChangScene::seCallBack, this));

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
		CC_CALLBACK_1(WuChangScene::roleCloseCallBack, this));
	roleData->setCloseBtnPosition(700.5, 565);

	
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
		CC_CALLBACK_1(WuChangScene::skillCloseCallBack, this));
	roleSkill->init(this);

	//背包初始化
	bagData = new BagData;
	bagData->closeBtn = MenuItemImage::create("return.png", "returnend.png",
		CC_CALLBACK_1(WuChangScene::bagCloseCallBack, this));
	bagData->init(this);
	//获取背景，设置背景位置
	backGround = Sprite::create("WuChang.jpg");
	backGround->setPosition(480, 320);
	addChild(backGround, 0);
	// NPC
	NpcBtn = MenuItemImage::create("chaguan1.png", "chaguanend.png", this, menu_selector(WuChangScene::NpcCallBack));
	NpcBtn->setPosition(141, 376);
	auto menu1 = Menu::create(NpcBtn, NULL);
	menu1->setPosition(Point(0, 0));
	this->addChild(menu1);

	MenuItemImage* test = MenuItemImage::create("xie1.png", "xie2.png",
		CC_CALLBACK_1(WuChangScene::testCallBack, this));
	Menu* testmenu = Menu::create(test, NULL);
	testmenu->setPosition(0, 0);
	test->setPosition(800, 320);
	addChild(testmenu, 100);
	test->setVisible(false);

	//剧情线~~~~~~~~~~~~~~~~~

	Count * pt = Count::Getinstance();
	//颍州地图解锁,防止重复领任务
	if (pt->retNumber()!=1)
	{
		NpcBtn->setVisible(false);
		mapBtn->setVisible(true);
	}

	return true;
}


void WuChangScene::setAllEnabled(bool T)
{
	menu->setEnabled(T);
	menuSe->setEnabled(T);
}


void WuChangScene::roleCallBack(Ref* sender)
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

void WuChangScene::bagCallBack(Ref* sender)
{
	bagData->showBagLayer(true);
	setAllEnabled(false);
	bagData->setWhichBag(0);
}

void WuChangScene::skillCallBack(Ref* sender)
{
	if (!roleSkill->layerIsVisible())
	{
		roleSkill->showSkillLayer(true);
		setAllEnabled(false);
	}
	log("skill");
}

void WuChangScene::setCallBack(Ref* sender)
{
	log("set");
}

void WuChangScene::closeCallBack(Ref* sender)
{
	log("close");
	Director::getInstance()->end();
}

void WuChangScene::saveCallBack(Ref* sender)
{
	log("save");
}

void WuChangScene::mapCallBack(Ref* sender)
{
	Director::getInstance()->pushScene(MainMap::createScene());
}

void WuChangScene::seCallBack(Ref* sender)
{
	scheduleOnce(schedule_selector(WuChangScene::bang), 0.1f);
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

void WuChangScene::roleCloseCallBack(Ref* sender)
{
	menuRole->setVisible(false);
	roleData->setLayerVisible(false);
	setAllEnabled(true);
}

void WuChangScene::skillCloseCallBack(Ref* sender)
{
	roleSkill->showSkillLayer(false);
	setAllEnabled(true);
}

void WuChangScene::bagCloseCallBack(Ref* sender)
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
void WuChangScene::NpcCallBack(Ref*pSender)


{
	NpcBtn->setVisible(false);
	Count * pt = Count::Getinstance();
	pt->numberPlus();    //2
	mapBtn->setVisible(true);
	if (pt->retNumber() ==2)
	{
		auto seq = RoleSequence::getInstance();
		seq->join(Nv1);
		Nv1->addSkill(WuYingLianCi);
		auto enemy = OurEnemy::Getinstance();
		enemy->createEnemy(*Dahan,6);
		enemy->addSkill(DaoKan);
		Dia_WuChangChaGuan.dialogBegin(this);
	}

}
void WuChangScene::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("wuchangmusic.mp3");
	Count * pt = Count::Getinstance();
	if (pt->retNumber() == 2)
	{
		//DaXue.Change_num(5);//获得一些道具
		bagData->getProp(&XiaoXue, WuChangGetPropXXue);
		bagData->getProp(&XiaoLan, WuChangGetPropXLan);
		bagData->getWeapon(&EMeiCi);
		bagData->getWeapon(&XuanGuang);
		bagData->getArmors(&NiChangYuYi); 
		//bagData->getArmors(&HuangJinJia);
		//bagData->getArmors(&MingGuangKai);
		//bagData->getArmors(&TianShiDaoPao);
		//bagData->getArmors(&MingGuangKai);
		//bagData->getArmors(&TianShiDaoPao);
	    Nv1->changeWeapon(XuanGuang);
		bagData->getMoney(WuChangGetMoney);
		//RoleSequence::Getinstance()->Get_Xp_All(300);
		Nan1->getExp(200);
		Nv1->getExp(200);
		//////////////////////////////////
		Nv1show = true;
		//升到四级
		pt->numberPlus();// 3
	}
}



void WuChangScene::testCallBack(Ref* sender)
{
	bagData->getArmors(&TianShiDaoPao);
}
