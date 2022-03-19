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

	void Average(RGB_ o, float fak = 1.f) {
		r = sqrt((r * r) + (o.r * o.r * fak)) / 2;
		g = sqrt((g * g) + (o.g * o.g * fak)) / 2;
		b = sqrt((b * b) + (o.b * o.b * fak)) / 2;
		if (r > 255) r = 255;
		if (g > 255) g= 255;
		if (b > 255) b = 255;
	}

	Color ToColor()
	{
		return Color(r, g, b);
	}
};