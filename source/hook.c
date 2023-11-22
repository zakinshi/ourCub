/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:17:01 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/22 21:33:49 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_close(t_global *_g)
{
	all_free(_g);
	exit(0);
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
		ft_close(_g);
	if (key == 78)
		if (player->move_speed - 2 > 0)
			player->move_speed--;
	if (key == 69)
		if (player->move_speed < 15)
			player->move_speed++;
	return (0);
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
	mlx_hook(_g->mlx_s->win, 17, 0, ft_close, _g);
}
