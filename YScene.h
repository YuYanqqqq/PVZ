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
private:
	IMAGE* m_BackgroundImg;//����ͼƬָ��
	//YPlant* m_Plant;
	YPlant* m_PlantTable[5][9];
};

