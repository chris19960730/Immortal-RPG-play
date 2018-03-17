#include"YiLuoStudio.h"
#include"Dialog.h"
#include"Enemy.h"
#include"MainMap.h"
#include"Sequence.h"
#include"SimpleAudioEngine.h"
#include"Count.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;


//���˾�����
int QunZong = 1;
int TianZong = 1;
int ZhangZong = 1;
Scene* YiLuoStudioScene::createScene()
{

	auto scene = Scene::create();

	auto layer = YiLuoStudioScene::create();

	scene->addChild(layer);

	// return the scene
	return scene;
}

void YiLuoStudioScene::bang(float dt)
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
bool YiLuoStudioScene::init()
{



	Size visibleSize = Director::getInstance()->getVisibleSize();

	if (!Layer::init())
	{
		return false;
	}

	//��ȡ������ť
	roleBtn = MenuItemImage::create("role.png", "roleend.png",
		CC_CALLBACK_1(YiLuoStudioScene::roleCallBack, this));
	bagBtn = MenuItemImage::create("bag.png", "bagend.png",
		CC_CALLBACK_1(YiLuoStudioScene::bagCallBack, this));
	skillBtn = MenuItemImage::create("skill.png", "skillend.png",
		CC_CALLBACK_1(YiLuoStudioScene::skillCallBack, this));
	closeBtn = MenuItemImage::create("exit.png", "exitend.png",
		CC_CALLBACK_1(YiLuoStudioScene::closeCallBack, this));
	saveBtn = MenuItemImage::create("save.png", "saveend.png",
		CC_CALLBACK_1(YiLuoStudioScene::saveCallBack, this));
	setBtn = MenuItemImage::create("set.png", "setend.png",
		CC_CALLBACK_1(YiLuoStudioScene::setCallBack, this));
	mapBtn = MenuItemImage::create("map.png", "mapend.png",
		CC_CALLBACK_1(YiLuoStudioScene::mapCallBack, this));
	//��ȡѡ��ť
	seBtn = MenuItemImage::create("what.png", "what.png",
		CC_CALLBACK_1(YiLuoStudioScene::seCallBack, this));

	xie = Sprite::create("xie1.png");
	addChild(xie, 2);
	xie->setPosition(760 + 130, 50);

	//���û�����ť��ѡ��ť��λ��
	seBtn->setPosition(760 + 130, 50);
	roleBtn->setPosition(400 + 120, 50);
	bagBtn->setPosition(400 + 240, 50);
	skillBtn->setPosition(400 + 240, 50);
	skillBtn->setVisible(false);
	closeBtn->setPosition(400 + 360, 50);
	mapBtn->setPosition(90, 550);
	saveBtn->setPosition(960 - 50 - 15, 140);
	setBtn->setPosition(960 - 50 - 15, 140 + 90);

	//��ȡ���������ñ���λ��
	auto  BackGround = CSLoader::createNode("YiLuo.csb");      //��������
															   // NPC
	BackGround->setTag(70);    //����tagֵΪ70
	this->addChild(BackGround);
	auto  Btn_QunZong = (Button *)BackGround->getChildByTag(10);
	Btn_QunZong->addTouchEventListener(CC_CALLBACK_2(YiLuoStudioScene::QunZongCallBack, this));
	auto  Btn_YangZong = (Button *)BackGround->getChildByTag(6);
	Btn_YangZong->addTouchEventListener(CC_CALLBACK_2(YiLuoStudioScene::YangZongCallBack, this));
	auto  Btn_TianZong = (Button *)BackGround->getChildByTag(9);
	Btn_TianZong->addTouchEventListener(CC_CALLBACK_2(YiLuoStudioScene::TianZongCallBack, this));
	if (TianZong == 2)
	{
		Btn_TianZong->setVisible(false);
	}
	auto  Btn_ZhangZong = (Button *)BackGround->getChildByTag(7);
	if (ZhangZong == 7)
	{
		Btn_ZhangZong->setVisible(false);
	}
	Btn_ZhangZong->addTouchEventListener(CC_CALLBACK_2(YiLuoStudioScene::ZhangZongCallBack, this));

	//close��ť
	roleData = new RoleData;
	roleData->closeBtn = MenuItemImage::create("return.png", "returnend.png",
		CC_CALLBACK_1(YiLuoStudioScene::roleCloseCallBack, this));
	roleData->setCloseBtnPosition(700.5, 565);

	//������Ϣͼ���ʼ��
	/*string layerFile[4] = { "data1.jpg","data2.jpg","data3.jpg","data4.jpg" };
	string headFile[4] = { "head1.png","head2.png" ,"head3.png" ,"head4.png" };
	roleData->bindSprite(layerFile,headFile);*/
	roleData->bindAllChild();
	roleData->addLayerTo(this, 2);
	//Nan1->addAllTo(roleData->layer[0]);
	roleData->setLayerPosition(480, 320);

	//������ť��
	menu = Menu::create(roleBtn, bagBtn, skillBtn, closeBtn, saveBtn, setBtn, NULL);
	//������Ϣ�رհ�ť��
	menuRole = Menu::create(roleData->closeBtn, NULL);
	//ѡ��ť����ͼ�󶨣����ǿɼ�
	menuSe = Menu::create(seBtn, mapBtn, NULL);

	//��ť��ʼ��
	menu->setVisible(false);
	menuRole->setVisible(false);

	menu->setPosition(0, 0);
	menuSe->setPosition(0, 0);
	menuRole->setPosition(0, 0);

	//��ӵ�������
	addChild(menu, 1);
	addChild(menuSe, 1);
	addChild(menuRole, 2);

	//����ѡ��ť��ʼ��
	string num[4] = { "1","2","3","4" };
	for (int i = 0; i < 4; i++)
	{
		roleData->bindRoleBtn("rolebtn" + num[i] + ".png", "rolebtn" + num[i] + "end.png", i);
	}
	roleData->addBtnTo(this, 4);

	//���ܿ��ʼ��
	roleSkill = new RoleSkill;
	roleSkill->closeBtn = MenuItemImage::create("return.png", "returnend.png",
		CC_CALLBACK_1(YiLuoStudioScene::skillCloseCallBack, this));
	roleSkill->init(this);

	//������ʼ��
	bagData = new BagData;
	bagData->closeBtn = MenuItemImage::create("return.png", "returnend.png",
		CC_CALLBACK_1(YiLuoStudioScene::bagCloseCallBack, this));
	bagData->init(this);
	//��ȡ���������ñ���λ��



	return true;
}


