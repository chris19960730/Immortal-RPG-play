#include "BattleScene.h"
#include<time.h>
#include"role.h"
#include"Dialog.h"
#include"Sequence.h"
#include"Enemy.h"
#include"Prop.h"
#include"SimpleAudioEngine.h"
#include"BaseScene.h"
#include"Count.h"
USING_NS_CC;

int winwhich = 1;

using namespace cocostudio::timeline;

Scene* BattleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = BattleScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool BattleScene::init()
{
   
	//��ȡ���˵�������
	OurEnemy * enemy = OurEnemy::Getinstance();
    if ( !Layer::init() )
    {
        return false;
    }
	//��Ӽ���
	auto seq = RoleSequence::getInstance();              //������д���
	auto rootNode = CSLoader::createNode("MainScene.csb");
	auto StateLay = CSLoader::createNode("Layer1.csb");
	rootNode->setTag(9);
	StateLay->setTag(11);                           //״̬����tag11
addChild(rootNode);
ShowAll();
Layer * BagLay = Ret_bagLayer();
BagLay->setTag(12);                             //���߽���tag12
this->addChild(BagLay);
BagLay->setVisible(false);                      //ʹ�õ��߽���
this->addChild(StateLay);
this->State_Layer();                           //ˢ�½���
for (int k = 0; k <= seq->retNumber() - 1; k++)
{
	Survive[k] = true;
}
//seq->Join(ZhugeYibin);
//��ȡ����,���ڶ����е�һ����ɫ����
Sprite * sp1 = Sprite::createWithTexture(seq->retRole(0)->retActivity().Stand_action()->getTexture());
rootNode->addChild(sp1);
sp1->setPosition(Vec2(175.56, 337.39));
sp1->setTag(5);
//���ڶ����еڶ�����ɫ������
if (seq->retNumber() >= 2)
{
	Sprite * sp2 = Sprite::createWithTexture(seq->retRole(1)->retActivity().Stand_action()->getTexture());
	sp2->setPosition(Vec2(289.86, 274.16));
	rootNode->addChild(sp2);
	sp2->setTag(6);
}
//���ڶ����е�������ɫ������
if (seq->retNumber() >= 3)
{
	Sprite * sp3 = Sprite::createWithTexture(seq->retRole(2)->retActivity().Stand_action()->getTexture());
	sp3->setPosition(Vec2(180.48, 184.11));
	sp3->setTag(7);
	rootNode->addChild(sp3);
}
//���ڶ����е��ĸ���ɫ������
if (seq->retNumber() >= 4)
{
	Sprite * sp4 = Sprite::createWithTexture(seq->retRole(3)->retActivity().Stand_action()->getTexture());
	sp4->setPosition(Vec2(289.73, 149.49));
	sp4->setTag(8);
	rootNode->addChild(sp4);
}
//���ڵ��˵�����
auto sp_enemy = enemy->retActivity().Stand_action();
rootNode->addChild(sp_enemy);
sp_enemy->setPosition(Vec2(701.05, 276.24));
//���˵ľ���tag����Ϊ25
sp_enemy->setTag(25);
//��ȡ��ť
Button * Skill_Button = (Button *)rootNode->getChildByName("skill");
Button * Prop_Button = (Button *)rootNode->getChildByName("prop");
auto lay_skill = CSLoader::createNode("Layer.csb");
//�����ܽ����tagֵ��Ϊ10
lay_skill->setTag(10);
//��ȡ���м��ܵİ�ť
Button * Skill_First_Button = (Button *)lay_skill->getChildByName("skill1");
Button * Skill_Second_Button = (Button *)lay_skill->getChildByName("skill2");
Button * Skill_Third_Button = (Button *)lay_skill->getChildByName("skill3");
//�������ص����˵�һ����ť֮���������ť
Skill_Second_Button->setVisible(false);
Skill_Third_Button->setVisible(false);
Sprite * Skillsp1 = (Sprite *)lay_skill->getChildByName("Skill1sp");
Sprite * Skillsp2 = (Sprite *)lay_skill->getChildByName("Skill2sp");
Sprite * Skillsp3 = (Sprite *)lay_skill->getChildByName("Skill3sp");
Skillsp2->setVisible(false);
Skillsp3->setVisible(false);
int skillnum = seq->retRole(run_num)->retSkillNum();
//������Ҫ��ʾ�İ�ť����
Skillsp1->setTexture(Sprite::create(seq->retRole(run_num)->retSkill(1).retIntroduction())->getTexture());
if (skillnum >= 2)
{
	Skill_Second_Button->setVisible(true);
	Skillsp2->setTexture(Sprite::create(seq->retRole(run_num)->retSkill(2).retIntroduction())->getTexture());
	Skillsp2->setVisible(true);
}
if (skillnum >= 3)
{
	Skill_Third_Button->setVisible(true);
	Skillsp3->setTexture(Sprite::create(seq->retRole(run_num)->retSkill(3).retIntroduction())->getTexture());
	Skillsp3->setVisible(true);
}
//���ð�ť�Ļص�����
Skill_First_Button->addTouchEventListener(CC_CALLBACK_2(BattleScene::Using1skill, this));
Skill_Second_Button->addTouchEventListener(CC_CALLBACK_2(BattleScene::Using2skill, this));
Skill_Third_Button->addTouchEventListener(CC_CALLBACK_2(BattleScene::Using3skill, this));
this->addChild(lay_skill);
lay_skill->setVisible(false);
//��ʹ�ü�����һ��ť���ûص��������ҽ�tagֵ�趨Ϊ15
Skill_Button->addTouchEventListener(CC_CALLBACK_2(BattleScene::UsingSkill, this));
Prop_Button->addTouchEventListener(CC_CALLBACK_2(BattleScene::UsingProp, this));
Skill_Button->setTag(15);
return true;
}
//ʹ�ü��ܵĻص�������������ѡ��ҳ�����
void BattleScene::UsingSkill(Ref * psender, ui::Widget::TouchEventType type)
{
	if (type == cocos2d::ui::Widget::TouchEventType::BEGAN)
	{
		Layer * lay_skill = (Layer *) this->getChildByTag(10);
		lay_skill->setVisible(true);
		Layer * battle_lay = (Layer *) this->getChildByTag(9);                 //����ͼ��
		Button * but = (Button *)battle_lay->getChildByTag(15);                //�ͷż��ܵİ�ť
		but->setVisible(false);                                          //�ͷ��꼼�����ظý���
		Button * but_prop = (Button *)battle_lay->getChildByName("prop");
		but_prop->setVisible(false);
	}

}
//ʹ�õ�һ������
void BattleScene::Using1skill(Ref * psender, ui::Widget::TouchEventType type)
{
	if (type == cocos2d::ui::Widget::TouchEventType::BEGAN)
	{
		srand((unsigned)time(NULL));  //��ȡʱ������
		auto enemy = OurEnemy::Getinstance();
		while (Survive[run_num] == false)
		{
			run_num++;
		}
		Layer * lay_skill = (Layer *) this->getChildByTag(10);                 //ս������ͼ��
		Layer * battle_lay = (Layer *) this->getChildByTag(9);                 //����ͼ��
		Button * but = (Button *)battle_lay->getChildByTag(15);                //�ͷż��ܵİ�ť
		lay_skill->setVisible(false);                                          //�ͷ��꼼�����ظý���
		RoleSequence * seq = RoleSequence::getInstance();                       //��õ�ǰ����
		Skill skill = (seq->retRole(run_num))->retSkill(1);                   //��ø������һ�ż���
		but->setVisible(false);                                                 //��ֹ���ܻ���ͷţ��ȵ�һ�����ܽ������øü��ܰ�ť����ʹ��
		Button * but_prop = (Button *)battle_lay->getChildByName("prop");
		but_prop->setVisible(false);                                            //ͬ�ϣ����߰�ť
		skill.skill(battle_lay);                                                //���ܶ���                                           
		Sprite * rolesp = (Sprite *)battle_lay->getChildByTag(run_num + 5);       //�ҵ���Ӧ�Ľ�ɫ���й�������
		auto  Callfunc1 = CallFunc::create([=]() {
			(seq->retRole(run_num))->retActivity().Attack_action(rolesp);

		});
		CCActionInterval * delaytime = CCDelayTime::create((seq->retRole(run_num))->retSkill(1).retTime());                  //�ͷż��ܺ�Ҫ�����ͷż��ܰ�ť��ֹ��������һ���ͷ�
		auto  Callfunc2 = CallFunc::create([=]() {
			if (Whether_End == false)
			{
				but->setVisible(true);
				but_prop->setVisible(true);
			}

		});
		auto  Callfunc3 = CallFunc::create([=]() {
			run_num++;
			if (run_num > seq->retNumber() - 1)
			{
				run_num = 0;
				if (enemy->retHealth()> 0)
				{
					BattleScene::EnemyAttack(0);
				}
			}

		});//���˹���
		Sprite * sp = (Sprite *)battle_lay->getChildByTag(20);

		auto  sequence = Sequence::create(Callfunc1, delaytime, Callfunc2, Callfunc3, NULL);
		rolesp->runAction(sequence);

		//���´��븺����ڼ��ܵĸ�������ʾ�����������ܵİ�ť��
		Button * Skill_1_Button = (Button *)lay_skill->getChildByName("skill1");
		Button * Skill_2_Button = (Button *)lay_skill->getChildByName("skill2");
		Button * Skill_3_Button = (Button *)lay_skill->getChildByName("skill3");
		Skill_2_Button->setVisible(false);
		Skill_3_Button->setVisible(false);
		int num_next = run_num;
		do
		{
			num_next++;
			if (num_next > seq->retNumber() - 1)
			{
				num_next = 0;
				while (Survive[num_next] == false)
				{
					num_next++;
				}
				if (seq->retRole(num_next)->retHealth() <= enemy->retSkill(1).retHealthc())
				{
					num_next++;
				}
				if (num_next > seq->retNumber() - 1)
				{
					num_next = 0;
					break;
				}
			}
		} while (seq->retRole(num_next)->retHealth() <= 0);
		int skillnum = seq->retRole(num_next)->retSkillNum();
		Sprite * Skillsp1 = (Sprite *)lay_skill->getChildByName("Skill1sp");
		Sprite * Skillsp2 = (Sprite *)lay_skill->getChildByName("Skill2sp");
		Sprite * Skillsp3 = (Sprite *)lay_skill->getChildByName("Skill3sp");
		Skillsp2->setVisible(false);
		Skillsp3->setVisible(false);
		Skillsp1->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(1).retIntroduction())->getTexture());
		if (skillnum >= 2)
		{
			Skill_2_Button->setVisible(true);
			Skillsp2->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(2).retIntroduction())->getTexture());
			Skillsp2->setVisible(true);
			if (skillnum >= 3)
			{
				Skill_3_Button->setVisible(true);
				Skillsp3->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(3).retIntroduction())->getTexture());
				Skillsp3->setVisible(true);
			}
		}                           //�˺�����
		int num = run_num;
		int Damage;
		Damage = DamageCal(seq->retRole(num)->retAttack() + seq->retRole(num)->retWeapon().retAttackUp(), skill.retHealthc(), enemy->retDefence());
		if (seq->retRole(num)->retMagic() >= skill.retMagicc())
		{
			seq->retRole(num)->changeMagic(skill.retMagicc());
			enemy->changeHealth(-Damage);
			if (enemy->retHealth() <= 0)
			{
				CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("win.mp3");
				auto WinLayer = CSLoader::createNode("Win" + to_string(winwhich) + ".csb");
				winwhich++;
				battle_lay->removeChildByTag(25);
				this->addChild(WinLayer);
				Button * WinButton = (Button *)WinLayer->getChildByName("Button_1");
				WinButton->addTouchEventListener(this, toucheventselector(BattleScene::PopSceneToGame));
				Button * but = (Button *)battle_lay->getChildByTag(15);                //�ͷż��ܵİ�ť
				but->removeFromParent();
				Button * but_prop = (Button *)battle_lay->getChildByName("prop");
				but_prop->removeFromParent();                                            //ͬ�ϣ����߰�ť
				Whether_End = true;
			}
		}
		this->State_Layer();                           //ˢ�½���

		auto damagetext = (Text *)(battle_lay->getChildByTag(86));
		char ch[128] = { 0 };
		sprintf(ch, "%d", Damage);
		damagetext->setString(ch);
	}
}
//֮�����ݻ���ͬ�ϣ�ֻ�ǵ��õļ���������ͬ
void BattleScene::Using2skill(Ref * psender, ui::Widget::TouchEventType type)
{
	if (type == cocos2d::ui::Widget::TouchEventType::BEGAN)
	{
		srand((unsigned)time(NULL));  //��ȡʱ������
		auto enemy = OurEnemy::Getinstance();
		while (Survive[run_num] == false)
		{
			run_num++;
		}
		Layer * lay_skill = (Layer *) this->getChildByTag(10);                 //ս������ͼ��
		Layer * battle_lay = (Layer *) this->getChildByTag(9);                 //����ͼ��
		Button * but = (Button *)battle_lay->getChildByTag(15);                //�ͷż��ܵİ�ť
		lay_skill->setVisible(false);                                          //�ͷ��꼼�����ظý���
		Button * but_prop = (Button *)battle_lay->getChildByName("prop");
		but_prop->setVisible(false);                                            //ͬ�ϣ����߰�ť
		RoleSequence * seq = RoleSequence::getInstance();                       //��õ�ǰ����
		Skill skill = (seq->retRole(run_num))->retSkill(2);                   //��ø������һ�ż���
		but->setVisible(false);                                                 //��ֹ���ܻ���ͷţ��ȵ�һ�����ܽ������øü��ܰ�ť����ʹ��
		skill.skill(battle_lay);                                                //���ܶ���                                           
		Sprite * rolesp = (Sprite *)battle_lay->getChildByTag(run_num + 5);       //�ҵ���Ӧ�Ľ�ɫ���й�������
		auto  Callfunc1 = CallFunc::create([=]() {
			(seq->retRole(run_num))->retActivity().Attack_action(rolesp);

		});
		CCActionInterval * delaytime = CCDelayTime::create((seq->retRole(run_num))->retSkill(2).retTime());                  //�ͷż��ܺ�Ҫ�����ͷż��ܰ�ť��ֹ��������һ���ͷ�
		auto  Callfunc2 = CallFunc::create([=]() {
			if (Whether_End == false)
			{
				but->setVisible(true);
				but_prop->setVisible(true);
			}

		});
		auto  Callfunc3 = CallFunc::create([=]() {
			run_num++;
			if (run_num > seq->retNumber() - 1)
			{
				run_num = 0;
				if (enemy->retHealth()> 0)
				{
					BattleScene::EnemyAttack(0);
				}
			}

		});//���˹���
		Sprite * sp = (Sprite *)battle_lay->getChildByTag(20);
		//���һ�˵��ж������Ҫ���й�������˼��ʱ��Ҫ��һЩ

		auto  sequence = Sequence::create(Callfunc1, delaytime, Callfunc2, Callfunc3, NULL);
		rolesp->runAction(sequence);

		//���´��븺����ڼ��ܵĸ�������ʾ�����������ܵİ�ť��
		Button * Skill_1_Button = (Button *)lay_skill->getChildByName("skill1");
		Button * Skill_2_Button = (Button *)lay_skill->getChildByName("skill2");
		Button * Skill_3_Button = (Button *)lay_skill->getChildByName("skill3");
		Skill_2_Button->setVisible(false);
		Skill_3_Button->setVisible(false);
		int num_next = run_num;
		do
		{
			num_next++;
			if (num_next > seq->retNumber() - 1)
			{
				num_next = 0;
				while (Survive[num_next] == false)
				{
					num_next++;
				}
				if (seq->retRole(num_next)->retHealth() <= enemy->retSkill(1).retHealthc())
				{
					num_next++;
				}
				if (num_next > seq->retNumber() - 1)
				{
					num_next = 0;
					break;
				}
			}
		} while (seq->retRole(num_next)->retHealth() <= 0);
		int skillnum = seq->retRole(num_next)->retSkillNum();
		Sprite * Skillsp1 = (Sprite *)lay_skill->getChildByName("Skill1sp");
		Sprite * Skillsp2 = (Sprite *)lay_skill->getChildByName("Skill2sp");
		Sprite * Skillsp3 = (Sprite *)lay_skill->getChildByName("Skill3sp");
		Skillsp2->setVisible(false);
		Skillsp3->setVisible(false);
		Skillsp1->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(1).retIntroduction())->getTexture());
		if (skillnum >= 2)
		{
			Skill_2_Button->setVisible(true);
			Skillsp2->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(2).retIntroduction())->getTexture());
			Skillsp2->setVisible(true);
			if (skillnum >= 3)
			{
				Skill_3_Button->setVisible(true);
				Skillsp3->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(3).retIntroduction())->getTexture());
				Skillsp3->setVisible(true);
			}
		}                   //�˺�����
		int num = run_num;
		int Damage;
		Damage = DamageCal(seq->retRole(num)->retAttack() + seq->retRole(num)->retWeapon().retAttackUp(), skill.retHealthc(), enemy->retDefence());
		if (seq->retRole(num)->retMagic() >= skill.retMagicc())
		{
			seq->retRole(num)->changeMagic(skill.retMagicc());
			enemy->changeHealth(-Damage);
			if (enemy->retHealth() <= 0)
			{
				CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("win.mp3");
				auto WinLayer = CSLoader::createNode("Win"+to_string(winwhich)+".csb");
				winwhich++;
				battle_lay->removeChildByTag(25);
				this->addChild(WinLayer);
				Button * WinButton = (Button *)WinLayer->getChildByName("Button_1");
				WinButton->addTouchEventListener(this, toucheventselector(BattleScene::PopSceneToGame));
				Button * but = (Button *)battle_lay->getChildByTag(15);                //�ͷż��ܵİ�ť
				but->removeFromParent();
				Button * but_prop = (Button *)battle_lay->getChildByName("prop");
				but_prop->removeFromParent();                                            //ͬ�ϣ����߰�ť
				Whether_End = true;
			}
		}
		this->State_Layer();                           //ˢ�½���

		auto damagetext = (Text *)(battle_lay->getChildByTag(86));
		char ch[128] = { 0 };
		sprintf(ch, "%d", Damage);
		damagetext->setString(ch);
	}
}
void BattleScene::Using3skill(Ref * psender, ui::Widget::TouchEventType type)
{
	if (type == cocos2d::ui::Widget::TouchEventType::BEGAN)
	{
		srand((unsigned)time(NULL));  //��ȡʱ������
		auto enemy = OurEnemy::Getinstance();
		while (Survive[run_num] == false)
		{
			run_num++;
		}
		Layer * lay_skill = (Layer *) this->getChildByTag(10);                 //ս������ͼ��
		Layer * battle_lay = (Layer *) this->getChildByTag(9);                 //����ͼ��
		Button * but = (Button *)battle_lay->getChildByTag(15);                //�ͷż��ܵİ�ť
		lay_skill->setVisible(false);                                          //�ͷ��꼼�����ظý���
		RoleSequence * seq = RoleSequence::getInstance();                       //��õ�ǰ����
		Skill skill = (seq->retRole(run_num))->retSkill(3);                   //��ø������һ�ż���
		but->setVisible(false);                                                 //��ֹ���ܻ���ͷţ��ȵ�һ�����ܽ������øü��ܰ�ť����ʹ��
		Button * but_prop = (Button *)battle_lay->getChildByName("prop");
		but_prop->setVisible(false);                                            //ͬ�ϣ����߰�ť
		skill.skill(battle_lay);                                                //���ܶ���                                           
		Sprite * rolesp = (Sprite *)battle_lay->getChildByTag(run_num + 5);       //�ҵ���Ӧ�Ľ�ɫ���й�������
		auto  Callfunc1 = CallFunc::create([=]() {
			(seq->retRole(run_num))->retActivity().Attack_action(rolesp);

		});
		CCActionInterval * delaytime = CCDelayTime::create((seq->retRole(run_num))->retSkill(3).retTime());                  //�ͷż��ܺ�Ҫ�����ͷż��ܰ�ť��ֹ��������һ���ͷ�
		auto  Callfunc2 = CallFunc::create([=]() {
			if (Whether_End == false)
			{
				but->setVisible(true);
				but_prop->setVisible(true);
			}

		});
		auto  Callfunc3 = CallFunc::create([=]() {
			run_num++;
			if (run_num > seq->retNumber() - 1)
			{
				run_num = 0;
				if (enemy->retHealth()> 0)
				{
					BattleScene::EnemyAttack(0);
				}
			}

		});//���˹���
		Sprite * sp = (Sprite *)battle_lay->getChildByTag(20);
		//���һ�˵��ж������Ҫ���й�������˼��ʱ��Ҫ��һЩ

		auto  sequence = Sequence::create(Callfunc1, delaytime, Callfunc2, Callfunc3, NULL);
		rolesp->runAction(sequence);
		//���´��븺����ڼ��ܵĸ�������ʾ�����������ܵİ�ť��
		Button * Skill_1_Button = (Button *)lay_skill->getChildByName("skill1");
		Button * Skill_2_Button = (Button *)lay_skill->getChildByName("skill2");
		Button * Skill_3_Button = (Button *)lay_skill->getChildByName("skill3");
		Skill_2_Button->setVisible(false);
		Skill_3_Button->setVisible(false);
		int num_next = run_num;
		do
		{
			num_next++;
			if (num_next > seq->retNumber() - 1)
			{
				num_next = 0;
				while (Survive[num_next] == false)
				{
					num_next++;
				}
				if (seq->retRole(num_next)->retHealth() <= enemy->retSkill(1).retHealthc())
				{
					num_next++;
				}
				if (num_next > seq->retNumber() - 1)
				{
					num_next = 0;
					break;
				}
			}
		} while (seq->retRole(num_next)->retHealth() <= 0);
		int skillnum = seq->retRole(num_next)->retSkillNum();
		Sprite * Skillsp1 = (Sprite *)lay_skill->getChildByName("Skill1sp");
		Sprite * Skillsp2 = (Sprite *)lay_skill->getChildByName("Skill2sp");
		Sprite * Skillsp3 = (Sprite *)lay_skill->getChildByName("Skill3sp");
		Skillsp1->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(1).retIntroduction())->getTexture());
		Skillsp2->setVisible(false);
		Skillsp3->setVisible(false);
		if (skillnum >= 2)
		{
			Skill_2_Button->setVisible(true);
			Skillsp2->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(2).retIntroduction())->getTexture());
			Skillsp2->setVisible(true);
			if (skillnum >= 3)
			{
				Skill_3_Button->setVisible(true);
				Skillsp3->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(3).retIntroduction())->getTexture());
				Skillsp3->setVisible(true);
			}
		}                            //�˺�����
		int num = run_num;
		int Damage;
		Damage = DamageCal(seq->retRole(num)->retAttack() + seq->retRole(num)->retWeapon().retAttackUp(), skill.retHealthc(), enemy->retDefence());
		if (seq->retRole(num)->retMagic() >= skill.retMagicc())
		{
			seq->retRole(num)->changeMagic(skill.retMagicc());
			enemy->changeHealth(-Damage);
			if (enemy->retHealth() <= 0)
			{
				CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("win.mp3");
				auto WinLayer = CSLoader::createNode("Win" + to_string(winwhich) + ".csb");
				winwhich++;
				battle_lay->removeChildByTag(25);
				this->addChild(WinLayer);
				Button * WinButton = (Button *)WinLayer->getChildByName("Button_1");
				WinButton->addTouchEventListener(this, toucheventselector(BattleScene::PopSceneToGame));
				Button * but = (Button *)battle_lay->getChildByTag(15);                //�ͷż��ܵİ�ť
				but->removeFromParent();
				Button * but_prop = (Button *)battle_lay->getChildByName("prop");
				but_prop->removeFromParent();                                            //ͬ�ϣ����߰�ť
				Whether_End = true;
			}
		}
		this->State_Layer();                           //ˢ�½���

		auto damagetext = (Text *)(battle_lay->getChildByTag(86));
		char ch[128] = { 0 };
		sprintf(ch, "%d", Damage);
		damagetext->setString(ch);
	}
}
void BattleScene::EnemyAttack(int num)          //����Ϊ��ǰ���е�����
{
	srand((unsigned)time(NULL));  //��ȡʱ������
	OurEnemy * enemy = OurEnemy::Getinstance();
	Layer * battle_lay = (Layer *) this->getChildByTag(9);
	Button * but = (Button *)battle_lay->getChildByTag(15);                //�ͷż��ܵİ�ť
	but->setVisible(false);
	Button * but_prop = (Button *)battle_lay->getChildByName("prop");
	but_prop->setVisible(false);                                            //ͬ�ϣ����߰�ť
	Skill skill = enemy->retSkill(1);
	Sprite * sp = (Sprite *)battle_lay->getChildByTag(25);     //��ȡ���˵�ͼ��
	auto CallFunc_Video = CallFunc::create([=]() {
		enemy->retActivity().Attack_action(sp);
		switch (object)
		{
		case 0:                 enemy->retSkill(1).enemySkill1(battle_lay); break;
		case 1:                 enemy->retSkill(1).enemySkill2(battle_lay); break;
		case 2:                 enemy->retSkill(1).enemySkill3(battle_lay); break;
		case 3:                 enemy->retSkill(1).enemySkill4(battle_lay); break;
		default:
			break;
		}
		auto Ourseq = RoleSequence::getInstance();
		if (Ourseq->retRole(object)->retHealth() <= 0)
		{
			Ourseq->retRole(object)->Health = 0;
			Sprite * sp_die = (Sprite*)battle_lay->getChildByTag(object + 5);
			sp_die->removeFromParent();
			Survive[object] = false;
			object++;
			if (object == Ourseq->retNumber())
			{
				auto FailLayer = CSLoader::createNode("Layer(1).csb");
				CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("lose.mp3");
				this->addChild(FailLayer);
				Button * button_fail = (Button *)FailLayer->getChildByName("Button_1");
				button_fail->addTouchEventListener(this , toucheventselector(BattleScene::PopSceneToMain));
				Count *pt = Count::Getinstance();
				pt->RestartNumber();
				Button * but = (Button *)battle_lay->getChildByTag(15);                //�ͷż��ܵİ�ť
				but->removeFromParent();
				Button * but_prop = (Button *)battle_lay->getChildByName("prop");
				but_prop->removeFromParent();                                            //ͬ�ϣ����߰�ť
				Whether_End = true;
			}
		}
		this->State_Layer();                           //ˢ�½���
	});
	auto  CallFunc_Visible = CallFunc::create([=]() {if (Whether_End == false) { but->setVisible(true); but_prop->setVisible(true); } });
	CCActionInterval * delaytime = CCDelayTime::create(enemy->retSkill(1).retTime());
	Sequence *seq = Sequence::create(CallFunc_Video, delaytime, CallFunc_Visible, NULL);
	auto Ourseq = RoleSequence::getInstance();
	sp->runAction(seq);
	int Damage;
	Damage = DamageCal(enemy->retAttack(), skill.retHealthc(), Ourseq->retRole(object)->retDefence());
	Ourseq->retRole(object)->changeHealth(-Damage);
}
void BattleScene::State_Layer()
{
	auto seq = RoleSequence::getInstance();         //��ȡ���е�������
	int seqnum = seq->retNumber();                 //��ȡ�����е���������
	Layer * StateLay = (Layer *)this->getChildByTag(11);
	for (int i = 1; i <= 4; i++)
	{
		Sprite * sp = (Sprite *)StateLay->getChildByTag(29 + i);
		Text  * NameLabel = (Text  *)StateLay->getChildByTag(60 + i);
		Text   * HealthLabel = (Text   *)StateLay->getChildByTag(64 + i);
		Text   * MagicLabel = (Text   *)StateLay->getChildByTag(68 + i);
		if (i > seqnum)
		{
			sp->setVisible(false);
			NameLabel->setVisible(false);
			HealthLabel->setVisible(false);
			MagicLabel->setVisible(false);
		}
		else
		{
			sp->setTexture(Sprite::create(seq->retRole(i - 1)->filename)->getTexture());
			//NameLabel->setString(seq->Ret_role(i - 1)->Name);
			char ch[128] = { 0 };
			sprintf(ch, "%d/%d", seq->retRole(i - 1)->Health, seq->retRole(i - 1)->HealthMax);
			HealthLabel->setString(ch);
			sprintf(ch, "%d/%d", seq->retRole(i - 1)->Magic, seq->retRole(i - 1)->MagicMax);
			MagicLabel->setString(ch);
		}
	}
}
void BattleScene::UsingProp(Ref * psender, ui::Widget::TouchEventType type)
{
	if (type == cocos2d::ui::Widget::TouchEventType::BEGAN)
	{
		Layer * Prop_Lay = (Layer *) this->getChildByTag(12);
		Prop_Lay->setVisible(true);
		Layer * battle_lay = (Layer *) this->getChildByTag(9);                 //����ͼ��
		Button * but = (Button *)battle_lay->getChildByTag(15);                //�ͷż��ܵİ�ť
		but->setVisible(false);                                          //�ͷ��꼼�����ظý���
		Button * but_prop = (Button *)battle_lay->getChildByName("prop");
		but_prop->setVisible(false);                                            //ͬ�ϣ����߰�ť
	}

}

