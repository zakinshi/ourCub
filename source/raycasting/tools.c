/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:53:29 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/21 16:26:01 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	_g->fov_angle = 60 * (M_PI / 180);
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

void	struct_copy(t_coord *copy_in, t_coord copy_to)
{
	copy_in->x = copy_to.x;
	copy_in->y = copy_to.y;
}

double	norm_angle(double my_angle)
{
	my_angle = fmod(my_angle, (2.00 * M_PI));
	if (my_angle < 0)
		my_angle += (2 * M_PI);
	return (my_angle);
}
