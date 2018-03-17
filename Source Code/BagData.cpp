#include"BagData.h"
#include"Prop.h"


int whichBag = 0; //第一个背包栏是0
int _bagNum = 0;  //第一个背包栏是0
int _itemNum = 0; //第一个道具是0

void BagData::showShop(bool bset)
{
	shopLayer->setVisible(bset);
	shopMenu->setVisible(bset);
}

void BagData::init(Layer* scene)
{
	//对商店的初始化
	shopBtn = MenuItemImage::create("shop.png", "shopend.png",
		[this](Ref*)
	{
		this->showShop(true);
		this->setAllBtnEnable(false);
	});
	shopLayer = Sprite::create("shoplayer.png");
	shopPropBtn[0] = MenuItemImage::create("buy.png", "buyend.png",
		[this](Ref*)
	{
		if (Propbag.retMoney() >= 100)
		{
			this->getProp(&XiaoXue, 1);
			this->getMoney(-100);
		}
	});
	shopPropBtn[1] = MenuItemImage::create("buy.png", "buyend.png",
		[this](Ref*)
	{
		if (Propbag.retMoney() >= 500)
		{
			this->getProp(&DaXue, 1);
			this->getMoney(-500);
		}
	});
	shopPropBtn[2] = MenuItemImage::create("buy.png", "buyend.png",
		[this](Ref*)
	{
		if (Propbag.retMoney() >= 100)
		{
			this->getProp(&XiaoLan, 1);
			this->getMoney(-100);
		}
	});
	shopPropBtn[3] = MenuItemImage::create("buy.png", "buyend.png",
		[this](Ref*)
	{
		if (Propbag.retMoney() >= 500)
		{
			this->getProp(&DaLan, 1);
			this->getMoney(-500);
		}
	});
	shopCloseBtn = MenuItemImage::create("shopclose.png", "shopcloseend.png",
		[this](Ref*)
	{
		this->showShop(false);
		this->setAllBtnEnable(true);
	});

	shopMenuMax = Menu::create(shopBtn, NULL);
	scene->addChild(shopMenuMax, 10);
	scene->addChild(shopLayer, 11);
	shopLayer->setPosition(480, 320);
	shopBtn->setPosition(360, 120);
	shopMenu = Menu::create(shopPropBtn[0], shopPropBtn[1], shopPropBtn[2],
		shopPropBtn[3], shopCloseBtn, NULL);

	scene->addChild(shopMenu, 100);
	shopPropBtn[0]->setPosition(300, 259.5);
	shopPropBtn[1]->setPosition(420, 259.5);
	shopPropBtn[2]->setPosition(540, 259.5);
	shopPropBtn[3]->setPosition(660, 259.5);
	shopCloseBtn->setPosition(750, 385);

	shopMenu->setPosition(0, 0);
	shopMenuMax->setPosition(0, 0);

	showShop(false);

	string bagBtnFile[3] = { "bagbtn1.png","bagbtn2.png" ,"bagbtn3.png" };
	string bagBtnEndFile[3] = { "bagbtn1end.png","bagbtn2end.png" ,"bagbtn3end.png" };
	this->bindSprite("baglayer.png", "money.png");
	this->bindMainScene(scene);
	this->bindBagBtn(bagBtnFile, bagBtnEndFile);
	/*this->closeBtn = MenuItemImage::create("return.png", "returnend.png",
	CC_CALLBACK_1(MainScene::bagCloseCallBack, scene));*/
	this->bindUseBtn("use.png", "useend.png");
	this->addLayerTo(scene, 2);

	this->addBtnTo(scene, 4);
	this->propBagInit();
	this->equipmentInit();
	this->addPropLabelTo(scene, 5);
	this->addMoneyLabelTo(scene, 4);
	this->addAllItemBtn(scene);
	this->setPosition(480, 320);
	this->showBagLayer(false);
	for (int i = 0; i < Propbag.P.size(); i++)
	{
		Propbag.P[i]->bindInformation();
		scene->addChild(Propbag.P[i]->Information, 2);
	}
	useChoose = Sprite::create("usechoose.png");
	choose[0] = MenuItemImage::create("chooserole1.png", "chooseend.png",
		[this](Ref*)
	{
		this->useChoose->setVisible(false);
		//closeBtn->setEnabled(true);
		this->setAllBtnEnable(true);
		//此处应有一个zz函数
		Nan1->useProp(Propbag.retProp(_itemNum));
		//对人物使用道具Propbag.Getprop(this->_itemNum)触发效果
		if (Propbag.retProp(_itemNum)->effect)
		{
			auto fadeto = FadeTo::create(1, 0);
			Propbag.retProp(_itemNum)->effect->setVisible(true);
			Propbag.retProp(_itemNum)->effect->setOpacity(255);
			Propbag.retProp(_itemNum)->effect->runAction(fadeto);
		}
		else
		{
			auto fadeto = FadeTo::create(1, 0);
			Propbag.retProp(_itemNum)->bindEffectAction(this->mainscene);
			Propbag.retProp(_itemNum)->effect->setVisible(true);
			Propbag.retProp(_itemNum)->effect->setOpacity(255);
			Propbag.retProp(_itemNum)->effect->runAction(fadeto);
		}
		Propbag.changeProp(Propbag.retProp(_itemNum)->retName(), -1);
	
		this->propBagRefresh();
	});
	choose[1] = MenuItemImage::create("chooserole2.png", "chooseend.png",
		[this](Ref*)
	{
		this->useChoose->setVisible(false);
		this->setAllBtnEnable(true);
		Nan2->useProp(Propbag.retProp(_itemNum));
		//对人物使用道具Propbag.Getprop(this->_itemNum)触发效果
		if (Propbag.retProp(_itemNum)->effect)
		{
			auto fadeto = FadeTo::create(1, 0);
			Propbag.retProp(_itemNum)->effect->setVisible(true);
			Propbag.retProp(_itemNum)->effect->setOpacity(255);
			Propbag.retProp(_itemNum)->effect->runAction(fadeto);
		}
		else
		{
			auto fadeto = FadeTo::create(1, 0);
			Propbag.retProp(_itemNum)->bindEffectAction(this->mainscene);
			Propbag.retProp(_itemNum)->effect->setVisible(true);
			Propbag.retProp(_itemNum)->effect->setOpacity(255);
			Propbag.retProp(_itemNum)->effect->runAction(fadeto);
		}
		Propbag.changeProp(Propbag.retProp(_itemNum)->retName(), -1);
	
		this->propBagRefresh();
	});
	choose[2] = MenuItemImage::create("chooserole3.png", "chooseend.png",
		[this](Ref*)
	{
		this->useChoose->setVisible(false);
		this->setAllBtnEnable(true);
		Nv1->useProp(Propbag.retProp(_itemNum));
		//对人物使用道具Propbag.Getprop(this->_itemNum)触发效果
		if (Propbag.retProp(_itemNum)->effect)
		{
			auto fadeto = FadeTo::create(1, 0);
			Propbag.retProp(_itemNum)->effect->setVisible(true);
			Propbag.retProp(_itemNum)->effect->setOpacity(255);
			Propbag.retProp(_itemNum)->effect->runAction(fadeto);
		}
		else
		{
			auto fadeto = FadeTo::create(1, 0);
			Propbag.retProp(_itemNum)->bindEffectAction(this->mainscene);
			Propbag.retProp(_itemNum)->effect->setVisible(true);
			Propbag.retProp(_itemNum)->effect->setOpacity(255);
			Propbag.retProp(_itemNum)->effect->runAction(fadeto);
		}
		Propbag.changeProp(Propbag.retProp(_itemNum)->retName(), -1);
		this->propBagRefresh();
	});
	choose[3] = MenuItemImage::create("chooserole4.png", "chooseend.png",
		[this](Ref*)
	{
		this->useChoose->setVisible(false);
		this->setAllBtnEnable(true);
		Nv2->useProp(Propbag.retProp(_itemNum));
		//对人物使用道具Propbag.Getprop(this->_itemNum)触发效果
		if (Propbag.retProp(_itemNum)->effect)
		{
			auto fadeto = FadeTo::create(1, 0);
			Propbag.retProp(_itemNum)->effect->setVisible(true);
			Propbag.retProp(_itemNum)->effect->setOpacity(255);
			Propbag.retProp(_itemNum)->effect->runAction(fadeto);
		}
		else
		{
			auto fadeto = FadeTo::create(1, 0);
			Propbag.retProp(_itemNum)->bindEffectAction(this->mainscene);
			Propbag.retProp(_itemNum)->effect->setVisible(true);
			Propbag.retProp(_itemNum)->effect->setOpacity(255);
			Propbag.retProp(_itemNum)->effect->runAction(fadeto);
		}
		Propbag.changeProp(Propbag.retProp(_itemNum)->retName(), -1);
		this->propBagRefresh();
	});
	for (int i = 0; i < 4; i++)
	{
		choose[i]->setVisible(false);
		choose[i]->setAnchorPoint(Vec2(0.5, 0.5));
		choose[i]->setPosition(93.5 + 135 * i, 149.5);
	}
	choose[0]->setVisible(Nan1show);
	choose[1]->setVisible(Nv1show);
	choose[2]->setVisible(Nan2show);
	choose[3]->setVisible(Nv2show);
	//这里choose初始化
	chooseMenu = Menu::create(choose[0], choose[1], choose[2], choose[3], NULL);
	chooseMenu->setPosition(0, 0);
	useChoose->addChild(chooseMenu, 1);
	useChoose->setVisible(false);
	useChoose->setPosition(480, 320);
	scene->addChild(useChoose, 6);
}

