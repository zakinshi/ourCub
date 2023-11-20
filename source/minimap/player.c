#include "minimap.h"

double	calc_speed(t_global *_g)
{
	double	dlt_height;
	double	dlt_width;
	double	speed_n;
	double	old_speed = 20;

	dlt_height = _g->maps->hieght_map / 9; 
	dlt_width = _g->maps->width_map / 26;
	double scale = dlt_height < dlt_width ? dlt_height : dlt_width;
	speed_n = old_speed * scale;
	return (10);
}

void	direction_view(t_global *_g, t_player *player)
{
	char	**map;
	int		i;
	int		j;

	i = _g->maps->py;
	j = _g->maps->px;
	map = _g->maps->map;
	if (map[i][j] == 'N')
		player->rotation_angle = (-1) * (M_PI / 2);
	else if (map[i][j] == 'W')
		player->rotation_angle = M_PI;
	else if (map[i][j] == 'S')
		player->rotation_angle = M_PI / 2;
	else if (map[i][j] == 'E')
		player->rotation_angle = 2 * M_PI;	
}

void	init_player(t_global *_g)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	if (!player)
		return ;
	//ft_lstadd_back(&g_cub.grbg_colct, ft_grbg_new(player));
	player->x = ((_g->maps->px * GRID_SIZE) + MINIMAP_OFF) + 1;
	player->y = ((_g->maps->py * GRID_SIZE) + MINIMAP_OFF) + 1;
	player->radius	= 3;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->side_walk = 0;
	direction_view(_g, player);
	// player->move_speed = calc_speed(_g);
	player->move_speed = 6;
	player->rotation_speed = 2 * (M_PI / 180);
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

int	isin_wall(double x, double y, t_map *maps)
{
	int	line;
	int	row;

	line = (y - MINIMAP_OFF) /GRID_SIZE;
	row = (x - MINIMAP_OFF) / GRID_SIZE;
	if (line > maps->hieght_map || maps->width_map < row)
		return (1);
	if (maps->map[line] && maps->map[line][row] && maps->map[line][row] == '1')
		return (1);
	return (0);
}

int	multicases(t_player *player, t_map *maps)
{
	if (isin_wall(player->x, player->y, maps))
		return 1;
	else if (isin_wall(player->x + 3, player->y, maps) && isin_wall(player->x, player->y - 3, maps))
		return 1;
	else if (isin_wall(player->x - 3, player->y, maps) && isin_wall(player->x, player->y + 3, maps))
		return 1;
	else if (isin_wall(player->x - 3, player->y, maps) && isin_wall(player->x, player->y - 3, maps))
		return 1;
	else if (isin_wall(player->x + 3, player->y, maps) && isin_wall(player->x, player->y + 3, maps))
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

void	update_player(t_player *player, t_map *maps)
{
	double	copy_x = player->x, copy_y = player->y;
	double	move_step;
	double	stepwalk;

	move_step = player->walk_direction * player->move_speed;
	stepwalk = player->side_walk * player->move_speed;
	forward_walk_ws(player, move_step);
	sides_walk_ad(player, stepwalk);
	player->rotation_angle += player->turn_direction * player->rotation_speed;
	if (multicases(player, maps))
	{
		player->y = copy_y;
		player->x = copy_x;
	}
}

void	_player(t_global *_g, t_minilx *mn_mlx_s)
{
	t_mlx		*mlx_s;
	t_player	*player;

	mlx_s = _g->mlx_s;
	player = _g->player;
	_disk(mn_mlx_s, MINI_WIDTH / 2, MINI_HEIGHT / 2, player->radius + 2);
	_daa_line_mini(mn_mlx_s, MINI_WIDTH / 2, MINI_HEIGHT / 2,\
				(MINI_WIDTH / 2) + cos(player->rotation_angle) * 20,\
				(MINI_HEIGHT / 2) + sin(player->rotation_angle) * 20, change_the_trans('g')); // line to know the deriction of player
}
