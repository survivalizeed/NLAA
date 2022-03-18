#include "../Headers/Line.h"

void DrawLine(Vec2 start, Vec2 end, Color color) 
{
	int dx = end.x - start.x;
	int dy = end.y - start.y;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float xInc = dx / static_cast<float>(steps);
	float yInc = dy / static_cast<float>(steps);

	float x = static_cast<float>(start.x);
	float y = static_cast<float>(start.y);

	for (int i = 0; i <= steps; i++) {
		Set({ static_cast<int>(round(x)), static_cast<int>(round(y)) }, color);
		x += xInc;
		y += yInc;
	}
}

void DrawAALineDrawer(Vec2 start, Vec2 end, Color color) 
{
	int dx = end.x - start.x;
	int dy = end.y - start.y;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float xInc = dx / static_cast<float>(steps);
	float yInc = dy / static_cast<float>(steps);

	float x = static_cast<float>(start.x);
	float y = static_cast<float>(start.y);

	for (int i = 0; i <= steps; i++) {
		RGB_ mixed{}, get{};
		mixed.ToRGB(color);
		get.ToRGB(Get({ static_cast<int>(round(x)), static_cast<int>(round(y)) }));
		mixed.Average(get);
		Set({ static_cast<int>(round(x)), static_cast<int>(round(y)) }, mixed.ToColor());
		x += xInc;
		y += yInc;
	}
}

void DrawAALine(Vec2 start, Vec2 end, Color color)
{
	DrawLine(start, end, color);
	int xN = 0;
	int yN = 0;
	float angle = atan2(end.y - 500, end.x - 500) * 180 / M_PI;
	if (angle < 0) angle += 360;
	if (angle >= 45 && angle <= 135) {
		xN = -1;
		yN = 0;
	}
	else if (angle >= 135 && angle <= 225) {
		xN = 0;
		yN = -1;
	}
	else if (angle >= 225 && angle <= 315) {
		xN = 1;
		yN = 0;
	}
	else if ((angle >= 315 && angle <= 360) || (angle >= 0 && angle <= 45)) {
		xN = 0;
		yN = 1;
	}
	DrawAALineDrawer({ start.x + xN, start.y + yN }, { end.x + xN, end.y + yN }, color);
	DrawAALineDrawer({ start.x - xN, start.y - yN }, { end.x - xN, end.y - yN }, color);
}
