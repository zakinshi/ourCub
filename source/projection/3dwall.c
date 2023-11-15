#include "../minimap.h"

int	_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	grade_color(double it, int hitvertical)
{
	int color;

	if (hitvertical)
		color = 255 - (it * 0.2);
	else
		color = 180 - (it * 0.1);
	return (_trgb(0, color, color, color));
}

void	sky_floor_color(t_global *_g, int i, int wall_top_pixel, int wall_bottom_pixel)
{
	int	y;

	y = -1;
	while (++y < wall_top_pixel)
		my_mlx_pixel_put(_g->mlx_s, i, y, _g->maps->sky_color);
	y = wall_bottom_pixel - 1;
	while (++y < HEIGHT)
		my_mlx_pixel_put(_g->mlx_s, i, y, _g->maps->floor_color);
}

void	_fake3d_wall(t_global *_g)
{
	t_rays	*ray;
	double	wallheight;
	double	raydistance;
	double	dis_projectplane;

	for (int i = 0; _g->rays[i]; i++)
	{
		ray = _g->rays[i];
		raydistance = ray->distance * cos(ray->angle_veiw - _g->player->rotation_angle);	// that fixed the fishi-blow-view
		dis_projectplane = (WIDTH / 2) / tan(FOV_ANGLE / 2);								// Calculate the distance to the projection plane
		wallheight = (GRID_SIZE / raydistance) * dis_projectplane;							// project wall height
		
		int	wall_top_pixel = (HEIGHT / 2) - (wallheight / 2);
		if (wall_top_pixel < 0)
			wall_top_pixel = 0;
		int	wall_bottom_pixel = (HEIGHT / 2) + (wallheight / 2);
		if (wall_bottom_pixel > WIDTH)
			wall_bottom_pixel = WIDTH;
		sky_floor_color(_g, i, wall_top_pixel, wall_bottom_pixel);
		for (int y = wall_top_pixel; y < wall_bottom_pixel; y++)
			my_mlx_pixel_put(_g->mlx_s, i, y, grade_color(raydistance, ray->hit_vertical));
	}
}
