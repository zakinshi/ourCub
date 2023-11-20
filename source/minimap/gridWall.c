/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gridWall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:55:14 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/20 18:55:17 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	draw_care(t_minilx *mn_mlx_s, double x, double y, int size_care, int color)
{
	
	double fixy = y;
	double fixx = x;
	while (y <= fixy + size_care)
	{
		double x = fixx;
		while (x <= fixx + size_care)
		{
			minimap_mlx_pixel_put(mn_mlx_s, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_rect(t_minilx *mn_mlx_s, double x, double y, int size_width, int size_height, int color)
{
	
	double fixy = y;
	double fixx = x;
	while (y <= fixy + size_height)
	{
		double x = fixx;
		while (x <= fixx + size_width)
		{
			minimap_mlx_pixel_put(mn_mlx_s, x, y, color);
			x++;
		}
		y++;
	}
}

void _grid(t_minilx *mn_mlx_s, double x, double y, int size_care, int color)
{
	
	double fixy = y;
	double fixx = x;
	while (y <= fixy + size_care)
	{
		while (x <= fixx + size_care)
		{
			minimap_mlx_pixel_put(mn_mlx_s, x, y, color);
			x++;
		}
		y += MINI_GRID;
	}

	x = fixx;
	y = fixy;
	while (x <= fixx + size_care)
	{
		while (y <= fixy + size_care)
		{
			minimap_mlx_pixel_put(mn_mlx_s, x, y, color);
			y++;
		}
		x += MINI_GRID;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int change_the_trans(char color)
{
	int	trans;

	trans = 0;
	if (color == 'b')
		return (create_trgb(150, 0, 0, 255));
	if (color == 'r')
		return (create_trgb(200, 255, 0, 0));
	if (color == 'g')
		return (create_trgb(200, 0, 255, 0));
	if (color == 'B')
		return (create_trgb(200, 0, 0, 0));
	return (create_trgb(254, 0, 0, 0));
}

int	isin_mnwall(t_global *_g, int x_start, int y_start)
{
	int	xs_in_map;
	int	ys_in_map;

	if (x_start < 0 && y_start < 0)
		return (0);
	xs_in_map = x_start / MINI_GRID >= 0 && x_start < _g->maps->width_map * MINI_GRID;
	ys_in_map = y_start / MINI_GRID >= 0 && y_start < _g->maps->hieght_map * MINI_GRID;
	if (xs_in_map && ys_in_map)
		if (_g->maps->map[(int)(y_start / MINI_GRID)][(int)(x_start / MINI_GRID)] == '1')
			return (1);
	return (0);
}

void	draw_mn_pxl(t_global *_g, t_minilx *mn_mlx_s , int i, int j, int x_start, int y_start)
{
		if (isin_mnwall(_g, x_start, y_start))
			minimap_mlx_pixel_put(mn_mlx_s, i / 2, j / 2, change_the_trans('b'));
		else
			minimap_mlx_pixel_put(mn_mlx_s, i / 2, j / 2, change_the_trans('\0'));
}

void	draw_walls(t_global *_g, t_minilx *mn_mlx_s)
{
	int	x_start;
	int	y_start;
	int	i;
	int	j;

	j = -1;
	y_start = _g->player->y - MINI_HEIGHT;
	while (++j < MINI_HEIGHT * 2)
	{
		i = -1;
		x_start = _g->player->x - MINI_WIDTH;
		while (++i < MINI_WIDTH * 2)
		{
			draw_mn_pxl(_g, mn_mlx_s, i, j, x_start, y_start);
			x_start++;
		}
		y_start++;
	}
}