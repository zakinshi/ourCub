#include "minimap.h"

int	lenlines(char **rows)
{
	int i = -1;
	while (rows[++i])
		;
	return i;
} 

static int	driver(t_global	*_g)
{
	image_driver(_g->mlx_s);
	update_player(_g->player, _g->maps);
	rays_cast(_g);
	draw_all(_g);
	init_move(_g->player);
	mlx_put_image_to_window(_g->mlx_s->mlx_ptr, _g->mlx_s->win, _g->mlx_s->img, 0, 0);
	mlx_destroy_image(_g->mlx_s->mlx_ptr,  _g->mlx_s->img);
	return 0;
}

int	ft_close(void)
{
	exit(0);
}

int main(void)
{
	t_global	*_g;

	_g = malloc(sizeof(t_global));
	if (!_g)
		return (printf("_g malloc failled.. \n"), 0);
	t_map *maps = malloc(sizeof(t_map));	// in the parsng function
	_g->maps = maps;						// where the t_maps will created in the parsing function
	if (!parsing_(_g))
		return (0);
	_g->maps->SIZE_GRID = (WIDTH / _g->maps->width_map);
	GRID_SIZE = _g->maps->SIZE_GRID;
	init_player(_g);
	init_mlx_s(_g);
	mlx_loop_hook(_g->mlx_s->mlx_ptr, driver, _g);
	mlx_hook(_g->mlx_s->win, 2, 5, move_hook, _g->player);
	mlx_hook(_g->mlx_s->win, 17, 0, ft_close, NULL);
	mlx_loop(_g->mlx_s->mlx_ptr);
	return 0;
}
