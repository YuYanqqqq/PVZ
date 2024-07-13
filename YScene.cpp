#include "YScene.h"
#include <stdio.h>

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
	loadimage(m_BackgroundImg,L"source/backGround/gameBackground.jpg");//����ͼƬ������ͼƬָ�룬LͼƬ�ڸ�Ŀ¼�µĵ�ַ

	////m_Plant = new YPlant;//Ϊֲ��ͼƬ�����ڴ�
	//m_Plant = YPlant::Create();//���÷�װ���Զ���Ĺ��캯���������Ͻ���
	//m_Plant->Init();//�ֶ����ó�ʼ������
	for(int i=0;i<5;i++)
		for (int j = 0; j < 9; j++)
		{
			m_PlantTable[i][j] = YPlant::Create();
			m_PlantTable[i][j]->SetPosition(YVector(320+j*96, 120+i*115));
		}

	return true;
}

void YScene::Draw_Tick()
{
	putimage(0, 0, m_BackgroundImg);//��ͼƬ��������̨�ϣ�ͼƬ��һ�������ڿ���̨�ϵĺ������꣬ͼƬ��

	static int i = 0;//����debug��̬��Ա�������۲캯�������˶��ٴ�

	printf("draw tick %d\n",++i);//�������
	//m_Plant->Draw_Tick();
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
		{
			m_PlantTable[i][j]->Draw_Tick();
		}
}

void YScene::Event_Tick(float delta)
{


}
