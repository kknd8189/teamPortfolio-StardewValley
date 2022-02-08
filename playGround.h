#pragma once
#include "gameNode.h"
#include "loadingScene.h"
#include "playerScene.h"
#include "openingScene.h"
#include "loadingScene.h"
#include "mainMenuScene.h"
#include "inventory.h"
#include "Map.h"
#include "enemyTestScene.h"
#include "gameScene.h"




class playGround : public gameNode
{
private:
	POINT  _winSize;
	bool _isChange;
	
	   	

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	void SetWindowSize(POINT size);
	void ChangeWindowSize();

	inline BOOL GetChange() { return _isChange; }
	inline void SetChange(bool change) { _isChange = change; }
	inline POINT GetWindowSize() { return _winSize; }
	
};

