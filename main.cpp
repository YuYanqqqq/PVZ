#include <stdio.h>
#include "YScene.h"
#include <time.h>
#include <easyx.h>
#include "Tools.h"

int main()
{
	initgraph(1280, 720, EX_SHOWCONSOLE);
	//�������ڣ����ߣ����ÿ���̨


	YScene* Scene = YScene::Create();
	Scene->Init();//����������������ʼ��

	float fps = 1000.0f / 60;//fps��ʾ֡�����ڿ���ˢ���ʣ���ÿ����ú������ٴ�
	clock_t begin_time = clock(), end_time = 0;//���û�ȡϵͳʱ��Ĳ�������ʾ���ú������õ�ʱ��

	BeginBatchDraw();//������˫���������ͼƬ��˸

	while (true)
	{
		end_time = clock();
		if ((float)(end_time - begin_time) >= fps)//��֡��С�����ӻ�
		{
			Scene->Event_Tick(0.0f);//һ����������ȴ����¼����ٴ������

			Scene->Draw_Tick();
			FlushBatchDraw(); //������˫���������ͼƬ��˸
			
			begin_time = end_time;//�ı俪ʼʱ��Ϊ��һ�ε��ÿ�ʼʱҲ������һ�ε��ý���ʱ
		}
		else
		{
			Sleep(fps - (float)(end_time - begin_time));//����˯���ӳٺ�����ʹϵͳ������ʱ�������ʵ�ֵ���Ƶ�ʵ��ӻ�
		}
	}
	EndBatchDraw();//������˫���������ͼƬ��˸


	return 0;
}
