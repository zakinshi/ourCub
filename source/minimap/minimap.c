#include "minimap.h"

void	draw_minimap(t_global *_g)
{
	t_minilx	*mn_mlx_s;

	mn_mlx_s = malloc(sizeof(t_minilx));
	//ft_lstadd_back(&g_cub.grbg_colct, ft_grbg_new(mn_mlx_s));
	mn_mlx_s->mlx_ptr = _g->mlx_s->mlx_ptr;
	mn_mlx_s->win = _g->mlx_s->win;
	minimap_image(mn_mlx_s);
	draw_walls(_g, mn_mlx_s);
	_player(_g, mn_mlx_s);
	mlx_put_image_to_window(mn_mlx_s->mlx_ptr, mn_mlx_s->win, mn_mlx_s->mn_img, 0, 0);
}