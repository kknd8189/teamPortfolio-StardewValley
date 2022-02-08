#pragma once
#include "gameNode.h"
#include <string>


enum WEATHER
{
    FINE, RAINY, SNOW, THUNDER
};

enum DAYNIGHT
{
    DAY, NIGHT
};

enum SEASON
{
    SPRING, SUMMER, FALL, WINTER
};

enum WEEKDAY
{
    MON, TUE, WED, THU, FRI, SAT, SUN
};

class Clock :
    public gameNode
{
private:
    image* _seasonImg;         //����
    image* _weatherImg;        //����
    image* _dayNightImg;       //�㳷
    image* _needleMoveImg;     //��ħ
    WEATHER _weather;       //��¥
    DAYNIGHT _dayNight;     //�㳷
    SEASON _season;         //����
    WEEKDAY _weekDay;           //����
    
    RECT _rc;               //��ħ ��Ʈ
    float _x, _y;           //��ħ ��ǥ
    float _angle;           //��ħ ����
    float _radius;          //��ħ ����
    float _moveSpeed;       //�ð� ���
    float _elapsedTime;     //��� �ð�
    float _worldTime;       //���� Ÿ��
    int _dayCount;          //���� üũ
    string _weekDayStr;     //���� str
    string _dayNightStr;    //�������� str

    int _hour, _minute, _date;
    bool _isCheck;

   

public:
    Clock();
    ~Clock();
    virtual HRESULT init();
    virtual void release();
    virtual void update();
    virtual void render();

    void ClockRender();
    void MoneyRender();
    void Move();
    void Font();

};