void YiLuoStudioScene::setAllEnabled(bool T)
{
	menu->setEnabled(T);
	menuSe->setEnabled(T);
}


void YiLuoStudioScene::roleCallBack(Ref* sender)
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

void YiLuoStudioScene::bagCallBack(Ref* sender)
{
	bagData->showBagLayer(true);
	setAllEnabled(false);
	bagData->setWhichBag(0);
}

void YiLuoStudioScene::skillCallBack(Ref* sender)
{
	if (!roleSkill->layerIsVisible())
	{
		roleSkill->showSkillLayer(true);
		setAllEnabled(false);
	}
	log("skill");
}

void YiLuoStudioScene::setCallBack(Ref* sender)
{
	log("set");
}

void YiLuoStudioScene::closeCallBack(Ref* sender)
{
	log("close");
	Director::getInstance()->end();
}

void YiLuoStudioScene::saveCallBack(Ref* sender)
{
	log("save");
}

void YiLuoStudioScene::mapCallBack(Ref* sender)
{
	Director::getInstance()->pushScene(MainMap::createScene());
}

void YiLuoStudioScene::seCallBack(Ref* sender)
{
	scheduleOnce(schedule_selector(YiLuoStudioScene::bang), 0.1f);
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

void YiLuoStudioScene::roleCloseCallBack(Ref* sender)
{
	menuRole->setVisible(false);
	roleData->setLayerVisible(false);
	setAllEnabled(true);
}

void YiLuoStudioScene::skillCloseCallBack(Ref* sender)
{
	roleSkill->showSkillLayer(false);
	setAllEnabled(true);
}

void YiLuoStudioScene::bagCloseCallBack(Ref* sender)
{
	bagData->showBagLayer(false);
	setAllEnabled(true);/*
	bagData->moneyLabel->setVisible(false);
	bagData->money->setVisible(false);
	bagData->useBtn->setVisible(false);
	bagData->showPropInformation(0, false);
	bagData->showEquipmentInformation(0, false, 0);
	bagData->showEquipmentInformation(0, false, 1);*/
}


void YiLuoStudioScene::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("hidden.mp3");
	Count * pt = Count::Getinstance();
	if (pt->retNumber() == 8)
	{
		RoleSequence::getInstance()->getExpAll(300);
		pt->numberPlus();   //9

	}
	if (pt->retNumber() == 10)
	{
		RoleSequence::getInstance()->getExpAll(300);
		pt->numberPlus();   //11

	}

}

