#include "pch.h"
#include "playGround.h"


playGround::playGround()
{
	_winSize = { WINSIZEX, WINSIZEY };
	_isChange = false;
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ���⿡�� �ض�!!!
HRESULT playGround::init()
{
	gameNode::init(true);

	SCENEMANAGER->addScene("loadingScene", new loadingScene);
	SCENEMANAGER->addScene("playerScene", new playerScene);
	SCENEMANAGER->addScene("openingScene", new openingScene);
	SCENEMANAGER->addScene("mainMenuScene", new mainMenuScene);
	SCENEMANAGER->addScene("enemyTestScene", new enemyTestScene);
	SCENEMANAGER->addScene("inventory", new inventory);
	SCENEMANAGER->addScene("gameScene", new gameScene);
	SCENEMANAGER->addScene("map", new Map);
	SCENEMANAGER->changeScene("openingScene");



	return S_OK;
}

//�޸� ������ ����� �ض�!!!!
void playGround::release()
{
	gameNode::release();
}

//����ó���� ����ٰ�!
void playGround::update()
{
	gameNode::update();
	ChangeWindowSize();
	SCENEMANAGER->update();
}

//����� �׷����!!!
void playGround::render()
{
	if (!SCENEMANAGER->GetVideoPlay())
	{
		PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
		//==============������ ���� �ǵ帮�� ���� ============

		SCENEMANAGER->render();

		char str[25];
		sprintf_s(str, "worldTime : %f", TIMEMANAGER->getWorldTime());
		TextOut(getMemDC(), 0, 0, str, strlen(str));

		//=============== �ؿ��� �ǵ������� ================
		_backBuffer->render(getHDC(), 0, 0);
	}
	

}

void playGround::SetWindowSize(POINT size)
{
	if (_winSize.x == size.x && _winSize.y == size.y)
		return;
	_isChange = true;
	_winSize = size;
}

void playGround::ChangeWindowSize()
{
	if (SCENEMANAGER->isCurrentScene("loadingScene"))
	{
		SetWindowSize({WINSIZEX, WINSIZEY});
	}
	else
	{
		SetWindowSize({ WINSIZEX, WINSIZEY });
	}
}