BagData::BagData()
{
	closeBtn = NULL;
	layer = NULL;
	money = NULL;
	for (int i = 0; i < 3; i++)
	{
		bagBtn[i] = NULL;
	}
	itemMenu = Menu::create(NULL);
	moneyLabel = NULL;
	whichBag = 0;
}

void BagData::propBagRefresh()
{
	if (!Propbag._refresh)
	{
		mainscene->removeChild(label[0][_itemNum]);
		label[0][_itemNum] = Label::create(to_string(Propbag.retProp(_itemNum)->retPropNum()),
			"Arial", 30);
		label[0][_itemNum]->setAnchorPoint(Vec2(0, 0));
		label[0][_itemNum]->setPosition(310 + (_itemNum % 3) * 120, 395 - (_itemNum / 3) * 120);
		mainscene->addChild(label[0][_itemNum], 5);
	}
	else
	{
		showPropInformation(0, false);
		for (int i = 0; i < itemBtn[0].size(); i++)
		{
			mainscene->removeChild(label[0][i]);
			mainscene->removeChild(itemBtn[0][i]);
			itemMenu->removeChild(itemBtn[0][i], true);
		}
		itemBtn[0].clear();
		label[0].clear();
		this->propBagInit();
		for (int i = 0; i < itemBtn[0].size(); i++)
		{
			mainscene->addChild(itemBtn[0][i]);
			mainscene->addChild(label[0][i], 5);
			itemMenu->addChild(itemBtn[0][i]);
		}
		useBtn->setVisible(false);
	}
	Propbag._refresh = false;
}

