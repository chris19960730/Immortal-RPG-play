#include"Dialog.h"
#include"Count.h"
#include"EndScene.h"

//               plist文件 /对话数量 / 触发战斗 / 当前对话  / 下一个dialog  / 第几张切换战斗
Dialog  ShuShan1("shushan1.plist", 4, false, 0, NULL, 2);
Dialog  Dia_WuChangChaGuan("wuchangchaguan.plist", 20, true, 0, NULL, 11);   //武昌茶馆对话
Dialog Dia_YingZhouKeZhan("yingzhoukezhan1.plist", 20, false, 0, NULL, 11);// 颍州客栈对话
Dialog Dia_YingZhouJiaoWai("yingzhoujiaowai1.plist", 36, true, 0, NULL, 5);//颍州郊外对话
Dialog Dia_DengZhou1("dengzhouduihua1.plist", 28, false, 0, NULL, 2);// 邓州1
Dialog Dia_DengZhou2("dengzhoudia2.plist", 16, false, 0, NULL, 2);//邓州2
Dialog Dia_DengZhouHouShan1("dengzhouhoushandia1.plist", 20, true, 0, NULL, 18);
Dialog Dia_DengZhouHouShan2("dengzhouhoushan2.plist", 23, true, 0, NULL, 16);
Dialog Dia_DengZhouLast("dengzhoulast.plist", 30, false, 0, NULL, 2);
//隐藏场景对话
Dialog Dia_YangZong("YangZong_dia.plist", 1, false, 0, NULL, 2);
Dialog Dia_QunZong1("QunZong_dia1.plist", 1, false, 0, NULL, 2);
Dialog Dia_QunZong2("QunZong_dia2.plist", 1, false, 0, NULL, 2);
Dialog Dia_TianZong1("TianZong_dia1.plist", 1, false, 0, NULL, 2);
Dialog Dia_TianZong2("TianZong_dia2.plist", 1, false, 0, NULL, 2);
Dialog Dia_ZhangZong1("ZhangZong_dia1.plist", 1, false, 0, NULL, 2);
Dialog Dia_ZhangZong2("ZhangZong_dia2.plist", 1, false, 0, NULL, 2);
Dialog Dia_ZhangZong3("ZhangZong_dia3.plist", 1, false, 0, NULL, 2);
Dialog Dia_ZhangZong4("ZhangZong_dia4.plist", 1, false, 0, NULL, 2);
Dialog Dia_ZhangZong5("ZhangZong_dia5.plist", 1, false, 0, NULL, 2);
Dialog Dia_ZhangZong6("ZhangZong_dia6.plist", 1, false, 0, NULL, 2);
bool  QunZongClose = false;

bool BarrierLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto Callback = [](Touch *, Event *)
	{
		return (true);
	};
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = Callback;
	listener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}
Dialog::Dialog(string s, int numt, bool whether_b, int numn, Dialog *  nextdia, int change) :
	filename(s), totalnum(numt), whetherBattle(whether_b), nownum(numn), pt(nextdia), changeNum(change)
{
}

Dialog::~Dialog()
{

}
void Dialog::dialogBegin(Node * node)
{
	Layer * Barrier = BarrierLayer::create();
	auto Back = node->getParent();
	Back->addChild(Barrier);
	Barrier->setTag(99);
	this->node = Back;
	Director::getInstance()->getTextureCache()->removeAllTextures();
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->removeSpriteFrames();
	frameCache->addSpriteFramesWithFile(filename);
	for (int i = 1; i <= totalnum ; i++)
	{
		char name[128] = { 0 };
		sprintf(name, "%d.jpg", i);
		SpriteFrame * sf = frameCache->spriteFrameByName(name);                                   //将图片加入vector
		vec.pushBack(sf);
	}
	frameCache->removeSpriteFrames();
	it = vec.begin();
	for (int i = 1; i <= nownum; i++)
	{
		it++;
	}
	Sprite *sp = Sprite::createWithSpriteFrame(*it);
	sp->setTag(SPTAG);
	sp->setPosition(Vec2(456.00, 231.00));
	Back->addChild(sp);
	Button * but = Button::create("toumingde.png", "toumingde.png", "toumingde.png");
	Back->addChild(but);
	but->setTag(BUTAG);
	but->setPosition(Vec2(480,320));
	nownum = 1;
	but->addTouchEventListener(CC_CALLBACK_2(Dialog::dialogContinue, this));
}
void Dialog::dialogContinue(Ref* sender, ui::Widget::TouchEventType type)
{
	if (type == ui::Widget::TouchEventType::ENDED)
	{
		Sprite * sp = (Sprite *)node->getChildByTag(SPTAG);
		Button * but = (Button *)node->getChildByTag(BUTAG);
		if (nownum < totalnum)
		{
			//sp = Sprite::createWithSpriteFrame(vec[nownum]);
			it = vec.begin();
			for (int i = 1; i <= nownum; i++)
			{
				it++;
			}
			sp->setSpriteFrame(*it);
			if (whetherBattle == true)
			{
				if (nownum == changeNum)
				{
					Director::getInstance()->pushScene( BattleScene::createScene());//添加切换场景
				}
			}
			/*if (pt != NULL)
			{
			pt->DialogBegin(node);
			}*/
			nownum++;
		}
		else
		{
			if (QunZongClose == true)
			{
				Director::getInstance()->end();
			}
			sp->removeFromParent();
			but->removeFromParent();
			for (int i = 1; i <= totalnum; i++)
			{
				vec.popBack();
			}
			nownum = 0;
			auto pt = Count::Getinstance();
			if (pt->retNumber() == 12)
			{
				Director::getInstance()->pushScene(TransitionFadeDown::create(2.0f,EndScene::createScene()));
			}
			node->removeChildByTag(99);
		}
	}
}

