/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:53:23 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/27 15:20:38 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_bonus.h"

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
