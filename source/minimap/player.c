/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:53:23 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/21 12:57:21 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

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
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return ;
	player->x = ((_g->maps->px * GRID_SIZE) + MINIMAP_OFF) + 1;
	player->y = ((_g->maps->py * GRID_SIZE) + MINIMAP_OFF) + 1;
	player->radius = 3;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->side_walk = 0;
	direction_view(_g, player);
	player->move_speed = 6;
	player->rotation_speed = 2 * (M_PI / 180);
	_g->player = player;
}

int	isin_wall(double x, double y, t_map *maps)
{
	int	line;
	int	row;

	line = (y - MINIMAP_OFF) / GRID_SIZE;
	row = (x - MINIMAP_OFF) / GRID_SIZE;
	if (line > maps->hieght_map || maps->width_map < row)
		return (1);
	if (maps->map[line] && maps->map[line][row] && maps->map[line][row] == '1')
		return (1);
	return (0);
}

int	multicases(t_player *player, t_map *maps)
{
	if (isin_wall(player->x + 5, player->y, maps))
		return (1);
	if (isin_wall(player->x, player->y + 5, maps))
		return (1);
	else if (isin_wall(player->x + 5, player->y, maps) \
		|| isin_wall(player->x, player->y - 5, maps))
		return (1);
	else if (isin_wall(player->x - 5, player->y, maps) \
		|| isin_wall(player->x, player->y + 5, maps))
		return (1);
	else if (isin_wall(player->x - 5, player->y, maps) \
		|| isin_wall(player->x, player->y - 5, maps))
		return (1);
	else if (isin_wall(player->x + 5, player->y, maps) \
		|| isin_wall(player->x, player->y + 5, maps))
		return (1);
	return (0);
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
	t_coord	copy;
	double	move_step;
	double	stepwalk;

	copy.x = player->x;
	copy.y = player->y;
	move_step = player->walk_direction * player->move_speed;
	stepwalk = player->side_walk * player->move_speed;
	forward_walk_ws(player, move_step);
	sides_walk_ad(player, stepwalk);
	player->rotation_angle += player->turn_direction * player->rotation_speed;
	if (multicases(player, maps))
	{
		player->y = copy.y;
		player->x = copy.x;
	}
}

void	_player(t_global *_g, t_minilx *mn_mlx_s)
{
	t_mlx		*mlx_s;
	t_player	*player;
	t_coord		player_pos0;
	t_coord		player_pos1;

	mlx_s = _g->mlx_s;
	player = _g->player;
	player_pos0.x = MINI_WIDTH / 2;
	player_pos0.y = MINI_HEIGHT / 2;
	_disk(mn_mlx_s, player_pos0.x, player_pos0.y, player->radius + 2);
	player_pos1.x = player_pos0.x + cos(player->rotation_angle) * 20;
	player_pos1.y = player_pos0.y + sin(player->rotation_angle) * 20;
	_daa_line_mini(mn_mlx_s, player_pos0, player_pos1, _transp('g'));
}
