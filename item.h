#pragma once
#include "gameNode.h"

//��ü������ 
enum ALLITEMS
{
	//�⺻�ڿ�
	WOOD,
	STONE,

	//���� TOOLS
	AXE,			//����
	PICKAXE,		//���
	HOE,			//ȣ��
	SICKLE,			//��
	CAN,			//��������	
	ROD,			//���ô�

	//���� WEAPON
	
	SWORD,			//��
	SLINGSHOT,		//����
	
	//������ FISH
	
	PUFFERFISH,		//Ȳ�ݖþ�
	TUNA,			//����
	HALIBUT,		//�ξ�
	
	//���� SEED
	
	CAULIFLOWERSEED,
	PARSNIPSEED,
	POTATOSEED,
	KALESEED,
	
	//�۹� CROPS
	
	CAULIFLOWER,	//�ݸ��ö��	350G	195Hp	87Sp	
	PARSNIP,		//�Ľ���		220G	65Hp	29Sp
	POTATO,			//����		150G	65Hp	29Sp
	KALE,			//����		220G	130Hp	58Sp
	
	//���� ORE
	COPPER,			//����		 5G
	IRON,			//ö			10G
	GOLD,			//���		25G

	//NONE;
	NONE
};
enum CRAFTITEMS
{
	BOX,
	FURNACE,
	SCARECROW1,
	SCARECROW2,
};
struct ITEMS
{
	//����ü�� �������
	ALLITEMS    items;						//�������� ����
	CRAFTITEMS  craftItems;
	image*		itemImg;					//������Ʈ �̹���

	//�κ��丮���� ���ٰ͵�
	string			itemName;					//������ �̸�
	string			itemInfo;					//������ ����

	POINT		pos;

	//�������� ������ ����
	int			frameX, frameY;			    //�������̹��� ��ġ
	int			buyPrice;					//�������� ���Ű�
	int			sellPrice;					//�������� �ǸŰ���
	int			damage;						//���ݷ�
	int			hP;							//ü���� ä���ش�.
	int			sP;							//���¹̳��� ä���ش�.
	//int			amount;						//����

	int			needAmountToCraft;			//�����ϴµ� �ʿ��� ����
	int			itemNum;                    // ������ ���� �ѹ�

	BOOL		isHandleAble;				//�տ��������� ����?
	BOOL		isEatAble;					//������ �ִ� ����
};


class item : public gameNode
{
protected:
	ITEMS _item;

public:
	item();
	~item();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(int x, int y);


	//void amountAdd() { _item.amount++; }

	//======================= ������ & ������ ======================= //
	ITEMS GetItemInfo() { return _item; }
	void  SetItemInfo(ITEMS item) { _item = item; }
	//======================= ============== ======================= //
	

	//=======================   �޸� ��ũ   ======================= //
	// 
	//======================= ============== ======================= //

};

