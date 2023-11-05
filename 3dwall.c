#include "minimap.h"

void	_fake3d_wall(t_global *_g)
{
	t_rays	*ray;
	double	wallheight;
	double	raydistance;
	double	dis_projectplane;
	// loop every ray in the array of rays
	for (int i = 0; _g->rays[i]; i++)
	{
		ray = _g->rays[i];
		raydistance = ray->distance;

		// Calculate the distance to the projection plane
		dis_projectplane = (WIDTH / 2) / tan(FOV_ANGLE / 2);
		
		// project wall height
		wallheight = (GRID_SIZE / raydistance) * dis_projectplane;
	
		draw_rect(_g->mlx_s, i * WallStripWidth,
				(HEIGHT / 2) - (wallheight / 2),
				WallStripWidth,
				wallheight, WHITE);
	}
}
