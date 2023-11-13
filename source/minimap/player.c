#include "../minimap.h"

void	init_player(t_global *_g)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->radius	= 3;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->side_walk = 0;
	player->rotation_angle = M_PI;
	player->move_speed = 5.0;
	player->rotation_speed = 4 * (M_PI / 180);
	_g->player = player;
}

int	init_move(void *formation)
{
	t_player *player;

	player = (t_player *)formation;
	player->walk_direction = 0; 
	player->turn_direction = 0;
	player->side_walk = 0;
	return 0;
}

int	isin_wall(double x, double y, char **map)
{
	int	i;
	int	j;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return 1;
	i = floor((y - MINIMAP_OFF) / GRID_SIZE);
	j = floor((x - MINIMAP_OFF) / GRID_SIZE);
	if (i > 5 || 10 < j)	// this condition is just t9oliba
		return 1;			// this codition for ignore the segfault whe you passe the map hieght width
	if (map && map[i] && map[i][j] && map[i][j] == '1')
		return (1);
	return (0);
}

int	multicases(t_player *player, char **map)
{
	if (isin_wall(player->x, player->y, map))
		return 1;
	else if (isin_wall(player->x + 3, player->y, map) && isin_wall(player->x, player->y - 3, map))
		return 1;
	else if (isin_wall(player->x - 3, player->y, map) && isin_wall(player->x, player->y + 3, map))
		return 1;
	else if (isin_wall(player->x - 3, player->y, map) && isin_wall(player->x, player->y - 3, map))
		return 1;
	else if (isin_wall(player->x + 3, player->y, map) && isin_wall(player->x, player->y + 3, map))
		return 1;
	return 0;
}

void	forward_walk_ws(t_player *player, double move_step)
{
	player->x += cos(player->rotation_angle) * move_step;
	player->y += sin(player->rotation_angle) * move_step;
}

void	sides_walk_ad(t_player *player, double stepwalk)
{
	player->x += cos((M_PI / 2) + player->rotation_angle) * stepwalk;
	player->y += sin((M_PI / 2) + player->rotation_angle) * stepwalk;
}

void	update_player(t_player *player, char **map)
{
	double	copy_x = player->x, copy_y = player->y;
	double	move_step;
	double	stepwalk;

	move_step = player->walk_direction * player->move_speed;
	stepwalk = player->side_walk * player->move_speed;
	forward_walk_ws(player, move_step);
	sides_walk_ad(player, stepwalk);
	player->rotation_angle += player->turn_direction * player->rotation_speed;
	if (multicases(player, map))
	{
		player->y = copy_y;
		player->x = copy_x;
	}
}

void	_player(t_global *_g)
{
	t_mlx		*mlx_s;
	t_player	*player;

	mlx_s = _g->mlx_s;
	player = _g->player;
	_disk(mlx_s, MINIMAP_FCTR * player->x, MINIMAP_FCTR * player->y, MINIMAP_FCTR * player->radius);
	draw_rays(_g);
	_daa_line(mlx_s, MINIMAP_FCTR * player->x, MINIMAP_FCTR * player->y,\
				MINIMAP_FCTR * (player->x + cos(player->rotation_angle) * 20),\
				MINIMAP_FCTR * (player->y + sin(player->rotation_angle) * 20), GREEN); // line to know the deriction of player
}
