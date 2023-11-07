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
	updatePlayer(_g->player, _g->maps->map);
	RaysCast(_g);
	draw_all(_g);
	initMove(_g->player);
	mlx_put_image_to_window(_g->mlx_s->mlx_ptr, _g->mlx_s->win, _g->mlx_s->img, 0, 0);
	return 0;
}

int main(void)
{
	char		*str = "1111111111 1000000001 1001000001 1010001001 1000100101 1010000101 1111111111";
	char		**map = ft_split(str, ' ');
	t_map		*maps;
	t_global	*_g;

	_g = malloc(sizeof(t_global));
	if (!_g)
		return (printf("_g malloc failled.. \n"), 0);
	init_player(_g);
	maps = malloc(sizeof(t_map));	// in the parsng function
	maps->map = map;				// where the t_maps will created in the parsing function
	maps->sky_color = 0x0000FF;		// in the parsing function
	maps->floor_color = 0x00FF00;	// in the parsing function
	_g->maps = maps;				// in the parsing function
	init_mlx_s(_g);
	mlx_loop_hook(_g->mlx_s->mlx_ptr, driver, _g);
	mlx_hook(_g->mlx_s->win, 2, 5, moveHook, _g->player);
    mlx_loop(_g->mlx_s->mlx_ptr);
    return 0;
}
