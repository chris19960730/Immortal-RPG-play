#include"RoleData.h"
USING_NS_CC;

bool Nan1show = true;
bool Nan2show = false;
bool Nv1show = false;
bool Nv2show = false;

void RoleData::bindAllChild()
{
	roledataLayer = Sprite::create("data1.jpg");
	string headFile[4] = { "head1.png","head2.png" ,"head3.png" ,"head4.png" };
	string layerFile[4] = { "data1.png","data1.png","data1.png","data1.png" };
	bindSprite(layerFile, headFile);

	Nan1->addAllTo(layer[0]);
	Nan2->addAllTo(layer[2]);
	Nv1->addAllTo(layer[1]);
	Nv2->addAllTo(layer[3]);

}

void RoleData::init(Layer* scene)
{
	Nan1->removeAll(layer[0]);
	Nan2->removeAll(layer[2]);
	Nv1->removeAll(layer[1]);
	Nv2->removeAll(layer[3]);

	Nan1->addAllTo(layer[0]);
	Nan2->addAllTo(layer[2]);
	Nv1->addAllTo(layer[1]);
	Nv2->addAllTo(layer[3]);

	for (int i = 0; i < 4; i++)
		scene->addChild(layer[i]);
}



RoleData::RoleData()
{
	closeBtn = NULL;
	for (int i = 0; i < 4; i++)
	{
		head[i] = NULL;
		roleBtn[i] = NULL;
		layer[i] = NULL;
	}
}

void RoleData::bindBtn()
{
	roleMenu = Menu::create(roleBtn[0], roleBtn[1], roleBtn[2], roleBtn[3], NULL);
	roleMenu->setVisible(false);
}

void RoleData::bindSprite(string* file, string* headfile)
{
	for (int i = 0; i < 4; i++)
	{
		layer[i] = Sprite::create(file[i]);
		head[i] = Sprite::create(headfile[i]);
	}
}

Sprite* RoleData::retLayer(int num)
{
	return layer[num];
}

MenuItemImage* RoleData::retCloseBtn()
{
	return closeBtn;
}

void RoleData::setLayerPosition(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		layer[i]->setPosition(x, y);
	}

}

void RoleData::setCloseBtnPosition(int x, int y)
{
	closeBtn->setPosition(x, y);
}

void RoleData::setBtnScale(float x, float y)
{
	closeBtn->setScale(x, y);
}

void RoleData::setLayerVisible(bool bset)
{
	for (int i = 3; i >= 0; i--)
	{
		layer[i]->setVisible(bset);
	}
	if (bset)
		showLayer(0);
	_layerIsVisible = bset;
	roleMenu->setVisible(bset);
	if (bset)
	{
		roleBtn[0]->setVisible(Nan1show);
		roleBtn[2]->setVisible(Nan2show);
		roleBtn[1]->setVisible(Nv1show);
		roleBtn[3]->setVisible(Nv2show);
	}
}

bool RoleData::layerIsVisible()
{
	return _layerIsVisible;
}

void RoleData::showLayer(int num)
{
	for (int i = 0; i < 4; i++)
	{
		layer[i]->setVisible(false);
	}
	layer[num]->setVisible(true);
}

void RoleData::setCloseBtnVisible(bool bset)
{
	closeBtn->setVisible(bset);
}

void RoleData::setLayerTag(int tag)
{
	for (int i = 0; i < 4; i++)
	{
		layer[i]->setTag(tag);
	}
	_layerTag = tag;
}

void RoleData::bindRoleBtn(string begin, string end, int rolenum)
{
	switch (rolenum)
	{
	case 0:roleBtn[0] = MenuItemImage::create(begin, end,
		[this](Ref*) {this->showLayer(0); });
		break;
	case 1:roleBtn[1] = MenuItemImage::create(begin, end,
		[this](Ref*) {this->showLayer(1); });
		break;
	case 2:roleBtn[2] = MenuItemImage::create(begin, end,
		[this](Ref*) {this->showLayer(2); });
		break;
	case 3:roleBtn[3] = MenuItemImage::create(begin, end,
		[this](Ref*) {this->showLayer(3); });
		break;
	}
	roleBtn[rolenum]->setPosition(330 + rolenum * 100, 585);
}

void RoleData::bindHead(string* file)
{
	for (int i = 0; i < 4; i++)
	{
		head[i] = Sprite::create(file[i]);
	}
}

void RoleData::addBtnTo(Layer* scene, int tag)
{
	bindBtn();
	scene->addChild(roleMenu, tag);
	roleMenu->setPosition(0, 0);
}

void RoleData::addHeadTo(Layer* scene, int tag)
{
	for (int i = 0; i < 4; i++)
	{
		scene->addChild(head[i], tag);
		head[i]->setPosition(330 + i * 100, 585);
	}
}

void RoleData::addLayerTo(Layer* scene, int tag)
{
	for (int i = 0; i < 4; i++)
	{
		scene->addChild(layer[i], tag);
		layer[i]->setPosition(480, 320);
		layer[i]->setVisible(false);
	}
	_layerTag = tag;
	_layerIsVisible = false;
}