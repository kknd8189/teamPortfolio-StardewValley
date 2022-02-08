#include "pch.h"
#include "itemParsnipSeed.h"

HRESULT itemParsnipSeed::init()
{
	_item.items = PARSNIPSEED;
	_item.itemImg = IMAGEMANAGER->findImage("seedItem");
	_item.frameX = 0;
	_item.frameY = 0;
	_item.itemName = "�Ľ��վ���";
	_item.itemInfo = "�Ľ��վ������� �Ľ����� Ű����";
	_item.buyPrice = 20;
	_item.sellPrice = 10;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = false;
	//_item.amount = 1;
	_item.itemNum = 19;
    return S_OK;
}

void itemParsnipSeed::release()
{
}

void itemParsnipSeed::update()
{
}

void itemParsnipSeed::render(int x, int y)
{
	item::render(x, y);
}
