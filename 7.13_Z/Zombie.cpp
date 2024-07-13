#include "Zombie.h"
#include "Tools.h"

Zombie* Zombie::Create()
{
	Zombie* NewZombie = new Zombie;
	NewZombie->Init();
	if (NewZombie && NewZombie->Init())
		return NewZombie;

	if (NewZombie)
		delete NewZombie;
	return nullptr;
}

bool Zombie::Init()
{
	m_Image = new IMAGE;
	if (!m_Image)return false;
	loadimage(m_Image, "source/zombies/walk/icecreamZombie/a (1).png");
	
	is_Animation = false;
	m_CurrentAnimationFrame = 0;
	m_AnimationCount = 0.0f;

	m_IsAttackState = false;//初始化为僵尸未碰到植物的状态

	return true;
}

void Zombie::Draw_Tick()
{
	//putimage(m_Position.x, m_Position.y, m_Image);
	if (!is_Animation)
		Tools::putimage_alpha(m_Position.x, m_Position.y, m_Image);//调用Tools.h头文件静态函数实现背景透明化

	else
	{
		if(!m_IsAttackState)
		Tools::putimage_alpha(m_Position.x, m_Position.y, m_Animation->GetAnimationVector()[m_CurrentAnimationFrame]);

		else
		Tools::putimage_alpha(m_Position.x, m_Position.y, m_AttackAnimation->GetAnimationVector()[m_CurrentAnimationFrame]);
	}
#ifdef _DEBUG
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 2);
	rectangle(m_Position.x+80, m_Position.y, m_Position.x + 160, m_Position.y + m_Image->getheight());
#endif//dubug模式下才有的代码，用于调试和测试
}

void Zombie::Event_Tick(float delta)
{
	if(!m_IsAttackState)
	m_Position.x -= 30.0f * delta;//改变僵尸的位置即让僵尸动起来

	m_AnimationCount += delta;

	if (!m_IsAttackState) {
		if (m_AnimationCount >= m_Animation->GetInvertal())
		{
			m_CurrentAnimationFrame++;
			if (m_CurrentAnimationFrame >= m_Animation->GetAnimationVector().size())
				m_CurrentAnimationFrame = 0;

			m_AnimationCount -= m_Animation->GetInvertal();
		}
	}

	else
	{
		if (m_AnimationCount >= m_AttackAnimation->GetInvertal())
		{
			m_CurrentAnimationFrame++;
			if (m_CurrentAnimationFrame >= m_AttackAnimation->GetAnimationVector().size())
				m_CurrentAnimationFrame = 0;
			m_AnimationCount -= m_AttackAnimation->GetInvertal();
		}
	}
}
