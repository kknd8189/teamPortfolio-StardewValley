#include "pch.h"
#include "itemCan.h"

itemCan::itemCan()
{
}

itemCan::~itemCan()
{
}

HRESULT itemCan::init()
{
	_item.items = CAN;
	_item.itemImg = IMAGEMANAGER->findImage("playerTool");
	_item.frameX = 4;
	_item.frameY = 0;
	_item.itemName = "���ɸ���";
	_item.itemInfo = "�۹��̳� ���� ����   �� �� �ִ�";
	_item.buyPrice = 10;
	_item.sellPrice = 5;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = true;
	//_item.amount = 1;
	_item.itemNum = 22;
    return S_OK;
}

void itemCan::release()
{
}

void itemCan::update()
{
}

void itemCan::render(int x, int y)
{
	item::render(x, y);
}
