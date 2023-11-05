#include "minimap.h"

int	lenlines(char **rows)
{

	int i = -1;
	while (rows[++i])
		;
	return i;
} 

void	_Disk(t_mlx *mlx_s, int cx, int cy, int r) {

	for (int y = -r; y <= r; y++)
		for (int x = -r; x <= r; x++)
			if (x * x + y * y <= r * r)
				my_mlx_pixel_put(mlx_s, cx + x, cy + y, 0x912a00);
}

int	driver(t_global	*_g) {
	
	image_driver(_g->mlx_s);
	RaysCast(_g);
	_fake3d_wall(_g);
	draw_walls(_g->mlx_s, _g->map);
	_player(_g, _g->map);
	mlx_put_image_to_window(_g->mlx_s->mlx_ptr, _g->mlx_s->win, _g->mlx_s->img, 0, 0);
	return 0;
}

int main()
{
	t_mlx	*mlx_s;
	char *str = "1111111111 1000000001 1001000001 1010001001 1000100101 1010000101 1111111111";
	// char *str = "111 101 101  11";
	char **map = ft_split(str, ' ');
	t_player *player;
	t_global	*_g;

	_g = malloc(sizeof(t_global));
	mlx_s =malloc(sizeof(t_mlx));
	player = init_player();
	_g->map = map;
	_g->mlx_s = mlx_s;
	_g->player = player;
    _g->mlx_s->mlx_ptr = mlx_init();
    _g->mlx_s->win = mlx_new_window(_g->mlx_s->mlx_ptr, WIDTH, HEIGHT, "Grid Example");
	mlx_loop_hook(_g->mlx_s->mlx_ptr, driver, _g);
	mlx_hook(_g->mlx_s->win, 2, 5, moveHook, _g->player);
    mlx_loop(_g->mlx_s->mlx_ptr);

    return 0;
}
