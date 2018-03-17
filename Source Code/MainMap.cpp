#pragma once
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include"MainMap.h"
#include"SimpleAudioEngine.h"
#include"MainScene.h"
#include"ThirdScene.h"
#include"WuChangScene.h"
#include"FifthScene.h"
#include"Count.h"
#include"YiLuoStudio.h"




USING_NS_CC;

using namespace ui;
using namespace cocostudio::timeline;


Scene* MainMap::createScene()
{
	auto scene = Scene::create();
	auto layer = MainMap::create();
	scene->addChild(layer);
	return scene;
}

bool MainMap::init()
{
	auto rootNode = CSLoader::createNode("123.csb");
	this->addChild(rootNode);
	auto ShuShan = (Button*)rootNode->getChildByName("Button_1");
	ShuShan->addTouchEventListener(this, toucheventselector(MainMap::callBackFunc1));
	auto WuChang = (Button*)rootNode->getChildByName("Button_2");
	WuChang->addTouchEventListener(this, toucheventselector(MainMap::callBackFunc4));
	auto YingZhou= (Button*)rootNode->getChildByName("Button_3");
	YingZhou->addTouchEventListener(this, toucheventselector(MainMap::callBackFunc7));
	auto DengZhou= (Button*)rootNode->getChildByName("Button_4");
	DengZhou->addTouchEventListener(this, toucheventselector(MainMap::callBackFunc2));
	auto HiddenScene = (Button *)rootNode->getChildByName("Button_5");
	HiddenScene->addTouchEventListener(this,toucheventselector(MainMap::callBackFunc8));
	//ShuShan->setVisible(false);
	WuChang->setVisible(false);
	YingZhou->setVisible(false);
	DengZhou->setVisible(false);
	Count * pt = Count::Getinstance();
	if (pt->retNumber() > 0)
	{
		WuChang->setVisible(true);
	}

	if (pt->retNumber()>1)
	{
	YingZhou->setVisible(true);
	}
	if (pt->retNumber() > 4)
	{
		DengZhou->setVisible(true);
	}
	MainBtn = Button::create("pass1.png", "pass3.png", "pass.png");
	MainBtn->addTouchEventListener(this, toucheventselector(MainMap::callBackFunc5));
	MainBtn->setPosition(Vec2(880, 20));
	this->addChild(MainBtn);
	VoiceBtn = Button::create("pass2.png", "pass.png", "pass2.png");
	VoiceBtn->setPosition(Vec2(900, 150));
	VoiceBtn->addTouchEventListener(this, toucheventselector(MainMap::callBackFunc3));
	//VoiceBtn->addTouchEventListener(this, toucheventselector(MainMap::callBackFunc5));

	CloseBtn = Button::create("out.png", "pass2.png", "pass.png");
	CloseBtn->setPosition(Vec2(750, 20));
	CloseBtn->addTouchEventListener(this, toucheventselector(MainMap::callBackFunc6));

	VoiceBtn->setVisible(false);
	CloseBtn->setVisible(false);
	this->addChild(CloseBtn);
	this->addChild(VoiceBtn);


	return true;
}

void MainMap::callBackFunc1(Ref*pSender, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
	{
		Director::getInstance()->pushScene(TransitionProgressOutIn::create(3.0f, MainScene::createScene()));
		break;
	}
	}
}



void  MainMap::callBackFunc2(Ref*pSender, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
	{
		Director::getInstance()->pushScene(TransitionProgressOutIn::create(3.0f, FifthScene::createScene()));
		break;
	}
	}

}
void  MainMap::callBackFunc3(Ref*pSender, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic("mp33.mp3");
		break;
	}
	}
}
void  MainMap::callBackFunc4(Ref*pSender, TouchEventType type)
{
		switch (type)
		{
		case TouchEventType::TOUCH_EVENT_ENDED:
			Director::getInstance()->pushScene(TransitionFadeDown::create(3.0f, WuChangScene::createScene()));
			
		}
}

// Set Visibility for the Buttons 
void  MainMap::callBackFunc5(Ref*pSender, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
	{
		if (VoiceBtn->isVisible())
		{
			VoiceBtn->setVisible(false);
			CloseBtn->setVisible(false);
		}
		else
		{
			VoiceBtn->setVisible(true);
			CloseBtn->setVisible(true);
		}
		break;
	}

	}
}

//ÇÐ»»µ½½áÊø»­Ãæ
void  MainMap::callBackFunc6(Ref*pSender, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
	{
		Director::getInstance()->end();
	}
	}
}
void MainMap::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	auto pt = Count::Getinstance();
	if (pt->retNumber() >= 10)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("mp33.mp3");
	}
	else
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("map.mp3");
	}
}

void MainMap::callBackFunc7(Ref*pSender, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
	{
		Director::getInstance()->pushScene(ThirdScene::createScene ());
	}
	}
}
void MainMap::callBackFunc8(Ref*pSender, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
	{
		Director::getInstance()->pushScene(YiLuoStudioScene::createScene());
	}
	}
}