void BagData::propBagInit()
{
	int count = 0;
	for (int i = 0; i < Propbag.P.size(); i++)
	{
		if (Propbag.P[i]->retPropNum()>0)
		{
			Label* tempLabel = Label::create(to_string(Propbag.P[i]->retPropNum()), "Arial", 30);
			tempLabel->setAnchorPoint(Vec2(0, 0));
			tempLabel->setPosition(310 + (count % 3) * 120, 395 - (count / 3) * 120);
			tempLabel->setVisible(whichBag == 0 && layer->isVisible());
			label[0].push_back(tempLabel);
			MenuItemImage* tempbtn = MenuItemImage::create(Propbag.P[i]->retFilename(),
				Propbag.P[i]->retFilename(),
				[this, count](Ref*)
			{
				log("item");
				bool bset = (!this->useBtnIsVisible()) || count != _itemNum;
				_bagNum = 0;
				_itemNum = count;
				this->showUseBtn(bset);
				this->showPropInformation(count, true);
			});
			tempbtn->setPosition(480 - 120 + (count % 3) * 120, 320 + 125 - (count / 3) * 120);
			tempbtn->setVisible(whichBag == 0 && layer->isVisible());
			itemBtn[0].push_back(tempbtn);
			count++;
		}
	}
}

void BagData::equipmentInit()
{
	for (int i = 0; i < Weapon_bag.bagSize(); i++)
	{
		Weapon_bag.E[i]->bindInfomation();
		this->mainscene->addChild(Weapon_bag.E[i]->Information, 2);
		MenuItemImage* tempbtn = MenuItemImage::create(Weapon_bag.E[i]->retFilename(),
			Weapon_bag.E[i]->retFilename(),
			[this, i](Ref*)
		{
			this->showEquipmentInformation(i, true, 1);
		}
		);
		itemBtn[1].push_back(tempbtn);
		tempbtn->setPosition(480 - 120 + (i % 3) * 120, 320 + 125 - (i / 3) * 120);
		tempbtn->setVisible(false);
	}
	for (int i = 0; i < Armors_bag.bagSize(); i++)
	{
		Armors_bag.E[i]->bindInfomation();
		this->mainscene->addChild(Armors_bag.E[i]->Information, 2);
		MenuItemImage* tempbtn = MenuItemImage::create(Armors_bag.E[i]->retFilename(),
			Armors_bag.E[i]->retFilename(),
			[this, i](Ref*)
		{
			this->showEquipmentInformation(i, true, 0);
		}
		);
		itemBtn[2].push_back(tempbtn);
		tempbtn->setPosition(480 - 120 + (i % 3) * 120, 320 + 125 - (i / 3) * 120);
		tempbtn->setVisible(false);
	}
}

