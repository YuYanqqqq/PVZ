#pragma once
#ifndef __TOOLS_H_
#define __TOOLS_H

#include <easyx.h>
#pragma comment(lib,"MSIMG32.LIB")

class Tools
{
public:
	static void putimage_alpha(int x, int y, IMAGE* img)
	{
		int w = img->getwidth();
		int h = img->getheight();
		AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
	}
};
//����ͷ�ļ��������ľ�̬��������������͸����
// ��.png��ʽ��ͼƬ����������Ӧ����͸���ģ�ֻ�����ն˿���̨�в�����ʾΪ͸��������ռ����ͼƬ��С���ڴ棩







#endif