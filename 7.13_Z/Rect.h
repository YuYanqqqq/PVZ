#pragma once
#include <stdio.h>
#include <vector>
#include "Vector.h"
class Rect
{
public:
	Rect(float _x, float _y, float _w, float _h) :x(_x), y(_y), w(_w),h(_h) {};
	bool IsOverlay(const Rect& _Rect)
	{
		//printf("%f %f", x, y, _Rect.x, _Rect.y);
		if (x<=_Rect.x+_Rect.w)
			return true;

		else
		return false;
	}

	bool IsOverlay(const YVector& Vector)//判断鼠标点击的位置是否在相应盒体内
	{
		if (x <= Vector.x && y <= Vector.y && Vector.x <= x + w && Vector.y <= y + h)
		{
			return true;
		}
		return false;
	}

	float x, y, w, h;
};

