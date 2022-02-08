#pragma once
#include "gameNode.h"
#include <vector>
//�̰� ���� ��ũ��Ÿ�� ����
#pragma region items

#include "itemStone.h"
#include "itemWood.h"
#include "itemBox.h"
#include "itemFurNance.h"
#include "itemScareCrow1.h"
#include "itemScareCrow2.h"

#include "itemCauliFlower.h"
#include "itemKale.h"
#include "itemParsnip.h"
#include "itemPotato.h"

#include "itemHaliBut.h"
#include "itemPufferFish.h"
#include "itemTuna.h"

#include "itemCopper.h"
#include "itemGold.h"
#include "itemIron.h"

#include "itemCauliSeed.h"
#include "itemKaleSeed.h"
#include "itemPotatoSeed.h"
#include "itemParsnipSeed.h"

#include "itemSlingShot.h"
#include "itemSword.h"

#include "itemAxe.h"
#include "itemPickAxe.h"
#include "itemCan.h"
#include "itemRod.h"
#include "itemHoe.h"
#include "itemSickle.h"

#pragma endregion
#include "itemNull.h"
#include <algorithm>



#define INVENTORYSIZE 36
#define QUICKSLOTSIZE 36

class button;
class player;
class CameraManager;
class objectManager;
class boxInventory;

enum CRAFTITEM 
{
	CRAFTBOX,
	CRAFTFURNANCE,
	CRAFTCROW1,
	CRAFTCROW2,
	CRAFTNULL
};


enum MenuPage
{
	InvenPage,
	CraftPage,
	SettingPage,
	ExitPage,
};
enum PLAYERTOOL
{
	PLAYERTOOL_AXE,
	PLAYERTOOL_CAN,
	PLAYERTOOL_HOE,
	PLAYERTOOL_PICKAXE,
	PLAYERTOOL_ROD,
	PLAYERTOOL_SICKLE,
	PLAYERTOOL_SWORD,
	PLAYERTOOL_ITEMS,
	PLAYERTOOL_NULL
};

struct tagInventory
{
	int		amount;
	bool	itemExist;
	RECT	rc;				//�޴� ĭ���� ���� ĭ��	
};

struct tagFrame
{
	image* img;
	RECT rc;
	float x, y;
};

struct tagSelectV
{
	image* img;
	RECT rc;
	RECT src;
	float x, y;
	float sx, sy;
	float cx, cy;
};



class inventory : public gameNode
{
private:
	vector<item*>				_vInven;
	vector<item*>::iterator		_viInven;

	//������ ������
#pragma region itemnew

	itemStone*			_stone;
	itemWood*			_wood;

	itemBox*			_box;
	itemFurNance*		_furnance;
	itemScareCrow1*		_scareCrow1;
	itemScareCrow2*		_scareCrow2;

	itemCauliFlower*	_cauliFlower;
	itemKale*			_kale;
	itemParsnip*		_parsnip;
	itemPotato*			_potato;

	itemHaliBut*		_halibut;
	itemPufferFish*		_pufferFish;
	itemTuna*			_tuna;

	itemCopper*			_copper;
	itemGold*			_gold;
	itemIron*			_iron;

	itemCauliSeed*		_cauliSeed;
	itemKaleSeed*		_kaleSeed;
	itemParsnipSeed*	_parsnipSeed;
	itemPotatoSeed*		_potatoSeed;

	itemAxe*			_axe;
	itemPickAxe*		_pickAxe;
	itemCan*			_can;
	itemHoe*			_hoe;
	itemRod*			_rod;
	itemSickle*			_sickle;

	itemSlingShot*		_slingShot;
	itemSword*			_sword;

	itemNull*			_null;
#pragma endregion
	
	CRAFTITEMS _craft;
	MenuPage _menuPage;

	tagInventory _inven[INVENTORYSIZE];
	tagInventory _quick[QUICKSLOTSIZE];

	//���� �����ִ� �޴� �̹���
	image* _currentMenuImg;

	//������
	image* _quickSlot;

	//������â
	RECT	_quickSlotRc;

	//���� �޴�â
	RECT	_menuRc;

	//�޴� �̹�����
	image* _invenImg;
	image* _statImg;
	image* _craftImg;
	image* _settingImg;
	image* _exitImg;
	image* _itemInfoImg;
	image* _BOXImg;
	
	//���ۿ�
	image* _craftObjImg[4];
	image* _alphaObjImg[4];
	//�޴��ٲٴ� ��ư��?
	RECT	_storageRc;
	RECT	_craftRc;
	RECT	_settingRc;
	RECT	_exitRc;
	RECT	_BOXRc;

