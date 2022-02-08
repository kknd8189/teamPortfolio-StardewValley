#pragma once
#define TILESIZE 32	//Ÿ�� ������ 32X32

#define TILEX 80	//���� Ÿ�� ����
#define TILEY 65	//���� Ÿ�� ����

#define MINETILEX 40	//���� Ÿ�� ����
#define MINETILEY 23	//���� Ÿ�� ����

//Ÿ�� �԰� 20 X 32 ������ϱ� -> �� ������� 640 X 640
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

//Ÿ�� �� ���� 20�� ���� 9��
#define SAMPLETILEX 13
#define SAMPLETILEY 18

#define SAMPLE2XOBJECTX 13
#define SAMPLE2XOBJECTY 4

#define SAMPLETREEX 3
#define SAMPLETREEY 2

//�̳ѹ����� �ص� ������ �������� �޸� �Ƴ��ٰ� ���� ���
//��Ʈ�ʵ�� �� �� �غ��ڽ��� (������ �� �̳ѹ� �ᵵ ������)

#define ATTR_UNMOVE		0x00000001	//������ Ÿ��
#define ATTR_HOE		0x00000002	//��������
#define ATTR_ROAD		0x00000004	//��������
#define ATTR_ENTRANCE	0x00000008	//���ⱸ
#define ATTR_CORNER		0x00000016  //�׵θ� Ÿ��
#define ATTR_MOVE		0x00000000  //���� �ִ� Ÿ��

//����
enum TERRAIN
{
	TR_GRASS, TR_DIRT, TR_DIRT_WET, TR_WATER, TR_WOOD, TR_NULL, TR_HOE
};

//������Ʈ
enum OBJECT
{
	OBJ_WALL, OBJ_GRASS, OBJ_TREE, OBJ_ROCK, OBJ_BUILD, OBJ_PROP, OBJ_NONE, OBJ_BOXX, OBJ_COPPERR, OBJ_IRONN, OBJ_GOLDD 
};

enum POS
{
	//1P���� ���(������ ���) 1P ��ũ ������ ��ġ
	POS_HOUSE_ENTER, POS_HOUSE_EXIT, POS_FARM_EXIT, POS_FARM_ENTER
};

//Ÿ�� ����ü (Ÿ�� �������� ����ִ�)
struct tagTile
{
	TERRAIN terrain;
	OBJECT obj;
	RECT rc;

	int terrainFrameX;
	int terrainFrameY;
	int objFrameX;
	int objFrameY;
	int posX, posY;

 	int tilePage;
	int objPage;
};

//Ÿ�� ��
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};
