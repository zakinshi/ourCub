#include "minimap.h"

int	lenlines(char **rows)
{
	int i = -1;
	while (rows[++i])
		;
	return i;
} 

void	draw_minimap(t_global *_g)
{
	draw_walls(_g->mlx_s, _g->map);
	_player(_g);
}

void	draw_all(t_global *_g)
{
	_fake3d_wall(_g);
	draw_minimap(_g);
}

static int	driver(t_global	*_g)
{	
	image_driver(_g->mlx_s);
	updatePlayer(_g->player, _g->map);
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
	t_player	*player;
	t_global	*_g;

	_g = malloc(sizeof(t_global));
	player = init_player();
	_g->map = map; // parsing hold all formation of struct
	_g->player = player;
	init_mlx_s(_g);
	mlx_loop_hook(_g->mlx_s->mlx_ptr, driver, _g);
	mlx_hook(_g->mlx_s->win, 2, 5, moveHook, _g->player);
    mlx_loop(_g->mlx_s->mlx_ptr);
    return 0;
}
