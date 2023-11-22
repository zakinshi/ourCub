/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:51:34 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/22 22:12:09 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	ray_facing(t_rays *ray)
{
	ray->facing_down = ray->angle_veiw > 0 && ray->angle_veiw < M_PI;
	ray->facing_up = !ray->facing_down;
	ray->facing_right = ray->angle_veiw < 0.5 * M_PI \
		|| ray->angle_veiw > 1.5 * M_PI;
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
	if (dis_hv.x <= dis_hv.y)
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
	double	_rayangle;
	int		column;
	t_rays	*ray;

	column = -1;
	rays = malloc (sizeof(t_rays *) * (WIDTH + 1));
	if (!rays)
		exit_msg("Alloction of rays Failed..\n");
	_rayangle = _g->player->rotation_angle - (_g->fov_angle / 2);
	while (++column < WIDTH)
	{
		ray = malloc (sizeof(t_rays));
		if (!ray)
			exit_msg("Alloction of ray Failed..\n");
		ray->angle_veiw = norm_angle(_rayangle);
		ray->index = column;
		cast_ray(_g, ray);
		rays[column] = ray;
		_rayangle += _g->fov_angle / WIDTH;
	}
	rays[column] = NULL;
	_g->rays = rays;
}
