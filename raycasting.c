#include "minimap.h"

#define FOV_ANGLE		60 * (M_PI / 180)
#define WallStripWidth	0.50
double	NUM_RAYS		= (double)WIDTH / WallStripWidth;

void	drawRays (t_global *_g)
{
	t_mlx *mlx_s;
	t_player *player;

	mlx_s = _g->mlx_s;
	player = _g->player;
	for (int column = 0; column < 1; column++)
	{
		_DaaLine(mlx_s, player->x, player->y,\
			player->x + cos(_g->rays[column]->angleVeiw) * 100,\
			player->y + sin(_g->rays[column]->angleVeiw) * 100, BLUECIEL);
			column++;
	}
	_g->mlx_s = mlx_s;
	_g->player = player;
}

void	ray_facing(t_rays *ray)
{
	ray->facing_down = ray->angleVeiw > 0 && ray->angleVeiw < M_PI;
	ray->facing_up = !ray->facing_down;

	ray->facing_right = ray->angleVeiw < 0.5 * M_PI || ray->angleVeiw > 1.5 * M_PI;
	ray->facing_left = !ray->facing_right;
}

void	struct_copy(t_coord *copy_in, t_coord copy_to)
{
	copy_in->x = copy_to.x;
	copy_in->y = copy_to.y;
}
void	cast_ray(t_global *_g, t_rays *ray, int i)
{
	t_coord	wallhit_hor;
	t_coord	wallhit_ver;
	t_coord	wallhit;
	int		washitvertical = 0;
	double	dis_hor;
	double	dis_ver;
	double	dis;

	ray_facing(ray);
	dis_hor = horizontal_distance(_g, ray, &wallhit_hor, i);
	dis_ver = vertical_distance(_g, ray, &wallhit_ver, i);
	if (dis_hor <= dis_ver) // only same the smallest dis
	{
		struct_copy(&wallhit, wallhit_hor);
		dis = dis_hor;
	}
	else
	{
		struct_copy(&wallhit, wallhit_ver);
		dis = dis_ver;
		washitvertical = 1;
	}
	_DaaLine(_g->mlx_s, _g->player->x, _g->player->y, wallhit.x, wallhit.y, BLUECIEL);
}

double	norm_angle(double my_angle)
{
	my_angle = fmod(my_angle ,(2.00 * M_PI));
	if (my_angle < 0)
		my_angle += (2 * M_PI);
	return my_angle;
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
		cast_ray(_g, ray, i);
		rays[++column] = ray;
		rayAngle += FOV_ANGLE / NUM_RAYS;
	}
	rays[column] = NULL;
	_g->rays = rays;
}
