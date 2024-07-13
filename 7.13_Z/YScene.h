#pragma once
#include <easyx.h>
#include "Plant.h"
#include "Animation.h"
#include "Zombie.h"
#include <list>

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

	void Event_Tick(const ExMessage* msg);//处理easyx消息事件


private:
	IMAGE* m_BackgroundImg;//背景图片指针
	//YPlant* m_Plant;
	YPlant* m_PlantTable[5][9];
	Animation* m_Animation;//动画

	//Zombie* m_Zombie;

	float m_ZombieCreateCount;//僵尸创建时间累加器

	std::vector<std::list<Zombie*>>m_Zombielist;//僵尸链表，僵尸放在5行，并且各行互不相干

	Animation* m_ZombieAnimation;
	Animation* m_ZombieAttackAnimation;
};

