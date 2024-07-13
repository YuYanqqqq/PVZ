#include "YScene.h"
#include <stdio.h>
#include "Animation.h"

YScene* YScene::Create()
{
	YScene* NewScene = new YScene;
	NewScene->Init();
	if (NewScene && NewScene->Init())
		return NewScene;

	if (NewScene)
		delete NewScene;
	return nullptr;
}

bool YScene::Init()
{
	m_BackgroundImg = new IMAGE;//����ͼƬ�ڴ�
	
	if (!m_BackgroundImg)return false;
	loadimage(m_BackgroundImg,"source/backGround/gameBackground.jpg");//����ͼƬ������ͼƬָ�룬LͼƬ�ڸ�Ŀ¼�µĵ�ַ

	////m_Plant = new YPlant;//Ϊֲ��ͼƬ�����ڴ�
	//m_Plant = YPlant::Create();//���÷�װ���Զ���Ĺ��캯���������Ͻ���
	//m_Plant->Init();//�ֶ����ó�ʼ������

	//����ֲ�ﶯ��
	Animation* NewAnimation = Animation::Create();
	NewAnimation->SetInvertal(0.07f);
	for (int i = 1; i <= 15; i++)
	{
		char path[256] = { 0 };
		sprintf(path, "source/plants/doubleGreenPeasShooter/a (%d).png", i);
		NewAnimation->Addimage(path);
	}

	for(int i=0;i<5;i++)
		for (int j = 0; j < 9; j++)
		{
			m_PlantTable[i][j] = YPlant::Create();
			m_PlantTable[i][j]->SetPosition(YVector(320+j*96, 120+i*115));
			m_PlantTable[i][j]->SetAnimation(NewAnimation);
		}//ֲ�ﶯ������

	//������ʬ����
	m_ZombieAnimation = Animation::Create();
	m_ZombieAnimation->SetInvertal(0.07f);
	for (int i = 1; i <= 21; i++)
	{
		char path[256] = { 0 };
		sprintf(path, "source/zombies/walk/icecreamZombie/a (%d).png", i);
		m_ZombieAnimation->Addimage(path);
	}

	//������ʬ��������
	m_ZombieAttackAnimation = Animation::Create();
	m_ZombieAttackAnimation->SetInvertal(0.07f);
	for (int i = 1; i <= 11; i++)
	{
		char path[256] = { 0 };
		sprintf(path, "source/zombies/eat/icecreamZombie/a (%d).png", i);
		m_ZombieAttackAnimation->Addimage(path);
	}


	//m_Zombie = Zombie::Create();
	//m_Zombie->SetPosition(YVector(500, 60));
	//m_Zombie->SetAnimation(NewZombieAnimation);
	//m_Zombie->SetStartAnimation();

	m_Zombielist.resize(5);//��ʬ�����ʼ����5��
	m_ZombieCreateCount = 0;


	return true;
}

void YScene::Draw_Tick()
{
	putimage(0, 0, m_BackgroundImg);//��ͼƬ��������̨�ϣ�ͼƬ��һ�������ڿ���̨�ϵĺ������꣬ͼƬ��

	static int i = 0;//����debug��̬��Ա�������۲캯�������˶��ٴ�

	//printf("draw tick %d\n",++i);//�������
	//m_Plant->Draw_Tick();
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
		{
			if(m_PlantTable[i][j])
			m_PlantTable[i][j]->Draw_Tick();
		}
	//ֲ�ﶯ������

	//m_Zombie->Draw_Tick();

	//��ʬ��������
	for (auto& Zombielist : m_Zombielist)
	{
		for (auto& _Zombie : Zombielist)
		{
			_Zombie->Draw_Tick();
		}
	}
}

void YScene::Event_Tick(float delta)
{
	printf("%f\n", delta);

	m_ZombieCreateCount += delta;
	if (m_ZombieCreateCount >= 2.0f)
	{
		int row = rand() % 5;

		Zombie* _Zombie = Zombie::Create();
		_Zombie->SetPosition(YVector(1200, 50+120*row));
		_Zombie->SetAnimation(m_ZombieAnimation);
		_Zombie->SetAttackAnimation(m_ZombieAttackAnimation);
		_Zombie->SetStartAnimation();
		

		m_Zombielist[row].push_back(_Zombie);

		m_ZombieCreateCount -= 2.0f;
	}

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
		{
			if(m_PlantTable[i][j])
			m_PlantTable[i][j]->Event_Tick(delta);
		}//ֲ���¼�����

	for (auto& Zombielist : m_Zombielist)
	{
		for (auto& Zombie : Zombielist)
		{
			Zombie->Event_Tick(delta);
			//printf("00\n");
		}
	}
	//��ʬ�¼�����

	//m_Zombie->Event_Tick(delta);

	//ֲ��ͽ�ʬ�ж�
	for (int i = 0; i < 5; i++)
	{
		auto& ZombieList = m_Zombielist[i];
		for (auto* _Zombie : ZombieList)
		{
			bool is = false;//�ж��Ƿ���ֲ���뵱ǰ��ʬ��ײ
			for (int j = 0; j < 9; j++)
			{
				YPlant* Plant = m_PlantTable[i][j];
				if (!Plant)continue;//�жϵ�ǰ������ֲ��
				if (_Zombie->GetPosition().x+80<=Plant->GetPosition().x+76)
				{
					//printf("%f %f", _Zombie->GetPosition().x, Plant->GetPosition().x);
					_Zombie->SetAttackState(true);
					is = true;
				}
			}

			if (!is)
			{
				_Zombie->SetAttackState(false);//����ʬ��һ��ֲ�������Ϊ����״̬
			}
		}
	}

	//�����ж�--��Ϸ����
	for (auto& Zombielist : m_Zombielist)
	{
		for (auto& Zombie : Zombielist)
		{
			if (Zombie->GetPosition().x <= 240)
			{
				MessageBox(NULL, "������ӱ��Ե��ˣ���", "ֻ����̫��", MB_OK);
				exit(-1);
			}
		}
	}

}

void YScene::Event_Tick(const ExMessage* msg)
{
	if (msg->message == WM_RBUTTONDOWN)//������¼�
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 9; j++)
			{
				YPlant* Plant = m_PlantTable[i][j];
				if (! Plant)continue;
				/*if (Plant->GetBoundingBox().IsOverlay(YVector(msg->x, msg->y)))*/
				if(msg->x>=Plant->GetPosition().x&& msg->x <= Plant->GetPosition().x+60&& msg->y >= Plant->GetPosition().y && msg->y <= Plant->GetPosition().y + 60)
				{
					delete Plant;
					m_PlantTable[i][j] = nullptr;
				}
			}

		//for (auto& Zombielist : m_Zombielist)
		//{
		//	for (std::list<Zombie*>::iterator it=Zombielist.begin();it!=Zombielist.end();it++)
		//	{
		//		Zombie* zombie = *it;
		//		if (msg->x >= zombie->GetPosition().x && msg->x <= zombie->GetPosition().x + 60 && msg->y >= zombie->GetPosition().y && msg->y <= zombie->GetPosition().y + 60)
		//		{
		//			//Zombielist.erase(it);
		//			Zombielist.clear();
		//		}
		//	}
		//}
	}
}
