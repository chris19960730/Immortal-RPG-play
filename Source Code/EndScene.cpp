#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include"SimpleAudioEngine.h"
#include"EndScene.h"

USING_NS_CC;

using namespace ui;
using namespace cocostudio::timeline;

Scene* EndScene::createScene()
{
	auto scene = Scene::create();
	auto layer = EndScene::create();
	scene->addChild(layer);
	return scene;
}

bool EndScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	auto background = Sprite::create("6666.png");
	/*background->setPosition(ccp(size.width / 2, size.height / 2));
	float winw = size.width;
	float winh = size.height;
	float backgroundX = background->getTextureRect().getMaxX();
	float backgroundY = background->getTextureRect().getMaxY();
	background->setScaleX(winw / backgroundX);
	background->setScaleY(winh / backgroundY);*/
	background->setAnchorPoint(Vec2(0,0));
	background->setPosition(0, 0);
	this->addChild(background);
	auto button1 = MenuItemImage::create("close.png", "closeend.png", this, menu_selector(EndScene::callBackFunc1));
	auto button2 = MenuItemImage::create("close.png", "closeend.png", this, menu_selector(EndScene::callBackFunc1));
	button1->setPosition(558.5, 389.6);
	button2->setPosition(776, 348.6);
	
	auto menu = Menu::create(button1, button2, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu);
	return true;
}

void EndScene::callBackFunc1(Ref*pSender)
{
	Director::getInstance()->end();
}

void EndScene::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("mp31.mp3");
}
