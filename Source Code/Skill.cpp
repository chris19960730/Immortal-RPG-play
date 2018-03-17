#include"Skill.h"


//        ����ͼƬ����/�����˺�/��������/��Ѫ/����/plist�ļ�/�ͷŶ���/ͼ���ļ���
Skill   JianYan(14, 300, -50, 0, 0, "jianyan.plist", Enemy, "JianYanJian_int.jpg");           
//���Խ��������˺�300���ķ�����50��
Skill    ChangKong23(29, 700, -100, 0, 0, "xianglong.plist", Enemy, "changkong23_int.png");   
//���ն�ʮ�����������˺�700���ķ�����100��
Skill   YuanLingGuiXin(26, 400, -80, 0, 0, "yuanling.plist", Friend, "DaXue.jpg");           
//Ԫ��������������ظ�400���ķ�����80��
Skill   HanBingZhenQi(20, 200, -20, 0, 0, "xiaoyao.plist", Enemy, "HanBingZhenQi_int.jpg");      
//��ң�񽣣������˺�600���ķ�����70��
Skill   CanYunQiangFa(7, 300, -50, 0, 0, "canyunqiangfa.plist", Enemy, "CanYunQiangFa_int.jpg");   
//����ǹ���������˺�300���ķ�����50��
                      
