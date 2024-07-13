#include <stdio.h>
#include "YScene.h"
#include <time.h>
#include <easyx.h>
#include "Tools.h"
#include<graphics.h>

ExMessage mouse;
bool flag_plant;
int num;
MOUSEMSG test;


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

		while (peekmessage(&mouse))
		{
			IMAGE move;
			if (mouse.message == WM_LBUTTONDOWN)
			{
				if (mouse.y > 10 && mouse.y < 82)
				{
					if (mouse.x > 375 && mouse.x < 426)
					{
						flag_plant = !flag_plant;
						loadimage((*Scene).get(1), _T("source/plantsCard/darkCard/Dark-sunFlowerCard.png"), 58, 89);
						(*Scene).set(1);
						num = 1;
					}
					else if (mouse.x > 429 && mouse.x < 480)
					{
						flag_plant = !flag_plant;
						loadimage((*Scene).get(2), _T("source/plantsCard/darkCard/Dark-greenPeasShooterCard.png"), 58, 89);
						(*Scene).set(2);
						num = 2;
					}
					else if (mouse.x > 483 && mouse.x < 534)
					{
						flag_plant = !flag_plant;
						loadimage((*Scene).get(3), _T("source/plantsCard/darkCard/Dark-normalNutCard.png"), 58, 89);
						(*Scene).set(3);
						num = 3;
					}
					else if (mouse.x > 537 && mouse.x < 588)
					{
						flag_plant = !flag_plant;
						loadimage((*Scene).get(4), _T("source/plantsCard/darkCard/Dark-snowShooterCard.png"), 58, 89);
						(*Scene).set(4);
						num = 4;
					}
					else if (mouse.x > 591 && mouse.x < 642)
					{
						flag_plant = !flag_plant;
						loadimage((*Scene).get(5), _T("source/plantsCard/darkCard/Dark-doubleGreenPeasShooterCard.png"), 58, 89);
						(*Scene).set(5);
						num = 5;
					}
				}
				else if (mouse.x >= 280 && mouse.x <= 1174 && mouse.y >= 90 && mouse.y <= 682)
				{
					flag_plant = !flag_plant;
					int x = mouse.x, y = mouse.y;
					int i, j;
					if (x < 398)j = 0;
					else if (x < 497) j = 1;
					else if (x < 591)j = 2;
					else if (x < 686)j = 3;
					else if (x < 787)j = 4;
					else if (x < 883)j = 5;
					else if (x < 973)j = 6;
					else if (x < 1069)j = 7;
					else if (x < 1174)j = 8;

					if (y < 218)i = 0;
					else if (y < 324)i = 1;
					else if (y < 452)i = 2;
					else if (y < 558)i = 3;
					else if (y < 682)i = 4;

					switch (num)
					{
					case 1:Scene->m_PlantTable[i][j] = new sunflower; break;
					case 2:Scene->m_PlantTable[i][j] = new greenPshooter; break;
					case 3:Scene->m_PlantTable[i][j] = new normalnut; break;
					case 4:Scene->m_PlantTable[i][j] = new doublegreenshooter; break;
					case 5:Scene->m_PlantTable[i][j] = new snowshooter; break;
					}
				}
			}
		}

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