bool BattleScene::exist(Prop* prop)
{
	if (prop->retPropNum() > 0)
		return true;
	else
		return false;
}

Layer* BattleScene::Ret_bagLayer()
{
	return bagLayer;
}

void BattleScene::ShowItemBtn()
{
	XLBtn = MenuItemImage::create("XiaoLanBtn.png", "XiaoLanBtn.png",
		[this](Ref*)
	{
		while (Survive[run_num] == false)
		{
			run_num++;
		}
		RoleSequence * seq = RoleSequence::getInstance();
		seq->retRole(run_num)->changeMagic(XiaoLan.retMagicUp());
		State_Layer();
		int num_next = run_num;
		run_num++;                          //���ڵ���һ���˻
		if (run_num > seq->retNumber() - 1)
		{
			run_num = 0;
			BattleScene::EnemyAttack(0);

		}

		auto enemy = OurEnemy::Getinstance();
		Layer * lay_skill = (Layer *) this->getChildByTag(10);                 //ս������ͼ��
		Button * Skill_1_Button = (Button *)lay_skill->getChildByName("skill1");
		Button * Skill_2_Button = (Button *)lay_skill->getChildByName("skill2");
		Button * Skill_3_Button = (Button *)lay_skill->getChildByName("skill3");
		Skill_2_Button->setVisible(false);
		Skill_3_Button->setVisible(false);
		do
		{
			num_next++;
			if (num_next > seq->retNumber() - 1)
			{
				num_next = 0;
				while (Survive[num_next] == false)
				{
					num_next++;
				}
				if (seq->retRole(num_next)->retHealth() <= enemy->retSkill(1).retHealthc())
				{
					num_next++;
				}
				if (num_next > seq->retNumber() - 1)
				{
					num_next = 0;
					break;
				}
			}
		} while (seq->retRole(num_next)->retHealth() <= 0);
		int skillnum = seq->retRole(num_next)->retSkillNum();
		Sprite * Skillsp1 = (Sprite *)lay_skill->getChildByName("Skill1sp");
		Sprite * Skillsp2 = (Sprite *)lay_skill->getChildByName("Skill2sp");
		Sprite * Skillsp3 = (Sprite *)lay_skill->getChildByName("Skill3sp");
		Skillsp1->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(1).retIntroduction())->getTexture());
		Skillsp2->setVisible(false);
		Skillsp3->setVisible(false);
		if (skillnum >= 2)
		{
			Skill_2_Button->setVisible(true);
			Skillsp2->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(2).retIntroduction())->getTexture());
			Skillsp2->setVisible(true);
			if (skillnum >= 3)
			{
				Skill_3_Button->setVisible(true);
				Skillsp3->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(3).retIntroduction())->getTexture());
				Skillsp3->setVisible(true);
			}
		}                            //�˺�����


		XiaoLan.changeNum(-1);
		bagLayer->removeChild(XLnum);
		ShowXLLabel();
		bagLayer->setVisible(false);
		XLBtn->setVisible(exist(&XiaoLan));
		Layer * battle_lay = (Layer *) this->getChildByTag(9);                 //����ͼ��
		Button * but = (Button *)battle_lay->getChildByTag(15);                //�ͷż��ܵİ�ť
		but->setVisible(true);                                          //�ͷ��꼼�����ظý���
		Button * but_prop = (Button *)battle_lay->getChildByName("prop");
		but_prop->setVisible(true);                                            //ͬ�ϣ����߰�ť

	});
	XLBtn->setPosition(180, 320);

	DLBtn = MenuItemImage::create("DaLanBtn.png", "DaLanBtn.png",
		[this](Ref*)
	{
		while (Survive[run_num] == false)
		{
			run_num++;
		}
		RoleSequence * seq = RoleSequence::getInstance();
		seq->retRole(run_num)->changeMagic(DaLan.retMagicUp());
		State_Layer();
		int num_next = run_num;
		run_num++;                          //���ڵ���һ���˻
		if (run_num > seq->retNumber() - 1)
		{
			run_num = 0;
			BattleScene::EnemyAttack(0);

		}
		auto enemy = OurEnemy::Getinstance();
		Layer * lay_skill = (Layer *) this->getChildByTag(10);                 //ս������ͼ��
		Button * Skill_1_Button = (Button *)lay_skill->getChildByName("skill1");
		Button * Skill_2_Button = (Button *)lay_skill->getChildByName("skill2");
		Button * Skill_3_Button = (Button *)lay_skill->getChildByName("skill3");
		Skill_2_Button->setVisible(false);
		Skill_3_Button->setVisible(false);
		do
		{
			num_next++;
			if (num_next > seq->retNumber() - 1)
			{
				num_next = 0;
				while (Survive[num_next] == false)
				{
					num_next++;
				}
				if (seq->retRole(num_next)->retHealth() <= enemy->retSkill(1).retHealthc())
				{
					num_next++;
				}
				if (num_next > seq->retNumber() - 1)
				{
					num_next = 0;
					break;
				}
			}
		} while (seq->retRole(num_next)->retHealth() <= 0);
		int skillnum = seq->retRole(num_next)->retSkillNum();
		Sprite * Skillsp1 = (Sprite *)lay_skill->getChildByName("Skill1sp");
		Sprite * Skillsp2 = (Sprite *)lay_skill->getChildByName("Skill2sp");
		Sprite * Skillsp3 = (Sprite *)lay_skill->getChildByName("Skill3sp");
		Skillsp1->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(1).retIntroduction())->getTexture());
		Skillsp2->setVisible(false);
		Skillsp3->setVisible(false);
		if (skillnum >= 2)
		{
			Skill_2_Button->setVisible(true);
			Skillsp2->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(2).retIntroduction())->getTexture());
			Skillsp2->setVisible(true);
			if (skillnum >= 3)
			{
				Skill_3_Button->setVisible(true);
				Skillsp3->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(3).retIntroduction())->getTexture());
				Skillsp3->setVisible(true);
			}
		}                            //�˺�����

		DaLan.changeNum(-1);
		bagLayer->removeChild(DLnum);
		ShowDLLabel();
		bagLayer->setVisible(false);
		DLBtn->setVisible(exist(&DaLan));
		Layer * battle_lay = (Layer *) this->getChildByTag(9);                 //����ͼ��
		Button * but = (Button *)battle_lay->getChildByTag(15);                //�ͷż��ܵİ�ť
		but->setVisible(true);                                          //�ͷ��꼼�����ظý���
		Button * but_prop = (Button *)battle_lay->getChildByName("prop");
		but_prop->setVisible(true);                                            //ͬ�ϣ����߰�ť
	});
	DLBtn->setPosition(380, 320);

	XXBtn = MenuItemImage::create("XiaoXueBtn.png", "XiaoXueBtn.png",
		[this](Ref*)
	{
		while (Survive[run_num] == false)
		{
			run_num++;
		}
		RoleSequence * seq = RoleSequence::getInstance();
		seq->retRole(run_num)->changeHealth(XiaoXue.retHealthUp());
		State_Layer();
		int num_next = run_num;
		run_num++;                          //���ڵ���һ���˻
		if (run_num > seq->retNumber() - 1)
		{
			run_num = 0;
			BattleScene::EnemyAttack(0);

		}
		auto enemy = OurEnemy::Getinstance();
		Layer * lay_skill = (Layer *) this->getChildByTag(10);                 //ս������ͼ��
		Button * Skill_1_Button = (Button *)lay_skill->getChildByName("skill1");
		Button * Skill_2_Button = (Button *)lay_skill->getChildByName("skill2");
		Button * Skill_3_Button = (Button *)lay_skill->getChildByName("skill3");
		Skill_2_Button->setVisible(false);
		Skill_3_Button->setVisible(false);
		do
		{
			num_next++;
			if (num_next > seq->retNumber() - 1)
			{
				num_next = 0;
				while (Survive[num_next] == false)
				{
					num_next++;
				}
				if (seq->retRole(num_next)->retHealth() <= enemy->retSkill(1).retHealthc())
				{
					num_next++;
				}
				if (num_next > seq->retNumber() - 1)
				{
					num_next = 0;
					break;
				}
			}
		} while (seq->retRole(num_next)->retHealth() <= 0);
		int skillnum = seq->retRole(num_next)->retSkillNum();
		Sprite * Skillsp1 = (Sprite *)lay_skill->getChildByName("Skill1sp");
		Sprite * Skillsp2 = (Sprite *)lay_skill->getChildByName("Skill2sp");
		Sprite * Skillsp3 = (Sprite *)lay_skill->getChildByName("Skill3sp");
		Skillsp1->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(1).retIntroduction())->getTexture());
		Skillsp2->setVisible(false);
		Skillsp3->setVisible(false);
		if (skillnum >= 2)
		{
			Skill_2_Button->setVisible(true);
			Skillsp2->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(2).retIntroduction())->getTexture());
			Skillsp2->setVisible(true);
			if (skillnum >= 3)
			{
				Skill_3_Button->setVisible(true);
				Skillsp3->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(3).retIntroduction())->getTexture());
				Skillsp3->setVisible(true);
			}
		}                            //�˺�����


		XiaoXue.changeNum(-1);
		bagLayer->removeChild(XXnum);
		ShowXXLabel();
		bagLayer->setVisible(false);
		XXBtn->setVisible(exist(&XiaoXue));
		Layer * battle_lay = (Layer *) this->getChildByTag(9);                 //����ͼ��
		Button * but = (Button *)battle_lay->getChildByTag(15);                //�ͷż��ܵİ�ť
		but->setVisible(true);                                          //�ͷ��꼼�����ظý���
		Button * but_prop = (Button *)battle_lay->getChildByName("prop");
		but_prop->setVisible(true);                                            //ͬ�ϣ����߰�ť
	});
	XXBtn->setPosition(580, 320);

	DXBtn = MenuItemImage::create("DaXueBtn.png", "DaXueBtn.png",
		[this](Ref*)
	{
		while (Survive[run_num] == false)
		{
			run_num++;
		}
		RoleSequence * seq = RoleSequence::getInstance();
		seq->retRole(run_num)->changeHealth(DaXue.retHealthUp());
		State_Layer();
		int num_next = run_num;
		run_num++;                          //���ڵ���һ���˻
		if (run_num > seq->retNumber() - 1)
		{
			run_num = 0;
			BattleScene::EnemyAttack(0);

		}
		auto enemy = OurEnemy::Getinstance();
		Layer * lay_skill = (Layer *) this->getChildByTag(10);                 //ս������ͼ��
		Button * Skill_1_Button = (Button *)lay_skill->getChildByName("skill1");
		Button * Skill_2_Button = (Button *)lay_skill->getChildByName("skill2");
		Button * Skill_3_Button = (Button *)lay_skill->getChildByName("skill3");
		Skill_2_Button->setVisible(false);
		Skill_3_Button->setVisible(false);
		do
		{
			num_next++;
			if (num_next > seq->retNumber() - 1)
			{
				num_next = 0;
				while (Survive[num_next] == false)
				{
					num_next++;
				}
				if (seq->retRole(num_next)->retHealth() <= enemy->retSkill(1).retHealthc())
				{
					num_next++;
				}
				if (num_next > seq->retNumber() - 1)
				{
					num_next = 0;
					break;
				}
			}
		} while (seq->retRole(num_next)->retHealth() <= 0);
		int skillnum = seq->retRole(num_next)->retSkillNum();
		Sprite * Skillsp1 = (Sprite *)lay_skill->getChildByName("Skill1sp");
		Sprite * Skillsp2 = (Sprite *)lay_skill->getChildByName("Skill2sp");
		Sprite * Skillsp3 = (Sprite *)lay_skill->getChildByName("Skill3sp");
		Skillsp1->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(1).retIntroduction())->getTexture());
		Skillsp2->setVisible(false);
		Skillsp3->setVisible(false);
		if (skillnum >= 2)
		{
			Skill_2_Button->setVisible(true);
			Skillsp2->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(2).retIntroduction())->getTexture());
			Skillsp2->setVisible(true);
			if (skillnum >= 3)
			{
				Skill_3_Button->setVisible(true);
				Skillsp3->setTexture(Sprite::create(seq->retRole(num_next)->retSkill(3).retIntroduction())->getTexture());
				Skillsp3->setVisible(true);
			}
		}                            //�˺�����

		DaXue.changeNum(-1);
		bagLayer->removeChild(DXnum);
		ShowDXLabel();
		bagLayer->setVisible(false);
		DXBtn->setVisible(exist(&DaXue));
		Layer * battle_lay = (Layer *) this->getChildByTag(9);                 //����ͼ��
		Button * but = (Button *)battle_lay->getChildByTag(15);                //�ͷż��ܵİ�ť
		but->setVisible(true);                                          //�ͷ��꼼�����ظý���
		Button * but_prop = (Button *)battle_lay->getChildByName("prop");
		but_prop->setVisible(true);                                            //ͬ�ϣ����߰�ť
	});
	DXBtn->setPosition(780, 320);

	XLBtn->setVisible(exist(&XiaoLan));
	DLBtn->setVisible(exist(&DaLan));
	XXBtn->setVisible(exist(&XiaoXue));
	DXBtn->setVisible(exist(&DaXue));

	bagmenu = Menu::create(XXBtn, XLBtn, DXBtn, DLBtn, NULL);
	bagmenu->setPosition(0, 0);
	bagLayer->addChild(bagmenu);
}

