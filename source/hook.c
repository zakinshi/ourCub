/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:17:01 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/21 16:20:28 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_close(void)
{
	exit(0);
}

int	mouse_move(int x, int y, t_global *_g)
{
	t_coord			delta;
	double			angle_new;
	double			deriction;
	static t_coord	copy_cord;

	if ((x <= WIDTH && x >= 0) && (y <= HEIGHT && y >= 0))
	{
		delta.x = _g->player->x - x;
		delta.y = _g->player->y - y;
		deriction = get_direction(x, copy_cord);
		angle_new = ((atan(fabs(delta.x) / fabs(delta.y))) \
			* (M_PI / 180)) * deriction;
		_g->player->rotation_angle += angle_new;
	}
	copy_cord.x = x;
	copy_cord.y = y;
	return (0);
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
		ft_close();
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
	mlx_hook(_g->mlx_s->win, 6, 0, mouse_move, _g);
	mlx_hook(_g->mlx_s->win, 17, 0, ft_close, NULL);
}
