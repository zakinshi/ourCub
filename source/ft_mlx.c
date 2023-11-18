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
	if (!mlx_s->img)
		exit_msg("Allocation Failed for mlx_s->img");
	mlx_s->addr = mlx_get_data_addr(mlx_s->img, &(mlx_s->b_p_l), &(mlx_s->l_l), &(mlx_s->dian));
	if (!mlx_s->addr)
		exit_msg("Allocation Failed for mlx_s->addr");

}

void	init_mlx_s(t_global *_g)
{
	t_mlx		*mlx_s;

	mlx_s =malloc(sizeof(t_mlx));
	if (!mlx_s)
		exit_msg("Allocation Failed for mlx_s");
	_g->mlx_s = mlx_s;
	_g->mlx_s->mlx_ptr = mlx_init();
	if (!_g->mlx_s->mlx_ptr)
		exit_msg("Allocation Failed for mlx_ptr");
	_g->mlx_s->win = mlx_new_window(_g->mlx_s->mlx_ptr, WIDTH, HEIGHT, "Grid Example");
	if (!_g->mlx_s->win)
		exit_msg("Allocation Failed for mlx->win");
}
