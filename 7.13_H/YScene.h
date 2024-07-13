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
	bool Init();//初始化

	void Draw_Tick();//绘制更新
	void Event_Tick(float delta);//事件重复处理
	IMAGE* get(int n);
	void set(int n);
	IMAGE* m_BackgroundImg;//背景图片指针
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

