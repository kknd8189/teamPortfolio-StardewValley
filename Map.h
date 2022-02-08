#pragma once
#include "tileNode.h"
#include "gameNode.h"
#include "button.h"



enum CTRL
{
	CTRL_SAVE,			//���̺�		��ư
	CTRL_LOAD,			//�ε�		��ư
	CTRL_TERRAINDRAW,	//����		��ư
	CTRL_OBJDRAW,		//������Ʈ	��ư
	CTRL_ERASER,		//���찳		��ư
	CTRL_END
};

struct tagCurrentTile
{
	int x;
	int y;
	CTRL ctrl;
	string str;
	int page;
};


class Map : public gameNode
{
private:
	tagTile _tiles[TILEX * TILEY];		//Ÿ��
	DWORD _attribute[TILEX * TILEY];	//Ÿ�ϼӼ�

	tagCurrentTile _currentTile;
	tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY];

	string _currentSampleString;

	RECT _dragRC;

	image* _background;
	image* _currentSample;

	button* _buttonSave;
	button* _buttonLoad;
	button* _buttonDraw;
	button* _buttonObject;
	button* _buttonErase;
	button* _buttonLeft;
	button* _buttonRight;
	button* _buttonDragMode;

	int _pos[2];
	int _ctrSelect;
	int _ctrPage;

	bool _isPicked;
	bool _isSample;
	bool _isDragMode;
	bool _isStart;

	float _posX, _posY;
	float _rendX, _rendY;
	float _dragStartX, _dragStartY;

public:
	Map();
	~Map();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void save();
	void load();

	void Movement();
	
	void RectSensor();

	void DrawTile();
	void DrawObject();

	void SetSample();
	void ChangeSample();
	void PickSample();
	void DrawMap();
	void DragMap(bool isDrag);
	void AutoDraw(tagTile* currentTile);

	static void Button(void* obj);

	tagTile* getTile() { return _tiles; }

	//STEP2
	//Ÿ�ϼӼ��� ���� �����ڵ� ������־�� �Ҳ��ϴ�
	DWORD* getAttribute() { return _attribute; }

	TERRAIN terrainSelect(int frameX, int frameY, int page);
	OBJECT objSelect(int frameX, int frameY, int page);

	//�츰 ����ϰ� ���� �ʽ��ϴ�
	int getPosFirst() { return _pos[0]; }
	int getPosSecond() { return _pos[1]; }

	bool getDragMode() { return _isDragMode; }
};

