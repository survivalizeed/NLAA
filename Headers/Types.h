#include "../Includes.h"

typedef unsigned int Color;

// RGB als Input -> Speicher als unsigned int Zahl
#define Color(r,g,b) (Color)(((((255)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))

struct Vec2 {
	int x, y;
};

struct RGB_ {
	int r = 0, g = 0, b = 0;
	
	void ToRGB(Color color)
	{
		r = GetBValue(color);
		g = GetGValue(color);
		b = GetRValue(color);
	}

	void Average(RGB_ o) {
		r = sqrt((r * r) + (o.r * o.r)) / 2;
		g = sqrt((g * g) + (o.g * o.g)) / 2;
		b = sqrt((b * b) + (o.b * o.b)) / 2;
	}

	Color ToColor()
	{
		return Color(r, g, b);
	}
};