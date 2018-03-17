#include "MainScene.h"
//#include"BattleScene.h"
#include"Dialog.h"
#include"MainMap.h"
#include"Sequence.h"
#include"Count.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include"SimpleAudioEngine.h"
//#include"Prop.h"

/*USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene()
{

	auto scene = Scene::create();

	auto layer = MainScene::create();

	scene->addChild(layer);

	// return the scene
	return scene;
}

void MainScene::bang(float dt)
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
bool MainScene::init()
{

	Size visibleSize = Director::getInstance()->getVisibleSize();

	if (!Layer::init())
	{
		return false;
	}

	//获取基础按钮
	roleBtn = MenuItemImage::create("role.jpg", "end.jpg",
		CC_CALLBACK_1(MainScene::roleCallBack, this));
	bagBtn = MenuItemImage::create("bag.jpg", "end.jpg",
		CC_CALLBACK_1(MainScene::bagCallBack, this));
	skillBtn = MenuItemImage::create("skill.jpg", "end.jpg",
		CC_CALLBACK_1(MainScene::skillCallBack, this));
	closeBtn = MenuItemImage::create("exit.jpg", "end.jpg",
		CC_CALLBACK_1(MainScene::closeCallBack, this));
	saveBtn = MenuItemImage::create("save.jpg", "end.jpg",
		CC_CALLBACK_1(MainScene::saveCallBack, this));
	setBtn = MenuItemImage::create("set.jpg", "end.jpg",
		CC_CALLBACK_1(MainScene::setCallBack, this));
	mapBtn = MenuItemImage::create("map.jpg", "end.jpg",
		CC_CALLBACK_1(MainScene::mapCallBack, this));
	//获取选择按钮
	seBtn = MenuItemImage::create("what.png", "what.png",
		CC_CALLBACK_1(MainScene::seCallBack, this));

	xie = Sprite::create("xie1.png");
	addChild(xie, 2);
	xie->setPosition(760 + 130, 50);

	//设置基础按钮、选择按钮的位置
	seBtn->setPosition(760 + 130, 50);
	roleBtn->setPosition(400, 50);
	bagBtn->setPosition(400 + 120, 50);
	skillBtn->setPosition(400 + 240, 50);
	closeBtn->setPosition(400 + 360, 50);
	mapBtn->setPosition(60, 590);
	saveBtn->setPosition(960 - 50 - 15, 140);
	setBtn->setPosition(960 - 50 - 15, 140 + 90);

	

	//close按钮
	roleData = new RoleData;
	roleData->closeBtn = MenuItemImage::create("return.png", "returnend.png",
		CC_CALLBACK_1(MainScene::roleCloseCallBack, this));
	roleData->setCloseBtnPosition(700.5, 565);

	//人物信息图层初始化
	/*string layerFile[4] = { "data1.jpg","data2.jpg","data3.jpg","data4.jpg" };
	string headFile[4] = { "head1.png","head2.png" ,"head3.png" ,"head4.png" };
	roleData->bindSprite(layerFile,headFile);
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
	addChild(menuSe, 3);
	addChild(menuRole, 2);

	//人物选择按钮初始化
	string num[4] = { "1","2","3","4" };
	for (int i = 0; i < 4; i++)
	{
		roleData->roleBtnCreate("rolebtn" + num[i] + ".png", "rolebtnend.png", i);
	}
	roleData->addBtnTo(this, 4);

	//技能框初始化
	roleSkill = new RoleSkill;
	roleSkill->closeBtn = MenuItemImage::create("return.png", "returnend.png",
		CC_CALLBACK_1(MainScene::skillCloseCallBack, this));
	roleSkill->init(this);

	//背包初始化
	bagData = new BagData;
	bagData->closeBtn = MenuItemImage::create("return.png", "returnend.png",
		CC_CALLBACK_1(MainScene::bagCloseCallBack, this));
	bagData->init(this);*/
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
	//#include"Prop.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene()
{

	auto scene = Scene::create();

	auto layer = MainScene::create();

	scene->addChild(layer);

	// return the scene
	return scene;
}

