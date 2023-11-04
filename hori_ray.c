#include "minimap.h"

static void	catch_xy_inte(t_player *player, t_rays *ray, t_coord *inte)
{

	// find the y-coord of the closet (H) grid-Intersection
	inte->y = floor(player->y / GRID_SIZE) * GRID_SIZE;
	inte->y += ray->facing_down ? GRID_SIZE : 0;
	// find the x-coord of the closet (H) grid-Intersection
	inte->x = player->x + ((inte->y - player->y) / tan(ray->angleVeiw));
}	

static void	catch_xy_step(t_player *player, t_rays *ray, t_coord *step)
{
	// calc the increment xstep and ystep
	step->y = GRID_SIZE;
	if (ray->facing_up)
		step->y *= -1;
	step->x = GRID_SIZE / tan(ray->angleVeiw);
	step->x *= ray->facing_left && step->x > 0 ? -1 : 1;
	step->x *= ray->facing_right && step->x < 0 ? -1 : 1;
}

static int	find_thehiro_wall(t_rays *ray, t_global *_g, t_coord *inte, t_coord *step, t_coord *wallhit)
{
	int		bool_hitWall;
	double	next_x_touch = inte->x;
	double	next_y_touch = inte->y;

	bool_hitWall = 0;
	if (ray->facing_up)
		next_y_touch--;
	// increment xstep/ystep until we find a wall
	while (next_x_touch >= 0 && next_x_touch <= WIDTH && next_y_touch >= 0 && next_y_touch < HEIGHT)
	{
		if (isin_wall(next_x_touch, next_y_touch, _g->map))
		{
			bool_hitWall = 1;
			wallhit->x = next_x_touch;
			wallhit->y = next_y_touch;
			// _DaaLine(_g->mlx_s, _g->player->x, _g->player->y, wallhit->x, wallhit->y);
			break ;
		}
		next_x_touch += step->x;
		next_y_touch += step->y;
	}
	return bool_hitWall;
}

static int	horizontal_inst(t_global *_g, t_rays *ray, t_coord *wallhit)
{
	t_coord inte;
	t_coord step;
	int		bool_hitwall;

	catch_xy_inte(_g->player, ray, &inte); // calc x - y intersection
	catch_xy_step(_g->player, ray, &step); // catch (x, y) steps
	bool_hitwall = find_thehiro_wall(ray, _g, &inte, &step, wallhit);

	return bool_hitwall;
}

double	horizontal_distance(t_global *_g, t_rays *ray, t_coord *wallhit, int i)
{
	int		hit_wall;

	hit_wall = horizontal_inst(_g, ray, wallhit);
	if (hit_wall)
		return (disatnce_between2points(_g->player->x, _g->player->y, wallhit->x, wallhit->y));
	return (-1);
}