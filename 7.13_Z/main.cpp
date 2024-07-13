#include <stdio.h>
#include "YScene.h"
#include <time.h>
#include <easyx.h>
#include "Tools.h"

int main()
{
	srand(time(NULL));//���������

	initgraph(1280, 720, EX_SHOWCONSOLE);
	//�������ڣ����ߣ����ÿ���̨


	YScene* Scene = YScene::Create();
	Scene->Init();//����������������ʼ��

	float fps = 1000.0f / 120;//fps��ʾ֡�����ڿ���ˢ���ʣ���ÿ����ú������ٴ�
	clock_t begin_time = clock(), end_time = 0;//���û�ȡϵͳʱ��Ĳ�������ʾ���ú������õ�ʱ��

	clock_t last_time = clock(), current_time = 0;

	BeginBatchDraw();//������˫���������ͼƬ��˸

	ExMessage msg;

	while (true)
	{
		end_time = clock();

		if ((float)(end_time - begin_time) >= fps)//��֡��С�����ӻ�
		{
			current_time = clock();
			Scene->Event_Tick(float(current_time-last_time)/CLOCKS_PER_SEC);//һ����������ȴ����¼����ٴ������
			//delta:��һ�ε��õ���һ�ε��øú�����ʱ��������������ʱ��
			last_time = current_time;

			Scene->Draw_Tick();
			FlushBatchDraw(); //������˫���������ͼƬ��˸
			
			begin_time = end_time;//�ı俪ʼʱ��Ϊ��һ�ε��ÿ�ʼʱҲ������һ�ε��ý���ʱ
		}
		else
		{
			Sleep(fps - (float)(end_time - begin_time));//����˯���ӳٺ�����ʹϵͳ������ʱ�������ʵ�ֵ���Ƶ�ʵ��ӻ�
		}

		if (peekmessage(&msg))
		{
			Scene->Event_Tick(&msg);
		}

	}
	EndBatchDraw();//������˫���������ͼƬ��˸


	return 0;
}