Skill   WuYingLianCi(20, 250, -30, 0, 0, "wuyinglianci.plist", Enemy, "WuYingLianCi_int.png"); 
//��Ӱ���̣������˺�300���ķ�����30��
Skill   DaoKan(5, 150, 0, 0, 0, "daokan.plist", Enemy, "DaXue.jpg");
Skill   QianDuWanShi(11, 250, 0, 0, 0, "qianduwanshi.plist", Enemy, "DaXue.png"); 
//ǧ����ʴ

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
int Skill::retHealthc()     //���������ı���
{
	return (changeHealth);
}
int Skill::retMagicc()        //���������ı���
{
	return (changeMagic);
}
int Skill::retAttackc()    //���ع������ı���
{
	return(changeAttack);
}
int Skill::retDefencec()    //���ط������ı���
{
	return (changeDefence);
}
string    Skill::retFilename()  //���ض����ļ���
{
	return (fileName);
}
SkillObject  Skill::retObject()  //���ؼ����ͷ�Ŀ��
{
	return(object);
}
float Skill::retTime()
{
	float ret = number*0.1;      //���ؼ����ͷŵ�ʱ��
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
	player->setPosition(Point(VisibleSize.width / 2 + 150, VisibleSize.height / 2 - 50));       //����λ��
	lay->addChild(player);
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile(fileName);
	Vector<SpriteFrame *> AllFrame;
	for (int i = 0; i <= number - 1; i++)
	{
		char name[128] = { 0 };
		sprintf(name, "%d.png", i);
		SpriteFrame * sf = frameCache->spriteFrameByName(name);
		AllFrame.pushBack(sf);                                                           //��ͼƬ����vector
	}
	Animation * animation = Animation::createWithSpriteFrames(AllFrame);                 //������������
	animation->setDelayPerUnit(0.1f);                                                    //ʱ����
	Animate * act = Animate::create(animation);
	auto  Callfunc = CallFunc::create([=]() {
		player->removeFromParent();
		frameCache->removeSpriteFrames();
	});                                                                                  //����Ƴ�����ͼƬ
	auto  sequence = Sequence::create(act, Callfunc, NULL);
	player->runAction(sequence);
}
void Skill::enemySkill1(Node  *   lay)
{
	Size VisibleSize = Director::getInstance()->getVisibleSize();
	auto player = Sprite::create();
	player->setPosition(Vec2(175.56, 337.39));       //����λ��
	lay->addChild(player);
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile(fileName);
	Vector<SpriteFrame *> AllFrame;
	for (int i = 0; i <= number - 1; i++)
	{
		char name[128] = { 0 };
		sprintf(name, "%d.png", i);
		SpriteFrame * sf = frameCache->spriteFrameByName(name);
		AllFrame.pushBack(sf);                                                           //��ͼƬ����vector
	}
	Animation * animation = Animation::createWithSpriteFrames(AllFrame);                 //������������
	animation->setDelayPerUnit(0.1f);                                                    //ʱ����
	Animate * act = Animate::create(animation);
	auto  Callfunc = CallFunc::create([=]() {
		player->removeFromParent();
		frameCache->removeSpriteFrames();
	});                                                                                  //����Ƴ�����ͼƬ
	auto  sequence = Sequence::create(act, Callfunc, NULL);
	player->runAction(sequence);
}
void Skill::enemySkill2(Node  *   lay)
{
	Size VisibleSize = Director::getInstance()->getVisibleSize();
	auto player = Sprite::create();
	player->setPosition(Vec2(289.86, 274.16));       //����λ��
	lay->addChild(player);
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile(fileName);
	Vector<SpriteFrame *> AllFrame;
	for (int i = 0; i <= number - 1; i++)
	{
		char name[128] = { 0 };
		sprintf(name, "%d.png", i);
		SpriteFrame * sf = frameCache->spriteFrameByName(name);
		AllFrame.pushBack(sf);                                                           //��ͼƬ����vector
	}
	Animation * animation = Animation::createWithSpriteFrames(AllFrame);                 //������������
	animation->setDelayPerUnit(0.1f);                                                    //ʱ����
	Animate * act = Animate::create(animation);
	auto  Callfunc = CallFunc::create([=]() {
		player->removeFromParent();
		frameCache->removeSpriteFrames();
	});                                                                                  //����Ƴ�����ͼƬ
	auto  sequence = Sequence::create(act, Callfunc, NULL);
	player->runAction(sequence);
}
void Skill::enemySkill3(Node  *   lay)
{
	Size VisibleSize = Director::getInstance()->getVisibleSize();
	auto player = Sprite::create();
	player->setPosition(Vec2(180.48, 184.11));       //����λ��
	lay->addChild(player);
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile(fileName);
	Vector<SpriteFrame *> AllFrame;
	for (int i = 0; i <= number - 1; i++)
	{
		char name[128] = { 0 };
		sprintf(name, "%d.png", i);
		SpriteFrame * sf = frameCache->spriteFrameByName(name);
		AllFrame.pushBack(sf);                                                           //��ͼƬ����vector
	}
	Animation * animation = Animation::createWithSpriteFrames(AllFrame);                 //������������
	animation->setDelayPerUnit(0.1f);                                                    //ʱ����
	Animate * act = Animate::create(animation);
	auto  Callfunc = CallFunc::create([=]() {
		player->removeFromParent();
		frameCache->removeSpriteFrames();
	});                                                                                  //����Ƴ�����ͼƬ
	auto  sequence = Sequence::create(act, Callfunc, NULL);
	player->runAction(sequence);
}
void Skill::enemySkill4(Node  *   lay)
{
	Size VisibleSize = Director::getInstance()->getVisibleSize();
	auto player = Sprite::create();
	player->setPosition(Vec2(289.73, 149.49));       //����λ��
	lay->addChild(player);
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile(fileName);
	Vector<SpriteFrame *> AllFrame;
	for (int i = 0; i <= number - 1; i++)
	{
		char name[128] = { 0 };
		sprintf(name, "%d.png", i);
		SpriteFrame * sf = frameCache->spriteFrameByName(name);
		AllFrame.pushBack(sf);                                                           //��ͼƬ����vector
	}
	Animation * animation = Animation::createWithSpriteFrames(AllFrame);                 //������������
	animation->setDelayPerUnit(0.1f);                                                    //ʱ����
	Animate * act = Animate::create(animation);
	auto  Callfunc = CallFunc::create([=]() {
		player->removeFromParent();
		frameCache->removeSpriteFrames();
	});                                                                                  //����Ƴ�����ͼƬ
	auto  sequence = Sequence::create(act, Callfunc, NULL);
	player->runAction(sequence);
}
