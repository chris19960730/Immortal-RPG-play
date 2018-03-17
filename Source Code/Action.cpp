#include"Action.h"

//                       plist�ļ���   ����  վ��ͼƬ
Activity  ZhugeYibin_act("zhugea.plist", 11, "zhuges.png");
Activity  TaoLingyuan_act("taolingyuan.plist", 20, "taolingyuans.png");
Activity  DaHan_act("Dahana.plist",16,"dahans.png");
Activity  NiuYao_act("niuyao_act.plist", 13, "niuyaos.png");
Activity GaoDieNie_act("gaodienie.plist", 13, "gaodienies.png");
Activity  GuShe_act("gushe_act.plist", 16, "gushe_s.png");
Activity  JiaFei_act("jiafei_act.plist", 13, "jiafei_s.png");

Activity::Activity()
{}

Activity::Activity(string  name, int number, string sname)
	:a_filename(name), s_filename(sname)
{
	num = number;
}

Activity::~Activity()
{
	string * s = &a_filename;
	delete s;
	s = &s_filename;
	delete s;
}

void  Activity::Attack_action(Sprite* sprite)
{
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile(a_filename);
	Vector<SpriteFrame *> AllFrame;
	for (int i = 1; i <= num; i++)
	{
		char name[128] = { 0 };
		sprintf(name, "a%d.png", i);
		SpriteFrame * sf = frameCache->spriteFrameByName(name);
		AllFrame.pushBack(sf);                                               //��ͼƬ����vector
	}
	Animation * animation = Animation::createWithSpriteFrames(AllFrame);     //������������
	animation->setDelayPerUnit((1.1 / num));                                 //ʱ����
	Animate * act = Animate::create(animation);
	sprite->runAction(act);
	Director::getInstance()->getTextureCache()->removeAllTextures();
	frameCache->removeSpriteFrames();
}
Sprite * Activity::Stand_action()
{
	Sprite * sp = Sprite::create(s_filename);
	return (sp);
}

void Activity::CopyAct(Activity & act)
{
	this->a_filename = act.a_filename;
	this->num = act.num;
	this->s_filename = act.s_filename;
}

