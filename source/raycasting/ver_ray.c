/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:38:40 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/22 22:25:12 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// find the x-coord of the closet (V) grid-Intersection
// find the y-coord of the closet (V) grid-Intersection
static void	catch_xy_inte(t_player *player, t_rays *ray, t_coord *inte)
{
	inte->x = floor(player->x / GRID_SIZE) * GRID_SIZE;
	if (ray->facing_right)
		inte->x += GRID_SIZE;
	inte->y = player->y + ((inte->x - player->x) * tan(ray->angle_veiw));
}

// calc the increment xstep and ystep
static void	catch_xy_step(t_rays *ray, t_coord *step)
{
	step->x = GRID_SIZE;
	if (ray->facing_left)
		step->x *= -1;
	step->y = GRID_SIZE * tan(ray->angle_veiw);
	if (ray->facing_up && step->y > 0)
		step->y *= -1;
	if (ray->facing_down && step->y < 0)
		step->y *= -1;
}

// increment xstep/ystep until we find a ver wall
static int	find_thever_wall(t_rays *ray, t_global *_g, \
	t_coord inte_step[], t_coord *wallhit)
{
	int		bool_hitwall;
	t_coord	next_touch;
	t_coord	max_rang;

	bool_hitwall = 0;
	next_touch.x = inte_step[0].x;
	next_touch.y = inte_step[0].y;
	max_rang.x = (double)(_g->maps->width_map * GRID_SIZE);
	max_rang.y = (double)(_g->maps->hieght_map * GRID_SIZE);
	while (next_touch.x >= 0 && next_touch.x <= max_rang.x && \
			next_touch.y >= 0 && next_touch.y <= max_rang.y)
	{
		if (next_touch.x <= max_rang.x && \
			isin_wall(next_touch.x - ray->facing_left, next_touch.y, _g->maps))
		{
			bool_hitwall = 1;
			wallhit->x = next_touch.x;
			wallhit->y = next_touch.y;
			break ;
		}
		next_touch.x += inte_step[1].x;
		next_touch.y += inte_step[1].y;
	}
	return (bool_hitwall);
}

static int	vertical_inst(t_global *_g, t_rays *ray, t_coord *wallhit)
{
	t_coord	inte_step[2];
	int		bool_hitwall;

	catch_xy_inte(_g->player, ray, &inte_step[0]);
	catch_xy_step(ray, &inte_step[1]);
	bool_hitwall = find_thever_wall(ray, _g, inte_step, wallhit);
	return (bool_hitwall);
}

double	vertical_distance(t_global *_g, t_rays *ray, t_coord *wallhit)
{
	int		hit_wall;

	hit_wall = vertical_inst(_g, ray, wallhit);
	if (hit_wall)
		return (disatnce_between2points(_g->player->x, _g->player->y, \
			wallhit->x, wallhit->y));
	return (999999);
}
