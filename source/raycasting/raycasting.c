#include "../cub3d.h"

// double	NUM_RAYS		= (double)WIDTH / WallStripWidth;

static void	ray_facing(t_rays *ray)
{
	ray->facing_down = ray->angle_veiw > 0 && ray->angle_veiw < M_PI;
	ray->facing_up = !ray->facing_down;
	ray->facing_right = ray->angle_veiw < 0.5 * M_PI || ray->angle_veiw > 1.5 * M_PI;
	ray->facing_left = !ray->facing_right;
}

static void	cast_ray(t_global *_g, t_rays *ray)
{
	t_coord	wallhit_hor;
	t_coord	wallhit_ver;
	t_coord	wallhit;
	t_coord	dis_hv;
	double	dis;

	ray_facing(ray);
	dis_hv.x = horizontal_distance(_g, ray, &wallhit_hor);
	dis_hv.y = vertical_distance(_g, ray, &wallhit_ver);
	if (dis_hv.x <= dis_hv.y) // only same the smallest dis
	{
		struct_copy(&wallhit, wallhit_hor);
		dis = dis_hv.x;
		ray->hit_vertical = 0;
	}
	else
	{
		struct_copy(&wallhit, wallhit_ver);
		dis = dis_hv.y;
		ray->hit_vertical = 1;
	}
	ray->distance = dis;
	ray->wallhitx = wallhit.x;
	ray->wallhity = wallhit.y;
}

void	rays_cast(t_global *_g)
{
	t_rays	**rays;
	double	rayAngle;
	int		column;
	t_rays *ray;

	column = -1;
	rays = malloc (sizeof(t_rays *) * (WIDTH + 1));
	if (!rays)
		exit_msg("Alloction of rays Failed..\n");
	//ft_lstadd_back(&g_cub.grbg_colct, ft_grbg_new(rays));
	rayAngle = _g->player->rotation_angle - (FOV_ANGLE / 2);
	while (++column < WIDTH)
	{
		ray = malloc (sizeof(t_rays));
		//ft_lstadd_back(&g_cub.grbg_colct, ft_grbg_new(ray));
		if (!ray)
			exit_msg("Alloction of ray Failed..\n");
		ray->angle_veiw = norm_angle(rayAngle);
		ray->index = column;
		cast_ray(_g, ray);
		rays[column] = ray;
		rayAngle += FOV_ANGLE / WIDTH;
	}
	rays[column] = NULL;
	_g->rays = rays;
}
