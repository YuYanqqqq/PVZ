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
	loadimage(m_Image, "source/plants/greenPeasShooter/a (1).png");
	m_CurrentAnimationFrame = 0;
	m_AnimationCount = 0.1f;

	return true;
}

void YPlant::Draw_Tick()
{
	if (!is_Animation)
		Tools::putimage_alpha(m_Position.x, m_Position.y, m_Image);//调用Tools.h头文件静态函数实现背景透明化
	//putimage(m_Position.x, m_Position.y, m_Image);

	else
		Tools::putimage_alpha(m_Position.x, m_Position.y, m_Animation->GetAnimationVector()[m_CurrentAnimationFrame]);

#ifdef _DEBUG
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 2);
	rectangle(m_Position.x, m_Position.y, m_Position.x + m_Image->getwidth(), m_Position.y + m_Image->getheight());
#endif//dubug模式下才有的代码，用于调试和测试
}

void YPlant::Event_Tick(float delta)
{
	m_AnimationCount += delta;
	if (m_AnimationCount >= m_Animation->GetInvertal())
	{
		m_CurrentAnimationFrame++;
		if (m_CurrentAnimationFrame >= m_Animation->GetAnimationVector().size())
			m_CurrentAnimationFrame = 0;

		m_AnimationCount -= m_Animation->GetInvertal();
	}
}
