#include "pch.h"
#include "mainMenuScene.h"

HRESULT mainMenuScene::init()
{
	SOUNDMANAGER->play("opening", 0.5f);
	_select.img[0] = IMAGEMANAGER->findImage("start");
	_select.img[1] = IMAGEMANAGER->findImage("load");
	_select.img[2] = IMAGEMANAGER->findImage("mapTool");
	_select.img[3] = IMAGEMANAGER->findImage("exit");
	for (int i = 0; i < 4; i++)
	{
		_select.rc[i] = RectMake(240 + 205 * i, 555, IMAGEMANAGER->findImage("start")->getWidth(), IMAGEMANAGER->findImage("start")->getFrameHeight());
		_select.x[i] = _select.rc[i].left;
		_select.y[i] = _select.rc[i].top;
	}
	_ui = new UserInterface;
	_ui->init();
	return S_OK;
}

void mainMenuScene::release()
{
}

void mainMenuScene::update()
{
	for (int i = 0; i < 4; i++)
	{
		if (PtInRect(&_select.rc[i], _ptMouse))
		{
			if (!SOUNDMANAGER->isPlaySound("menuOpen") && !_select.isPlay[i])
			{
				SOUNDMANAGER->play("menuOpen", 0.5f);
				_select.isPlay[i] = true;
			}
			_select.img[i]->setFrameY(1);

			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				SOUNDMANAGER->play("menuSelect", 0.5f);
				switch (i)
				{
					//1��ư�� ������ �ΰ��� ȭ������ ����
				//case 0:
					//2��ư�� ������ �ε� ȭ������ ����
				//case 1:
					//3��ư�� ������ ���� ������ ����
				//case 2:
					//4��ư�� ������ �����찡 �����
				case 3:
					PostQuitMessage(0);
					break;
				}
			}
		}
		else if(!PtInRect(&_select.rc[i], _ptMouse))
		{
			!SOUNDMANAGER->isPlaySound("menuOpen");
			_select.img[i]->setFrameY(0);
			_select.isPlay[i] = false;
		}

		
	}
	_ui->update();
}

void mainMenuScene::render()
{
	IMAGEMANAGER->findImage("mainScene")->render(getMemDC());
	for (int i = 0; i < 4; i++)
	{
		_select.img[i]->frameRender(getMemDC(), _select.x[i], _select.y[i], 0, _select.img[i]->getFrameY());
	}

	char str[128];
	sprintf_s(str, "X : %d", _ptMouse.x);
	TextOut(getMemDC(), 10, 20, str, strlen(str));
	sprintf_s(str, "Y : %d", _ptMouse.y);
	TextOut(getMemDC(), 10, 40, str, strlen(str));

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		for (int i = 0; i < 4; i++)
		{
			Rectangle(getMemDC(), _select.rc[i]);
		}
		
	}
	_ui->render();
}
