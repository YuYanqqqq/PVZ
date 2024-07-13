#pragma once
#include <easyx.h>
#include "Plant.h"

class YScene
{
private:
	YScene() = default;
public:
	static YScene* Create();

public:
	bool Init();//��ʼ��

	void Draw_Tick();//���Ƹ���
	void Event_Tick(float delta);//�¼��ظ�����
	IMAGE* get(int n);
	void set(int n);
	IMAGE* m_BackgroundImg;//����ͼƬָ��
	//YPlant* m_Plant;
	IMAGE* Cardbar;
	IMAGE* plantcard;
	IMAGE sunFlowerCard;
	IMAGE greenShooterCard;
	IMAGE NutCard;
	IMAGE snowShooterCard;
	IMAGE dgreenShooterCard;

	bool flag = 0;
	IMAGE move;
	YPlant* m_PlantTable[5][9];
};

