#pragma once
#include "cocos2d.h"
#include"editor-support/cocostudio/CCSGUIReader.h"
#include"ui/CocosGUI.h"
#include"SimpleAudioEngine.h"
#include"cocos2d.h"

USING_NS_CC;
using namespace ui;

class BaseScene :public cocos2d::Layer
{
public:
	Sprite*setImage;
	static cocos2d::Scene*createScene();
	virtual  bool init();
	virtual void callBackFunc1(Ref*pSender);
	void onEnterTransitionDidFinish();
	CREATE_FUNC(BaseScene);

};
