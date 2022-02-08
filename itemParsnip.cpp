#include "pch.h"
#include "itemParsnip.h"

HRESULT itemParsnip::init()
{
	_item.items = PARSNIP;
	_item.itemImg = IMAGEMANAGER->findImage("crops");
	_item.frameX = 0;
	_item.frameY = 0;
	_item.itemName = "�Ľ���";
	_item.itemInfo = "�Ľ����� �Ѹ�ä�ҷ� ��ٰ� ����� �Ĺ��̴�";
	_item.buyPrice = 0;
	_item.sellPrice = 220;
	_item.damage = 0;
	_item.hP = 65;
	_item.sP = 29;
	_item.isEatAble = true;
	_item.isHandleAble = false;
	//_item.amount = 1;
	_item.itemNum = 9;
	return S_OK;
}

void itemParsnip::release()
{
}

void itemParsnip::update()
{
}

void itemParsnip::render(int x, int y)
{
	item::render(x, y);
}
