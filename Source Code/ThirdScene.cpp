#include"ThirdScene.h"
#include"Enemy.h"
#include"MainMap.h"
#include"Sequence.h"
#include"OutSideYingZhou.h"
#include"SimpleAudioEngine.h"
#include"Count.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocostudio::timeline;

bool NpcBtn2JiaoWai = false;

Scene* ThirdScene::createScene()
{

	auto scene = Scene::create();

	auto layer = ThirdScene::create();

	scene->addChild(layer);

	return scene;
}

void ThirdScene::bang(float dt)
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
bool ThirdScene::init()
{


	Size visibleSize = Director::getInstance()->getVisibleSize();

	if (!Layer::init())
	{
		return false;
	}

	//获取基础按钮
	roleBtn = MenuItemImage::create("role.png", "roleend.png",
		CC_CALLBACK_1(ThirdScene::roleCallBack, this));
	bagBtn = MenuItemImage::create("bag.png", "bagend.png",
		CC_CALLBACK_1(ThirdScene::bagCallBack, this));
	skillBtn = MenuItemImage::create("skill.png", "skillend.png",
		CC_CALLBACK_1(ThirdScene::skillCallBack, this));
	closeBtn = MenuItemImage::create("exit.png", "exitend.png",
		CC_CALLBACK_1(ThirdScene::closeCallBack, this));
	saveBtn = MenuItemImage::create("save.png", "saveend.png",
		CC_CALLBACK_1(ThirdScene::saveCallBack, this));
	setBtn = MenuItemImage::create("set.png", "setend.png",
		CC_CALLBACK_1(ThirdScene::setCallBack, this));
	mapBtn = MenuItemImage::create("map.png", "mapend.png",
		CC_CALLBACK_1(ThirdScene::mapCallBack, this));
	//获取选择按钮
	seBtn = MenuItemImage::create("what.png", "what.png",
		CC_CALLBACK_1(ThirdScene::seCallBack, this));

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
		CC_CALLBACK_1(ThirdScene::roleCloseCallBack, this));
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
		CC_CALLBACK_1(ThirdScene::skillCloseCallBack, this));
	roleSkill->init(this);

	//背包初始化
	bagData = new BagData;
	bagData->closeBtn = MenuItemImage::create("return.png", "returnend.png",
		CC_CALLBACK_1(ThirdScene::bagCloseCallBack, this));
	bagData->init(this);
	//获取背景，设置背景位置
	backGround = Sprite::create("yingzhou.jpg");
	backGround->setPosition(480, 320);
	addChild(backGround, 0);
	// NPC
	NpcBtn1 = MenuItemImage::create("kezhan1.png", "kezhanend.png", this, menu_selector(ThirdScene::Npc1CallBack));
	NpcBtn1->setPosition(590, 389);
	NpcBtn2 = MenuItemImage::create("senlin1.jpg", "senlin1.jpg", this, menu_selector(ThirdScene::Npc2CallBack));
	NpcBtn2->setPosition(350, 200);
	NpcBtn2->setVisible(NpcBtn2JiaoWai);
	auto menu1 = Menu::create(NpcBtn1,NpcBtn2, NULL);
	menu1->setPosition(Point(0, 0));
	this->addChild(menu1);


	//剧情线~~~~~~~~~~~~~~~~~

	Count * pt = Count::Getinstance();
	if (pt->retNumber() != 3)
	{
		NpcBtn1->setVisible(false);
		mapBtn->setVisible(true);
	}

	return true;
}


void ThirdScene::setAllEnabled(bool T)
{
	menu->setEnabled(T);
	menuSe->setEnabled(T);
}


void ThirdScene::roleCallBack(Ref* sender)
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

void ThirdScene::bagCallBack(Ref* sender)
{
	bagData->showBagLayer(true);
	setAllEnabled(false);
	bagData->setWhichBag(0);
}

void ThirdScene::skillCallBack(Ref* sender)
{
	if (!roleSkill->layerIsVisible())
	{
		roleSkill->showSkillLayer(true);
		setAllEnabled(false);
	}
	log("skill");
}

void ThirdScene::setCallBack(Ref* sender)
{
	log("set");
}

void ThirdScene::closeCallBack(Ref* sender)
{
	log("close");
	Director::getInstance()->end();
}

void ThirdScene::saveCallBack(Ref* sender)
{
	log("save");
}

void ThirdScene::mapCallBack(Ref* sender)
{
	Director::getInstance()->pushScene(MainMap::createScene());
}

void ThirdScene::seCallBack(Ref* sender)
{
	scheduleOnce(schedule_selector(ThirdScene::bang), 0.1f);
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

void ThirdScene::roleCloseCallBack(Ref* sender)
{
	menuRole->setVisible(false);
	roleData->setLayerVisible(false);
	setAllEnabled(true);
}

void ThirdScene::skillCloseCallBack(Ref* sender)
{
	roleSkill->showSkillLayer(false);
	setAllEnabled(true);
}

void ThirdScene::bagCloseCallBack(Ref* sender)
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

void ThirdScene::Npc1CallBack(Ref*pSender)


{
	NpcBtn1->setVisible(false);
	NpcBtn2->setVisible(true);
	NpcBtn2JiaoWai = true;
	Dia_YingZhouKeZhan.dialogBegin(this);
	(RoleSequence::getInstance())->popRole();

	Count * pt = Count::Getinstance();  
	pt->numberPlus();// 4
	mapBtn->setVisible(true);
	//对话，出按钮

}


	void ThirdScene::Npc2CallBack(Ref*pSender)
	{
		//NpcBtn2JiaoWai = false;
		Director::getInstance()->pushScene(TransitionFade::create(3.0f, OutSideYingZhouScene::createScene()));
	}

void ThirdScene::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("mp32.mp3");
}

