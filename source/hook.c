#include "minimap.h"

int	mouse_hook(int key, void *gf)
{
	t_player	*player;

	player = (t_player *)gf;
	printf("%d\n", key);
	puts("before the seg");
	if (key == 1)
		player->active_mouse = 1;
	puts("before the seg");
	printf("%d :am\n", player->active_mouse);
	return (0);
}

int	mouse_move(int x, int y, t_global *_g)
{
	double			angle_new;
	double			delta_y;
	double			delta_x;
	double			deriction;
	static t_coord	copy_cord;

	if ((x <= WIDTH && x >= 0) && (y <= HEIGHT && y >= 0))
	{
		delta_x = _g->player->x - x;
		delta_y = _g->player->y - y;
		deriction = get_direction(x, copy_cord);
		angle_new = ((atan(fabs(delta_x) / fabs(delta_y))) * (M_PI / 180)) * deriction;
		_g->player->rotation_angle += angle_new;
	}
	copy_cord.x = x;
	copy_cord.y = y;
	return 0;
}

int	move_hook(int key, void *formation)
{
	t_player	*player;

	player = (t_player *)formation;
	if (key == 13)
		player->walk_direction = 1;
	else if (key == 1)
		player->walk_direction = -1;
	else if (key == 124)
		player->turn_direction = 1;
	else if (key == 123)
		player->turn_direction = -1;
	else if (key == 2)
		player->side_walk = 1;
	else if (key == 0)
		player->side_walk = -1;
	else if (key == 53)
		exit(0);
	return 0;
}