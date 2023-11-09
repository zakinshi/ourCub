#include "../minimap.h"

void	draw_rays(t_global *_g)
{
	t_mlx		*mlx_s;
	t_player	*player;
	int			column;

	column = 0;
	mlx_s = _g->mlx_s;
	player = _g->player;
	while (_g->rays[column])
	{
		_daa_line(mlx_s, MINIMAP_FCTR * player->x, MINIMAP_FCTR * player->y,\
			MINIMAP_FCTR * _g->rays[column]->wallhitx,\
			MINIMAP_FCTR * _g->rays[column]->wallhity, BLUECIEL);
		column++;
	}
}

void	struct_copy(t_coord *copy_in, t_coord copy_to)
{
	copy_in->x = copy_to.x;
	copy_in->y = copy_to.y;
}

double	norm_angle(double my_angle)
{
	my_angle = fmod(my_angle ,(2.00 * M_PI));
	if (my_angle < 0)
		my_angle += (2 * M_PI);
	return my_angle;
}
