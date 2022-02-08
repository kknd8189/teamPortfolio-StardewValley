#include "pch.h"
#include "loadingScene.h"
#include "progressBar.h"

loadingScene::loadingScene()
	: _background(nullptr), 
	_loadingBar(nullptr),
	_currentCount(0)
{
}


loadingScene::~loadingScene()
{
}

HRESULT loadingScene::init()
{
	_background = IMAGEMANAGER->addImage("���", "source/Images/loadingScene/blackWindow.bmp", WINSIZEX, WINSIZEY, true, MAGENTA);

	/*_loadingBar = new progressBar;
	_loadingBar->init(0, WINSIZEY - 50, WINSIZEX, 50);
	_loadingBar->setGauge(0, 0);*/

	IMAGEMANAGER->addFrameImage("loading", "source/Images/loadingScene/loading.bmp", 822, 62, 3, 1, true, MAGENTA);
	_loadingImg = IMAGEMANAGER->findImage("loading");
	_frameX = 0;
	_count = 0;

	CreateThread(
		NULL,				//������ ���ȼӼ�(�ڽ������� �����Ҷ�)
		NULL,				//�������� ����ũ��(0�̸� ���ξ����� ����)
		threadFunction,		//����� �Լ�
		this,				//������ �Ű�����(this �� ������ �� Ŭ����)
		NULL,				//������ Ư��
		NULL);				//������ ID

	return S_OK;
}

void loadingScene::release()
{
	SAFE_DELETE(_loadingBar);
}

void loadingScene::update()
{
 /* _loadingBar->update();
  _loadingBar->setGauge(_currentCount, LOADINGMAX);*/

	if (_currentCount == LOADINGMAX)
	{
		//�̵��� �� ���� ����
		SCENEMANAGER->changeScene("gameScene");
	}

	_count++;

	if (_count % 30 == 0)
	{
		_frameX++;
	}
	if (_frameX >= 3) _frameX = 0;
}
  
void loadingScene::render()
{
	_background->render(getMemDC());
	//_loadingBar->render();
	_loadingImg->frameRender(getMemDC(), 50, WINSIZEY - 100, _frameX, 0);
}

