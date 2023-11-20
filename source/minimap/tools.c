#include "minimap.h"

static void	put_circle_pixles(t_minilx *mlx_s, int x, int y, int i, int j)
{
	int color;

	color = change_the_trans('g');
	minimap_mlx_pixel_put(mlx_s, x + i, y + j, color);
	minimap_mlx_pixel_put(mlx_s, x - i, y + j, color);
	minimap_mlx_pixel_put(mlx_s, x + i, y - j, color);
	minimap_mlx_pixel_put(mlx_s, x - i, y - j, color);
	minimap_mlx_pixel_put(mlx_s, x + j, y + i, color);
	minimap_mlx_pixel_put(mlx_s, x - j, y + i, color);
	minimap_mlx_pixel_put(mlx_s, x + j, y - i, color);
	minimap_mlx_pixel_put(mlx_s, x - j, y - i, color);
}

void	draw_circle(t_minilx *mlx_s, int x, int y, int r)
{
	int i;
	int j;
	int d;

	i = r;
	j = 0;
	d = 1 - r;
	while (i > j) {
		put_circle_pixles(mlx_s, x, y , i, j);
		if (d < 0)
			d += 2 * j + 3;
		else
		{
			i--;
			d += 2 * (j - i) + 5;
		}
		j++;
	}
}

void	_disk(t_minilx *mlx_s, int cx, int cy, int r)
{
	int	y;
	int	x;

	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y <= r * r)
				minimap_mlx_pixel_put(mlx_s, cx + x, cy + y, 0x912a00);
			x++;
		}
		y++;
	}
}

void _daa_line_mini(t_minilx *mlx_s, double x0, double y0, double x1, double y1, long color)
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

		minimap_mlx_pixel_put(mlx_s, x, y, color);
		x += Xinc;
		y += Yinc;
	}
}
