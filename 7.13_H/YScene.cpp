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
	m_BackgroundImg = new IMAGE;//创建图片内存
	
	if (!m_BackgroundImg)return false;
	loadimage(m_BackgroundImg,L"source/backGround/gameBackground.jpg");//加载图片函数，图片指针，L图片在根目录下的地址
	Cardbar = new IMAGE;
	loadimage(Cardbar, L"source/backGround/chooseCardBar.png");

	loadimage(&sunFlowerCard, _T("source/plantsCard/sunFlowerCard.png"),51, 72);

	loadimage(&greenShooterCard, _T("source/plantsCard/greenPeasShooterCard.png"),51,72);
	
	loadimage(&NutCard, _T("source/plantsCard/normalNutCard.png"), 51, 72);
	
	loadimage(&dgreenShooterCard, _T("source/plantsCard/doubleGreenPeasShooterCard.png"), 51, 72);
	
	loadimage(&snowShooterCard, _T("source/plantsCard/snowShooterCard.png"), 51, 72);
	////m_Plant = new YPlant;//为植物图片创建内存
	//m_Plant = YPlant::Create();//调用封装的自定义的构造函数，保持严谨性
	//m_Plant->Init();//手动调用初始化函数
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
	putimage(0, 0, m_BackgroundImg);//将图片贴到控制台上，图片第一个像素在控制台上的横纵坐标，图片名
	putimage(300, 1, Cardbar);
	putimage(375, 10, &sunFlowerCard);//向日葵卡片
	putimage(429, 10, &greenShooterCard);//豌豆射手卡片
	putimage(483, 10, &NutCard);//坚果卡片
	putimage(537, 10, &snowShooterCard);//寒冰射手卡片
	putimage(591, 10, &dgreenShooterCard);//双发射手卡片
	static int i = 0;//用于debug静态成员变量，观察函数调用了多少次

	
	printf("draw tick %d\n",++i);//测试输出
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