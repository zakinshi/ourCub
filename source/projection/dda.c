#include "../cub3d.h"

double	disatnce_between2points(double x1, double y1, double x2, double y2)
{
	double	deltax2;
	double	deltay2;

	deltax2 = x2 - x1;
	deltay2 = y2 - y1;
	deltax2 = deltax2 * deltax2;
	deltay2 = deltay2 * deltay2;
	return (sqrt(deltax2 + deltay2));
}

double	abs_(double n)
{
	if (n < 0)
		return n * -1;
	return n;
}
