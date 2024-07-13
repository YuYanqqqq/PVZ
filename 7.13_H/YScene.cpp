#include "YScene.h"
#include <stdio.h>
#include<easyx.h>
#include <graphics.h>


MOUSEMSG mouse1;

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
	Cardbar = new IMAGE;
	loadimage(Cardbar, L"source/backGround/chooseCardBar.png");

	loadimage(&sunFlowerCard, _T("source/plantsCard/sunFlowerCard.png"),51, 72);

	loadimage(&greenShooterCard, _T("source/plantsCard/greenPeasShooterCard.png"),51,72);
	
	loadimage(&NutCard, _T("source/plantsCard/normalNutCard.png"), 51, 72);
	
	loadimage(&dgreenShooterCard, _T("source/plantsCard/doubleGreenPeasShooterCard.png"), 51, 72);
	
	loadimage(&snowShooterCard, _T("source/plantsCard/snowShooterCard.png"), 51, 72);
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
	putimage(300, 1, Cardbar);
	putimage(375, 10, &sunFlowerCard);//���տ���Ƭ
	putimage(429, 10, &greenShooterCard);//�㶹���ֿ�Ƭ
	putimage(483, 10, &NutCard);//�����Ƭ
	putimage(537, 10, &snowShooterCard);//�������ֿ�Ƭ
	putimage(591, 10, &dgreenShooterCard);//˫�����ֿ�Ƭ
	static int i = 0;//����debug��̬��Ա�������۲캯�������˶��ٴ�

	
	printf("draw tick %d\n",++i);//�������
	//m_Plant->Draw_Tick();
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
		{
			m_PlantTable[i][j]->Draw_Tick();
		}


	if (flag)
	{
		int x = 0, y = 0;
		mouse1 = GetMouseMsg();
		if (mouse1.uMsg == WM_MOUSEMOVE)
		{
			x = mouse1.x;
			y = mouse1.y;
		}
		Tools::putimage_alpha(x-35, y-45, &move);
	}
}

IMAGE* YScene::get(int n)
{
	switch (n)
	{
	case 1:return &sunFlowerCard;
	case 2:return &greenShooterCard;
	case 3:return &NutCard;
	case 4:return &snowShooterCard;
	case 5:return &dgreenShooterCard;
	}
}

void YScene::Event_Tick(float delta)
{

}

void YScene::set(int n)
{
	if (n == 0)
	{
		flag = 0;
		return;
	}
	else
	{
		flag = 1;
		switch (n)
		{
		case 1:loadimage(&move, _T("source/plants/sunflower/a (10).png"), 70, 90);
			break;
		case 2:loadimage(&move, _T("source/plants/greenPeasShooter/a (4).png"), 70, 90);
			break;
		case 3:loadimage(&move, _T("source/plants/normalNut/a (4).png"), 70, 90);
			break;
		case 4:loadimage(&move, _T("source/plants/snowShooter/a (1).png"), 70, 90);
			break;
		case 5:loadimage(&move, _T("source/plants/doubleGreenPeasShooter/a (1).png"), 70, 90);
			break;
		}
	}
}