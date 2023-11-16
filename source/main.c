#include "minimap.h"

int	lenlines(char **rows)
{
	int i = -1;
	while (rows[++i])
		;
	return i;
} 

int	driver(t_global	*_g)
{
	image_driver(_g->mlx_s);
	update_player(_g->player, _g->maps);
	rays_cast(_g);
	draw_all(_g);
	init_move(_g->player);
	mlx_put_image_to_window(_g->mlx_s->mlx_ptr, _g->mlx_s->win, _g->mlx_s->img, 0, 0);
	mlx_destroy_image(_g->mlx_s->mlx_ptr,  _g->mlx_s->img);
	return (0);
}

int	ft_close(void)
{
	exit(0);
}

void	define_grid_size(t_global *_g)
{
	int	for_height;
	int	for_width;

	for_width = (WIDTH / _g->maps->width_map);
	for_height = (HEIGHT / _g->maps->hieght_map);
	GRID_SIZE = for_height < for_width ? for_height : for_width;
	// GRID_SIZE = 32;
}

int	get_direction(int x, t_coord last_coord)
{
	if (x > last_coord.x)
		return (1);
	if (x < last_coord.x)
		return (-1);
	return (0);
}



int	main_driver(char *path)
{
	t_global	*_g;

	_g = malloc(sizeof(t_global));
	if (!_g)
		return (printf("_g malloc failled.. \n"), 1);
	t_map *maps = malloc(sizeof(t_map));	// in the parsng function
	_g->maps = maps;						// where the t_maps will created in the parsing function
	_g->path = path;
	if (!parsing_(_g))
		return (1);
	define_grid_size(_g);
	init_player(_g);
	init_mlx_s(_g);
	mlx_loop_hook(_g->mlx_s->mlx_ptr, driver, _g);
	mlx_hook(_g->mlx_s->win, 2, 5, move_hook, _g->player);
	// mlx_mouse_hook(_g->mlx_s->win, mouse_hook, _g->player);
	mlx_hook(_g->mlx_s->win, 6, 0, mouse_move, _g);
	mlx_hook(_g->mlx_s->win, 17, 0, ft_close, NULL);
	mlx_loop(_g->mlx_s->mlx_ptr);

	return (0);
}
int main(int ac, char **av)
{
	if (ac != 2)
		exit_msg("Warnning :\n\t./Cub3D ./[Path_map]\n");
	return (main_driver(av[1]));
}
