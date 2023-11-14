#include "../minimap.h"

static void	catch_xy_inte(t_player *player, t_rays *ray, t_coord *inte)
{

	// find the x-coord of the closet (V) grid-Intersection
	inte->x = floor(player->x / GRID_SIZE) * GRID_SIZE;
	inte->x += ray->facing_right ? GRID_SIZE : 0;
	// find the y-coord of the closet (V) grid-Intersection
	inte->y = player->y + ((inte->x - player->x) * tan(ray->angle_veiw));
}	

// calc the increment xstep and ystep
static void	catch_xy_step(t_rays *ray, t_coord *step)
{
	step->x = GRID_SIZE;
	if (ray->facing_left)
		step->x *= -1;
	step->y = GRID_SIZE * tan(ray->angle_veiw);
	step->y *= ray->facing_up && step->y > 0 ? -1 : 1;
	step->y *= ray->facing_down && step->y < 0 ? -1 : 1;
}

static int	find_thever_wall(t_rays *ray, t_global *_g, t_coord *inte, t_coord *step, t_coord *wallhit)
{
	int		bool_hit_wall;
	t_coord	next_touch;

	next_touch.x = inte->x;
	next_touch.y = inte->y;
	bool_hit_wall = 0;
	// increment xstep/ystep until we find a wall
	while (next_touch.x >= 0 && next_touch.x <= WIDTH && next_touch.y >= 0 && next_touch.y <= HEIGHT)
	{
		if (isin_wall(next_touch.x - ray->facing_left, next_touch.y, _g->maps))
		{
			bool_hit_wall = 1;
			wallhit->x = next_touch.x;
			wallhit->y = next_touch.y;
			break ;
		}
		next_touch.x += step->x;
		next_touch.y += step->y;
	}
	return (bool_hit_wall);
}

static int	vertical_inst(t_global *_g, t_rays *ray, t_coord *wallhit)
{
	t_coord inte;
	t_coord step;
	int		bool_hitwall;

	catch_xy_inte(_g->player, ray, &inte); // calc x - y intersection
	catch_xy_step(ray, &step); // catch (x, y) steps
	bool_hitwall = find_thever_wall(ray, _g, &inte, &step, wallhit);

	return (bool_hitwall);
}

double	vertical_distance(t_global *_g, t_rays *ray, t_coord *wallhit)
{
	int		hit_wall;

	hit_wall = vertical_inst(_g, ray, wallhit);
	if (hit_wall)
		return (disatnce_between2points(_g->player->x, _g->player->y, wallhit->x, wallhit->y));
	return (999999);
}