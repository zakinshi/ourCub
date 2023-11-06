#include "minimap.h"

static int    _trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

static int    grade_color(double it)
{
	return (_trgb(0, 255, 255 - (it * 0.35), 255 - (it * 0.15)));
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
		raydistance = ray->distance * cos(ray->angleVeiw - _g->player->rotationAngle);	// that fixed the fishi-blow-view

		dis_projectplane = (WIDTH / 2) / tan(FOV_ANGLE / 2);							// Calculate the distance to the projection plane

		wallheight = (GRID_SIZE / raydistance) * dis_projectplane;						// project wall height
	
		draw_rect(_g->mlx_s, i * WallStripWidth,
				(HEIGHT / 2) - (wallheight / 2),
				WallStripWidth,
				wallheight, grade_color(raydistance));
	}
}
