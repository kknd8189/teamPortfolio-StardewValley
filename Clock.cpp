#include "pch.h"
#include "Clock.h"

Clock::Clock()
{
}

Clock::~Clock()
{
}

HRESULT Clock::init()
{
	IMAGEMANAGER->addImage("Clock", "source/clock/Clock.bmp", 288, 236, true, MAGENTA);
	_needleMoveImg = IMAGEMANAGER->addFrameImage("NeedleMove", "source/clock/NeedleMove.bmp", 1330, 120, 19, 1, true, MAGENTA);
	_weatherImg = IMAGEMANAGER->addImage("FineDay", "source/clock/FineDay.bmp", 48, 32, true, MAGENTA);
	IMAGEMANAGER->addImage("RainyDay", "source/clock/RainyDay.bmp", 48, 32, true, MAGENTA);
	_seasonImg = IMAGEMANAGER->addImage("Spring", "source/clock/Spring.bmp", 48, 32, true, MAGENTA);
	IMAGEMANAGER->addImage("Summer", "source/clock/Summer.bmp", 48, 32, true, MAGENTA);
	

	_hour = 06;			//���� 6�� ����
	_minute = 00;		//00��
	_date = 1;			//1��
	_weekDay = MON;		//������
	_season = SPRING;	//��
	_weekDayStr = "��";
	_dayNightStr = "����";

	_x = 1000;
	_y = 40;
	_angle = 0.0f;
	_rc = RectMakeCenter(_x, _y,
		_needleMoveImg->getFrameWidth(), _needleMoveImg->getHeight());
	_radius = _needleMoveImg->getFrameWidth() / 2;


	
	
	return S_OK;
}

void Clock::release()
{
}

void Clock::update()
{
	Move();
	_angle += PI20 / 1800 ;
	
}

void Clock::render()
{
	ClockRender();
	
	Font();
	char str[128];
	sprintf_s(str, "X : %d", _ptMouse.x);
	TextOut(getMemDC(), 10, 10, str, strlen(str));
	sprintf_s(str, "Y : %d", _ptMouse.y);
	TextOut(getMemDC(), 10, 30, str, strlen(str));
	sprintf_s(str, "elapsedTime : %f", TIMEMANAGER->getWorldTime());
	TextOut(getMemDC(), 10, 50, str, strlen(str));
	sprintf_s(str, "angle : %f", _angle);
	TextOut(getMemDC(), 10, 70, str, strlen(str));
	sprintf_s(str, "minute : %d", _minute);
	TextOut(getMemDC(), 10, 90, str, strlen(str));
	sprintf_s(str, "hour : %d", _hour);
	TextOut(getMemDC(), 10, 110, str, strlen(str));
	
}

void Clock::ClockRender()
{
	IMAGEMANAGER->findImage("Clock")->render(getMemDC(), 980, 20);
	_weatherImg->render(getMemDC(), 1096, 84);
	_seasonImg->render(getMemDC(), 1192, 84);
	_needleMoveImg->frameRender(getMemDC(), _x, _y);


}

void Clock::MoneyRender()
{
	
	
}

void Clock::Move()
{
	int frame;

	//Ư�� �������� ���������� ������ ��ȣ�� ����Ѵ�.
	frame = int(_angle / PI20);
	_needleMoveImg->setFrameX(frame);

	_worldTime = TIMEMANAGER->getWorldTime();

	if ((int)_worldTime % 5 == 0 && !_isCheck)
	{
		_isCheck = true;
		_minute += 10;
	}
	else if ((int)_worldTime % 5 != 0)
	{
		_isCheck = false;
	}

	if (_minute >= 60)
	{
		_minute = 0;
		_hour++;
	}
	if (_hour >= 26 || KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_hour = 0;
		_minute = 0;
		switch (_weekDay)
		{
		case MON:
			_weekDay = TUE;
			_weekDayStr = "ȭ";
			_hour = 6;
			break;
		case TUE:
			_weekDay = WED;
			_weekDayStr = "��";
			_hour = 6;
			break;
		case WED:
			_weekDay = THU;
			_weekDayStr = "��";
			_hour = 6;
			break;
		case THU:
			_weekDay = FRI;
			_weekDayStr = "��";
			_hour = 6;
			break;
		case FRI:
			_weekDay = SAT;
			_weekDayStr = "��";
			_hour = 6;
			break;
		case SAT:
			_weekDay = SUN;
			_weekDayStr = "��";
			_hour = 6;
			break;
		case SUN:
			_weekDay = MON;
			_weekDayStr = "��";
			_hour = 6;
			break;
		}
		_date++;
	}

	if (_date > 28)
	{
		_date = 0;
		_season = SUMMER;
	}

	_elapsedTime = TIMEMANAGER->GetWorldElapsedTime();
	

	if (_angle >= PI)
	{
		_angle -= PI;
		TIMEMANAGER->SetWorldElapsedTime(0);
	}
	if (_angle <= 0) _angle += PI;

	//_x += cosf(_angle) * 0;
	//_y += -sinf(_angle) * 0;

	_rc = RectMakeCenter(_x, _y,
		_needleMoveImg->getFrameWidth(), _needleMoveImg->getFrameHeight());
}