void MainScene::bang(float dt)
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
bool MainScene::init()
{

	Size visibleSize = Director::getInstance()->getVisibleSize();

	if (!Layer::init())
	{
		return false;
	}

	//获取基础按钮
	roleBtn = MenuItemImage::create("role.png", "roleend.png",
		CC_CALLBACK_1(MainScene::roleCallBack, this));
	bagBtn = MenuItemImage::create("bag.png", "bagend.png",
		CC_CALLBACK_1(MainScene::bagCallBack, this));
	skillBtn = MenuItemImage::create("skill.png", "skillend.png",
		CC_CALLBACK_1(MainScene::skillCallBack, this));
	closeBtn = MenuItemImage::create("exit.png", "exitend.png",
		CC_CALLBACK_1(MainScene::closeCallBack, this));
	saveBtn = MenuItemImage::create("save.png", "saveend.png",
		CC_CALLBACK_1(MainScene::saveCallBack, this));
	setBtn = MenuItemImage::create("set.png", "setend.png",
		CC_CALLBACK_1(MainScene::setCallBack, this));
	mapBtn = MenuItemImage::create("map.png", "mapend.png",
		CC_CALLBACK_1(MainScene::mapCallBack, this));
	//获取选择按钮
	seBtn = MenuItemImage::create("what.png", "what.png",
		CC_CALLBACK_1(MainScene::seCallBack, this));

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
		CC_CALLBACK_1(MainScene::roleCloseCallBack, this));
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
		CC_CALLBACK_1(MainScene::skillCloseCallBack, this));
	roleSkill->init(this);

	//背包初始化
	bagData = new BagData;
	bagData->closeBtn = MenuItemImage::create("return.png", "returnend.png",
		CC_CALLBACK_1(MainScene::bagCloseCallBack, this));
	bagData->init(this);
	backGround = Sprite::create("daoguan.jpg");
	backGround->setPosition(480, 320);
	addChild(backGround, 0);
	// NPC
	NpcBtn = MenuItemImage::create("zhugejun1.png", "zhugejunend.png", this, menu_selector(MainScene::NpcCallBack));
	NpcBtn->setPosition(274, 253);
	auto menu1 = Menu::create(NpcBtn, NULL);
	menu1->setPosition(Point(0, 0));
	this->addChild(menu1);
	Count * pt = Count::Getinstance();
	if (pt->retNumber() == -1)
	{
		auto seq = RoleSequence::getInstance();
		seq->join(Nan1);
		Nan1->addSkill(JianYan);
		Nan1->addSkill(HanBingZhenQi);
		pt->numberPlus();
	}
	if (pt->retNumber() != 0)
	{
		NpcBtn->setVisible(false);
		mapBtn->setVisible(true);
	}

	MenuItemImage* test = MenuItemImage::create("xie1.png", "xie2.png",
		CC_CALLBACK_1(MainScene::testCallBack, this));
	Menu* testmenu = Menu::create(test, NULL);
	testmenu->setPosition(0, 0);
	test->setPosition(800, 320);
	addChild(testmenu, 100);
	test->setVisible(false);

	return true;
}

void MainScene::testCallBack(Ref* sender)
{
	
}

void MainScene::setAllEnabled(bool T)
{
	menu->setEnabled(T);
	menuSe->setEnabled(T);
}


void MainScene::roleCallBack(Ref* sender)
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
	log("role");
}

void MainScene::bagCallBack(Ref* sender)
{
	bagData->showBagLayer(true);
	setAllEnabled(false);
	bagData->setWhichBag(0);
}

void MainScene::skillCallBack(Ref* sender)
{
	if (!roleSkill->layerIsVisible())
	{
		roleSkill->showSkillLayer(true);
		setAllEnabled(false);
	}
	log("skill");
}

void MainScene::setCallBack(Ref* sender)
{
	log("set");
}

void MainScene::closeCallBack(Ref* sender)
{
	log("close");
	Director::getInstance()->end();
}

void MainScene::saveCallBack(Ref* sender)
{
	log("save");
}

void MainScene::mapCallBack(Ref* sender)
{
	Director::getInstance()->pushScene(MainMap::createScene());
}

void MainScene::seCallBack(Ref* sender)
{
	scheduleOnce(schedule_selector(MainScene::bang), 0.1f);
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

void MainScene::roleCloseCallBack(Ref* sender)
{
	menuRole->setVisible(false);
	roleData->setLayerVisible(false);
	setAllEnabled(true);
}

void MainScene::skillCloseCallBack(Ref* sender)
{
	roleSkill->showSkillLayer(false);
	setAllEnabled(true);
}

void MainScene::bagCloseCallBack(Ref* sender)
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

void MainScene::NpcCallBack(Ref*pSender)
{

	ShuShan1.dialogBegin(this);
	NpcBtn->setVisible(false);
	Count * pt = Count::Getinstance();
	pt->numberPlus();
    //1
	mapBtn->setVisible(true);

}
void MainScene::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("shushanmusic.mp3");
}




