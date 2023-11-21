/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:19:29 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/21 12:20:05 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	draw_minimap(t_global *_g)
{
	t_minilx	*mnlx_s;

	mnlx_s = malloc(sizeof(t_minilx));
	mnlx_s->mlx_ptr = _g->mlx_s->mlx_ptr;
	mnlx_s->win = _g->mlx_s->win;
	minimap_image(mnlx_s);
	draw_walls(_g, mnlx_s);
	_player(_g, mnlx_s);
	mlx_put_image_to_window(mnlx_s->mlx_ptr, mnlx_s->win, mnlx_s->mn_img, 0, 0);
}
