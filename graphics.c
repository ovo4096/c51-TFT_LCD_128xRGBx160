#include <graphics.h>
#include <lcddrive.h>
#include <math.h>

void graphics_init()
{
	LCDInit();
}

static bool SetDrawStartPos(byte x, byte y)
{
	if (x > SCREEN_RESOLUTION_X_MAX || y > SCREEN_RESOLUTION_Y_MAX) return false;
	LCDRegisterWrite(SRAM_POS_X, x);
	LCDRegisterWrite(SRAM_POS_Y, y);
	return true;
}

void put_pixel(byte x, byte y, uint color)
{
	if (!SetDrawStartPos(x, y)) return;
	LCDMemoryWrite(color);
}

uint get_pixel(byte x, byte y)
{
	uint color;
	if (SetDrawStartPos(x, y)) return 0;
	LCDMemoryRead(&color);
	return color;
}

void draw_line(int x0, int y0, int x1, int y1, uint color)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int err = dx - dy;
	sbyte sx, sy;

	if (x0 < x1)
		sx = 1;
	else
		sx = -1;

	if (y0 < y1)
		sy = 1;
	else
		sy = -1;

	while (1)
	{
		int e2 = 2 * err;

		put_pixel(x0, y0, color);

		if (x0 == x1 && y0 == y1)
			return;

		if (e2 > -dy)
		{
			err = err - dy;
			x0 = x0 + sx;
		}

		if (x0 == x1 && y0 == y1)
		{
			put_pixel(x0, y0, color);
			return;
		}

		if (e2 < dx)
		{
			err = err + dx;
			y0 = y0 + sy;
		}
	}
}