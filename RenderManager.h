#pragma once
#include "singletonBase.h"

#include <vector>


#define ARRSIZE 10


class entity;

class RenderManager :  public singletonBase<RenderManager>
{
private:

	typedef vector<entity*>					arrRender;
	typedef vector<entity*>::iterator		iterRender;

	int _arr[ARRSIZE] = { 2 , 5 ,1 , 4 , 7 , 8 , 9, 3, 11, 10 }; // �׽�Ʈ�� �迭

private:
	arrRender _vRender;
	iterRender _viRender;

public:
	RenderManager();
	~RenderManager();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void swap(entity** a, entity** b);
	void selectionSort();
	void addRender(entity* obj); // �ٸ� ��ü���� �ڽ��� �����Ŵ����� ��Ͻ�ų�� ����.
	void removeRender(int arrNum);
};

