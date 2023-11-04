#include "minimap.h"

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

double	abs_(double n) {
	if (n < 0)
		return n * -1;
	return n;
}

void _DaaLine(t_mlx *mlx_s, double x0, double y0, double x1, double y1)
{
	double	deltaX = x1 - x0;
	double	deltaY = y1 - y0;

	double	steps;
	steps = abs_(deltaX) > abs_(deltaY) ? abs_(deltaX) : abs_(deltaY);

	float	Xinc, Yinc;
	Xinc = deltaX / (float)steps;
	Yinc = deltaY / (float)steps;

	double	x = x0, y = y0, i = -1;
	while (++i <= steps) {

		my_mlx_pixel_put(mlx_s, x, y, GREEN);
		x += Xinc;
		y += Yinc;
	}

}
