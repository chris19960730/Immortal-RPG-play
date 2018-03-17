#include"RoleSkill.h"
USING_NS_CC;
using namespace std;

void RoleSkill::init(Layer* scene)
{
	string roleBtnFile[4] = { "skillbtn1.png","skillbtn2.png" ,"skillbtn3.png" ,"skillbtn4.png" };
	string roleBtnEndFile[4] = { "skillbtnend.png","skillbtnend.png" ,
		"skillbtnend.png" ,"skillbtnend.png" };
	this->bindSkillBtn(roleBtnFile, roleBtnEndFile);
	string roleLayerFile = "roleskill.jpg";
	string roleSkillFile[4][4] = { "skill1.1.png","skill1.2.png" ,"skill1.3.png" ,"skill1.4.png" ,
		"skill2.1.png","skill2.2.png" ,"skill2.3.png" ,"skill2.4.png"  ,
		"skill3.1.png","skill3.2.png" ,"skill3.3.png" ,"skill3.4.png"  ,
		"skill4.1.png","skill4.2.png" ,"skill4.3.png" ,"skill4.4.png" };
	string headFile[4] = { "head1.png","head2.png" ,"head3.png" ,"head4.png" };
	this->bindSprite(roleLayerFile, (string**)roleSkillFile, headFile);
	//°ó¶¨Í¼²ã¡¢°´Å¥
	this->addBtnTo(scene, 4);
	this->addLayerTo(scene, 2);
	this->setSkillLayerPosition(480, 320);
	this->showSkillLayer(false);
}

RoleSkill::RoleSkill()
{
	layer = NULL;
	for (int i = 0; i < 4; i++)
	{
		head[i] = NULL;
		skillBtn[i] = NULL;
		for (int j = 0; j < 4; j++)
		{
			skill[i][j] = NULL;
		}
	}
	closeBtn = NULL;
}

void RoleSkill::bindSprite(string file,string** skillfile,string* headfile)
{
	layer = Sprite::create(file);
	for (int i = 0; i < 4; i++)
	{
		head[i] = Sprite::create(headfile[i]);
		for (int j = 0; j < 4; j++)
		{
			if (*((string*)skillfile + 4 * i + j)!="")
				skill[i][j] = Sprite::create(*((string*)skillfile+4*i+j));
		}
	}
}

void RoleSkill::bindSkillBtn(string* begin, string* end)
{
	skillBtn[0] = MenuItemImage::create(begin[0], end[0], 
		[this](Ref*) {this->showLayer(0); });
	skillBtn[1] = MenuItemImage::create(begin[1], end[1],
		[this](Ref*) {this->showLayer(1); });
	skillBtn[2] = MenuItemImage::create(begin[2], end[2], 
		[this](Ref*) {this->showLayer(2); });
	skillBtn[3] = MenuItemImage::create(begin[3], end[3],
		[this](Ref*) {this->showLayer(3); });
}

void RoleSkill::bindBtn()
{
	skillMenu = Menu::create(skillBtn[0], skillBtn[1], skillBtn[2], skillBtn[3],closeBtn, NULL);
}

void RoleSkill::showLayer(int num)
{
	for (int i = 0; i < 4; i++)
	{
		bool _bset;
		if (i == num)
			_bset = true;
		else
			_bset = false;
		head[i]->setVisible(_bset);
		for (int j = 0; j < 4; j++)
		{
			skill[i][j]->setVisible(_bset);
		}
	}
}

void RoleSkill::showSkillLayer(bool bset)
{
	if (bset)
	{
		showLayer(0);
		layer->setVisible(true);
		skillMenu->setVisible(true);
		_layerIsVisible = true;
	}
	else
	{
		skillMenu->setVisible(false);
		layer->setVisible(false);
		for (int i = 0; i < 4; i++)
		{
			head[i]->setVisible(false);
			for (int j = 0; j < 4; j++)
			{
				skill[i][j]->setVisible(false);
			}
		}
		_layerIsVisible = false;
	}
}

bool RoleSkill::layerIsVisible()
{
	return _layerIsVisible;
}

void RoleSkill::addBtnTo(Layer* scene, int tag)
{
	//scene->addChild(closeBtn, tag );
	bindBtn();
	scene->addChild(skillMenu, tag);
	skillMenu->setPosition(0, 0);
}

void RoleSkill::addLayerTo(Layer* scene, int tag)
{
	scene->addChild(layer, tag);
	for (int i = 0; i < 4; i++)
	{
		scene->addChild(head[i], tag + 1);
		for (int j = 0; j < 4; j++)
		{
			scene->addChild(skill[i][j], tag + 1);
		}
	}
}

void RoleSkill::rebindSkill(int numi,int numj,string file)
{
	skill[numi][numj] = Sprite::create(file);
}

void RoleSkill::setSkillLayerPosition(int x, int y)
{
	//°ó¶¨Í¼²ã£¬ÉèÖÃÍ¼²ãÎ»ÖÃ
	layer->setPosition(x, y);
	for (int i = 0; i < 4; i++)
	{
		skill[i][0]->setPosition(x - 50, y + 70);
		skill[i][1]->setPosition(x + 145, y + 70);
		skill[i][2]->setPosition(x - 50, y - 90);
		skill[i][3]->setPosition(x + 145, y - 90);
		head[i]->setPosition(x - 230, y);
		skillBtn[i]->setPosition(x - 300 + 75 + i * 150, y + 200 - 15);
		closeBtn->setPosition(x + 320.5, y + 165);
	}
}