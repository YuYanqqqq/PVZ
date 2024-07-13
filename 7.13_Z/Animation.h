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

	std::vector<IMAGE*>& GetAnimationVector() { return m_AnimationImageVector; };//获取动画接口

private:
	std::vector<IMAGE*> m_AnimationImageVector;//动画图片数组

	float m_Interval;//切换图片的间隔时间
};

