#include "Plant.h"

YPlant* YPlant::Create()
{
	YPlant* NewPlant = new YPlant;
	NewPlant->Init();
	if(NewPlant&&NewPlant->Init())
	return NewPlant;

	if (NewPlant)
		delete NewPlant;
	return nullptr;
}

bool YPlant::Init()
{
	m_Image = new IMAGE;
	if(m_Image)
	loadimage(m_Image, L"source/plants/greenPeasShooter/a (1).png");
	
	return true;
}

void YPlant::Draw_Tick()
{
	Tools::putimage_alpha(m_Position.x, m_Position.y, m_Image);//调用Tools.h头文件静态函数实现背景透明化
	//putimage(m_Position.x, m_Position.y, m_Image);
}

void YPlant::Event_Tick(float delta)
{
}
