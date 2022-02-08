#include "pch.h"
#include "aStarTest.h"


aStarTest::aStarTest()
{
}

aStarTest::~aStarTest()
{
}

HRESULT aStarTest::init()
{
	setTiles();

	_count = _start = 0;


	return S_OK;
}

void aStarTest::setTiles() // Ÿ�� ����
{
	_startTile = new tile;
	_startTile->init(4, 12);
	_startTile->setAttribute("start");

	_endTile = new tile;
	_endTile->init(20, 12);
	_endTile->setAttribute("end");

	//���� Ÿ���� ����Ÿ�Ϸ� �д�
	_currentTile = _startTile;

	for (int i = 0; i < TILENUMY; ++i) // �� ���̸�ŭ
	{
		for (int j = 0; j < TILENUMX; ++j) // �� ���̸�ŭ
		{
			if (j == _startTile->getIdX() && i == _startTile->getIdY()) // ������ ����ϰ�� �������� ���Ϳ� ����ִ´�.
			{
				_startTile->setColor(RGB(0, 255, 255));
				_vTotalList.push_back(_startTile);
				continue;
			}
			if (j == _endTile->getIdX() && i == _endTile->getIdY()) // ������ ����ϰ�� �������� ���Ϳ� ����ִ´�.
			{
				_endTile->setColor(RGB(10, 120, 55));
				_vTotalList.push_back(_endTile);
				continue;
			}

			tile* node = new tile; // �̿ܿ� ������ ��� �ʱ�ȭ �� ���Ϳ� ����ִ´�.
			node->init(j, i);
			_vTotalList.push_back(node);
		}
	}
}

//�����ִ� ���� �߰��ϴ� �Լ�
vector<tile*> aStarTest::addOpenList(tile* currentTile)
{
	//�˻� �������� ������� ���� ����
	int startX = currentTile->getIdX() - 1; 
	int startY = currentTile->getIdY() - 1;

	// �ڽ��� ������ 9ĭ�� �˻�
	for (int i = 0; i < 3; ++i) 
	{
		for (int j = 0; j < 3; ++j)
		{
			tile* node = _vTotalList[(startY * TILENUMX) + startX + j + (i * TILENUMX)]; //��带 ���λ����Ͽ� �˻��� ��带 ����

			//����ó��
			if (!node->getIsOpen()) continue;
			if (node->getAttribute() == "start") continue;
			if (node->getAttribute() == "wall") continue;

			//���� Ÿ�� �������ش�
			node->setParentNode(_currentTile);

			bool addObj = true; 

			for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
			{
				//�̹� �ִ� �ָ�
				if (*_viOpenList == node)
				{
					addObj = false;
					break;
				}
			}

			if (node->getAttribute() != "end") node->setColor(RGB(128, 64, 28));

			//�̹� üũ�� �ָ�
			if (!addObj) continue;

			_vOpenList.push_back(node);
		}
	}

	return _vOpenList;
}

//���� ã�ƶ�~
void aStarTest::pathFinder(tile* currentTile)
{
	//���ϱ� ���� ������ ��κ���� �����صд�
	float tempTotalCost = 5000;
	tile* tempTile = nullptr;

	//���¸���Ʈ ���� �ȿ��� ���� ���� ��θ� �̾Ƴ���
	for (int i = 0; i < addOpenList(currentTile).size(); ++i)
	{
		//H �� ����
		_vOpenList[i]->setCostToGoal(
			(abs(_endTile->getIdX() - _vOpenList[i]->getIdX()) +
			abs(_endTile->getIdY() - _vOpenList[i]->getIdY())) * 10);
		
	
		POINT center1 = _vOpenList[i]->getParentNode()->getCenter();
		POINT center2 = _vOpenList[i]->getCenter();
		//G �� ����
		_vOpenList[i]->setCostFromStart((getDistance(center1.x, center1.y, center2.x, center2.y) > TILEWIDTH) ? 14 : 10);

		//�� ��κ�� ����
		_vOpenList[i]->setTotalCost(_vOpenList[i]->getCostToGoal() +
									_vOpenList[i]->getCostFromStart());


		//�̾Ƴ� �� ��κ�� �߿� ���� ���� ��� �˻�
		if (tempTotalCost > _vOpenList[i]->getTotalCost())
		{
			tempTotalCost = _vOpenList[i]->getTotalCost();
			tempTile = _vOpenList[i];
		}

		bool addObj = true;
		
		//���� ��κ���� ������尡 �����ٸ� �ش� ���� �˻����� ������
		for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
		{
			if (*_viOpenList == tempTile)
			{
				addObj = false;
				break;
			}
		}

		_vOpenList[i]->setIsOpen(false);
		if (!addObj) continue;

		_vOpenList.push_back(tempTile);
	}

	//����
	if (tempTile->getAttribute() == "end")
	{
		//�ִ� ��� ��ĥ
		while (_currentTile->getParentNode() != NULL)
		{
			_currentTile->setColor(RGB(22, 14, 128));
			_currentTile = _currentTile->getParentNode();
		}
		return;
	}

	_vCloseList.push_back(tempTile);

	//�߰���� �˻�
	for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
	{
		if (*_viOpenList == tempTile)
		{
			_viOpenList = _vOpenList.erase(_viOpenList);
			break;
		}
	}

	_currentTile = tempTile;

	//����Լ�
	//����Լ��� ���� �ڵ尡 �ſ� ª������ ���������� ������ ������
	//�ӵ��鿡���� ������
	//�� �� �� ȣ��ɶ����� �ҷ��� �޸𸮰� ���̴µ�
	//�� 1.2�ް� �̻� ���̸� �����µ� �̰� ���ÿ����÷ο��� �Ѵ�.
	//pathFinder(_currentTile);
}

void aStarTest::release()
{
}

void aStarTest::update()
{

	if (KEYMANAGER->isToggleKey(VK_TAB)) _start = false;
	else _start = true;


	if(KEYMANAGER->isOnceKeyDown(VK_SPACE))pathFinder(_currentTile);

	if (_start)
	{
		_count++;
		if (_count % 1 == 0)
		{
			pathFinder(_currentTile);
			_count = 0;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < _vTotalList.size(); ++i)
		{
			RECT temp = _vTotalList[i]->getRect();
			if (PtInRect(&temp, _ptMouse))
			{
				if (_vTotalList[i]->getAttribute() == "start") continue;
				if (_vTotalList[i]->getAttribute() == "end") continue;

				_vTotalList[i]->setIsOpen(false);
				_vTotalList[i]->setAttribute("wall");
				_vTotalList[i]->setColor(RGB(230, 140, 200));
				break;
			}
		}
	}


}

void aStarTest::render()
{
	for (int i = 0; i < _vTotalList.size(); ++i)
	{
		_vTotalList[i]->render();
	}
}
