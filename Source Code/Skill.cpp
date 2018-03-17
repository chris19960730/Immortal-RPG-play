#include"Skill.h"


//        技能图片数量/基础伤害/消耗内力/加血/加蓝/plist文件/释放对象/图标文件名
Skill   JianYan(14, 300, -50, 0, 0, "jianyan.plist", Enemy, "JianYanJian_int.jpg");           
//建言剑，基础伤害300，耗费内力50点
Skill    ChangKong23(29, 700, -100, 0, 0, "xianglong.plist", Enemy, "changkong23_int.png");   
//长空二十三剑，基础伤害700，耗费内力100点
Skill   YuanLingGuiXin(26, 400, -80, 0, 0, "yuanling.plist", Friend, "DaXue.jpg");           
//元灵归心术，基础回复400，耗费内力80点
Skill   HanBingZhenQi(20, 200, -20, 0, 0, "xiaoyao.plist", Enemy, "HanBingZhenQi_int.jpg");      
//逍遥神剑，基础伤害600，耗费内力70点
Skill   CanYunQiangFa(7, 300, -50, 0, 0, "canyunqiangfa.plist", Enemy, "CanYunQiangFa_int.jpg");   
//残云枪法，基础伤害300，耗费内力50点
                      
Skill   WuYingLianCi(20, 250, -30, 0, 0, "wuyinglianci.plist", Enemy, "WuYingLianCi_int.png"); 
//无影连刺，基础伤害300，耗费内力30点
Skill   DaoKan(5, 150, 0, 0, 0, "daokan.plist", Enemy, "DaXue.jpg");
Skill   QianDuWanShi(11, 250, 0, 0, 0, "qianduwanshi.plist", Enemy, "DaXue.png"); 
//千毒万蚀

Skill::Skill()
{

}


Skill::Skill(int num, int changeh, int changem, int changea, int changed, string filen, SkillObject object, string intro_name)
	:fileName(filen), object(object), introductionName(intro_name)
{
	this->number = num;
	changeHealth = changeh;
	changeMagic = changem;
	changeAttack = changea;
	changeDefence = changed;
}