void Clock::Font()
{
	//��, ��, ��������
	char str[256];
	char str2[256];
	HFONT oldFont, font1;
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	RECT rcText = RectMake(1040, 100, 200, 100);
	HFONT font2 = CreateFont(40, 0, 0, 0, 400, true, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("sandoll �̻�"));
	HFONT oldFont2 = (HFONT)SelectObject(getMemDC(), font2);
	sprintf_s(str, "%.2d : %.2d", _hour, _minute);
	if (_hour < 12 || _hour >=24)
	{
		sprintf_s(str2, "����", strlen(str2));
	}
	else if (_hour >=12 && _hour < 24)
	{
		sprintf_s(str2, "����", strlen(str2));
	}
	TextOut(getMemDC(), 1195, 128, str2, strlen(str2));
	SetBkMode(getMemDC(), 0);
	DrawText(getMemDC(), TEXT(str), 7, &rcText, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	SelectObject(getMemDC(), oldFont2);
	DeleteObject(font2);

	//����, ����
	char str3[256];
	char str4[256];
	HFONT oldFont3, font3;
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	RECT rcText2 = RectMake(1130, 5, 200, 100);
	HFONT font4 = CreateFont(40, 0, 0, 0, 400, false, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("sandoll �̻�"));
	HFONT oldFont4 = (HFONT)SelectObject(getMemDC(), font4);
	switch (_weekDay)
	{
	case MON:
		sprintf_s(str4, "��,", strlen(str4));
		break;
	case TUE:
		sprintf_s(str4, "ȭ,", strlen(str4));
		break;
	case WED:
		sprintf_s(str4, "��,", strlen(str4));
		break;
	case THU:
		sprintf_s(str4, "��,", strlen(str4));
		break;
	case FRI:
		sprintf_s(str4, "��,", strlen(str4));
		break;
	case SAT:
		sprintf_s(str4, "��,", strlen(str4));
		break;
	case SUN:
		sprintf_s(str4, "��,", strlen(str4));
		break;
	}
	sprintf_s(str3, "%d", _date);
	TextOut(getMemDC(), 1130, 35, str4, strlen(str4));
	SetBkMode(getMemDC(), 0);
	DrawText(getMemDC(), TEXT(str3), 7, &rcText2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	SelectObject(getMemDC(), oldFont4);
	DeleteObject(font4);
	
}
/*
	CreateFont(
		40,			//������
		0,			//���� ����
		40,			//���� ����(��¥ ������)
		0,			//���� ����
		600,		//���� ����
		0,			//bool ���� ���� ���Ÿ�ü �������
		0,			//bool ���� ����
		0,			//bool ���� ��Ҽ� (������Ű�� ���� �װ�)
		HANGUL_CHARSET,	//���� ����
		0,				//��� ��Ȯ��
		0,				//Ŭ���� ��Ȯ��
		0,				//����� ����Ƽ
		0,				//�ڰ�
		TEXT("�ü�ü"));	//��Ʈ
	*/
	/*


	font1 = CreateFont(50, 0, 0, 0, 100, true, true, true, HANGUL_CHARSET, 0, 0, 0, 50, TEXT("�޸ձ���"));
	oldFont = (HFONT)SelectObject(getMemDC(), font1);
	sprintf_s(str, "��Ʈ�� ĸ�� ���̾�");
	TextOut(getMemDC(), 10, 100, str, strlen(str));
	DeleteObject(font1);
	*/