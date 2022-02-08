#pragma once
#include "gameNode.h"
#include "homeMap.h"
//#include "player.h" //<- inventory ����
#include "npcManager.h"
#include "EnemyManager.h"
#include "objectManager.h"
#include "entity.h"
#include "UserInterface.h"
#include "boxInventory.h"


class gameScene : public gameNode
{
private:
	entity* _player;	//�÷��̾�
	npcManager* _npcManager; //NPC �Ŵ���
	EnemyManager* _enemyManager; //���ʹ� �Ŵ���
	homeMap* _homeMap;
	CameraManager* _cameraManager; //ī�޶�Ŵ���
	objectManager* _objectManager; //������Ʈ �Ŵ���
	UserInterface* _uiManager;
	boxInventory* _boxIv;



public:
	virtual HRESULT init();
	virtual void update();
	virtual	void release();
	virtual	void render();
};

