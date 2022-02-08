#include "pch.h"
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

HRESULT Enemy::init()
{
	
	return S_OK;
}

HRESULT Enemy::init(const char* imageName, POINT position)
{
	

	_image = IMAGEMANAGER->findImage(imageName);
	_count = _start = _i = 0;
	_posX = position.x;
	_posY = position.y;
	_idX = _posX / TILEWIDTH;
	_idY = _posY / TILEHEIGHT;
	
	_enemyDirection = STOP;
	_speed = 5.0f;	
	setTiles();
	_vGoList.push_back(_endTile);
	_isFind = false;
	_isCheck = false;

	
	return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{

}

void Enemy::render()
{
	
}

void Enemy::setTiles()
{
	_startTile = new tile;
	_startTile->init(_idX, _idY);
	_startTile->setAttribute("start");

	_endTile = new tile;
	_endTile->init(20, 20);
	_endTile->setAttribute("end");

	//���� Ÿ���� ����Ÿ�Ϸ� �д�
	_currentTile = _startTile;

	for (int i = 0; i < 22; ++i)
	{
		for (int j = 0; j < 40; ++j)
		{
			if (j == _startTile->getIdX() && i == _startTile->getIdY())
			{
				_startTile->setColor(RGB(0, 255, 255));
				_vTotalList.push_back(_startTile);
				continue;
			}
			if (j == _endTile->getIdX() && i == _endTile->getIdY())
			{
				_endTile->setColor(RGB(10, 120, 55));
				_vTotalList.push_back(_endTile);
				continue;
			}

			tile* node = new tile;

			node->init(j, i);

			_vTotalList.push_back(node);
		}
	}
}

vector<tile*> Enemy::addOpenList(tile* currentTile)
{
	int startX = currentTile->getIdX() - 1;
	int startY = currentTile->getIdY() - 1;


	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == 0)
			{
				if (j == 0 || j == 2) continue;
			}

			else if (i == 1 && j == 1) continue;

			else if (i == 2)
			{
				if (j == 0 || j == 2)continue;
			}

			tile* node = _vTotalList[(startY * 40) + startX + j + (i * 40)];

			//����ó��
			if (!node->getIsOpen()) continue;
			if (node->getAttribute() == "start") continue;
			if (node->getAttribute() == "wall") continue;



			//���� Ÿ�� �������ش�
			node->setParentNode(_currentTile);

			bool addObj = true;

			for (int i = 0; i < _vOpenList.size(); i++)
			{
				//�̹� �ִ� �ָ�
				if (_vOpenList[i] == node)
				{
					addObj = false;
					break;
				}
			}


			if (node->getAttribute() != "end") node->setColor(RGB(255, 0, 0));

			//�̹� üũ�� �ָ�
			if (!addObj) continue;

			//�ڷ� �Ѿ�� �ʰ� �ϱ����� ���� ó��
			if (node->getIdX() <= 0) continue;
			if (node->getIdX() >= TILEX) continue;
			if (node->getIdY() <= 0) continue;
			if (node->getIdY() >= TILEY) continue;

			_vOpenList.push_back(node);
		}

	}
	return _vOpenList;
}

void Enemy::pathFinder(tile* currentTile)
{
	//���ϱ� ���� ������ ��κ���� �����ؿ�õӽô�
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
		//4 ������ ��� 14�� ���� ������ ��������.
		_vOpenList[i]->setCostFromStart((getDistance(center1.x, center1.y, center2.x, center2.y) > TILEWIDTH) ? 14 : 10);

		//�� ��κ�� ����
		_vOpenList[i]->setTotalCost(_vOpenList[i]->getCostToGoal() +
			_vOpenList[i]->getCostFromStart());

		//�̾Ƴ� �� ��κ�� �߿� ���� ���� ����� �ָ� ã��
		if (tempTotalCost > _vOpenList[i]->getTotalCost())
		{
			tempTotalCost = _vOpenList[i]->getTotalCost();

			tempTile = _vOpenList[i];
		}

		bool addObj = true;

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

	//�����ߴ�
	if (tempTile->getAttribute() == "end")
	{
		_isFind = true;

		//�ִ� ��δ� ��ĥ�ؿ���ݽô�
		while (_currentTile->getParentNode() != nullptr)
		{
			_currentTile->setColor(RGB(22, 14, 128));
			_vGoList.push_back(_currentTile);
			_currentTile = _currentTile->getParentNode();
		}
		return;

	}


	_vCloseList.push_back(tempTile);

	for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
	{
		if (*_viOpenList == tempTile)
		{
			_viOpenList = _vOpenList.erase(_viOpenList);
			break;
		}
	}

	for (int i = 0; i < _vCloseList.size(); i++)
	{
		_vCloseList[i]->setColor(RGB(255, 0, 255));
	}

	_currentTile = tempTile;

	if (_vOpenList.size() == 0) //�����ִ� ���¸���Ʈ�� ���ٸ� �Լ�����.
	{
		_start = false;
		return;
	}

	//����Լ�
	//����Լ��� ���� �ڵ尡 �ſ� ª������ ���������� ������ ������
	//�ӵ��鿡���� ������
	//�� �� �� ȣ��ɶ����� �ҷ��� �޸𸮰� ���̴µ�
	//�� 1.2�ް� �̻� ���̸� �����µ� �̰� ���ÿ����÷ο��� �Ѵ�.
	pathFinder(_currentTile);
}

