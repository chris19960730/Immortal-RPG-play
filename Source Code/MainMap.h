#pragma once
#include "cocos2d.h"
#include"editor-support/cocostudio/CCSGUIReader.h"
#include"ui/CocosGUI.h"
#include"SimpleAudioEngine.h"
#include"cocos2d.h"

USING_NS_CC;
using namespace ui;


class MainMap :public cocos2d::Layer
{
public:
	static cocos2d::Scene*createScene();
	virtual  bool init();
	Button*MainBtn;
	Button*VoiceBtn;
	Button*CloseBtn;
	virtual void callBackFunc1(Ref*pSender, TouchEventType type);
	virtual void callBackFunc2(Ref*pSender, TouchEventType type);
	virtual void callBackFunc3(Ref*pSender, TouchEventType type);
	virtual void callBackFunc4(Ref*pSender, TouchEventType type);
	virtual void callBackFunc5(Ref*pSender, TouchEventType type);
	virtual void callBackFunc6(Ref*pSender, TouchEventType type);
	virtual void callBackFunc7(Ref*pSender, TouchEventType type);
	virtual void callBackFunc8(Ref*pSender, TouchEventType type);
	void onEnterTransitionDidFinish();
	CREATE_FUNC(MainMap);

};
