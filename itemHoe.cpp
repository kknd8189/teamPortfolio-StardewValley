#include "pch.h"
#include "itemHoe.h"

itemHoe::itemHoe()
{
}

itemHoe::~itemHoe()
{
}

HRESULT itemHoe::init()
{
	_item.items = HOE;
	_item.itemImg = IMAGEMANAGER->findImage("playerTool");
	_item.frameX = 1;
	_item.frameY = 0;
	_item.itemName = "ȣ��";
	_item.itemInfo = "��縦 �������ִ� ������ ���� �� �ִ�";
	_item.buyPrice = 20;
	_item.sellPrice = 10;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = true;
	//_item.amount = 1;
	_item.itemNum = 23;
    return S_OK;
}

void itemHoe::release()
{
}

void itemHoe::update()
{
}

void itemHoe::render(int x, int y)
{
	item::render(x, y);
}
