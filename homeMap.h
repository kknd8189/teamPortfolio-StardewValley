#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include "object.h"

#define TILEHEIGHT 32
#define TILEWIDTH 32

class CameraManager;

class homeMap : public gameNode
{
private:
	tagTile _tiles[TILEX * TILEY];		//Ÿ��
	DWORD _attribute[TILEX * TILEY];	//Ÿ�ϼӼ�

	CameraManager* _cameraManager;

	int _pos[2];

public:
	homeMap();
	~homeMap();

	HRESULT init();
	void release();
	void update();
	void render();
	
	void load();

	void DrawTile(float posX, float posY);
	void DrawObject(float posX, float posY, int pT);

	void CultivateTile(int num);
	void PlaceObject(ALLOBJECTS object, int num);
	void RemoveObject(int num);

	tagTile* getTile() { return _tiles; }
	
	//STEP2
	//Ÿ�ϼӼ��� ���� �����ڵ� ������־�� �Ҳ��ϴ�
	DWORD* getAttribute() { return _attribute; }
	OBJECT objSelect(int frameX, int frameY);

	//�츰 ����ϰ� ���� �ʽ��ϴ�
	int getPosFirst() { return _pos[0]; }
	int getPosSecond() { return _pos[1]; }

	void setCameraLink(CameraManager* cm) { _cameraManager = cm; }
};

