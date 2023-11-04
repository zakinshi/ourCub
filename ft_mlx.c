#include "minimap.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		dst = data->addr + (y * data->l_l + x * (data->b_p_l / 8));
		*(int *)dst = color;
	}
}

void	image_driver(t_mlx *mlx_s)
{
	mlx_clear_window(mlx_s->mlx_ptr, mlx_s->win);
	mlx_s->img = mlx_new_image(mlx_s->mlx_ptr, WIDTH, HEIGHT);
	mlx_s->addr = mlx_get_data_addr(mlx_s->img, &(mlx_s->b_p_l), &(mlx_s->l_l), &(mlx_s->dian));
}
