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
	YPlant() = default;//��Ĭ�Ϲ��캯��д��private��ʵ�ֹ�����ʱ�ķ�װ
						//��������Ϊprivate��������Ͳ����Զ�����һ��Ĭ�Ϲ��캯��
						//��˼���default�ؼ��ֱ�ʾ��ʾָ���ñ���������һ��Ĭ�Ϲ��캯��
						//�����û�����磩ֻ��ͨ���Զ���Ĺ��캯�����������������ڽ���debug�Ȳ���
	Animation* m_Animation;//����


	bool is_Animation;//�Ƿ�������

	int m_CurrentAnimationFrame;//��ǰ����֡

	float m_AnimationCount;//����ʱ���ۼ���

public:
	static YPlant* Create();//�Զ���Ĺ��캯��������Ϊ��̬������ȷ����Ķ������ڴ���ֻ����һ��ʵ����
	//�����ж��ٸ�������������������Щ��ϣ�����ж��ʵ������ֻ��Ҫһ��ȫ��ʵ��������˵�ǳ�����
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
	
	void SetStartAnimation(bool IsStartAnimation = true) { is_Animation = IsStartAnimation; };//������������״̬Ϊ�棬��������
	
	Rect GetBoundingBox() { return Rect(m_Position.x, m_Position.y, m_Position.x + m_Image->getwidth(), m_Position.y + m_Image->getheight()); };
	//��ȡ��Χ��


};

