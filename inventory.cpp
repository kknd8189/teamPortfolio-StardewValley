#include "pch.h"
#include "inventory.h"
#include "button.h"
#include "player.h"
#include "CameraManager.h"
#include "objectManager.h"
#include "boxInventory.h"

HRESULT inventory::init()
{
    //������ �ڽĵ� //�濰���� ���ٴ� NEW ����....
#pragma region Newitems
    _null           = new itemNull;

    _stone          = new   itemStone;
    _wood           = new   itemWood;

    _box            = new  itemBox;
    _furnance       = new  itemFurNance;
    _scareCrow1     = new  itemScareCrow1;
    _scareCrow2     = new  itemScareCrow2;

    _cauliFlower    = new  itemCauliFlower;
    _kale           = new  itemKale;
    _parsnip        = new  itemParsnip;
    _potato         = new  itemPotato;

    _halibut        = new  itemHaliBut;
    _pufferFish     = new  itemPufferFish;
    _tuna           = new  itemTuna;

    _copper         = new  itemCopper;
    _gold           = new  itemGold;
    _iron           = new  itemIron;

    _cauliSeed      = new  itemCauliSeed;
    _kaleSeed       = new  itemKaleSeed;
    _parsnipSeed    = new  itemParsnipSeed;
    _potatoSeed     = new  itemPotatoSeed;

    _axe            = new  itemAxe;
    _pickAxe        = new  itemPickAxe;
    _can            = new  itemCan;
    _hoe            = new  itemHoe;
    _rod            = new  itemRod;
    _sickle         = new  itemSickle;

    _slingShot      = new  itemSlingShot;
    _sword          = new   itemSword;
   

    //�� ����Ÿ �ϱܾ�Ͷ� ��!
    _null        ->init();
                
    _stone       ->init();
    _wood        ->init();
             
    _box         ->init();
    _furnance    ->init();
    _scareCrow1  ->init();
    _scareCrow2  ->init();
            
    _cauliFlower ->init();
    _kale        ->init();
    _parsnip     ->init();
    _potato      ->init();
               
    _halibut     ->init();
    _pufferFish  ->init();
    _tuna        ->init();
            
    _copper      ->init();
    _gold        ->init();
    _iron        ->init();
           
    _cauliSeed   ->init();
    _kaleSeed    ->init();
    _parsnipSeed ->init();
    _potatoSeed  ->init();
           
    _axe         ->init();
    _pickAxe     ->init();
    _can         ->init();
    _hoe         ->init();
    _rod         ->init();
    _sickle      ->init();
          
    _slingShot   ->init();
    _sword       ->init();
#pragma endregion

    //��ư���̹���
    IMAGEMANAGER->addFrameImage("ExitButton", "source/Images/inventory/ExitButton.bmp", 185, 292, 1, 2, true, MAGENTA);
    IMAGEMANAGER->addFrameImage("MenuButton", "source/Images/inventory/MenuButton.bmp", 185, 292, 1, 2, true, MAGENTA);
    IMAGEMANAGER->addImage("BOX", "source/Images/inventory/box.bmp", 42, 42, true, MAGENTA);
    
    for (int i = 0; i < 4; i++) 
    {
        _craftObjImg[i] = IMAGEMANAGER->findImage("craftObject");  
        _alphaObjImg[i] = IMAGEMANAGER->findImage("craftObjectAlpha");

    }
  
    _quickSlotMin = 0;
    _quickSlotMax = 12;

    _buttonExit = new button;
    _buttonToMenu = new button;

    _BOXImg = IMAGEMANAGER->findImage("BOX");
    //����������â �̹���
    _itemInfoImg = IMAGEMANAGER->findImage("itemInfo");
     
    //������ �̹���
    _quickSlot = IMAGEMANAGER->findImage("quickSlot");
    
    //�޴��� �̹��� �ʱ�ȭ
    _invenImg = IMAGEMANAGER->findImage("itemInventory");
    _statImg = IMAGEMANAGER->findImage("statMenu");
    _craftImg = IMAGEMANAGER->findImage("craftMenu");
    _settingImg = IMAGEMANAGER->findImage("settingMenu");
    _exitImg = IMAGEMANAGER->findImage("exitMenu");

    //���� �޴� �̹����� = �κ��̹����� �ʱ�ȭ
    _currentMenuImg = _invenImg;
    
    //�޴��� ������ Rc ��ġ �ʱ�ȭ
  
    _menuRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _currentMenuImg->getWidth(), _currentMenuImg->getHeight());
    _quickSlotRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY - _quickSlot->getHeight() / 2, _quickSlot->getWidth(), _quickSlot->getHeight());

    //��ư�� RC �ʱ�ȭ
    _storageRc = RectMake(_menuRc.left + 46, _menuRc.top, 53, 60);
    _craftRc = RectMake(_storageRc.right + 5, _storageRc.top, 53, 60);
    _settingRc = RectMake(_craftRc.right + 5, _craftRc.top, 53, 60);
    _exitRc = RectMake(_settingRc.right + 5, _settingRc.top, 53, 60);
    _BOXRc = RectMake((_quickSlotRc.left + 15), (_quickSlotRc.top + 13), _BOXImg->getWidth(), _BOXImg->getHeight());

    _isMenuOpen = false;

    //��ư�޴�
    _buttonToMenu->init("MenuButton", WINSIZEX / 2, WINSIZEY / 2 - 100, PointMake(0, 1), PointMake(0, 0), Button, this);
    _buttonExit->init("ExitButton", WINSIZEX / 2, WINSIZEY / 2 + 100, PointMake(0, 1), PointMake(0, 0), Button, this);

  

    //�κ��� �ΰ��̶� �ĳ���
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        _vInven.push_back(_null);
    }

    //�⺻������
    AddItem(_axe);
    AddItem(_pickAxe);
    AddItem(_can);
    AddItem(_hoe);
    AddItem(_rod);
    AddItem(_sickle);
    AddItem(_slingShot);
    AddItem(_sword);

    for(int i = 0 ; i < 160 ; i++) AddItem(_wood);

 

    //�׽�Ʈ ������ ����ֱ�
    _canBox = false;
    _canFur = false;

   //QuickSlot();
    
    _downPtItem = NULL;
    _upPtItem = NULL;

    SettingInit();


    return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
    //�޴��� Ű�� ���� �Լ�
    MenuOpen();
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        if (_vInven[i] == _null)
        {
            _inven[i].amount = 0;
            _inven[i].itemExist = false;
        }
    }
    //�޴�â�� ��������
    if (_isMenuOpen)
    {
        //â���� ��ư
        SelectMenu();

        //�޴�â���� ����� �Լ�
        switch (_menuPage)
        {
        case InvenPage:
            MenuInvetoryOpen();       
            break;
        case CraftPage:
            MenuCraftOpen();

            break;
        case SettingPage:
            SettingUpdate();
            break;
        case ExitPage:
            _buttonExit->update();
            _buttonToMenu->update();
            break;

        default:
            break;
        }
    }

    else if (!_isMenuOpen)
    {
       QuickSlot();
       checkPlayerTool();
    }
   
}