void BagData::bindSprite(string file, string moneyfile)
{
	layer = Sprite::create(file);
	money = Sprite::create(moneyfile);
}

void BagData::bindBagBtn(string* begin, string* end)
{
	bagBtn[0] = MenuItemImage::create(begin[0], end[0],
		[this](Ref*)
	{
		this->showLayer(0);
		whichBag = 0;
		this->useBtn->setVisible(false);
		this->showPropInformation(0, false);
		this->showEquipmentInformation(0, false, 0);
		this->showEquipmentInformation(0, false, 1);
	});
	bagBtn[1] = MenuItemImage::create(begin[1], end[1],
		[this](Ref*)
	{
		this->showLayer(1);
		whichBag = 1;
		this->useBtn->setVisible(false);
		this->showPropInformation(0, false);
		this->showEquipmentInformation(0, false, 0);
		this->showEquipmentInformation(0, false, 1);
	});
	bagBtn[2] = MenuItemImage::create(begin[2], end[2],
		[this](Ref*)
	{
		this->showLayer(2);
		whichBag = 2;
		this->useBtn->setVisible(false);
		this->showPropInformation(0, false);
		this->showEquipmentInformation(0, false, 0);
		this->showEquipmentInformation(0, false, 1);
	});
}

void BagData::bindUseBtn(string begin, string end)
{
	useBtn = MenuItemImage::create(begin, end, [this](Ref*)
	{
		this->useBtn->setVisible(false);
		this->useChoose->setVisible(true);
		this->choose[0]->setVisible(Nan1show);
		this->choose[1]->setVisible(Nv1show);
		this->choose[2]->setVisible(Nan2show);
		this->choose[3]->setVisible(Nv2show);
		setAllBtnEnable(false);
	});
	useBtn->setAnchorPoint(Vec2(0, 0));
	useBtn->setVisible(false);
}

void BagData::showItemBtn(int num, bool bset)
{
	bool show;
	for (int i = 0; i < 3; i++)
	{
		show = false;
		if (i == num)
			show = bset;
		for (int j = 0; j < itemBtn[i].size(); j++)
		{
			itemBtn[i][j]->setVisible(show);
		}
	}
}

