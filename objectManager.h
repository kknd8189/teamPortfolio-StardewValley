#pragma once
#include "gameNode.h"
#include <vector>

#pragma region object
#include "axe.h"
#include "pickAxe.h"
#include "sickle.h"
#include "hoe.h"
#include "can.h"
#include "rod.h"

#include "sword.h"
#include "slingShot.h"

#include "pufferFish.h"
#include "tuna.h"
#include "haliBut.h"

#include "cauliFlower.h"
#include "parsnip.h"
#include "potato.h"
#include "kale.h"

#include "cauliFlowerSeed.h"
#include "parsnipSeed.h"
#include "potatoSeed.h"
#include "kaleSeed.h"

#include "copper.h"
#include "iron.h"
#include "gold.h"

#include "wood.h"
#include "stone.h"
#include "Box.h"
#include "furnance.h"
#include "scarecrow1.h"
#include "scarecrow2.h"

#pragma endregion

class inventory;
class CameraManager;
class entity;


class objectManager : public gameNode
{
private:
	vector<object*>				_vObject;
	vector<object*>::iterator	_viObject;

private:

	
	//����
	inventory* _inven;
	//������Ʈ
	axe*				_axe;
	pickAxe*			_pickAxe;
	hoe*				_hoe;
	can*			    _can;
	rod*				_rod;
	sickle*				_sickle;
	//����
	sword*				_sword;
	slingShot*			_slingShot;

	//����
	pufferFish*			_pufferFish;
	tuna*				_tuna;
	haliBut*			_halibut;

	//����
	cauliFlowerSeed*	_cauliFlowerSeed;
	parsnipSeed*		_parsnipSeed;
	potatoSeed*			_potatoSeed;
	kaleSeed*			_kaleSeed;

	//�۹�
	cauliFlower*		_cauliFlower;
	parsnip*			_parsnip;
	potato*				_potato;
	kale*				_kale;

	//����
	copper*				_copper;
	iron*				_iron;
	gold*				_gold;

	wood*				_wood;
	stone*				_stone;
	
	Box* _box;
	furnance* _furnance;
	scarecrow1* _crow1;
	scarecrow2* _crow2;


	int _objectNum;

	CameraManager* _cm;

	entity* _player;

public:
	objectManager();
	~objectManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void SetWood(float x, float y, int amount);
	void SetStone(float x, float y, int amount);

	//��	��
	void SetPufferFish(float x, float y, int amount);
	void SetTuna(float x, float y, int amount);
	void SetHaliBut(float x, float y, int amount);

	//��	��
	void SetCauliFlowerSeed(float x, float y, int amount);
	void SetParsnipSeed(float x, float y, int amount);
	void SetPotatoSeed(float x, float y, int amount);
	void SetKaleSeed(float x, float y, int amount);

	//�۹�
	void SetCauliFlower(float x, float y, int amount);
	void SetParsnip(float x, float y, int amount);
	void SetPotato(float x, float y, int amount);
	void SetKale(float x, float y, int amount);

	//����
	void SetCopper(float x, float y, int amount);
	void SetIron(float x, float y, int amount);
	void SetGold(float x, float y, int amount);


	void SetBox(float x, float y, int amount);
	void SetFurnance(float x, float y, int amount);
	void SetScarecrow1(float x, float y, int amount);
	void SetScarecrow2(float x, float y, int amount);




	void ObjectCollsion();

	//======================= ������ & ������ ======================= //
	vector<object*> GetVObject() { return _vObject; }
	vector<object*>::iterator GetVIObject() { return _viObject; }

	//======================= ============== ======================= //
	//=======================   �޸� ��ũ   ======================= //
	void SetInventoryMemoryLink(inventory* inven) { _inven = inven; }

	void SetObjectCameraManagerMemoryLink(CameraManager* cm) { _cm = cm; }

	void SetplayerMemoryLink(entity* pl) { _player = pl; }

	//======================= ============== ======================= //








};

