#include "pch.h"
#include "MouseSetting.h"

MouseSetting::MouseSetting()
{
}

MouseSetting::~MouseSetting()
{
}

HRESULT MouseSetting::init()
{
	_mouse = IMAGEMANAGER->addFrameImage("mouse", "source/images/mainScene/Cursor.bmp", 144, 96, 3, 2, true, MAGENTA);
	_frameX = 0;
	_frameY = 1;


	

	// X,Y �� �������� ���콺 �̹���
	// 0,0 �⺻ ���� ���콺
	// 0,1 ���̾�α� ���콺
	// 0,2 NPC ȣ���� ���콺
	// 1,0 ���� ��� ���콺
	// 1,1 �� ��� ���콺

	ShowCursor(false);
	return S_OK;
}

void MouseSetting::release()
{
}

void MouseSetting::update()
{
	//���� ���� ���콺�� �������� �� ����
	if (SCENEMANAGER->isCurrentScene("mainMenuScene"))
	{
		//ShowCursor(true);
	}

}

void MouseSetting::render()
{
	_mouse->frameRender(getMemDC(), _ptMouse.x, _ptMouse.y, _frameX, _frameY);
}
