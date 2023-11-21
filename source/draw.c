/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:21:01 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/21 13:21:02 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_all(t_global *_g)
{
	_fake3d_wall(_g);
	mlx_put_image_to_window(_g->mlx_s->mlx_ptr, _g->mlx_s->win, \
		_g->mlx_s->img, 0, 0);
	draw_minimap(_g);
}
