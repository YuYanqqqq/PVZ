#pragma once
#include "Tools.h"
#include <easyx.h>
#include "Vector.h"
#include "Animation.h"
#include "Rect.h"
class YPlant
{
private:
	IMAGE* m_Image;
	YVector m_Position;
	YPlant() = default;//将默认构造函数写到private中实现构造类时的封装
						//由于设置为private后编译器就不能自动创建一个默认构造函数
						//因此加上default关键字表示显示指出让编译器给出一个默认构造函数
						//这样用户（外界）只能通过自定义的构造函数来创建对象，有利于进行debug等操作
	Animation* m_Animation;//动画


	bool is_Animation;//是否开启动画

	int m_CurrentAnimationFrame;//当前动画帧

	float m_AnimationCount;//动画时间累加器

public:
	static YPlant* Create();//自定义的构造函数，设置为静态有助于确保类的对象在内存中只创建一次实例，
	//无论有多少个类对象被声明。这对于那些不希望类有多个实例或者只需要一个全局实例的类来说非常有用
public:
	//YPlant() {};

	bool Init();

	void Draw_Tick();
	void Event_Tick(float delta);
	void SetPosition(const YVector& Position){
		m_Position = Position;
	}

	YVector GetPosition()const { return m_Position; };


	void SetAnimation(Animation* _Animation) { m_Animation = _Animation; };
	
	void SetStartAnimation(bool IsStartAnimation = true) { is_Animation = IsStartAnimation; };//设置启动动画状态为真，开启动画
	
	Rect GetBoundingBox() { return Rect(m_Position.x, m_Position.y, m_Position.x + m_Image->getwidth(), m_Position.y + m_Image->getheight()); };
	//获取包围盒


};

