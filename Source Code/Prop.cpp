#include"Prop.h"

//           道具名    hp   mp 数量 价格  图标文件名      信息文件名          效果文件名
Prop XiaoLan("蓝色药水", 0, 100, 0, 0, "XiaoLan.jpg", "XiaoLanInformation.png","mp+100.png");
Prop DaLan("活力神水", 0, 400, 0, 0, "DaLan.jpg", "DaLanInformation.png","mp+500.png");
Prop XiaoXue("红色药水", 100, 0, 0, 0, "XiaoXue.jpg", "XiaoXueInformation.png","hp+100.png");
Prop DaXue("白色药水", 400, 0, 0, 0, "DaXue.jpg", "DaXueInformation.png","hp+500.png");
PropBag Propbag;

void Prop::bindEffectAction(Layer* scene)
{
	effect = Sprite::create(effectfile);
	scene->addChild(effect,100);
	effect->setVisible(false);
	effect->setPosition(480, 320);
}

string Prop::retFilename()
{
	return Filename;
}

void Prop::bindLabel()
{
	propLabel = Label::create(to_string(Prop_num), "Arial", 30);
}

Prop::Prop(string name, int health_up, int magic_up,
	int prop_num, int prop_price, string filename,string infile, string _effectfile)
{
	Name = name;
	Filename = filename;
	Health_up = health_up;
	Magic_up = magic_up;
	Prop_num = prop_num;
	Prop_price = prop_price;
	//Information = Sprite::create("bag.jpg");
	//Information->setVisible(false);
	informationFile = infile;
	effectfile = _effectfile;
	effect = NULL;
}

void Prop::bindInformation()
{
	Information = Sprite::create(informationFile);
	Information->setVisible(false);
	Information->setPosition(185, 405);
}

Prop::Prop()
{}

Label* Prop::getLabel()
{
	return propLabel;
}

string Prop::retName()
{
	return Name;
}

int Prop::retHealthUp()
{
	return Health_up;
}

int Prop::retMagicUp()
{
	return Magic_up;
}

int Prop::retPropNum()
{
	return Prop_num;
}
Sprite * Prop::retSurrender()
{
	Sprite * surrender = Sprite::create(Filename);
	return surrender;
}

void Prop::changeNum(int num)
{
	this->Prop_num += num;
}

int Prop::retPrice()
{
	return Prop_price;
}

//------------------------------------------------------------------------------------\\
\\------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------\\
\\------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------\\
\\------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------\\
\\------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------\\
\\------------------------------------------------------------------------------------//


void PropBag::bindAllLabel()
{
	for (int i = 0; i < P.size(); i++)
	{
		P[i]->bindLabel();
	}
}

PropBag::PropBag()
{
	//Propbag.bindAllLabel();
	Money = 200;
	Propbag.pushProp(&XiaoLan, 6);
	Propbag.pushProp(&DaLan, 0);
	Propbag.pushProp(&XiaoXue, 1);
	Propbag.pushProp(&DaXue, 1);
	_refresh = false;
}

bool PropBag::changeProp(string propName, int num)
{
	for (int i = 0; i < P.size(); i++)
	{
		if (P[i]->Name == propName)
		{
			if (P[i]->Prop_num + num < 0)
				return false;
			P[i]->Prop_num += num;
			if (P[i]->Prop_num == 0)
				_refresh = true;
			return true;
		}
	}
	return false;
}


PropBag::PropBag(int money)
{
	Money = money;
	Propbag.pushProp(&XiaoLan, 0);
	Propbag.pushProp(&DaLan, 0);
	Propbag.pushProp(&XiaoXue, 0);
	Propbag.pushProp(&DaXue, 0);
}


void PropBag::useProp(Prop * prop)
{
	if (prop->Prop_num > 0)
	{
		vector<Prop* >::iterator it = P.begin();
		while ((*it)->Name != prop->Name)
		{
			it++;
		}
		prop->Prop_num--;
		if (prop->Prop_num == 0)
		{
			P.erase(it);
		}
	}
}

//使用时候触发的效果
void PropBag::useProp(int i)
{
	vector<Prop*>::iterator it = P.begin();
	if (P[i]->Prop_num > 0)
	{
		for (int j = 0; j <= i; j++)
		{
			it++;
		}
		P[i]->Prop_num--;
		//P[i].second->release();
		//P[i].second = Label::create(to_string(P[i].first->Prop_num), "Arial", 10);
		if (P[i]->Prop_num == 0)
		{
			P.erase(it);
		}
	}
}

Prop* PropBag::retProp(int num)
{
	int count = 0;
	for (int i = 0; i < P.size(); i++)
	{
		if (P[i]->retPropNum()>0)
		{
			if (count == num)
			{
				return P[i];
			}
			count++;
		}
	}
	return NULL;
}

void PropBag::pushProp(Prop* prop, int number)
{
	prop->Prop_num = number;
	P.push_back(prop);
}

void PropBag::changeMoney(int num)
{
	Money += num;
}

int PropBag::retMoney()
{
	return Money;
}

int PropBag::searchProp(Prop* prop)
{
	int count = 0;
	for (int i = 0; i < P.size(); i++)
	{
		if (P[i]->retPropNum()>0)
		{
			if (P[i] == prop)
				return count;
			count++;
		}
	}
	return -1;
}

