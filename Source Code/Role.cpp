#include"role.h"


#define hpmpSize 30
#define qualitySize 30
//                                 职业      姓名        图标文件           动作            头像文件
Role * Nan1 = Role::createNewRole(swordsman, "诸葛弈斌", "zhugeyibin.png", ZhugeYibin_act, "nan1head.png");
Role * Nan2 = Role::createNewRole(accompanist, "高嵽嵲", "nan2head.png", GaoDieNie_act, "nan2head.png");
Role * Nv1 = Role::createNewRole(assassin, "陶凌苑", "taolingyuan.jpg", TaoLingyuan_act, "nv1head.png");
Role * Nv2 = Role::createNewRole(ranger, "陶凌苑", "taolingyuan.jpg", TaoLingyuan_act, "nv2head.png");

Role * Dahan = Role::createNewRole(accompanist, "大汉", "gaodieniesurrender.png", DaHan_act,"");
Role* NiuYao = Role::createNewRole(accompanist, "牛妖", "gaodieniesurrender.png", NiuYao_act, "");
Role * GuShe = Role::createNewRole(accompanist, "骨蛇", "gaodieniesurrender.png", GuShe_act,"");
Role * JiaFei = Role::createNewRole(accompanist, "贾飞", "gaodieniesurrender.png", JiaFei_act,"");


void Role::removeAll(Sprite* scene)
{
	scene->removeChild(hpLabel, true);
	scene->removeChild(mpLabel, true);
	scene->removeChild(attackLabel, true);
	scene->removeChild(defenceLabel, true);
	scene->removeChild(weapromSprite, true);
	scene->removeChild(armorsSprite, true);
	scene->removeChild(headSprite, true);
	scene->removeChild(expLabel, true);
	scene->removeChild(levelLabel, true);
}

void Role::addAllTo(Sprite* scene)
{
	removeAll(scene);
	hpLabel = Label::create(to_string(Health) + "/" + to_string(HealthMax), "Arial", hpmpSize);
	mpLabel = Label::create(to_string(Magic) + "/" + to_string(MagicMax), "Arial", hpmpSize);
	hpLabel->setPosition(280, 490);
	mpLabel->setPosition(280, 445);

	attackLabel = Label::create(to_string(Attack) + "+" + to_string(My_Weapon.retAttackUp()+My_Armors.retAttackUp()), "Arial", qualitySize);
	defenceLabel = Label::create(to_string(Defence) + "+" + to_string(My_Armors.retDefenceUp()+My_Weapon.retDefenceUp()), "Arial", qualitySize);
	attackLabel->setAnchorPoint(Vec2(0, 0.5));
	defenceLabel->setAnchorPoint(Vec2(0, 0.5));
	attackLabel->setPosition(140, 333);
	defenceLabel->setPosition(140, 275);
	attackLabel->setColor(Color3B(0, 0, 0));
	defenceLabel->setColor(Color3B(0, 0, 0));

	weapromSprite = Sprite::create(My_Weapon.retFilename());
	armorsSprite = Sprite::create(My_Armors.retFilename());
	weapromSprite->setPosition(100, 130);
	armorsSprite->setPosition(300, 130);

	headSprite = Sprite::create(headFile);
	headSprite->setPosition(70, 460);

	string a[10] = { "10","50","150","300","500","750","1100","1800","2400","max" };
	expLabel = Label::create(to_string(Exp) + "/" + a[Level-1], "Arial", 30);
	expLabel->setAnchorPoint(Vec2(0, 0.5));
	expLabel->setPosition(165, 38);
	expLabel->setColor(Color3B(0, 0, 0));


	levelLabel = Label::create(to_string(Level), "Arial", 30);
	levelLabel->setAnchorPoint(Vec2(0, 0.5));
	levelLabel->setPosition(232, 389);
	levelLabel->setColor(Color3B(0, 0, 0));

	//人物没有出现就隐藏人物按钮，跟着剧情再显示(解决方案：按钮自带一个bool?)
	//每次点人物信息按钮，都重新刷新图层信息：hp、mp、攻击、防御、所佩戴的武器、防具
	//所有的子节点都添加在roledataLayer上
	//按钮的回调函数、图片保持不变，与roledataLayer相互独立开
	//这里应该先设置一下位置
	//下面的函数记得加Tag

	scene->addChild(hpLabel, 5);
	scene->addChild(mpLabel, 5);
	scene->addChild(attackLabel, 5);
	scene->addChild(defenceLabel, 5);
	scene->addChild(weapromSprite, 5);
	scene->addChild(armorsSprite, 5);
	scene->addChild(headSprite, 5);
	scene->addChild(expLabel, 5);
	scene->addChild(levelLabel, 5);
}


