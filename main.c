#include <reg52.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

void main()
{
	graphics_init();
	
	draw_line(0, 0, SCREEN_RESOLUTION_X_MAX, SCREEN_RESOLUTION_Y_MAX, RGB(RGBMAX, RGBMAX, RGBMAX));
	draw_line(SCREEN_RESOLUTION_X_MAX, 0, 0, SCREEN_RESOLUTION_Y_MAX, RGB(RGBMAX, RGBMAX, RGBMAX));
	
	draw_line(0, 0, SCREEN_RESOLUTION_X_MAX, 0, RGB(RGBMAX, RGBMAX, RGBMAX));
	draw_line(SCREEN_RESOLUTION_X_MAX, 0, SCREEN_RESOLUTION_X_MAX, SCREEN_RESOLUTION_Y_MAX, RGB(RGBMAX, RGBMAX, RGBMAX));
	draw_line(SCREEN_RESOLUTION_X_MAX, SCREEN_RESOLUTION_Y_MAX, 0, SCREEN_RESOLUTION_Y_MAX, RGB(RGBMAX, RGBMAX, RGBMAX));
	draw_line(0, SCREEN_RESOLUTION_Y_MAX, 0, 0, RGB(RGBMAX, RGBMAX, RGBMAX));
	
	while (1)
	{
// 		uint color = RGB(rand() % RGBMAX, rand() % RGBMAX, rand() % RGBMAX);
// 		int i = 0;
// 		for (i = 0; i <= SCREEN_RESOLUTION_Y_MAX; i++)
// 		{
// 			draw_line(0, i, SCREEN_RESOLUTION_X_MAX, i, color);
// 		}
	}
}
