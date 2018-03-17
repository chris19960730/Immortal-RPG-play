#include "BaseScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include"SimpleAudioEngine.h"
#include"MainScene.h"

USING_NS_CC;

using namespace ui;
using namespace cocostudio::timeline;

Scene* BaseScene::createScene()
{
	auto scene = Scene::create();
	auto layer = BaseScene::create();
	scene->addChild(layer);
	return scene;
}

bool BaseScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// Load the UI from cocostudio.
	auto rootNode = CSLoader::createNode("MainScene.csb");

	addChild(rootNode);

	CCSize size = CCDirector::sharedDirector()->getWinSize();
	auto background = Sprite::create("kaishiyouxi.png");
	background->setPosition(ccp(size.width / 2, size.height / 2));
	float winw = size.width;
	float winh = size.height;
	float backgroundX = background->getTextureRect().getMaxX();
	float backgroundY = background->getTextureRect().getMaxY();
	background->setScaleX(winw / backgroundX);
	background->setScaleY(winh / backgroundY);
	this->addChild(background);

	auto beginBtn = MenuItemImage::create("beginBtn.png", "beginbtnend.png", this, menu_selector(BaseScene::callBackFunc1));
	beginBtn->setPosition(300, 200);
	auto menu = Menu::create(beginBtn, NULL);
	menu->setPosition(Point(0, 0));
	this->addChild(menu);
	return true;
}

void BaseScene::callBackFunc1(Ref*pSender)
{
	Director::getInstance()->pushScene(TransitionCrossFade::create(3.0f, MainScene::createScene()));
}

void BaseScene::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("mp31.mp3");
}