Skill::~Skill()
{
	string *s = &fileName;
	delete s;
}
int Skill::retHealthc()     //返回生命改变量
{
	return (changeHealth);
}
int Skill::retMagicc()        //返回内力改变量
{
	return (changeMagic);
}
int Skill::retAttackc()    //返回攻击力改变量
{
	return(changeAttack);
}
int Skill::retDefencec()    //返回防御力改变量
{
	return (changeDefence);
}
string    Skill::retFilename()  //返回动画文件名
{
	return (fileName);
}
SkillObject  Skill::retObject()  //返回技能释放目标
{
	return(object);
}
float Skill::retTime()
{
	float ret = number*0.1;      //返回技能释放的时间
	return ret;
}
string Skill::retIntroduction()
{
	return(introductionName);
}
void  Skill::skill(Node  *lay)
{
	Size VisibleSize = Director::getInstance()->getVisibleSize();
	auto player = Sprite::create();
	player->setPosition(Point(VisibleSize.width / 2 + 150, VisibleSize.height / 2 - 50));       //设置位置
	lay->addChild(player);
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile(fileName);
	Vector<SpriteFrame *> AllFrame;
	for (int i = 0; i <= number - 1; i++)
	{
		char name[128] = { 0 };
		sprintf(name, "%d.png", i);
		SpriteFrame * sf = frameCache->spriteFrameByName(name);
		AllFrame.pushBack(sf);                                                           //将图片加入vector
	}
	Animation * animation = Animation::createWithSpriteFrames(AllFrame);                 //创建动画动作
	animation->setDelayPerUnit(0.1f);                                                    //时间间隔
	Animate * act = Animate::create(animation);
	auto  Callfunc = CallFunc::create([=]() {
		player->removeFromParent();
		frameCache->removeSpriteFrames();
	});                                                                                  //最后移除技能图片
	auto  sequence = Sequence::create(act, Callfunc, NULL);
	player->runAction(sequence);
}
void Skill::enemySkill1(Node  *   lay)
{
	Size VisibleSize = Director::getInstance()->getVisibleSize();
	auto player = Sprite::create();
	player->setPosition(Vec2(175.56, 337.39));       //设置位置
	lay->addChild(player);
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile(fileName);
	Vector<SpriteFrame *> AllFrame;
	for (int i = 0; i <= number - 1; i++)
	{
		char name[128] = { 0 };
		sprintf(name, "%d.png", i);
		SpriteFrame * sf = frameCache->spriteFrameByName(name);
		AllFrame.pushBack(sf);                                                           //将图片加入vector
	}
	Animation * animation = Animation::createWithSpriteFrames(AllFrame);                 //创建动画动作
	animation->setDelayPerUnit(0.1f);                                                    //时间间隔
	Animate * act = Animate::create(animation);
	auto  Callfunc = CallFunc::create([=]() {
		player->removeFromParent();
		frameCache->removeSpriteFrames();
	});                                                                                  //最后移除技能图片
	auto  sequence = Sequence::create(act, Callfunc, NULL);
	player->runAction(sequence);
}
void Skill::enemySkill2(Node  *   lay)
{
	Size VisibleSize = Director::getInstance()->getVisibleSize();
	auto player = Sprite::create();
	player->setPosition(Vec2(289.86, 274.16));       //设置位置
	lay->addChild(player);
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile(fileName);
	Vector<SpriteFrame *> AllFrame;
	for (int i = 0; i <= number - 1; i++)
	{
		char name[128] = { 0 };
		sprintf(name, "%d.png", i);
		SpriteFrame * sf = frameCache->spriteFrameByName(name);
		AllFrame.pushBack(sf);                                                           //将图片加入vector
	}
	Animation * animation = Animation::createWithSpriteFrames(AllFrame);                 //创建动画动作
	animation->setDelayPerUnit(0.1f);                                                    //时间间隔
	Animate * act = Animate::create(animation);
	auto  Callfunc = CallFunc::create([=]() {
		player->removeFromParent();
		frameCache->removeSpriteFrames();
	});                                                                                  //最后移除技能图片
	auto  sequence = Sequence::create(act, Callfunc, NULL);
	player->runAction(sequence);
}
void Skill::enemySkill3(Node  *   lay)
{
	Size VisibleSize = Director::getInstance()->getVisibleSize();
	auto player = Sprite::create();
	player->setPosition(Vec2(180.48, 184.11));       //设置位置
	lay->addChild(player);
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile(fileName);
	Vector<SpriteFrame *> AllFrame;
	for (int i = 0; i <= number - 1; i++)
	{
		char name[128] = { 0 };
		sprintf(name, "%d.png", i);
		SpriteFrame * sf = frameCache->spriteFrameByName(name);
		AllFrame.pushBack(sf);                                                           //将图片加入vector
	}
	Animation * animation = Animation::createWithSpriteFrames(AllFrame);                 //创建动画动作
	animation->setDelayPerUnit(0.1f);                                                    //时间间隔
	Animate * act = Animate::create(animation);
	auto  Callfunc = CallFunc::create([=]() {
		player->removeFromParent();
		frameCache->removeSpriteFrames();
	});                                                                                  //最后移除技能图片
	auto  sequence = Sequence::create(act, Callfunc, NULL);
	player->runAction(sequence);
}
void Skill::enemySkill4(Node  *   lay)
{
	Size VisibleSize = Director::getInstance()->getVisibleSize();
	auto player = Sprite::create();
	player->setPosition(Vec2(289.73, 149.49));       //设置位置
	lay->addChild(player);
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile(fileName);
	Vector<SpriteFrame *> AllFrame;
	for (int i = 0; i <= number - 1; i++)
	{
		char name[128] = { 0 };
		sprintf(name, "%d.png", i);
		SpriteFrame * sf = frameCache->spriteFrameByName(name);
		AllFrame.pushBack(sf);                                                           //将图片加入vector
	}
	Animation * animation = Animation::createWithSpriteFrames(AllFrame);                 //创建动画动作
	animation->setDelayPerUnit(0.1f);                                                    //时间间隔
	Animate * act = Animate::create(animation);
	auto  Callfunc = CallFunc::create([=]() {
		player->removeFromParent();
		frameCache->removeSpriteFrames();
	});                                                                                  //最后移除技能图片
	auto  sequence = Sequence::create(act, Callfunc, NULL);
	player->runAction(sequence);
}