	RECT	_craftObjRc[4];
	//�޴��� ���Ǵ���
	BOOL _isMenuOpen;

	//�巡�� ������
	BOOL _dragActivate;

	//�������� �ε���
	int _downPtItem;
	//�������� �ε���
	int _upPtItem;

	int _quickSlotMin;
	int _quickSlotMax;

	int _nowQuickItem;

	int woodTemp;
	int stoneTemp;
	int ironTemp;
	int copperTemp;

	//�κ� ������
	BOOL	_invenIsFull;

	//��ư��
	button* _buttonToMenu;
	button* _buttonExit;
	//���۰����ϴ�?
	BOOL	_canBox;
	BOOL	_canFur;
	BOOL	_canCrow1;
	BOOL	_canCrow2;
	
	CRAFTITEM _CRAFT;
	PLAYERTOOL _playerTool;
	player* _player;
	CameraManager* _cm;
	objectManager* _om;
	boxInventory* _boxInventory;

	tagFrame	 _frame;
	tagSelectV	 _select[2];
	RECT		 _volumeRC[20];

	float _currentTotalVolume, _currentSFXVolume;
	bool _isClickUp, _isClickDown;


public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	void MenuOpen();
	void SelectMenu();

	void QuickSlot();
	void MenuInvetoryOpen();
	void MenuCraftOpen();



	//NULL�� �ִ� ���ʹ� ����� ���ִ� 
	void AddItem(item* item);
	

	static void Button(void* obj);

	void checkPlayerTool();

	

	//������� �۾��Լ�
	void SettingInit();
	void SettingUpdate();
	void SettingRender();
	void SettingVolumeFrame();

	void saveInventory();

	void loadInventory();

	void drawOnThePlayer();

	void eraseSelectQuickNum();

	void SetInventory(item* item, int num);


	//======================= ������ & ������ ======================= //
	vector<item*> GetvInven() { return _vInven; }
	vector<item*>::iterator GetviInven() { return _viInven; }

	void SetvInven(vector<item*> vi) { _vInven = vi; }

	MenuPage GetMenuPage() { return _menuPage; }
	void SetMenuPage(MenuPage page) { _menuPage = page; }


	tagInventory* GetInven() { return _inven; } 


	BOOL GetIsMenuOpen() { return _isMenuOpen; }
	void SetIsMenuOpen(BOOL open) { _isMenuOpen = open; }

	int GetQuickItemType() { return _nowQuickItem; }
	void SetQuickItemType(int now) { _nowQuickItem = now; }
	
	PLAYERTOOL getPlayerTool() { return _playerTool; }
	CRAFTITEM getCraft() { return _CRAFT; }


	//======================= ============== ======================= //
	itemStone* GetStone() { return _stone; }
	itemWood* GetWood() { return _wood; }

	itemBox* GetBox() { return _box; }
	itemFurNance* GetFurNance() { return _furnance; }
	itemScareCrow1* GetCrow1() { return _scareCrow1; }
	itemScareCrow2* GetCrow2() { return _scareCrow2; }

	itemCauliFlower* GetCauliFlower() { return _cauliFlower; }
	itemKale* GetKale() { return _kale; }
	itemParsnip* GetParsnip() { return _parsnip; }
	itemPotato* GetPotato() { return _potato; }

	itemHaliBut* GetHaliBut() { return _halibut; }
	itemPufferFish* GetPufferFish() { return _pufferFish; }
	itemTuna* GetTuna() { return _tuna; }

	itemCopper* GetCopper() { return _copper; }
	itemGold* GetGold() { return _gold; }
	itemIron* GetIron() { return _iron; }

	itemCauliSeed* GetCauliSeed() { return _cauliSeed; }
	itemKaleSeed* GetKaleSeed() { return _kaleSeed; }
	itemParsnipSeed* GetParsnipSeed() { return _parsnipSeed; }
	itemPotatoSeed* GetPotatoSeed() { return _potatoSeed; }
	itemNull* GetNull() { return _null; }

	//=======================   �޸� ��ũ   ======================= //
	void SetPlayerMemoryLink(player* pl) { _player = pl; }

	void SetCameraMemoryLink(CameraManager* cm) { _cm = cm; }

	void SetObjectManagerMemoryLink(objectManager* om) { _om = om; }

	void SetBoxInventory(boxInventory* bi) { _boxInventory = bi; }
	//======================= ============== ======================= //
};







