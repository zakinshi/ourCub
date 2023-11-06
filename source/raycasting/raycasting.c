#include "../minimap.h"

double	NUM_RAYS		= (double)WIDTH / WallStripWidth;

static void	ray_facing(t_rays *ray)
{
	ray->facing_down = ray->angleVeiw > 0 && ray->angleVeiw < M_PI;
	ray->facing_up = !ray->facing_down;
	ray->facing_right = ray->angleVeiw < 0.5 * M_PI || ray->angleVeiw > 1.5 * M_PI;
	ray->facing_left = !ray->facing_right;
}

static void	cast_ray(t_global *_g, t_rays *ray)
{
	t_coord	wallhit_hor;
	t_coord	wallhit_ver;
	t_coord	wallhit;
	double	dis_hor;
	double	dis_ver;
	double	dis;

	ray_facing(ray);
	dis_hor = horizontal_distance(_g, ray, &wallhit_hor);
	dis_ver = vertical_distance(_g, ray, &wallhit_ver);
	if (dis_hor <= dis_ver) // only same the smallest dis
	{
		struct_copy(&wallhit, wallhit_hor);
		dis = dis_hor;
		ray->hitVertical = 0;
	}
	else
	{
		struct_copy(&wallhit, wallhit_ver);
		dis = dis_ver;
		ray->hitVertical = 1;
	}
	ray->distance = dis;
	ray->wallhitX = wallhit.x;
	ray->wallhitY = wallhit.y;
}

void	RaysCast(t_global *_g)
{
	t_rays	**rays;
	double	rayAngle;
	int		column;
	int		i;
	t_rays *ray;

	i = -1;
	column = i;
	rays = malloc (sizeof(t_rays *) * (NUM_RAYS + 1));
	if (!rays)
		return ;
	rayAngle	= _g->player->rotationAngle - (FOV_ANGLE / 2); // start first ray subtra-half of the fov
	while (++i < NUM_RAYS)
	{
		ray = malloc (sizeof(t_rays));
		if (!ray)
			return ;
		ray->angleVeiw = norm_angle(rayAngle);
		cast_ray(_g, ray);
		rays[++column] = ray;
		rayAngle += FOV_ANGLE / NUM_RAYS;
	}
	rays[column] = NULL;
	_g->rays = rays;
}
