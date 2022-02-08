#include "pch.h"
#include "itemCopper.h"

HRESULT itemCopper::init()
{
	_item.items = COPPER;
	_item.itemImg = IMAGEMANAGER->findImage("ores");
	_item.frameX = 6;
	_item.frameY = 4;
	_item.itemName = "����";
	_item.itemInfo = "������ �پ��Ѱ��� ������ �� �� �ִ�";
	_item.buyPrice = 20;
	_item.sellPrice = 10;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = false;
	//_item.amount = 1;
	_item.itemNum = 14;
    return S_OK;
}

void itemCopper::release()
{
}

void itemCopper::update()
{
}

void itemCopper::render(int x, int y)
{
	item::render(x, y);
}