Role::Role()
{
}

void Role::useProp(Prop* prop)
{
	changeHealth(prop->retHealthUp());
	changeMagic(prop->retMagicUp());
}

//构造函数
Role::Role(int level, int xp, string name, int health, int healthm, int magic, int magicm, int attack, int defence,
	int healthup, int magicup, int attackup, int defenceup, Job MyJob, string filename, Activity act, int skill_num, Weapon myweapon, Armors myarmors, string headfile)
	:Name(name), myActivity(act.a_filename, act.num, act.s_filename), My_Weapon(myweapon), My_Armors(myarmors)
{
	skillnum = skill_num;
	Level = level;
	Exp = xp;
	Health = health;
	HealthMax = healthm;
	Magic = magic;
	MagicMax = magicm;
	Attack = attack;
	Defence = defence;
	HealthUp = healthup;
	MagicUp = magicup;
	AttackUp = attackup;
	DefenceUp = defenceup;
	this->MyJob = MyJob;
	this->filename = filename;
	headFile = headfile;
}
//析构函数
Role::~Role()
{
}
//返回各项参数的函数
int  Role::retLevel()
{
	return  Level;
}
int Role::retExp()
{
	return Exp;
}
string Role::retName()
{
	return Name;
}
int Role::retHealth()
{
	return Health;
}
int Role::retHealthmax()
{
	return HealthMax;
}
int Role::retMagic()
{
	return Magic;
}
int Role::retMagicmax()
{
	return MagicMax;
}
int Role::retAttack()
{
	return Attack;
}
int Role::retDefence()
{
	return  Defence;
}
int Role::retHealthup()
{
	return HealthUp;
}
int Role::retMagicup()
{
	return MagicUp;
}
int Role::retDefenceup()
{
	return  DefenceUp;
}
int Role::retAttackup()
{
	return AttackUp;
}
int Role::retSkillNum()
{
	return (skillnum);
}
Activity Role::retActivity()
{
	return (myActivity);
}
Weapon Role::retWeapon()
{
	return (My_Weapon);
}
Armors Role::retArmors()
{
	return (My_Armors);
}
//等级提升函数
void Role::Level_Up()
{
	Level++;
	HealthMax += HealthUp;
	Health = HealthMax;
	MagicMax += MagicUp;
	Magic = MagicMax;
	Attack += AttackUp;
	Defence += DefenceUp;

}
//获取经验值函数
void Role::getExp(int addXp)
{
	int nowlevel;          //加上经验之后的当前等级
	Exp += addXp;           //经验值增加
						   //获取当前等级
	if (Exp >= 2400)
	{
		nowlevel = 10;
		//Level = 10;
	}
	else if (Exp >= 1800)
	{
		nowlevel = 9;
		//Level = 9;
	}
	else if (Exp >= 1100)
	{
		nowlevel = 8;
		//Level = 8;
	}
	else if (Exp >= 750)
	{
		nowlevel = 7;
		//Level = 7;
	}
	else if (Exp >= 500)
	{
		nowlevel = 6;
		//Level = 6;
	}
	else if (Exp >= 300)
	{
		nowlevel = 5;
		//Level = 5;
	}
	else if (Exp >= 150)
	{
		nowlevel = 4;
		//Level = 4;
	}
	else if (Exp >= 50)
	{
		nowlevel = 3;
		//Level = 3;
	}
	else if (Exp >= 10)
	{
		nowlevel = 2;
		//Level = 2;
	}
	//升级处理
	if (nowlevel > Level)
	{
		for (; Level < nowlevel; )
		{
			Level_Up();
		}
	}
}
//气血，内力，攻击，韧性的改变
void Role::changeAttack(int change)
{
	Attack += change;
}
void Role::changeDefence(int change)
{
	Defence += change;
}
void Role::changeHealth(int change)
{
	Health += change;
	if (Health > HealthMax)
		Health = HealthMax;
}
void Role::changeMagic(int change)
{
	Magic += change;
	if (Magic > MagicMax)
		Magic = MagicMax;
}
void Role::copyf(Role rolec)
{
	Level = rolec.retLevel();
	Exp = rolec.retExp();
	Name = rolec.retName();
	Health = rolec.retHealth();
	HealthMax = rolec.retHealthmax();
	Magic = rolec.retMagic();
	MagicMax = rolec.retMagicmax();
	Attack = rolec.retAttack();
	Defence = rolec.retDefence();
	HealthUp = rolec.retHealthup();
	MagicUp = rolec.retMagicup();
	AttackUp = rolec.retAttackup();
	DefenceUp = rolec.retDefenceup();
	MyJob = rolec.retJob();
}
//重载等号的运算符
bool  Role::changeWeapon(Weapon myweapon)
{
	this->My_Weapon = myweapon;
	return (true);
}
bool Role::changeArmors(Armors myarmors)
{
	if ((this->MyJob == swordsman&&myarmors.retArmorstype() == hero1) || (this->MyJob == assassin&&myarmors.retArmorstype() == heroine1) || (this->MyJob == accompanist&&myarmors.retArmorstype() == hero2) || (this->MyJob == ranger&&myarmors.retArmorstype() == heroine2))
	{
		this->My_Armors = myarmors;
		return (true);
	}
	return (false);
}
void Role::operator=(const Role role)

