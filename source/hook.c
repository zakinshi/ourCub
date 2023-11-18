#include "minimap.h"

static int	get_direction(int x, t_coord last_coord)
{
	if (x > last_coord.x)
		return (1);
	if (x < last_coord.x)
		return (-1);
	return (0);
}

static int	ft_close(void)
{
	exit(0);
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

int	move_hook(int key, t_global *_g)
{
	t_player	*player;

	player = _g->player;
	if (key == 13)
		player->walk_direction = 1;
	if (key == 1)
		player->walk_direction = -1;
	if (key == 124)
		player->turn_direction = 1;
	if (key == 123)
		player->turn_direction = -1;
	if (key == 2)
		player->side_walk = 1;
	if (key == 0)
		player->side_walk = -1;
	if (key == 53)
		exit(0);
	return 0;
}

int	init_move_hook(int key, t_global *_g)
{
	t_player	*player;

	player = _g->player;
	if (key == 13)
		player->walk_direction = 0;
	if (key == 1)
		player->walk_direction = 0;
	if (key == 124)
		player->turn_direction = 0;
	if (key == 123)
		player->turn_direction = 0;
	if (key == 2)
		player->side_walk = 0;
	if (key == 0)
		player->side_walk = 0;
	return (0);
}

void	all_my_hooks(t_global *_g)
{
	mlx_hook(_g->mlx_s->win, 2, 0, move_hook, _g);
	mlx_hook(_g->mlx_s->win, 3, 0, init_move_hook, _g);
	mlx_hook(_g->mlx_s->win, 6, 0, mouse_move, _g);
	mlx_hook(_g->mlx_s->win, 17, 0, ft_close, NULL);
}