void Enemy::setEnemyPosition(tile* tile)
{
	tile->setColor(RGB(0, 0, 0));

	if (_idX < tile->getIdX()) _enemyDirection = RIGHT;
	else if (_idX > tile->getIdX()) _enemyDirection = LEFT;
	else if (_idY > tile->getIdY()) _enemyDirection = UP;
	else if (_idY < tile->getIdY()) _enemyDirection = DOWN;

	if (_enemyDirection == RIGHT && _idX >= tile->getIdX()) _isArrive = true;
	if (_enemyDirection == LEFT && _idX < tile->getIdX()) _isArrive = true;
	if (_enemyDirection == UP && _idY < tile->getIdY())   _isArrive = true;
	if (_enemyDirection == DOWN && _idY >= tile->getIdY()) _isArrive = true;
}

void Enemy::Move()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _posX += _speed;
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		_start = true;
	}

	if (_start)
	{
		pathFinder(_currentTile);

		if (_i >= _vGoList.size())
		{
			_isFind = false;
		}

		if (_idX == _endTile->getIdX() && _idY == _endTile->getIdY()) _enemyDirection = STOP;
	}

	if (_isFind)
	{
		setEnemyPosition(_vGoList[_vGoList.size() - 1 - _i]);

		if (_isArrive && !_isCheck)
		{
			_isCheck = true;

			SetIsArrive(false);

			_i++;
		}

		else if (!GetIsArrive()) _isCheck = false;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < _vTotalList.size(); ++i)
		{
			RECT rc = _vTotalList[i]->getRect();
			if (PtInRect(&rc, _ptMouse))
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
	//���Ⱑ ���� �߿��� �κ����� �ͽ���
	RECT rcCollision;	//������ �浹������Ʈ�� �ϳ� ����

	int tileIndex[2];	//Ÿ�� ���⿡ �ʿ��� �ε���
	int tileX, tileY;	//�÷��̾ ��� �ִ� Ÿ���� �ε���

	//������ ������Ʈ�� ���� ��Ʈ�� ����������
	rcCollision = _rc;

	float elapsedTime = TIMEMANAGER->getElapsedTime();
	float moveSpeed = elapsedTime * _speed;

	switch (_enemyDirection)
	{
	case LEFT:
		_posX -= moveSpeed;
		break;
	case UP:
		_posY -= moveSpeed;
		break;
	case RIGHT:
		_posX += moveSpeed;
		break;
	case DOWN:
		_posY += moveSpeed;
		break;
	case STOP:
		_posX += 0;
		_posY += 0;
		break;
	}
	rcCollision = RectMakeCenter(_posX, _posY, _image->getFrameWidth(), _image->getFrameHeight());
	//STEP3
	//������ ������Ʈ�� ���¦ �������
	rcCollision.left += 2;
	rcCollision.top += 2;
	rcCollision.right -= 2;
	rcCollision.bottom -= 2;

	//STEP4
	//���� ������ �ƴұ� ������
	tileX = rcCollision.left / TILESIZE;
	tileY = rcCollision.top / TILESIZE;

	_idX = tileX;
	_idY = tileY;

	switch (_enemyDirection)
	{

	case LEFT:
		tileIndex[0] = tileX + (tileY * TILEX);
		tileIndex[1] = tileX + (tileY + 1) * TILEX;
		break;
	case UP:
		tileIndex[0] = tileX + (tileY * TILEX);
		tileIndex[1] = (tileX + 1) + tileY * TILEX;
		break;
	case RIGHT:
		tileIndex[0] = (tileX + tileY * TILEX) + 1;
		tileIndex[1] = (tileX + (tileY + 1) * TILEX) + 1;
		break;
	case DOWN:
		tileIndex[0] = (tileX + tileY * TILEX) + TILEX;
		tileIndex[1] = (tileX + 1 + tileY * TILEX) + TILEX;
		break;
	}

	_rc = rcCollision;

	_rc = RectMakeCenter(_posX, _posY, _image->getFrameWidth(), _image->getFrameHeight());
}

void Enemy::Draw()
{
	for (int i = 0; i < _vTotalList.size(); ++i)
	{
		_vTotalList[i]->render();
	}

#pragma region Frame
	_frameCount++;
	_image->setFrameX(_frameX);
	_image->setFrameY(_frameY);

	switch (_enemyDirection)
	{
	case DOWN:
		_frameY = 0;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	case RIGHT:
		_frameY = 1;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	case UP:
		_frameY = 2;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	case LEFT:
		_frameY = 3;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	case STOP:
		_frameY = 0;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	}
#pragma endregion

	_image->frameRender(getMemDC(), _posX, _posY, _frameX, _frameY);
}

void Enemy::Collision()
{
}
