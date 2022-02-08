#pragma once
#include "gameNode.h"
class MouseSetting :
    public gameNode
{
private:
    image*  _mouse; //���콺 �̹���
    RECT    _rc;    //���콺 ��Ʈ
    int _frameX, _frameY; //���콺 ������ X,Y

public:
    MouseSetting();
    ~MouseSetting();
    virtual HRESULT init();
    virtual void release();
    virtual void update();
    virtual void render();
};