DWORD CALLBACK threadFunction(LPVOID lpParameter)
{
	loadingScene* loadingHelper = (loadingScene*)lpParameter;


	while (loadingHelper->_currentCount != LOADINGMAX)
	{
		//�ҽ� ���� �߰�	
		IMAGEMANAGER->addFrameImage("player", "source/Images/�÷��̾��̹���3.bmp", 1152, 4352, 12, 34, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("marnie", "source/Images/NPC/npc_item.bmp", 128, 256, 4, 4, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("wizard", "source/Images/NPC/npc_skill.bmp",128, 256, 4, 4, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("fisher", "source/Images/NPC/�Ҿƹ���.bmp", 64, 128, 4, 4, true, MAGENTA);
		IMAGEMANAGER->addImage("dialogueBox", "source/Images/�ʻ�ȭ��ȭ.bmp", 720, 278, true, MAGENTA);
		IMAGEMANAGER->addImage("shopBox", "source/Images/shop_itemslot.bmp", 640, 64, true, MAGENTA);
		//�ҽ� ���� �߰�
		//
		// �κ��丮 UI
		IMAGEMANAGER->addImage("itemInventory",		"source/Images/inventory/itemInventory.bmp", 750, 550, true, MAGENTA);
		// ������ UI
		IMAGEMANAGER->addImage("quickSlot",			"source/Images/inventory/playerQuickslot.bmp", 565, 69, true, MAGENTA);
		// ���۸޴�
		IMAGEMANAGER->addImage("craftMenu",			"source/Images/inventory/Craftinven.bmp", 750, 550, true, MAGENTA);
		// ���ȸ޴�
		IMAGEMANAGER->addImage("statMenu",			"source/Images/inventory/skill.bmp", 750, 550, true, MAGENTA);
		// �����޴�
		IMAGEMANAGER->addImage("settingMenu",		"source/Images/inventory/setting.bmp", 750, 550, true, MAGENTA);
		// ������޴�
		IMAGEMANAGER->addImage("exitMenu",			"source/Images/inventory/exit.bmp", 750, 550, true, MAGENTA);
		// ������ ����
		IMAGEMANAGER->addImage("itemInfo",			"source/Images/shop/item_info.bmp", 210, 210, true, MAGENTA);
		//�ݱ� ������
		IMAGEMANAGER->addImage("closeButton",		"source/Images/inventory/�ݱ��ư.bmp", 44, 44, true, MAGENTA);
		
		IMAGEMANAGER->addImage("Storage", "source/Images/inventory/playerStorage.bmp", 653, 430, true, MAGENTA);

		//��� ������Ʈ
		IMAGEMANAGER->addFrameImage("springObjectsItem", "source/Images/springobjects4.bmp", 768,1088, 24, 34, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("springObjects", "source/Images/springobjects2.bmp", 960, 1360, 24, 34, true, MAGENTA);
		////���� �κ��丮
		IMAGEMANAGER->addFrameImage("playerTool",	"source/Images/playerInventory/playerTool.bmp", 280, 40, 7, 1, true, MAGENTA); // �÷��̾� ����
		//���� ������
		IMAGEMANAGER->addFrameImage("seedItem",		"source/Images/BMP/���Ѿ�����(original).bmp", 360, 160, 9, 4, true, MAGENTA);
		//���� �����۾����ܿ�
		IMAGEMANAGER->addFrameImage("seedItemSmall","source/Images/BMP/small���Ѿ�����(original).bmp", 144, 64, 9, 4, true, MAGENTA);
		//�۹�
		IMAGEMANAGER->addFrameImage("crops",		"source/Images/BMP/����(ori).bmp", 640, 120, 16, 3, true, MAGENTA);
		//�۹� ������
		IMAGEMANAGER->addFrameImage("cropsSmall",	"source/Images/BMP/����small(ori).bmp", 256, 48, 16, 3, true, MAGENTA);

		//���� 
		IMAGEMANAGER->addFrameImage("ores",			"source/Images/BMP/oreItem.bmp", 640, 200, 16, 5, true, MAGENTA);


		//������Ʈ������
		IMAGEMANAGER->addFrameImage("craftItems",	 "source/Images/inventory/craftItem3.bmp", 160, 40, 4, 1, true, MAGENTA);

		//������Ʈ
		IMAGEMANAGER->addFrameImage("craftObject",	 "source/Images/inventory/craftObject2.bmp", 160, 80, 4, 1, true, MAGENTA);
		//������Ʈ����
		IMAGEMANAGER->addFrameImage("craftObjectAlpha", "source/Images/inventory/craftObjectAlpha2.bmp", 160, 80, 4, 1, true, MAGENTA);

		//��ġ�� ������Ʈ
		IMAGEMANAGER->addFrameImage("craftObjectSmall", "source/Images/inventory/craftObjectSmall1.bmp", 176, 32, 11, 1, true, MAGENTA);

		
			
		//==================���� �κ� ���� �߰� ��=====================
		//�̹���
		IMAGEMANAGER->addFrameImage("RockStone", "source/Images/monster/RockStone.bmp", 52, 60, 4, 4, true, MAGENTA);

		//==================UI �κ� ���� �߰� ��=====================
		//�̹���
		IMAGEMANAGER->addImage("title",			"source/Images/mainScene/title.bmp", 690, 318, true, MAGENTA);
		IMAGEMANAGER->addImage("mainScene",		"source/Images/mainScene/mainScene.bmp", WINSIZEX, WINSIZEY, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("start",	"source/Images/mainScene/start.bmp", 185, 292, 1, 2, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("load",		"source/Images/mainScene/load.bmp", 185, 292, 1, 2, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("mapTool",  "source/Images/mainScene/mapTool.bmp", 185, 292, 1, 2, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("exit",		"source/Images/mainScene/exit.bmp", 185, 292, 1, 2, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("back",		"source/Images/mainScene/back.bmp", 198, 162, 1, 2, true, MAGENTA);
		

		//����
		//SOUNDMANAGER->addSound("bugCave", "source/Sounds/bugCave.mp3", true, true);				//���� �Ҹ�
		//SOUNDMANAGER->addSound("character", "source/Sounds/character.mp3", true, false);		//�층 �츮�������� �Ҹ�
		SOUNDMANAGER->addSound("death", "source/Sounds/death.mp3", true, false);				//���� �� ���� �Ҹ�
		SOUNDMANAGER->addSound("doorOpen", "source/Sounds/doorOpen.mp3", true, false);			//���� �� ���� �Ҹ�
		SOUNDMANAGER->addSound("springBGM", "source/Sounds/springBGM.mp3", true, true);			//�ΰ��� ��� ����
		//SOUNDMANAGER->addSound("fireSpell", "source/Sounds/fireSpell.mp3", true, false);		//�뱤�� �����Ǵ� �Ҹ�
		SOUNDMANAGER->addSound("getItem", "source/Sounds/getItem.mp3", true, false);			//������ �ֿ� �� ���� �Ҹ�
		SOUNDMANAGER->addSound("hitGrass", "source/Sounds/hitGrass.mp3", true, false);			//������ Ǯ �� �� ���� ȿ����
		SOUNDMANAGER->addSound("hitRock", "source/Sounds/hitRock.mp3", true, false);			//��̷� �� ���� �� ���� ȿ����
		SOUNDMANAGER->addSound("hitTree", "source/Sounds/hitTree.mp3", true, false);			//������ ���� ���� �� ���� ȿ����
		SOUNDMANAGER->addSound("hitPlayer", "source/Sounds/hitPlayer.mp3", true, false);		//���� �� �� ���� �Ҹ�
		SOUNDMANAGER->addSound("hoe", "source/Sounds/hoe.mp3", true, false);					//�� ���� ���� �Ҹ�
		SOUNDMANAGER->addSound("menuClose", "source/Sounds/menuClose.mp3", true, false);		//�޴� �ݴ� �Ҹ�
		SOUNDMANAGER->addSound("menuOpen", "source/Sounds/menuOpen.mp3", true, false);			//�޴� ���� �Ҹ�
		SOUNDMANAGER->addSound("menuSelect", "source/Sounds/menuSelect.mp3", true, false);		//�޴� ���� �Ҹ�
		//SOUNDMANAGER->addSound("monsterDead", "source/Sounds/monsterDead.mp3", true, false);	//���� �״� �Ҹ�
		SOUNDMANAGER->addSound("moveGrass", "source/Sounds/moveGrass.mp3", true, false);		//Ǯ���� ���� ��
		SOUNDMANAGER->addSound("moveRock", "source/Sounds/moveRock.mp3", true, false);			//������ ���� ��
		SOUNDMANAGER->addSound("moveSoil", "source/Sounds/moveSoil.mp3", true, false);			//���� ���� ��
		//SOUNDMAMNAGER->addSound("day", "source/Sounds/day.mp3", true, true);						//��ħ�� �� �� ���� �Ҹ�
		//SOUNDMANAGER->addSound("night", "source/Sounds/night.mp3", true, true);					//���� �� �� ���� �Ҹ�
		SOUNDMANAGER->addSound("opening", "source/Sounds/opening.mp3", true, true);				//������ �Ҹ�
		SOUNDMANAGER->addSound("pickUpItem", "source/Sounds/pickUpItem.mp3", true, false);		//�Ⱦ� ������(?)
		//SOUNDMANAGER->addSound("purchase", "source/Sounds/purchase.mp3", true, false);			//���� ���� �Ҹ�
		SOUNDMANAGER->addSound("removeGrass", "source/Sounds/removeGrass.mp3", true, false);	//Ǯ ���� �Ҹ�
		SOUNDMANAGER->addSound("removeRock", "source/Sounds/removeRock.mp3", true, false);		//�� ���� �Ҹ�
		SOUNDMANAGER->addSound("removeTree", "source/Sounds/removeTree.mp3", true, false);		//���� ���� �Ҹ�
		//SOUNDMANAGER->addSound("seeds", "source/Sounds/seeds.mp3", true, false);				//���� �ɴ� �Ҹ�
		//SOUNDMANAGER->addSound("slime", "source/Sounds/slime.mp3", true, false);				//�������� ������ �� ���� �Ҹ�
		SOUNDMANAGER->addSound("toolSwap", "source/Sounds/toolSwap.mp3", true, false);			//�Ǵ����� ���� �Ҹ�
		SOUNDMANAGER->addSound("watering", "source/Sounds/watering.mp3", true, false);			//���� ��ų� ���� �� �� ���� �Ҹ�

		loadingHelper->_currentCount++;
	}
	return 0;
}
