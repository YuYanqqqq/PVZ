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
	bool Init();//��ʼ��

	void Draw_Tick();//���Ƹ���
	void Event_Tick(float delta);//�¼��ظ�����

	void Event_Tick(const ExMessage* msg);//����easyx��Ϣ�¼�


private:
	IMAGE* m_BackgroundImg;//����ͼƬָ��
	//YPlant* m_Plant;
	YPlant* m_PlantTable[5][9];
	Animation* m_Animation;//����

	//Zombie* m_Zombie;

	float m_ZombieCreateCount;//��ʬ����ʱ���ۼ���

	std::vector<std::list<Zombie*>>m_Zombielist;//��ʬ������ʬ����5�У����Ҹ��л������

	Animation* m_ZombieAnimation;
	Animation* m_ZombieAttackAnimation;
};

