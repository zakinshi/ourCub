#include "../minimap.h"

static void	put_circle_pixles(t_mlx *mlx_s, int x, int y, int i, int j)
{
	int color;

	color = 0x111000;
	my_mlx_pixel_put(mlx_s, x + i, y + j, color);
	my_mlx_pixel_put(mlx_s, x - i, y + j, color);
	my_mlx_pixel_put(mlx_s, x + i, y - j, color);
	my_mlx_pixel_put(mlx_s, x - i, y - j, color);
	my_mlx_pixel_put(mlx_s, x + j, y + i, color);
	my_mlx_pixel_put(mlx_s, x - j, y + i, color);
	my_mlx_pixel_put(mlx_s, x + j, y - i, color);
	my_mlx_pixel_put(mlx_s, x - j, y - i, color);
}

void	draw_circle(t_mlx *mlx_s, int x, int y, int r)
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

void	_disk(t_mlx *mlx_s, int cx, int cy, int r)
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
				my_mlx_pixel_put(mlx_s, cx + x, cy + y, 0x912a00);
			x++;
		}
		y++;
	}
}
