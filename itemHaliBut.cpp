#include "pch.h"
#include "itemHaliBut.h"

HRESULT itemHaliBut::init()
{
	_item.items = HALIBUT;
	_item.itemImg = IMAGEMANAGER->findImage("springObjects");
	_item.frameX = 23;
	_item.frameY = 5;
	_item.itemName = "����";
	_item.itemInfo = "�ſ� ������ ���� ���� �������� �����ִ�";
	_item.buyPrice = 0;
	_item.sellPrice = 300;
	_item.damage = 0;
	_item.hP = 150;
	_item.sP = 80;
	_item.isEatAble = true;
	_item.isHandleAble = false;
	_item.itemNum = 11;
	//_item.amount = 1;
    return S_OK;
}

void itemHaliBut::release()
{
}

void itemHaliBut::update()
{
}

void itemHaliBut::render(int x, int y)
{
	item::render(x, y);
}
