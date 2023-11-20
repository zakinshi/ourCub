#include "../cub3d.h"

static void	catch_xy_inte(t_player *player, t_rays *ray, t_coord *inte)
{

	// find the y-coord of the closet (H) grid-Intersection
	inte->y = floor(player->y / GRID_SIZE) * GRID_SIZE;
	inte->y += ray->facing_down ? GRID_SIZE : 0;
	// find the x-coord of the closet (H) grid-Intersection
	inte->x = player->x + ((inte->y - player->y) / tan(ray->angle_veiw));
}	

static void	catch_xy_step(t_rays *ray, t_coord *step)
{
	// calc the increment xstep and ystep
	step->y = GRID_SIZE;
	if (ray->facing_up)
		step->y *= -1;
	step->x = GRID_SIZE / tan(ray->angle_veiw);
	step->x *= ray->facing_left && step->x > 0 ? -1 : 1;
	step->x *= ray->facing_right && step->x < 0 ? -1 : 1;
}

static int	find_thehiro_wall(t_rays *ray, t_global *_g, t_coord *inte, t_coord *step, t_coord *wallhit)
{
	t_coord	next_touch;
	int		bool_hitWall;

	bool_hitWall = 0;
	next_touch.x = inte->x;
	next_touch.y = inte->y;
	// increment xstep/ystep until we find a wall
	while (next_touch.x >= 0 && next_touch.x <= (double)(_g->maps->width_map * GRID_SIZE) &&\
		 next_touch.y >= 0 && next_touch.y <= _g->maps->hieght_map * GRID_SIZE) // *** i
	{
		// printf("next_touch(%.2f ,%.2f)\n", next_touch.x, next_touch.y);
		if (next_touch.x <= (double)(_g->maps->width_map * GRID_SIZE) &&
			isin_wall(next_touch.x, next_touch.y - ray->facing_up, _g->maps))
		{
			bool_hitWall = 1;
			wallhit->x = next_touch.x;
			wallhit->y = next_touch.y;
			// _daa_line(_g->mlx_s, _g->player->x, _g->player->y, wallhit->x, wallhit->y);
			break ;
		}
		next_touch.x += step->x;
		next_touch.y += step->y;
	}
	return (bool_hitWall);
}

static int	horizontal_inst(t_global *_g, t_rays *ray, t_coord *wallhit)
{
	t_coord inte;
	t_coord step;
	int		bool_hitwall;

	catch_xy_inte(_g->player, ray, &inte);	// calc x - y intersection
	catch_xy_step(ray, &step);				// catch (x, y) steps
	bool_hitwall = find_thehiro_wall(ray, _g, &inte, &step, wallhit);
	return (bool_hitwall);
}

double	horizontal_distance(t_global *_g, t_rays *ray, t_coord *wallhit)
{
	int		hit_wall;

	hit_wall = horizontal_inst(_g, ray, wallhit);
	if (hit_wall)
		return (disatnce_between2points(_g->player->x, _g->player->y, wallhit->x, wallhit->y));
	return (999999);
}