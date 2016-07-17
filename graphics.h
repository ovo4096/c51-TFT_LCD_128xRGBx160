#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <basetypehelp.h>

#define SCREEN_RESOLUTION_X_MAX	(127)
#define SCREEN_RESOLUTION_Y_MAX	(159)

#define RGB(r, g, b) ((uint)(r << 11 | ((g << 1) | (g >> 4)) << 5 | b))
#define RGBMAX	(31)

extern void graphics_init();
extern void put_pixel(byte x, byte y, uint color);
extern uint get_pixel(byte x, byte y);
extern void draw_line(int x0, int y0, int x1, int y1, uint color);

#endif