void inventory::render()
{
    //����� �׽�Ʈ
    char str[128];
    SetBkMode(getMemDC(), TRANSPARENT);
    HFONT oldFont, font1;
    SetTextColor(getMemDC(), RGB(0, 0, 0));
    HFONT font2 = CreateFont(30, 0, 0, 0, 400, true, false, false,
        DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
        PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("sandoll �̻�"));
    HFONT oldFont2 = (HFONT)SelectObject(getMemDC(), font2);

    sprintf_s(str, "%f", _cm->getRenderPosY());
    TextOut(getMemDC(), 300, 400, str, strlen(str));

    sprintf_s(str, "%d", INIDATA->loadDataInterger("inventory", "14", "�����۹�ȣ"));
    TextOut(getMemDC(), 100, 420, str, strlen(str));
    sprintf_s(str, "%d", INIDATA->loadDataInterger("inventory", "14", "���Ʈ"));
    TextOut(getMemDC(), 100, 440, str, strlen(str));
    sprintf_s(str, "%d", ironTemp);
    TextOut(getMemDC(), 100, 460, str, strlen(str));
   
    
     

    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        if (PtInRect(&_inven[i].rc, _ptMouse))
        {
            sprintf_s(str, "%d", _inven[i].itemExist);
            TextOut(getMemDC(), 10, 180, str, strlen(str));

    
            sprintf_s(str, "%s", _vInven[i]->GetItemInfo().itemName.c_str());
            TextOut(getMemDC(), 10, 200, str, strlen(str));
        }
    
    }

    //�޴�â�� �������� �޴�â �ƴϸ� �����Կ�
    if (_isMenuOpen)
    {
        _currentMenuImg->render(getMemDC(), _menuRc.left, _menuRc.top);

        if (KEYMANAGER->isToggleKey(VK_F1))
        {
            for (int i = 0; i < INVENTORYSIZE; ++i)
            {
                Rectangle(getMemDC(), _inven[i].rc);
                sprintf_s(str, "%d", i);
                TextOut(getMemDC(), _inven[i].rc.left, _inven[i].rc.bottom, str, strlen(str));
            }
        }
        //�޴�â���� ����� ����
        switch (_menuPage)
        {
        case InvenPage:
            
            for (int i = 0; i < INVENTORYSIZE; i++)
            {
                _vInven[i]->render(_inven[i].rc.left, _inven[i].rc.top);
                //
                if (_inven[i].amount != 1 && _inven[i].amount != 0 && _inven[i].amount > 1)
                {
                    sprintf_s(str, "%d", _inven[i].amount);
                    TextOut(getMemDC(), _inven[i].rc.right - 25, _inven[i].rc.bottom - 12, str, strlen(str));
                }
                if (_dragActivate)
                {
                    _vInven[_downPtItem]->render(_ptMouse.x - 20, _ptMouse.y - 20);

                    if (_inven[_downPtItem].amount != 1 && _inven[_downPtItem].amount != 0 && _inven[_downPtItem].amount > 1)
                    {
                        sprintf_s(str, "%d", _inven[_downPtItem].amount);
                        TextOut(getMemDC(), _ptMouse.x + 10, _ptMouse.y + 10, str, strlen(str));
                    }
                }
            
            }
            for (int i = 0; i < INVENTORYSIZE; i++)
            {
                if (PtInRect(&_inven[i].rc, _ptMouse) && _vInven[i] != _null)
                {
                    if (!_dragActivate)
                    {
                        _itemInfoImg->render(getMemDC(), _ptMouse.x, _ptMouse.y);


                        sprintf_s(str, "%s", _vInven[i]->GetItemInfo().itemName.c_str());
                        TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 20, str, strlen(str));


                        string  temp = _vInven[i]->GetItemInfo().itemInfo;


                        if (temp.length() > 20)
                        {
                            sprintf_s(str, "%s", temp.substr(0, 20).c_str());
                            TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 70, str, strlen(str));
                            sprintf_s(str, "%s", temp.substr(20, 20).c_str());
                            TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 90, str, strlen(str));
                        }
                        if (temp.length() < 20)
                        {
                            sprintf_s(str, "%s", temp.substr(0, temp.length()).c_str());
                            TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 70, str, strlen(str));
                        }

                    }

                }
            }
            break;

        case CraftPage:
      
          if (_canBox)
          {
              _craftObjImg[0]->frameRender(getMemDC(), _menuRc.left + 40 + (0 * 80), _menuRc.top + 80, 0, 0);
          }
          else
          {
              _alphaObjImg[0]->frameRender(getMemDC(), _menuRc.left + 40 + (0 * 80), _menuRc.top + 80, 0, 0);
              //IMAGEMANAGER->findImage("craftObjectAlpha")->frameRender(getMemDC(), _menuRc.left + 40 + (0 * 80), _menuRc.top + 80, 0, 0);
          }

          if (_canFur)
          {
              _craftObjImg[1]->frameRender(getMemDC(), _menuRc.left + 40 + (1 * 80), _menuRc.top + 80, 1, 0);
          }
          else
          {
              _alphaObjImg[1]->frameRender(getMemDC(), _menuRc.left + 40 + (1 * 80), _menuRc.top + 80, 1, 0);
             // IMAGEMANAGER->findImage("craftObjectAlpha")->frameRender(getMemDC(), _menuRc.left + 40 + (1 * 80), _menuRc.top + 80, 1, 0);
          }
          if (_canCrow1)
          {
              _craftObjImg[2]->frameRender(getMemDC(), _menuRc.left + 40 + (2 * 80), _menuRc.top + 80, 2, 0);
          }   
          else
          {
              _alphaObjImg[2]->frameRender(getMemDC(), _menuRc.left + 40 + (2 * 80), _menuRc.top + 80, 2, 0);
            //  IMAGEMANAGER->findImage("craftObjectAlpha")->frameRender(getMemDC(), _menuRc.left + 40 + (2 * 80), _menuRc.top + 80, 2, 0);
          }
          if (_canCrow2)
          {
              _craftObjImg[3]->frameRender(getMemDC(), _menuRc.left + 40 + (3 * 80), _menuRc.top + 80, 3, 0);
          }
          else
          {
              _alphaObjImg[3]->frameRender(getMemDC(), _menuRc.left + 40 + (3 * 80), _menuRc.top + 80, 3, 0);
             // IMAGEMANAGER->findImage("craftObjectAlpha")->frameRender(getMemDC(), _menuRc.left + 40 + (3 * 80), _menuRc.top + 80, 3, 0);
          }

             
            

            for (int i = 0; i < INVENTORYSIZE; i++)
            {
       
                if (PtInRect(&_inven[i].rc, _ptMouse) && _vInven[i] != _null)
                {
                    sprintf_s(str, "%d", _inven[i].amount);
                    TextOut(getMemDC(), _ptMouse.x + 30, _ptMouse.y, str, strlen(str));
                }

                _vInven[i]->render(_inven[i].rc.left, _inven[i].rc.top);

                if (_inven[i].amount != 1 && _inven[i].amount != 0 && _inven[i].amount > 1)
                {
                    sprintf_s(str, "%d", _inven[i].amount);
                    TextOut(getMemDC(), _inven[i].rc.right-25, _inven[i].rc.bottom-12, str, strlen(str));
                }
                if (_dragActivate)
                {
                    _vInven[_downPtItem]->render(_ptMouse.x - 20, _ptMouse.y - 20);
                    if (_inven[_downPtItem].amount != 1 && _inven[_downPtItem].amount != 0 && _inven[_downPtItem].amount > 1)
                    {
                        sprintf_s(str, "%d", _inven[_downPtItem].amount);
                        TextOut(getMemDC(), _ptMouse.x + 10, _ptMouse.y + 10, str, strlen(str));
                    }
                }
            }

            break;

        case SettingPage:
            SettingRender();
            break;

        case ExitPage:
                 _buttonExit->render();
                 _buttonToMenu->render();
            break;

        default:
            break;
        }
        

    }
    //�޴�â�� �������� �������� �����Ѵ�
    else if (!_isMenuOpen)
    {

        //�������� �̹����� �����Ѵ�
        _quickSlot->render(getMemDC(), _quickSlotRc.left, _quickSlotRc.top);

        for (int i = _quickSlotMin; i < _quickSlotMax; i++) 
        {
            _vInven[i]->render(_quick[i % 12].rc.left, _quick[i % 12].rc.top);

            _BOXImg->render(getMemDC(), _BOXRc.left, _BOXRc.top);

            if (_inven[i].amount != 1 && _inven[i].amount != 0)
            {
                sprintf_s(str, "%d", _inven[i].amount);
                TextOut(getMemDC(), _quick[i].rc.right - 25, _quick[i].rc.bottom - 12, str, strlen(str));
            }

         
        }
        sprintf_s(str, "%s", _vInven[_nowQuickItem]->GetItemInfo().itemName.c_str());
        TextOut(getMemDC(), 200, 200, str, strlen(str));
        
    }
    //������ ���� �Ѱ��ִ� �뵵
    if (KEYMANAGER->isOnceKeyDown(VK_TAB))
    {
        SOUNDMANAGER->play("pickUpItem", 0.1f);
        _quickSlotMin += 12;
        _quickSlotMax += 12;

        _nowQuickItem += 12;

        if (_quickSlotMax > 36)
        {
            _quickSlotMin = 0;
            _quickSlotMax = 12;
            _nowQuickItem -= 36;
        }
        SOUNDMANAGER->play("toolSwap", 1.0f);

    }
   
 

}
//�޴�â �����ְ� ���°�(��)
void inventory::MenuOpen()
{
    //�޴� Ű�� ���� ��ư
    if (KEYMANAGER->isOnceKeyDown('E') && !GAMEDATA->getIsPause()) 
    { 
        _isMenuOpen = !_isMenuOpen; 
     
     
        if (!_isMenuOpen)
        {
            SOUNDMANAGER->play("menuClose", 0.5f);
        }
        else
        {
            SOUNDMANAGER->play("menuOpen", 0.5f);
        }
    }
}
//������ ĭ����(��)
void inventory::QuickSlot()
{
    
    int Temp = 0;
    if (!_isMenuOpen)
    {
        for (int i = 0; i < 12; i++)
        {
           
             if (_cm->getRenderPosY() > 360)
            {
                 _quickSlotRc = RectMakeCenter(WINSIZEX / 2, 0 + _quickSlot->getHeight() / 2, _quickSlot->getWidth(), _quickSlot->getHeight());  
                 _BOXRc = RectMake(_quick[Temp].rc.left, _quick[Temp].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
            }
            else if (_cm->getRenderPosY()<360)
            {
                 _quickSlotRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY - _quickSlot->getHeight() / 2, _quickSlot->getWidth(), _quickSlot->getHeight());   
                 _BOXRc = RectMake(_quick[Temp].rc.left, _quick[Temp].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
            }
             _quick[i].rc = RectMake((_quickSlotRc.left + 15) + (i * 44.7), (_quickSlotRc.top + 13), 42, 42);

            if (KEYMANAGER->isOnceKeyDown('1'))
            {
                _BOXRc = RectMake(_quick[0].rc.left, _quick[0].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin;
                SOUNDMANAGER->play("pickUpItem", 1.0f);
                Temp = 0;
            }
            if (KEYMANAGER->isOnceKeyDown('2'))
            {
                _BOXRc = RectMake(_quick[1].rc.left, _quick[1].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 1;
                SOUNDMANAGER->play("pickUpItem", 1.0f);
                Temp = 1;
            }
            if (KEYMANAGER->isOnceKeyDown('3'))
            {
                _BOXRc = RectMake(_quick[2].rc.left, _quick[2].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 2;
                SOUNDMANAGER->play("pickUpItem", 1.0f);
                Temp = 2;
            }
            if (KEYMANAGER->isOnceKeyDown('4'))
            {
                _BOXRc = RectMake(_quick[3].rc.left, _quick[3].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 3;
                SOUNDMANAGER->play("pickUpItem", 1.0f);
                Temp = 3;
            }
            if (KEYMANAGER->isOnceKeyDown('5'))
            {
                _BOXRc = RectMake(_quick[4].rc.left, _quick[4].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 4;
                SOUNDMANAGER->play("pickUpItem", 1.0f);
                Temp = 4;
            }
            if (KEYMANAGER->isOnceKeyDown('6'))
            {
                _BOXRc = RectMake(_quick[5].rc.left, _quick[5].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 5;
                SOUNDMANAGER->play("pickUpItem", 1.0f);
                Temp = 5;
            }
            if (KEYMANAGER->isOnceKeyDown('7'))
            {
                _BOXRc = RectMake(_quick[6].rc.left, _quick[6].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 6;
                SOUNDMANAGER->play("pickUpItem", 1.0f);
                Temp = 6;
            }
            if (KEYMANAGER->isOnceKeyDown('8'))
            {
                _BOXRc = RectMake(_quick[7].rc.left, _quick[7].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 7;
                SOUNDMANAGER->play("pickUpItem", 1.0f);
                Temp = 7;
            }
            if (KEYMANAGER->isOnceKeyDown('9'))
            {
                _BOXRc = RectMake(_quick[8].rc.left, _quick[8].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 8;
                SOUNDMANAGER->play("pickUpItem", 1.0f);
                Temp = 8;
            }
            if (KEYMANAGER->isOnceKeyDown('0'))
            {
                _BOXRc = RectMake(_quick[9].rc.left, _quick[9].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 9;
                SOUNDMANAGER->play("pickUpItem", 1.0f);
                Temp = 9;
            }
            if (KEYMANAGER->isOnceKeyDown(VK_OEM_MINUS))
            {
                _BOXRc = RectMake(_quick[10].rc.left, _quick[10].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 10;
                SOUNDMANAGER->play("pickUpItem", 1.0f);
                Temp = 10;
            }
            if (KEYMANAGER->isOnceKeyDown(VK_OEM_PLUS))
            {
                _BOXRc = RectMake(_quick[11].rc.left, _quick[11].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 11;
                SOUNDMANAGER->play("pickUpItem", 1.0f);
                Temp = 11;
            }
          
        }
    }   
}
//�޴�â���� �κ��丮â
void inventory::MenuInvetoryOpen()
{

    //���� ���簢�� �������ش�
        for (int j = 0; j < 3; ++j)
        {
            for (int i = 0; i < 12; ++i)
            {
                //12X3 ���������� rc ����
                _inven[12 * j + i].rc = RectMake(307 + (i * 55.3), 178 + (j * 63), 49, 45);
            }
        }

        //���� ����
        for (int i = 0; i < INVENTORYSIZE; i++)
        {
       
            if (PtInRect(&_inven[i].rc, _ptMouse))
            {
                if (KEYMANAGER->isStayKeyDown(VK_LBUTTON)) _dragActivate = true;

                if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
                {
                    _downPtItem = i;
                    if (!_inven[i].itemExist) continue;
                    SOUNDMANAGER->play("pickUpItem", 0.1f);
                }

                if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
                {
                    _dragActivate = false;

                    for (int j = 0; j < INVENTORYSIZE; j++)
                    {
                        if (PtInRect(&_inven[j].rc, _ptMouse))
                        {
                            _upPtItem = j;
                            if (!_inven[_downPtItem].itemExist) break;
                            SOUNDMANAGER->play("pickUpItem", 0.1f);
                        }

                    }

                    //�׳� ��������� ���� �ٸ� �ش�ĭ�� ���� ������
                    if (_vInven[_downPtItem] != _vInven[_upPtItem])
                    {
                        swap(_vInven[_downPtItem], _vInven[_upPtItem]);
                        swap(_inven[_downPtItem].amount, _inven[_upPtItem].amount);
                        swap(_inven[_downPtItem].itemExist, _inven[_upPtItem].itemExist);
                    }
                    else
                    {
                        //����� 999���� ������
                        if (_inven[_upPtItem].amount < 999)
                        {
                            //���� ���Ѱ� 998���� ũ�ٸ� ��ŵ
                            if (_inven[_upPtItem].amount + _inven[_downPtItem].amount > 998)
                            {
                                continue;
                            }
                            else //�۴ٸ� ���� �������� �����ġ�� �ֱ�
                            {
                                _inven[_upPtItem].amount += _inven[_downPtItem].amount;
                                _inven[_downPtItem].amount = 0;
                            }
                        }

                    }

         
                }
            }
        }
        if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
        {
            _dragActivate = false;

            if (PtInRect(&_menuRc, _ptMouse))
            {
                swap(_vInven[_downPtItem], _vInven[_downPtItem]);
            }
            //������
            if (!PtInRect(&_menuRc, _ptMouse)) //�ۿ��� ������
            {
                if (   _vInven[_downPtItem]->GetItemInfo().itemNum == 21
                    || _vInven[_downPtItem]->GetItemInfo().itemNum == 22
                    || _vInven[_downPtItem]->GetItemInfo().itemNum == 23
                    || _vInven[_downPtItem]->GetItemInfo().itemNum == 24
                    || _vInven[_downPtItem]->GetItemInfo().itemNum == 25
                    || _vInven[_downPtItem]->GetItemInfo().itemNum == 26
                    || _vInven[_downPtItem]->GetItemInfo().itemNum == 27
                    || _vInven[_downPtItem]->GetItemInfo().itemNum == 28)
                {
                    swap(_vInven[_downPtItem], _vInven[_downPtItem]);
                }
                else
                {
                    switch (_vInven[_downPtItem]->GetItemInfo().itemNum)
                    {
                    case 0:                    //���� �ѹ� ��
                        break;
                    case 1:
                        _om->SetStone(_player->getX()+150+ RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                        break;
                    case 2:
                        _om->SetWood(_player->getX() + 150 +RND->getFromIntTo(-50,+50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                        break;
                     case 3:
                         _om->SetBox(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 4:
                        _om->SetFurnance(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 5:
                         _om->SetScarecrow1(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 6:
                         _om->SetScarecrow2(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 7:
                         _om->SetCauliFlower(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 8:
                         _om->SetKale(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 9:
                         _om->SetParsnip(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 10:
                         _om->SetPotato(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 11:                 
                         _om->SetHaliBut(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 12:
                         _om->SetPufferFish(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 13:
                         _om->SetTuna(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 14:
                         _om->SetCopper(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 15:
                         _om->SetGold(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 16:
                         _om->SetIron(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 17:
                         _om->SetCauliFlowerSeed(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 18:
                         _om->SetKaleSeed(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 19:
                         _om->SetParsnipSeed(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
                     case 20:
                         _om->SetPotatoSeed(_player->getX() + 150 + RND->getFromIntTo(-50, +50), _player->getY() + 150 + RND->getFromIntTo(-50, +50), _inven[_downPtItem].amount);
                         break;
   
                     default:
                         break;

                    }
                    _vInven[_downPtItem] = _null;
                    _inven[_downPtItem].amount = 0;
                    _inven[_downPtItem].itemExist = false;
                }
            }
            
        }
}
//����â(�̿�)
void inventory::MenuCraftOpen()
{
    // ������ ���簢�� ����
    for (int i = 0; i < 4; i++)
    {
        _craftObjRc[i] = RectMake(_menuRc.left + 40 + (i * 80), _menuRc.top + 80, _craftObjImg[i]->getFrameWidth(), _craftObjImg[i]->getFrameHeight());
    }
    //���簢�� ĭ����
    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < 12; ++i)
        {
            //12X3 ���������� rc ����
            _inven[12 * j + i].rc = RectMake(307 + (i * 55.3), 448 + (j * 55.2), 49, 45);
        }
    }
    //���� ����
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        if (PtInRect(&_inven[i].rc, _ptMouse))
        {
            if (KEYMANAGER->isStayKeyDown(VK_LBUTTON)) _dragActivate = true;

            if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
            {
                _downPtItem = i;
                if (!_inven[i].itemExist) continue;
                SOUNDMANAGER->play("pickUpItem", 0.1f);
            }

            if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
            {
                _dragActivate = false;

                for (int j = 0; j < INVENTORYSIZE; j++)
                {
                    if (PtInRect(&_inven[j].rc, _ptMouse))
                    {
                        _upPtItem = j;
                        if (!_inven[_downPtItem].itemExist) break;
                        SOUNDMANAGER->play("pickUpItem", 0.1f);
                    }
                }
                
                //�׳� ��������� ���� �ٸ� �ش�ĭ�� ���� ������
                if (_vInven[_downPtItem] != _vInven[_upPtItem])
                {
                    swap(_vInven[_downPtItem], _vInven[_upPtItem]);
                    swap(_inven[_downPtItem].amount, _inven[_upPtItem].amount);
                    swap(_inven[_downPtItem].itemExist, _inven[_upPtItem].itemExist);
                }
                else
                {

                    //����� 999���� ������
                    if (_inven[_upPtItem].amount < 999)
                    {
                        //���� ���Ѱ� 998���� ũ�ٸ� ��ŵ
                        if (_inven[_upPtItem].amount + _inven[_downPtItem].amount > 998)
                        {
                             continue;
                        }
                        else //�۴ٸ� ���� �������� �����ġ�� �ֱ�
                        {
                            if (_upPtItem != _downPtItem)
                            {
                            _inven[_upPtItem].amount += _inven[_downPtItem].amount;
                            _inven[_downPtItem].amount = 0;
                            }
                            else
                            {
                                continue;
                            }
                        }  
                
                    }
                  
                }
                
            }
            if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
            {
                _dragActivate = false;

                if (PtInRect(&_menuRc, _ptMouse))
                {
                    swap(_vInven[_downPtItem], _vInven[_downPtItem]);
                }
                if (!PtInRect(&_menuRc, _ptMouse))
                {
                    _vInven[_downPtItem] = _null;
                    _inven[_downPtItem].amount = 0;
                    _inven[_downPtItem].itemExist = false;
                }
            }

        }
    }

    if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
    {
        _dragActivate = false;

        if (PtInRect(&_menuRc, _ptMouse))
        {
            swap(_vInven[_downPtItem], _vInven[_downPtItem]);

        }
    }
    //0���� ���� ������ �ִٸ�
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        if (_inven[i].amount < 1)
        {
            _vInven[i] = _null;
            _inven[i].amount = 0;
            _inven[i].itemExist = false;
        }
    }

    int TempCount1 = 0;
    int TempCount2 = 0;
    int TempCount3 = 0;
    int TempCount4 = 0;

    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        if (_vInven[i] == _wood)
        {
            TempCount1++;
            if (_inven[i].amount > _box->GetItemInfo().needAmountToCraft)
            {
                _canBox = true;
            }
            else
            {
                _canBox = false;
            }
            if ((PtInRect(&_craftObjRc[0], _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) && _canBox)
            {

                AddItem(_box);
                _inven[i].amount -= _box->GetItemInfo().needAmountToCraft;
            }
        
        }
        
        if (_vInven[i] == _stone)
        {
            TempCount2++;
            if (_inven[i].amount > _furnance->GetItemInfo().needAmountToCraft)
            {
                _canFur = true;
            }
            else
            {
                _canFur = false;
            }
            if ((PtInRect(&_craftObjRc[1], _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) && _canFur)
            {

                AddItem(_furnance);
                _inven[i].amount -= _furnance->GetItemInfo().needAmountToCraft;
            }

        }

        if (_vInven[i] == _copper)
        {
            TempCount3++;
            if (_inven[i].amount > _scareCrow1->GetItemInfo().needAmountToCraft)
            {
                _canCrow1 = true;
            }
            if ((PtInRect(&_craftObjRc[2], _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) && _canCrow1)
            {

                AddItem(_scareCrow1);
                _inven[i].amount -= _scareCrow1->GetItemInfo().needAmountToCraft;
            }

        }

        if (_vInven[i] == _iron)
        {
            TempCount4++;
            if (_inven[i].amount > _scareCrow2->GetItemInfo().needAmountToCraft)
            {
                _canCrow2 = true;
            }
            if ((PtInRect(&_craftObjRc[3], _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) && _canCrow2)
            {

                AddItem(_scareCrow2);
                _inven[i].amount -= _scareCrow2->GetItemInfo().needAmountToCraft;
            }

        }
    }
    //�������� ����
    if (TempCount1 == 0)
    {
        _canBox = false;
    }
    if (TempCount2 == 0)
    {
        _canFur = false;
    }
    if (TempCount3 == 0)
    {
        _canCrow1 = false;
    }
    if (TempCount4 == 0)
    {
        _canCrow2 = false;
    }
}
//������ �߰�(��)
void inventory::AddItem(item* item)
{
    //�ż���
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        //���� ������ �ִ°ų�>>??
        if (_vInven[i] == item)
        {
            //��ǻ� 99��
            if (_inven[i].amount > 998)
            {
                continue;
            }
            else 
            {
                _inven[i].amount++; 
                _inven[i].itemExist = true;
                break; 
            }
        }
        //������ ����?
        else
        {
            //���ڸ��Դϱ�?
            if (!_inven[i].itemExist)
            {
                if (item == _null) continue;
                _vInven[i] = item;
                
                _inven[i].itemExist = true;
               
                _inven[i].amount = 1;
                break;
            }
            //�����ֳ׿�
            else
            {
                continue;
            }
        }
    }
}
//�޴���ư��(��)
void inventory::SelectMenu()
{
    if (PtInRect(&_storageRc, _ptMouse) || PtInRect(&_craftRc, _ptMouse) || PtInRect(&_settingRc, _ptMouse) || PtInRect(&_exitRc, _ptMouse))
    {
        if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
        {
            if (PtInRect(&_storageRc, _ptMouse) && _menuPage != InvenPage)
            {
                SOUNDMANAGER->play("menuSelect", 0.5f);
                _currentMenuImg = _invenImg;
                _menuPage = InvenPage;

            }
            if (PtInRect(&_craftRc, _ptMouse) && _menuPage != CraftPage)
            {
                SOUNDMANAGER->play("menuSelect", 0.5f);
                _currentMenuImg = _craftImg;
                _menuPage = CraftPage;
            }
            if (PtInRect(&_settingRc, _ptMouse) && _menuPage != SettingPage)
            {
                SOUNDMANAGER->play("menuSelect", 0.5f);
                _currentMenuImg = _settingImg;
                _menuPage = SettingPage;
            }
            if (PtInRect(&_exitRc, _ptMouse))
            {
                SOUNDMANAGER->play("menuSelect", 0.5f);
                _currentMenuImg = _exitImg;
                _menuPage = ExitPage;
            }
        }
    }
}
//�������ư �ݹ��Լ�
void inventory::Button(void* obj)
{
    inventory* invento = (inventory*)obj;

    if (invento->_buttonExit->getBtnDir() == BUTTONDIRECTION_UP) exit(1);
    if (invento->_buttonToMenu->getBtnDir() == BUTTONDIRECTION_UP) SCENEMANAGER->changeScene("mainMenuScene");
}
//���� ���̹���
void inventory::checkPlayerTool()
{
    switch (_vInven[_nowQuickItem]->GetItemInfo().itemNum)
    {
    case 0 :
        _playerTool = PLAYERTOOL_NULL;
        break;
    case 21:
        _playerTool = PLAYERTOOL_AXE;
        break;
    case 24:
        _playerTool = PLAYERTOOL_PICKAXE;
        break;
    case 23:
        _playerTool = PLAYERTOOL_HOE;
        break;
    case 26:
        _playerTool = PLAYERTOOL_SICKLE;
        break;
    case 22:
        _playerTool = PLAYERTOOL_CAN;
        break;
    case 25:
        _playerTool = PLAYERTOOL_ROD;
        break;
    case 28:
        _playerTool = PLAYERTOOL_SWORD;
        break;
    default :
        _playerTool = PLAYERTOOL_ITEMS;
    break;
    }

    if (_playerTool == PLAYERTOOL_ITEMS)
    {
        switch (_vInven[_nowQuickItem]->GetItemInfo().itemNum)
        {
        case 3:
            _CRAFT = CRAFTBOX;
            break;
        case 4:
            _CRAFT = CRAFTFURNANCE;
            break;
        case 5:
            _CRAFT = CRAFTCROW1;
            break;
        case 6:
            _CRAFT = CRAFTCROW2;
            break;
        default:
            _CRAFT = CRAFTNULL;
            break;
        }
    }

}
//����â ����
void inventory::SettingInit()
{
    _frame.img = IMAGEMANAGER->addImage("settingFrame", "source/Images/mainScene/settingFrame.bmp", 403, 210, true, MAGENTA);
    for (int i = 0; i < 2; i++)
    {
        _select[i].img = IMAGEMANAGER->addImage("volumeSelect", "source/Images/mainScene/volumeSelect.bmp", 40, 24, true, MAGENTA);
        _select[i].x = WINSIZEX / 2 - 80;
        _select[i].y = WINSIZEY / 2- 4 + 78 * i;
        _select[i].rc = RectMake(_select[i].x, _select[i].y, _select[i].img->getWidth(), _select[i].img->getHeight());
        _select[i].cx = _select[i].x + _select[i].img->getWidth() / 2;
        _select[i].cy = _select[i].y + _select[i].img->getHeight() / 2;
        _select[i].src = RectMakeCenter(_select[i].sx, _select[i].sy, 10, 10);
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            _volumeRC[j+10*i] = RectMake(452 +19 * j, WINSIZEY / 2 - 4 + 78 * i, 19, 24);
        }
    }

    _currentTotalVolume = GAMEDATA->getBGMVolume() / 10;
    _currentSFXVolume = GAMEDATA->getSFXVolume() / 10;
}
//���� �ʱ�ȭ
void inventory::SettingUpdate()
{
    SettingVolumeFrame();

    for (int i = 0; i < 2; i++)
    {
        _select[i].cx = _select[i].x + _select[i].img->getWidth() / 2;
        _select[i].cy = _select[i].y + _select[i].img->getHeight() / 2;
        _select[i].rc = RectMake(_select[i].x, _select[i].y, _select[i].img->getWidth(), _select[i].img->getHeight());
        _select[i].src = RectMakeCenter(_select[i].cx, _select[i].cy, 3, 3);
      
    }
    //���� ����â ����ٰ� ������ �˴ϴٿ�
    SOUNDMANAGER->setVolume("opening", _currentTotalVolume);
}
//���� ����
void inventory::SettingRender()
{
    _frame.img->render(getMemDC(), WINSIZEX / 2 - _frame.img->getWidth() / 2, WINSIZEY / 2 - _frame.img->getHeight() / 2 + 30);
    for (int i = 0; i < 2; i++)
    {
        _select[i].img->render(getMemDC(), _select[i].x, _select[i].y);
        if (KEYMANAGER->isToggleKey(VK_F2))
        {
            Rectangle(getMemDC(), _select[i].src);
        }
        
    
    }
    if (KEYMANAGER->isToggleKey(VK_F1))
    {
        for (int i = 0; i < 20; i++)
        {
            Rectangle(getMemDC(), _volumeRC[i]);
        }
    }

    char str[256];
    sprintf_s(str, "%d %d", _ptMouse.x, _ptMouse.y);
    TextOut(getMemDC(), _ptMouse.x, _ptMouse.y, str, strlen(str));

    sprintf_s(str, "%f %f", _select[0].cx, _select[1].cx);
    TextOut(getMemDC(), 50, 100, str, strlen(str));
}
//���� ��������
void inventory::SettingVolumeFrame()
{
   
    if (PtInRect(&_select[0].rc, _ptMouse) )
    {
        if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) && _select[0].x > 455 && _select[0].x < 600)
        {
            _isClickUp = true;
            _select[0].x = _ptMouse.x /*- _select[i].img->getWidth() / 2*/;
        }
        else if (_select[0].x <= 455)
        {
            _select[0].x = 456;
        }
        else if (_select[0].x >= 600)
        {
            _select[0].x = 599;
        }
    }

    if (PtInRect(&_select[1].rc, _ptMouse))
    {
        if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) && _select[1].x > 455 && _select[1].x < 600)
        {
            _isClickDown = true;
            _select[1].x = _ptMouse.x /*- _select[i].img->getWidth() / 2*/;
        }
        else if (_select[1].x <= 455)
        {
            _select[1].x = 456;
        }
        else if (_select[1].x >= 600)
        {
            _select[1].x = 599;
        }
    }
 
    if (_isClickUp )
    {
         if (_select[0].x > 455 && _select[0].x < 600)
         {
             _select[0].x = _ptMouse.x;
         }
         else if (_select[0].x <= 455)
         {
             _select[0].x = 456;
         }
         else if (_select[0].x >= 600)
         {
             _select[0].x = 599;
         }
    }

    if (_isClickDown)
    {
        if (_select[1].x > 455 && _select[1].x < 600)
        {
            _select[1].x = _ptMouse.x;
        }
        else if (_select[1].x <= 455)
        {
            _select[1].x = 456;
        }
        else if (_select[1].x >= 600)
        {
            _select[1].x = 599;
        }
    }
    
    if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
    {
        _isClickUp = false;
        _isClickDown = false;
    }

    //�� ���� ���� ���� ����� ��Ÿ��
    RECT temp;
    for (int i = 0; i < 10; i++)
    {
        if (IntersectRect(&temp, &_volumeRC[i], &_select[i].src))
        {
            switch (i)
            {
            case 0:
                _currentTotalVolume = 0;
                break;
            case 1:
                _currentTotalVolume = 0.1f;
                break;
            case 2:
                _currentTotalVolume = 0.2f;
                break;
            case 3:
                _currentTotalVolume = 0.3f;
                break;
            case 4:
                _currentTotalVolume = 0.4f;
                break;
            case 5:
                _currentTotalVolume = 0.5f;
                break;
            case 6:
                _currentTotalVolume = 0.6f;
                break;
            case 7:
                _currentTotalVolume = 0.7f;
                break;
            case 8:
                _currentTotalVolume = 0.8f;
                break;
            case 9:
                _currentTotalVolume = 1.0f;
                break;
            }
        }
    }

    for (int i = 10; i < 20; i++)
    {
        if (IntersectRect(&temp, &_volumeRC[i], &_select[i].src))
        {
            switch (i)
            {
            case 10:
                _currentSFXVolume = 0;
                break;
            case 11:
                _currentSFXVolume = 0.1f;
                break;
            case 12:
                _currentSFXVolume = 0.2f;
                break;
            case 13:
                _currentSFXVolume = 0.3f;
                break;
            case 14:
                _currentSFXVolume = 0.4f;
                break;
            case 15:
                _currentSFXVolume = 0.5f;
                break;
            case 16:
                _currentSFXVolume = 0.6f;
                break;
            case 17:
                _currentSFXVolume = 0.7f;
                break;
            case 18:
                _currentSFXVolume = 0.8f;
                break;
            case 19:
                _currentSFXVolume = 1.0f;
                break;
            }
        }
    }
    
    GAMEDATA->setBGMVolume(_currentTotalVolume * 10);
    GAMEDATA->setSFXVolume(_currentSFXVolume * 10);
}
//�κ��丮 ���̺��ϴ� ��
void inventory::saveInventory()
{
    for (int i = 0; i < _vInven.size(); i++)
    {
        // i �κ��丮 ���� �迭 �ε���  , ���� �ѹ�,  ����
        _vInven[i]->GetItemInfo().itemNum;

        char str[5], str2[5], str3[5];
        sprintf_s(str, "%d", i);
        sprintf_s(str2, "%d", _vInven[i]->GetItemInfo().itemNum);
        sprintf_s(str3, "%d", _inven[i].amount);

        INIDATA->addData(str, "�����۹�ȣ" , str2);
        INIDATA->addData(str, "���Ʈ", str3);
        INIDATA->iniSave("inventory");
    }
}
//�κ��丮 �ε��ϴ� �Լ�
void inventory::loadInventory()
{
    char str[5];

    for (int i = 0; i < INVENTORYSIZE; ++i)
    {
        sprintf_s(str, "%d", i);

        switch (INIDATA->loadDataInterger("inventory", str, "�����۹�ȣ"))
        {
        case 0:                    //���� �ѹ� ��
            _vInven[i] = _null;  
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 1:   
            _vInven[i] = _stone;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 2:
            _vInven[i] = _wood;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 3:
            _vInven[i] = _box;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 4:
            _vInven[i] = _furnance;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 5:
            _vInven[i] = _scareCrow1;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 6:
            _vInven[i] = _scareCrow2;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 7:
            _vInven[i] = _cauliFlower;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 8:
            _vInven[i] = _kale;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 9:
            _vInven[i] = _parsnip;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 10:
            _vInven[i] = _potato;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 11:
            _vInven[i] = _halibut;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 12:
            _vInven[i] = _pufferFish;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 13:
            _vInven[i] = _tuna;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 14:
            _vInven[i] = _copper;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 15:
            _vInven[i] = _gold;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 16:
            _vInven[i] = _iron;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 17:
            _vInven[i] = _cauliSeed;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 18:
            _vInven[i] = _kaleSeed;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 19:
            _vInven[i] = _parsnipSeed;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 20:
            _vInven[i] = _potatoSeed;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 21:
            _vInven[i] = _axe;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 22:
            _vInven[i] = _can;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 23:
            _vInven[i] = _hoe;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 24:
            _vInven[i] = _pickAxe;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 25:
            _vInven[i] = _rod;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 26:
            _vInven[i] = _sickle;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 27:
            _vInven[i] = _slingShot;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        case 28:
            _vInven[i] = _sword;  //��
            _inven[i].amount = INIDATA->loadDataInterger("inventory", str, "���Ʈ");
            break;
        default:
            break;
        }

    }
}

void inventory::drawOnThePlayer()
{
    if (_playerTool == PLAYERTOOL_ITEMS)
    {
        _vInven[_nowQuickItem]->render( _player->getRenderX() - 24, _player->getRenderY() - 84);
    }
}

void inventory::eraseSelectQuickNum()
{
    _inven[_nowQuickItem].amount--;

    if (_inven[_nowQuickItem].amount <= 0)
    {
        _vInven[_nowQuickItem] = _null;
    }
}

void inventory::SetInventory(item* item, int num)
{
    _vInven[num] = item;
}