void BattleScene::ShowLayer()
{
	bagLayer = Layer::create();
	background = Sprite::create("BattleBag.jpg");
	background->setPosition(480, 320);
	bagLayer->addChild(background);
}
void BattleScene::ShowXLLabel()
{
	XLnum = Label::create(to_string(XiaoLan.retPropNum()), "Arial", 30);
	bagLayer->addChild(XLnum);
	XLnum->setAnchorPoint(Vec2(0, 0));
	XLnum->setPosition(Vec2(130, 270));
}

void BattleScene::ShowDLLabel()
{
	DLnum = Label::create(to_string(DaLan.retPropNum()), "Arial", 30);
	bagLayer->addChild(DLnum);
	DLnum->setAnchorPoint(Vec2(0, 0));
	DLnum->setPosition(Vec2(330, 270));
}

void BattleScene::ShowXXLabel()
{
	XXnum = Label::create(to_string(XiaoXue.retPropNum()), "Arial", 30);
	bagLayer->addChild(XXnum);
	XXnum->setAnchorPoint(Vec2(0, 0));
	XXnum->setPosition(Vec2(530, 270));
}

void BattleScene::ShowDXLabel()
{
	DXnum = Label::create(to_string(DaXue.retPropNum()), "Arial", 30);
	bagLayer->addChild(DXnum);
	DXnum->setAnchorPoint(Vec2(0, 0));
	DXnum->setPosition(Vec2(730, 270));
}

void BattleScene::ShowAll()
{
	this->ShowLayer();
	this->ShowItemBtn();
	this->ShowDLLabel();
	this->ShowDXLabel();
	this->ShowXLLabel();
	this->ShowXXLabel();
}

int BattleScene::DamageCal(int AttackValue, int BasicValue, int DeffenceValue)
{
	int DamageValue;
	DamageValue = (float)AttackValue / 80 * (float)BasicValue / ((float)DeffenceValue / 80);
	int a, b;
	a = DamageValue*0.95;
	b = DamageValue*1.05;
	//srand((unsigned)time(NULL));
	return (rand() % (b - a + 1)) + a;
}

void BattleScene::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	if (Count::Getinstance()->retNumber() < 10)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("battlemusic.mp3");
	}
	else
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("last.mp3");
	}
}
void  BattleScene::PopSceneToMain(Ref * psender, TouchEventType Type)
{
	switch (Type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
	{
		Director::getInstance()->replaceScene(BaseScene::createScene());
		break;
	}
	}
}
void  BattleScene::PopSceneToGame(Ref * psender, TouchEventType  Type)
{
	switch (Type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
	{
		Director::getInstance()->popScene();
		break;
	}
	}
}

	