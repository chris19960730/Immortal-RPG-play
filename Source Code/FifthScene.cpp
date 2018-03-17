#include"Dialog.h"
#include"FifthScene.h"
#include"DengZhouHouShanScene.h"
#include"Enemy.h"
#include"MainMap.h"
#include"Sequence.h"
#include"SimpleAudioEngine.h"
#include"Count.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
//#include"Prop.h"

bool Button123Fif = false;

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* FifthScene::createScene()
{

	auto scene = Scene::create();

	auto layer = FifthScene::create();

	scene->addChild(layer);

	// return the scene
	return scene;
}

void FifthScene::bang(float dt)
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
bool FifthScene::init()
{

	Size visibleSize = Director::getInstance()->getVisibleSize();

	if (!Layer::init())
	{
		return false;
	}

	//获取基础按钮
	roleBtn = MenuItemImage::create("role.png", "roleend.png",
		CC_CALLBACK_1(FifthScene::roleCallBack, this));
	bagBtn = MenuItemImage::create("bag.png", "bagend.png",
		CC_CALLBACK_1(FifthScene::bagCallBack, this));
	skillBtn = MenuItemImage::create("skill.png", "skillend.png",
		CC_CALLBACK_1(FifthScene::skillCallBack, this));
	closeBtn = MenuItemImage::create("exit.png", "exitend.png",
		CC_CALLBACK_1(FifthScene::closeCallBack, this));
	saveBtn = MenuItemImage::create("save.png", "saveend.png",
		CC_CALLBACK_1(FifthScene::saveCallBack, this));
	setBtn = MenuItemImage::create("set.png", "setend.png",
		CC_CALLBACK_1(FifthScene::setCallBack, this));
	mapBtn = MenuItemImage::create("map.png", "mapend.png",
		CC_CALLBACK_1(FifthScene::mapCallBack, this));
	//获取选择按钮
	seBtn = MenuItemImage::create("what.png", "what.png",
		CC_CALLBACK_1(FifthScene::seCallBack, this));

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
		CC_CALLBACK_1(FifthScene::roleCloseCallBack, this));
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
		CC_CALLBACK_1(FifthScene::skillCloseCallBack, this));
	roleSkill->init(this);

	//背包初始化
	bagData = new BagData;
	bagData->closeBtn = MenuItemImage::create("return.png", "returnend.png",
		CC_CALLBACK_1(FifthScene::bagCloseCallBack, this));
	bagData->init(this);
	//获取背景，设置背景位置
	backGround = Sprite::create("dengzhou.jpg");
	backGround->setPosition(480, 320);
	addChild(backGround, 0);
	// NPC
	NpcBtn1 = MenuItemImage::create("huangfusong1.png", "huangfuzhaoend.png", this, menu_selector(FifthScene::Npc1CallBack));
	NpcBtn1->setPosition(130, 107);
	NpcBtn2 = MenuItemImage::create("shenminvzi1.png", "shenminvziend.png", this, menu_selector(FifthScene::Npc2CallBack));
	NpcBtn2->setPosition(875, 90);
	NpcBtn2->setVisible(false);
	NpcBtn3 = MenuItemImage::create("shenminvzi1.png", "shenminvziend.png", this, menu_selector(FifthScene::Npc3CallBack));
	NpcBtn3->setPosition(875, 90);
	NpcBtn3->setVisible(false);
	button123 = Button::create("houshanshandong.jpg", "houshanshandong.jpg", "houshanshandong.jpg");
	button123->addTouchEventListener(this, toucheventselector(FifthScene::callFunc));
	button123->setPosition(Vec2(300, 200));
	button123->setVisible(Button123Fif);
	this->addChild(button123);
	auto menu1 = Menu::create(NpcBtn1,NpcBtn2,NpcBtn3, NULL);
	menu1->setPosition(Point(0, 0));
	this->addChild(menu1);

	

	//剧情线~~~~~~~~~~~~~~~~~

	Count * pt = Count::Getinstance();
	if (pt->retNumber() !=6)
	{
		NpcBtn1->setVisible(false);
		mapBtn->setVisible(true);
	}
	if (pt->retNumber() ==11)
	{
		NpcBtn3->setVisible(true);
	}

	return true;
}


void FifthScene::setAllEnabled(bool T)
{
	menu->setEnabled(T);
	menuSe->setEnabled(T);
}


void FifthScene::roleCallBack(Ref* sender)
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

void FifthScene::bagCallBack(Ref* sender)
{
	bagData->showBagLayer(true);
	setAllEnabled(false);
	bagData->setWhichBag(0);
}

void FifthScene::skillCallBack(Ref* sender)
{
	if (!roleSkill->layerIsVisible())
	{
		roleSkill->showSkillLayer(true);
		setAllEnabled(false);
	}
	log("skill");
}

void FifthScene::setCallBack(Ref* sender)
{
	log("set");
}

void FifthScene::closeCallBack(Ref* sender)
{
	log("close");
	Director::getInstance()->end();
}

void FifthScene::saveCallBack(Ref* sender)
{
	log("save");
}

void FifthScene::mapCallBack(Ref* sender)
{
	Director::getInstance()->pushScene(MainMap::createScene());
}

void FifthScene::seCallBack(Ref* sender)
{
	scheduleOnce(schedule_selector(FifthScene::bang), 0.1f);
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

void FifthScene::roleCloseCallBack(Ref* sender)
{
	menuRole->setVisible(false);
	roleData->setLayerVisible(false);
	setAllEnabled(true);
}

void FifthScene::skillCloseCallBack(Ref* sender)
{
	roleSkill->showSkillLayer(false);
	setAllEnabled(true);
}

void FifthScene::bagCloseCallBack(Ref* sender)
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
void FifthScene::Npc1CallBack(Ref*pSender)


{
	NpcBtn1->setVisible(false);
	Dia_DengZhou1.dialogBegin(this);
	NpcBtn2->setVisible(true);
	Count * pt = Count::Getinstance();
	pt->numberPlus();   //7
	mapBtn->setVisible(true);
	


}


void FifthScene::Npc2CallBack(Ref*pSender)
{
	Dia_DengZhou2.dialogBegin(this);
	NpcBtn2->setVisible(false);
	button123->setVisible(true);
	Button123Fif = true;
}

void FifthScene::Npc3CallBack(Ref*pSender)
{
	NpcBtn3->setVisible(false);
	auto pt = Count::Getinstance();
	pt->numberPlus(); //12
	Dia_DengZhouLast.dialogBegin(this);
}
void FifthScene::callFunc(Ref*pSender, TouchEventType type)
{ 
	
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
	{
		Director::getInstance()->pushScene(TransitionProgressOutIn::create(3.0f, DengZhouHouShanScene::createScene()));
		break;
	}
	}
}

void FifthScene::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	Count * pt = Count::Getinstance();
	if (pt->retNumber() < 11)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("mp33.mp3");
	}
	else
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("mp34.mp3");
	}
	
	
}

