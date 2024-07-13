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
	m_BackgroundImg = new IMAGE;//创建图片内存
	
	if (!m_BackgroundImg)return false;
	loadimage(m_BackgroundImg,L"source/backGround/gameBackground.jpg");//加载图片函数，图片指针，L图片在根目录下的地址

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

	static int i = 0;//用于debug静态成员变量，观察函数调用了多少次

	printf("draw tick %d\n",++i);//测试输出
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
