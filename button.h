#pragma once
#include "gameNode.h"

//�Լ������� ���¸� ���� �ݹ��Լ�
typedef void(*CALLBACK_FUNCTION_)(void);
typedef void(*CALLBACK_FUNCTION_PARAMETER)(void*);



//���β���~ ���� ���ϼŵ� �˴ϴ� ����
//<Functional> �̷� ���̺귯���� �ִµ�
//std::Function, std::move, std::bind ����� �Լ��� ������
//��� �� ��� ����ϰ� �Ǹ� �Ϲ����� �Ű������� ���� �ݹ��Լ��� ����� �� ����.

//����1) �ʹ� �ǿܷ� ������ ��¥ �̰� �����ΰ�? �ǹ��� ����ִ�
//����) Lambda expression, ���ٽ��̶� ����� �ʹ� ����
//      ���ٽ� == �͸��Լ� <-- �����غ��� �ҿ����ϴ�
//�Լ�<>{}


enum BUTTONDIRECTION
{
	BUTTONDIRECTION_NULL,
	BUTTONDIRECTION_UP,
	BUTTONDIRECTION_DOWN
};

class button : public gameNode
{
private:
	BUTTONDIRECTION _direction;

	const char* _imageName;
	image* _image;
	RECT _rc;
	float _x, _y;

	void* _obj;

	POINT _btnDownFramePoint;
	POINT _btnUpFramePoint;

	//�ݹ��Լ� ����
	CALLBACK_FUNCTION_ _callbackFunction;
	CALLBACK_FUNCTION_PARAMETER _callbackFunctionParameter;

public:
	button();
	~button();

	HRESULT init(const char* imageName, int x, int y,
		POINT btnDownFramePoint, POINT btnUpFramePoint,
		CALLBACK_FUNCTION_ cbFunction);

	HRESULT init(const char* imageName, int x, int y,
		POINT btnDownFramePoint, POINT btnUpFramePoint,
		CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);


	HRESULT init(const char* imageName, int x, int y,
		POINT btnDownFramePoint, POINT btnUpFramePoint);


	void release();
	void update();
	void Update();
	void render();
	void render(bool isToggled);

	BUTTONDIRECTION getBtnDir() { return _direction; }
	void setBtnDir(BUTTONDIRECTION dir) { _direction = dir; }

	int	getButtonX() { return _x; }
	void setButtonX(int x) { _x = x; }
};

