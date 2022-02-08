#pragma once
#include "gameNode.h"

class CameraManager : public gameNode
{
private:
	int _posX;
	int _posY;

	float _renderPosX;
	float _renderPosY;
	
	float _minMapSizeX;
	int _mapSizeX;
	float _mapSizeY;

	RECT _rc;

public:
	CameraManager();
	~CameraManager();

	HRESULT init(int mapSizeX, float mapSizeY); //��ü �� ������ ( ���� ����, ���� ũ�� )
	virtual void release();
	virtual void update(float playerX, float playerY); //���� �÷��̾� ���� ��ǥ( PosX �� PosY )

	void CameraWork(float playerX, float playerY);
	void CameraClamp();

	float getRenderPosX() { return _renderPosX; } // �� ���� ���ο��� �޾Ƽ� ���� ���ݴϴ�.
	float getRenderPosY() { return _renderPosY; }

	int getCamX() { return _rc.left; } // ��� �� �ٸ� ������Ʈ�� ����� ī�޶� ��ǥ
	int getCamY() { return _rc.top; }

};

