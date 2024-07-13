#pragma once
#include "Tools.h"
#include <easyx.h>
#include "Vector.h"
class YPlant
{
public:
	IMAGE* m_Image;
	YVector m_Position;
	YPlant() = default;//��Ĭ�Ϲ��캯��д��private��ʵ�ֹ�����ʱ�ķ�װ
						//��������Ϊprivate��������Ͳ����Զ�����һ��Ĭ�Ϲ��캯��
						//��˼���default�ؼ��ֱ�ʾ��ʾָ���ñ���������һ��Ĭ�Ϲ��캯��
						//�����û�����磩ֻ��ͨ���Զ���Ĺ��캯�����������������ڽ���debug�Ȳ���


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


};

class greenPshooter : public YPlant
{
public:
	int blood = 10;
	bool Init();
};

class sunflower : public YPlant
{
public:
	int blood = 7;
	bool Init();
};

class normalnut : public YPlant
{
public:
	int blood = 20;
	bool Init();
};

class doublegreenshooter : public YPlant
{
public:
	int blood = 12;
	bool Init();
};

class snowshooter : public YPlant
{
public:
	int blood = 12;
	bool Init();
};
