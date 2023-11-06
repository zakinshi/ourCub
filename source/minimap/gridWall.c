#include "../minimap.h"

static void	draw_care(t_mlx *mlx_s, double x, double y, int size_care, int color)
{
	
	double fixy = y;
	double fixx = x;
	while (y <= fixy + size_care)
	{
		double x = fixx;
		while (x <= fixx + size_care)
		{
			my_mlx_pixel_put(mlx_s, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_rect(t_mlx *mlx_s, double x, double y, int size_width, int size_height, int color)
{
	
	double fixy = y;
	double fixx = x;
	while (y <= fixy + size_height)
	{
		double x = fixx;
		while (x <= fixx + size_width)
		{
			my_mlx_pixel_put(mlx_s, x, y, color);
			x++;
		}
		y++;
	}
}

static void _grid(t_mlx *mlx_s, double x, double y, int size_care, int color)
{
	
	double fixy = y;
	double fixx = x;
	while (y <= fixy + size_care)
	{
		while (x <= fixx + size_care)
		{
			my_mlx_pixel_put(mlx_s, x, y, color);
			x++;
		}
		y += GRID_SIZE;
	}

	x = fixx;
	y = fixy;
	while (x <= fixx + size_care)
	{
		while (y <= fixy + size_care)
		{
			my_mlx_pixel_put(mlx_s, x, y, color);
			y++;
		}
		x += GRID_SIZE;
	}
}

void	draw_walls(t_mlx *mlx_s, char **map)
{
	int NUM_ROWS = lenlines(map);
	int NUM_COLON = strlen(map[0]);
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLON; j++)
		{
			
			int tileX = MINIMAP_FCTR * (j *  GRID_SIZE + MINIMAP_OFF);
			int tileY = MINIMAP_FCTR * (i *  GRID_SIZE + MINIMAP_OFF);
			long long tileColor = map[i][j] == '1' ? RED : WHITE;
			draw_care(mlx_s, tileX, tileY, \
						MINIMAP_FCTR * GRID_SIZE, tileColor);
			_grid(mlx_s, tileX, tileY, \
					MINIMAP_FCTR * GRID_SIZE, BLACK);
		}
	}
}
