#pragma once
#include "gameNode.h"


class CameraManager;

enum ALLOBJECTS
{
	//�⺻�ڿ�
	OBJ_WOOD,
	OBJ_STONE,

	//���� WEAPON

	OBJ_SWORD,			//��
	OBJ_SLINGSHOT,		//����

	//������ FISH

	OBJ_PUFFERFISH,		//Ȳ�ݖþ�
	OBJ_TUNA,			//����
	OBJ_HALIBUT,		//�ξ�

	//���� SEED

	OBJ_CAULIFLOWERSEED,
	OBJ_PARSNIPSEED,
	OBJ_POTATOSEED,
	OBJ_KALESEED,

	//�۹� CROPS
	
	OBJ_CAULIFLOWER,	//�ݸ��ö��	350G	195Hp	87Sp	
	OBJ_PARSNIP,		//�Ľ���		220G	65Hp	29Sp
	OBJ_POTATO,			//����		150G	65Hp	29Sp
	OBJ_KALE,			//����		220G	130Hp	58Sp

	//���� ORE
	OBJ_COPPER,			//����		 5G
	OBJ_IRON,			//ö			10G
	OBJ_GOLD,			//���		25G
	
	//����
	OBJ_BOX,
	OBJ_FURNACE,
	OBJ_SCARECROW1,
	OBJ_SCARECROW2,
};

class object : public gameNode
{
protected:
	ALLOBJECTS	_obj;
	RECT		_objectRc;
	image*		_objectImg;
	int			_frameX, _frameY;
	float		_posX, _posY;
	float		_speed;
	int			_objectNum;
	bool		_isdelete;

	CameraManager* _cm;


public:
	object();
	~object();

	virtual HRESULT init(ALLOBJECTS obj, const char* imageName, int framex, int framey, POINT pos, int objNum);
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void itemSetup();

	void Draw(int camX,int camY);



	//======================= ������ & ������ ======================= //
	ALLOBJECTS GetObjectType() { return _obj; }

	RECT GetObjectRect() { return _objectRc; }
	void SetObjectRect(RECT rc) { _objectRc = rc; }

	float GetObjectPosX() { return _posX; }
	void SetObjectPosX(float posx) { _posX = posx; }

	float GetObjectPosY() { return _posY; }
	void SetObjectPosY(float posy) { _posY = posy; }

	float GetObjectSpeed() { return _speed; }
	void SetObjectSpeed(float spd) { _speed = spd; }

	bool GetObjectDelete() { return _isdelete; }
	void SetObjectDelete(bool del) { _isdelete = del; }
	//======================= ============== ======================= //
	
	//=======================   �޸� ��ũ   ======================= //
	void SetCameraManagerMemoryLink(CameraManager* cm) { _cm = cm; }

	//======================= ============== ======================= //
};

