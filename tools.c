#include "minimap.h"

void draw_grid(void *mlx, void *win)
{
    int x, y;

    // Draw horizontal lines
    y = 60;
    while (y <= HEIGHT - 100)
    {
        x = 60;
        while (x < WIDTH - 100)
        {
            my_mlx_pixel_put(mlx, win, x, y, 0xF80DA0); // Draw a white pixel
            x++;
        }
        y += GRID_SIZE;
    }

    // Draw vertical lines
    x = 60;
    while (x <= WIDTH - 100)
    {
        y = 60;
        while (y < HEIGHT - 100)
        {
            my_mlx_pixel_put(mlx, win, x, y, 0xF80DA0); // Draw a white pixel
            y++;
        }
        x += GRID_SIZE;
    }
}

void	draw_circle(void *mlx, void *win, int x, int y, int r) {

	long color = 0x111000;
	int i, j;
	int d;

	i = r;
	j = 0;
	d = 1 - r;

	while (i > j) {
		my_mlx_pixel_put(mlx, win, x + i, y + j, color);
		my_mlx_pixel_put(mlx, win, x - i, y + j, color);
		my_mlx_pixel_put(mlx, win, x + i, y - j, color);
		my_mlx_pixel_put(mlx, win, x - i, y - j, color);
		my_mlx_pixel_put(mlx, win, x + j, y + i, color);
		my_mlx_pixel_put(mlx, win, x - j, y + i, color);
		my_mlx_pixel_put(mlx, win, x + j, y - i, color);
		my_mlx_pixel_put(mlx, win, x - j, y - i, color);

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