#pragma once
#include <easyx.h>
#include <vector>

class Animation
{
private:
	Animation() = default;

public:
	static Animation* Create();
public:
	bool Init();

	void Addimage(const char* Filename);

	void SetInvertal(float Invertal) { m_Interval = Invertal; };
	float GetInvertal() { return m_Interval; };

	std::vector<IMAGE*>& GetAnimationVector() { return m_AnimationImageVector; };//��ȡ�����ӿ�

private:
	std::vector<IMAGE*> m_AnimationImageVector;//����ͼƬ����

	float m_Interval;//�л�ͼƬ�ļ��ʱ��
};

