/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:57:50 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/21 12:57:51 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static void	put_circle_pixles(t_minilx *mlx_s, int x, int y, int i, int j)
{
	int color;

	color = _transp('g');
	minimap_mlx_pixel_put(mlx_s, x + i, y + j, color);
	minimap_mlx_pixel_put(mlx_s, x - i, y + j, color);
	minimap_mlx_pixel_put(mlx_s, x + i, y - j, color);
	minimap_mlx_pixel_put(mlx_s, x - i, y - j, color);
	minimap_mlx_pixel_put(mlx_s, x + j, y + i, color);
	minimap_mlx_pixel_put(mlx_s, x - j, y + i, color);
	minimap_mlx_pixel_put(mlx_s, x + j, y - i, color);
	minimap_mlx_pixel_put(mlx_s, x - j, y - i, color);
}

void	draw_circle(t_minilx *mlx_s, int x, int y, int r)
{
	int i;
	int j;
	int d;

	i = r;
	j = 0;
	d = 1 - r;
	while (i > j) {
		put_circle_pixles(mlx_s, x, y , i, j);
		if (d < 0)
			d += 2 * j + 3;
		else
		{
			i--;
			d += 2 * (j - i) + 5;
		}
		j++;
	}
}

void	_disk(t_minilx *mlx_s, int cx, int cy, int r)
{
	int	y;
	int	x;

	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y <= r * r)
				minimap_mlx_pixel_put(mlx_s, cx + x, cy + y, 0x912a00);
			x++;
		}
		y++;
	}
}

void _daa_line_mini(t_minilx *mlx_s, t_coord pos0, t_coord pos1, long color)
{
	t_coord	inc;
	t_coord	delta;
	t_coord	pixl;
	double	steps;
	int		i;

	delta.x = pos1.x - pos0.x;
	delta.y = pos1.y - pos0.y;
	if (abs_(delta.x) > abs_(delta.y))
		steps = abs_(delta.x);
	else
		steps = abs_(delta.y);
	inc.x = delta.x / steps;
	inc.y = delta.y / steps;
	pixl.x = pos0.x;
	pixl.y = pos0.y;
	i = -1;
	while (++i <= steps) 
	{
		minimap_mlx_pixel_put(mlx_s, pixl.x, pixl.y, color);
		pixl.x += inc.x;
		pixl.y += inc.y;
	}
}
