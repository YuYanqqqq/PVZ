#include <stdio.h>
#include "YScene.h"
#include <time.h>
#include <easyx.h>
#include "Tools.h"

int main()
{
	srand(time(NULL));//随机数种子

	initgraph(1280, 720, EX_SHOWCONSOLE);
	//创建窗口，宽，高，调用控制台


	YScene* Scene = YScene::Create();
	Scene->Init();//创建场景，场景初始化

	float fps = 1000.0f / 120;//fps表示帧率用于控制刷新率，即每秒调用函数多少次
	clock_t begin_time = clock(), end_time = 0;//利用获取系统时间的差异来表示调用函数所用的时间

	clock_t last_time = clock(), current_time = 0;

	BeginBatchDraw();//！！！双缓冲来解决图片闪烁

	ExMessage msg;

	while (true)
	{
		end_time = clock();

		if ((float)(end_time - begin_time) >= fps)//若帧率小则不用延缓
		{
			current_time = clock();
			Scene->Event_Tick(float(current_time-last_time)/CLOCKS_PER_SEC);//一般情况下是先处理事件，再处理绘制
			//delta:上一次调用到这一次调用该函数的时间间隔，可用作定时器
			last_time = current_time;

			Scene->Draw_Tick();
			FlushBatchDraw(); //！！！双缓冲来解决图片闪烁
			
			begin_time = end_time;//改变开始时间为下一次调用开始时也就是上一次调用结束时
		}
		else
		{
			Sleep(fps - (float)(end_time - begin_time));//利用睡眠延迟函数来使系统工作的时间减慢，实现调用频率的延缓
		}

		if (peekmessage(&msg))
		{
			Scene->Event_Tick(&msg);
		}

	}
	EndBatchDraw();//！！！双缓冲来解决图片闪烁


	return 0;
}