{
	this->copyf(role);

}
void Role::setValue(int healthm, int magicm, int attack, int defence,
	int healthup, int magicup, int attackup, int defenceup)                        //设置属性
{
	this->HealthMax = healthm;
	this->Health = healthm;
	this->HealthUp = healthup;
	this->MagicMax = magicm;
	this->MagicUp = magicup;
	this->Magic = magicm;
	this->Attack = attack;
	this->Defence = defence;
	this->AttackUp = attackup;
	this->DefenceUp = defenceup;
}

Role * Role::createNewRole(Job ItsJob, string ItsName, string filename, Activity act, string headfile)       //创建一个新的角色
{

	Role *role;
	role = new Role(1, 0, ItsName, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ItsJob, filename, act, 0, TieJian, JinPao,headfile);
	switch (ItsJob)
	{
	case swordsman:           role->setValue(500, 500, 100, 80, 50, 50, 20, 20);
		break;
	case assassin:            role->setValue(450, 450, 120, 55, 40, 40, 30, 15);  role->changeWeapon(EMeiCi); role->changeArmors(NiChangYuYi);
		break;
	case accompanist:         role->setValue(600, 600, 70, 110, 70, 70, 15, 25); role->changeWeapon(TiLu); role->changeArmors(HuangJinJia);
		break;
	case ranger:              role->setValue(400, 600, 120, 50, 40, 50, 25, 15); role->changeWeapon(DiaoHuaQin); role->changeArmors(JiangNanJinYi);
		break;
	default:
		break;
	}

	return(role);

}

enum Job Role::retJob()
{
	return(this->MyJob);
}
string  Role::retFilename()
{
	return(filename);
}
void Role::addSkill(Skill askill)
{
	vec.push_back(askill);
	skillnum++;
}
void Role::popSkill()
{
	vec.pop_back();
	skillnum--;
}
Skill Role::retSkill(int num)
{
	if (num <= skillnum)
	{
		return (vec[num - 1]);
	}
}