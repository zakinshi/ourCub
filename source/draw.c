#include "minimap.h"

void	draw_minimap(t_global *_g)
{
	draw_walls(_g->mlx_s, _g->maps->map);
	_player(_g);
}

void	color_sky_floor(t_global *_g)
{
	draw_rect(_g->mlx_s, 0, 0, WIDTH, HEIGHT / 2, _g->maps->sky_color);
	draw_rect(_g->mlx_s, 0, HEIGHT / 2, WIDTH, HEIGHT / 2, _g->maps->floor_color);
}

void	draw_all(t_global *_g)
{
	// printf("( %.2f )\n", norm_angle(_g->player->rotation_angle));
	_fake3d_wall(_g);
	// draw_minimap(_g);
}
