/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gridWall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:55:14 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/22 21:19:03 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

int	_transp(char color)
{
	int	trans;

	trans = 0;
	if (color == 'b')
		return (_trgb(150, 0, 0, 255));
	if (color == 'r')
		return (_trgb(200, 255, 0, 0));
	if (color == 'g')
		return (_trgb(200, 0, 255, 0));
	if (color == 'B')
		return (_trgb(200, 0, 0, 0));
	return (_trgb(254, 0, 0, 0));
}

int	isin_mnwall(t_global *_g, int x_start, int y_start)
{
	int		xs_in_map;
	int		ys_in_map;
	t_coord	max_rang;

	if (x_start < 0 && y_start < 0)
		return (0);
	max_rang.x = _g->maps->width_map * MINI_GRID;
	max_rang.y = _g->maps->hieght_map * MINI_GRID;
	xs_in_map = x_start / MINI_GRID >= 0 && x_start < max_rang.x;
	ys_in_map = y_start / MINI_GRID >= 0 && y_start < max_rang.y;
	if (xs_in_map && ys_in_map)
		if (_g->maps->map[(y_start / MINI_GRID)][(x_start / MINI_GRID)] == '1')
			return (1);
	return (0);
}

void	draw_mn_pxl(t_global *_g, t_minilx *mnlx_s, t_coord pxl, t_coord start)
{
	if (isin_mnwall(_g, start.x, start.y))
		minimap_mlx_pixel_put(mnlx_s, pxl.x / 2, pxl.y / 2, _transp('b'));
	else
		minimap_mlx_pixel_put(mnlx_s, pxl.x / 2, pxl.y / 2, _transp('\0'));
}

void	draw_walls(t_global *_g, t_minilx *mn_mlx_s)
{
	t_coord	start;
	t_coord	pixel;

	pixel.y = -1;
	start.y = _g->player->y - MINI_HEIGHT;
	while (++pixel.y < MINI_HEIGHT * 2)
	{
		pixel.x = -1;
		start.x = _g->player->x - MINI_WIDTH;
		while (++pixel.x < MINI_WIDTH * 2)
		{
			draw_mn_pxl(_g, mn_mlx_s, pixel, start);
			start.x++;
		}
		start.y++;
	}
}
