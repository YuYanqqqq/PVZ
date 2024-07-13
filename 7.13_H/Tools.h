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
//工具头文件，包含的静态函数用来将背景透明化
// （.png格式的图片背景本来就应该是透明的，只是在终端控制台中不能显示为透明，而是占有其图片大小的内存）







#endif