#include "pch.h"
#include "itemBox.h"


HRESULT itemBox::init()
{
	_item.craftItems = BOX;
	_item.itemImg = IMAGEMANAGER->findImage("craftItems");
	_item.frameX = 0;
	_item.frameY = 0;
	_item.itemName = "����";
	_item.itemInfo = "�κ��丮�� �����ϸ� ��ġ�ϼ���!";
	_item.buyPrice = 0;
	_item.sellPrice = 0;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = true;
	//_item.amount = 1;
	_item.needAmountToCraft = 50;
	_item.itemNum = 3;

	return S_OK;
}

void itemBox::release()
{
}

void itemBox::update()
{
}

void itemBox::render(int x, int y)
{
	item::render(x, y);
}
