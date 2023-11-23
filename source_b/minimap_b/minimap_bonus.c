/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:19:29 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/23 18:02:17 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_bonus.h"

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

void	draw_minimap(t_global *_g)
{
	t_minilx	*mnlx_s;

	mnlx_s = malloc(sizeof(t_minilx));
	if (!mnlx_s)
		exit_msg("Error: Allocation mnlx_s Failed...\n");
	mnlx_s->mlx_ptr = _g->mlx_s->mlx_ptr;
	mnlx_s->win = _g->mlx_s->win;
	minimap_image(mnlx_s);
	draw_walls(_g, mnlx_s);
	_player(_g, mnlx_s);
	mlx_put_image_to_window(mnlx_s->mlx_ptr, mnlx_s->win, mnlx_s->mn_img, 0, 0);
	free(mnlx_s);
}
