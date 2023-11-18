#include "../minimap.h"

int	_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


void	int_xpm(t_global *_g)
{
	t_text	*xpm;

	xpm = malloc(sizeof(t_text));
	xpm->addr_x[0] = NULL;
	xpm->b_p_x = 0;
	xpm->distpropln = 0.00;
	xpm->l_x = 0;
	xpm->per_dist = 0.00;
	xpm->projwallht = 0.00;
	xpm->textureoffsetx = 0;
	xpm->textureoffsety = 0;
	xpm->wallbotmpixl = 0;
	xpm->wallstripht = 0;
	xpm->walltext = 0;
	xpm->walltoppixl = 0;
	xpm->x_hight = 0;
	xpm->x_width = 0;
	xpm->xpm[0] = NULL;

	_g->texture = xpm;
}

void	_fake3d_wall(t_global *_g)
{
	int	i = 0;

	int_xpm(_g);
	xpm_driver(_g);
	while (_g->rays[i])
	{
		calcule_text(_g, i);
		texture_offset(_g, i);
		for (int y = 0; y < _g->texture->walltoppixl; y++)
			my_mlx_pixel_put(_g->mlx_s, i, y, _g->maps->sky_color);
		for (int y = _g->texture->wallbotmpixl; y < HEIGHT; y++)
			my_mlx_pixel_put(_g->mlx_s, i, y, _g->maps->floor_color);
		i++;
	}
}

// static int	grade_color(double it, int hitvertical)
// {
// 	int color;

// 	if (hitvertical)
// 		color = 255 - (it * 0.2);
// 	else
// 		color = 180 - (it * 0.1);
// 	return (_trgb(0, color, color, color));
// }

// void	_fake3d_wall(t_global *_g)
// {
// 	t_rays	*ray;
// 	double	wallheight;
// 	double	raydistance;
// 	double	dis_projectplane;

// 	for (int i = 0; _g->rays[i]; i++)
// 	{
// 		ray = _g->rays[i];
// 		raydistance = ray->distance * cos(ray->angle_veiw - _g->player->rotation_angle);	// that fixed the fishi-blow-view
// 		dis_projectplane = (WIDTH / 2) / tan(FOV_ANGLE / 2);							// Calculate the distance to the projection plane
// 		wallheight = (GRID_SIZE / raydistance) * dis_projectplane;						// project wall height
		
// 		int	wall_top_pixel = (HEIGHT / 2) - (wallheight / 2);
// 		if (wall_top_pixel < 0)
// 			wall_top_pixel = 0;
// 		int	wall_bottom_pixel = (HEIGHT / 2) + (wallheight / 2);
// 		if (wall_bottom_pixel > WIDTH)
// 			wall_bottom_pixel = WIDTH;
		
// 		for (int y = 0; y < wall_top_pixel; y++)
// 			my_mlx_pixel_put(_g->mlx_s, i, y, _g->maps->sky_color);

// 		for (int y = wall_top_pixel; y < wall_bottom_pixel; y++)
// 			my_mlx_pixel_put(_g->mlx_s, i, y, grade_color(raydistance, ray->hit_vertical));
		
// 		for (int y = wall_bottom_pixel; y < HEIGHT; y++)
// 			my_mlx_pixel_put(_g->mlx_s, i, y, _g->maps->floor_color);
// 		// draw_rect(_g->mlx_s, i * WallStripWidth,
// 		// 		wall_top_pixel,
// 		// 		WallStripWidth,
// 		// 		wallheight, grade_color(raydistance, ray->hit_vertical));
// 	}
// }