void BagData::showLayer(int num)
{
	showItemBtn(num, true);
	showLabel(num, true);
}

void BagData::showBagLayer(bool bset)
{
	//其他按钮、、
	money->setVisible(bset);
	moneyLabel->setVisible(bset);
	layer->setVisible(bset);
	bagMenu->setVisible(bset);
	if (bset)
	{
		showItemBtn(0, true);
		showLabel(0, true);
	}
	else
	{
		useBtn->setVisible(false);
		showPropInformation(0, false);
		showEquipmentInformation(0, false, 0);
		showEquipmentInformation(0, false, 1);
		showShop(false);
		showLabel(0, false);
		for (int i = 0; i < 3; i++)
		{
			showItemBtn(i, false);
		}
	}
	shopBtn->setVisible(bset);
}

void BagData::showLabel(int num, bool bset)
{
	bool show;
	for (int i = 0; i < 3; i++)
	{
		show = false;
		if (i == num)
			show = bset;
		for (int j = 0; j < label[i].size(); j++)
		{
			label[i][j]->setVisible(show);
		}
	}
}

void BagData::showUseBtn(bool bset)
{
	useBtn->setVisible(bset);
	Vec2 point1 = label[0][_itemNum]->getPosition();
	useBtn->setPosition(point1.x, point1.y - 20);
}

void BagData::showPropInformation(int num, bool bset)
{
	for (int i = 0; i < Propbag.P.size(); i++)
	{
		if (Propbag.P[i]->Information)
			Propbag.P[i]->Information->setVisible(false);
	}
	if (bset && Propbag.retProp(num))
		Propbag.retProp(num)->Information->setVisible(bset);
}

void BagData::showEquipmentInformation(int num, bool bset, int which)
{
	if (which == 1)
	{
		for (int i = 0; i < Weapon_bag.E.size(); i++)
		{
			Weapon_bag.E[i]->Information->setVisible((i == num) ? bset : false);
		}
	}
	else
	{
		for (int i = 0; i < Armors_bag.E.size(); i++)
		{
			Armors_bag.E[i]->Information->setVisible((i == num) ? bset : false);
		}
	}
}


void BagData::bindBtn()
{
	bagMenu = Menu::create(bagBtn[0], bagBtn[1], bagBtn[2], closeBtn, useBtn, NULL);
}

void BagData::bindMainScene(Layer* scene)
{
	mainscene = scene;
}

void BagData::addAllItemBtn(Layer* scene)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < itemBtn[i].size(); j++)
		{
			scene->addChild(itemBtn[i][j]);
			itemMenu->addChild(itemBtn[i][j]);
		}
	}
}

void BagData::addLayerTo(Layer* scene, int tag)
{
	scene->addChild(layer, tag);
}

void BagData::addBtnTo(Layer* scene, int tag)
{
	bindBtn();
	scene->addChild(bagMenu, tag);
	bagMenu->setPosition(0, 0);
	scene->addChild(itemMenu, tag + 1);
	itemMenu->setPosition(0, 0);
}

void BagData::addPropLabelTo(Layer* scene, int tag)
{
	for (int i = 0; i < label[0].size(); i++)
	{
		scene->addChild(label[0][i], tag);
	}
}

void BagData::addMoneyLabelTo(Layer* scene, int tag)
{
	moneyLabel = Label::create(to_string(Propbag.retMoney()), "Arial", 20);
	moneyLabel->setAnchorPoint(Vec2(1, 0.5));
	moneyLabel->setPosition(640, 320 - 200);
	scene->addChild(moneyLabel, tag + 1);
	//moneyLabel->setTextColor(Color4B(0, 0,0, 255));
	moneyLabel->setVisible(false);
	scene->addChild(money, tag);
	money->setPosition(480, 320 - 205);
	money->setVisible(false);
}

void BagData::setItem(int bagNum, int itemNum)
{
	_bagNum = bagNum;
	_itemNum = itemNum;
}

void BagData::setWhichBag(int num)
{
	whichBag = num;
}

