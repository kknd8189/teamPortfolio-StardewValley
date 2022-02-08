#include "pch.h"
#include "itemCauliSeed.h"

HRESULT itemCauliSeed::init()
{
	_item.items = CAULIFLOWERSEED;
	_item.itemImg = IMAGEMANAGER->findImage("seedItem");
	_item.frameX = 2;
	_item.frameY = 0;
	_item.itemName = "�ݸ��ö�� ����";
	_item.itemInfo = "�ݸ��ö�� ���� ���� �ݸ��ö���� Ű����!";
	_item.buyPrice = 30;
	_item.sellPrice = 15;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = false;
	//_item.amount = 1;
	_item.itemNum = 17;
    return S_OK;
}

void itemCauliSeed::release()
{
}

void itemCauliSeed::update()
{
}

void itemCauliSeed::render(int x, int y)
{
	item::render(x, y);
}