void YiLuoStudioScene::QunZongCallBack(Ref* sender, ui::Widget::TouchEventType type)
{
	if (type == ui::Widget::TouchEventType::BEGAN)
	{
		if (QunZong == 1)
		{
			Dia_QunZong2.dialogBegin(this);
			QunZong++;
		}
		else
		{
			QunZongClose = true;
			Dia_QunZong1.dialogBegin(this);
		}
	}
}
void YiLuoStudioScene::TianZongCallBack(Ref* sender, ui::Widget::TouchEventType type)
{
	if (type == ui::Widget::TouchEventType::BEGAN)
	{
		if (Propbag.retMoney()<500)
		{
			Dia_TianZong2.dialogBegin(this);

		}
		else
		{
			Dia_TianZong1.dialogBegin(this);
			auto seq = RoleSequence::getInstance();
			seq->retRole(0)->changeAttack(100);
			seq->retRole(0)->changeDefence(100);
			Propbag.changeMoney(-500);
			TianZong++;
			this->getChildByTag(70)->getChildByTag(9)->setVisible(false);
			auto _sprite = Sprite::create("txg.png");
			_sprite->setPosition(480, 320);
			addChild(_sprite,1000);
			auto fadeto = FadeTo::create(3, 0);
			_sprite->runAction(fadeto);
		}
	}
}
void YiLuoStudioScene::YangZongCallBack(Ref* sender, ui::Widget::TouchEventType type)
{
	if (type == ui::Widget::TouchEventType::BEGAN)
	{
		Dia_YangZong.dialogBegin(this);
	}
}
void YiLuoStudioScene::ZhangZongCallBack(Ref* sender, ui::Widget::TouchEventType type)
{
	if (type == ui::Widget::TouchEventType::BEGAN)
	{
		if (ZhangZong == 1)
		{
			Dia_ZhangZong1.dialogBegin(this);
			ZhangZong++;
		}
		else if (ZhangZong == 2)
		{
			Dia_ZhangZong2.dialogBegin(this);
			ZhangZong++;
		}
		else if (ZhangZong == 3)
		{
			Dia_ZhangZong3.dialogBegin(this);
			ZhangZong++;
		}
		else if (ZhangZong == 4)
		{
			Dia_ZhangZong4.dialogBegin(this);
			ZhangZong++;
		}
		else if (ZhangZong == 5)
		{
			Dia_ZhangZong5.dialogBegin(this);
			ZhangZong++;
		}
		else
		{
			Dia_ZhangZong6.dialogBegin(this);
			auto seq = RoleSequence::getInstance();
			seq->retRole(0)->addSkill(ChangKong23);
			ZhangZong++;
			this->getChildByTag(70)->getChildByTag(7)->setVisible(false);
			auto _sprite = Sprite::create("zjn.png");
			_sprite->setPosition(480, 320);
			addChild(_sprite,1000);
			auto fadeto = FadeTo::create(3, 0);
			_sprite->runAction(fadeto);
		}
	}
}