void BagData::setPosition(float x, float y)
{
	//绑定layer
	layer->setPosition(x, y);
	money->setPosition(x + 55, y - 200);
	closeBtn->setPosition(x + 215.5, y + 200);
	for (int i = 0; i < 3; i++)
	{
		bagBtn[i]->setPosition(x - 130 + i * 130, y + 220);
	}
}

bool BagData::useBtnIsVisible()
{
	return useBtn->isVisible();
}

bool BagData::getMoney(int num)
{
	Propbag.changeMoney(num);
	mainscene->removeChild(moneyLabel);
	moneyLabel = Label::create(to_string(Propbag.retMoney()), "Arial", 20);
	moneyLabel->setAnchorPoint(Vec2(1, 0.5));
	moneyLabel->setPosition(640, 320 - 200);
	//moneyLabel->setTextColor(Color4B(255, 255, 255, 255));
	mainscene->addChild(moneyLabel, 4);
	moneyLabel->setVisible(layer->isVisible());
	return true;
}

void BagData::getWeapon(Equipment* weapon)
{
	weapon->bindInfomation();
	this->mainscene->addChild(weapon->Information, 2);
	Weapon_bag.E.push_back(weapon);
	int i = Weapon_bag.E.size() - 1;
	MenuItemImage* tempbtn = MenuItemImage::create(weapon->retFilename(), weapon->retFilename(),
		[this,i](Ref*)
	{
		this->showEquipmentInformation(i, true, 1);
	}
	);
	itemBtn[1].push_back(tempbtn);
	mainscene->addChild(tempbtn);
	itemMenu->addChild(tempbtn);
	tempbtn->setPosition(480 - 120 + ((Weapon_bag.E.size() - 1) % 3) * 120, 320 + 125 - ((Weapon_bag.E.size() - 1) / 3) * 120);
	tempbtn->setVisible(whichBag == 1 && layer->isVisible());
}

void BagData::getArmors(Equipment* armors)
{
	armors->bindInfomation();
	this->mainscene->addChild(armors->Information, 2);
	Armors_bag.E.push_back(armors);
	int i = Armors_bag.E.size() - 1;
	MenuItemImage* tempbtn = MenuItemImage::create(armors->retFilename(), armors->retFilename(),
		[this,i](Ref*)
	{
		this->showEquipmentInformation(i, true, 0);
	}
	);
	itemBtn[2].push_back(tempbtn);
	mainscene->addChild(tempbtn);
	itemMenu->addChild(tempbtn);
	tempbtn->setPosition(480 - 120 + ((Armors_bag.E.size() - 1) % 3) * 120, 320 + 125 - ((Armors_bag.E.size() - 1) / 3) * 120);
	tempbtn->setVisible(whichBag == 2 && layer->isVisible());
}

void BagData::getProp(Prop* prop, int num)
{
	if (prop->retPropNum() == 0)
	{
		Propbag._refresh = true;
		prop->changeNum(num);
		propBagRefresh();
	}
	else
	{
		prop->changeNum(num);
		int pos = Propbag.searchProp(prop);
		mainscene->removeChild(label[0][pos]);
		label[0][pos] = Label::create(to_string(prop->retPropNum()), "Arial", 30);
		label[0][pos]->setAnchorPoint(Vec2(0, 0));
		label[0][pos]->setPosition(310 + (pos % 3) * 120, 395 - (pos / 3) * 120);
		mainscene->addChild(label[0][pos], 5);
		label[0][pos]->setVisible(whichBag == 0 && layer->isVisible());
	}
}

void BagData::setAllBtnEnable(bool bset)
{
	closeBtn->setEnabled(bset);
	for (int i = 0; i < 3; i++)
	{
		bagBtn[i]->setEnabled(bset);
	}
	for (int i = 0; i < itemBtn[0].size(); i++)
	{
		itemBtn[0][i]->setEnabled(bset);
	}
	shopBtn->setEnabled(bset);
}

Layer* BagData::retMainScene()
{
	return mainscene;
}

int BagData::retItemNum()
{
	return _itemNum;
}