/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3dwall_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:57:18 by enaam             #+#    #+#             */
/*   Updated: 2023/11/23 18:02:17 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	int_xpm(t_global *_g)
{
	t_text	*xpm;

	xpm = malloc(sizeof(t_text));
	if (!xpm)
		exit_msg("Error: Allocation Xpm Failled..\n");
	xpm->addr_x[0] = NULL;
	xpm->b_p_x = 0;
	xpm->distpropln = 0.00;
	xpm->l_x = 0;
	xpm->per_dist = 0.00;
	xpm->projwallht = 0.00;
	xpm->textureoffsetx = 0;
	xpm->textureoffsety = 0;
	xpm->wallbotmpixl = 0;
	xpm->wallstripht = 0;
	xpm->walltext = 0;
	xpm->walltoppixl = 0;
	xpm->x_hight = 0;
	xpm->x_width = 0;
	xpm->xpm[0] = NULL;
	_g->texture = xpm;
	return (1);
}

void	sky_floor_color(t_global *_g, int i, \
	int wall_top_pixel, int wall_bottom_pixel)
{
	int	y;

	y = -1;
	while (++y < wall_top_pixel)
		my_mlx_pixel_put(_g->mlx_s, i, y, _g->maps->sky_color);
	y = wall_bottom_pixel - 1;
	while (++y < HEIGHT)
		my_mlx_pixel_put(_g->mlx_s, i, y, _g->maps->floor_color);
}

void	_fake3d_wall(t_global *_g)
{
	int	i;

	i = 0;
	if (!int_xpm(_g))
		return ;
	xpm_driver(_g);
	while (_g->rays[i])
	{
		calcule_text(_g, i);
		texture_offset(_g, i);
		i++;
	}
}

void	_addr_x(t_global *_g)
{
	int	i;

	_g->texture->addr_x[0] = mlx_get_data_addr(_g->texture->xpm[0], \
		&(_g->texture->b_p_x), &(_g->texture->l_x), &(_g->mlx_s->dian));
	_g->texture->addr_x[1] = mlx_get_data_addr(_g->texture->xpm[1], \
		&(_g->texture->b_p_x), &(_g->texture->l_x), &(_g->mlx_s->dian));
	_g->texture->addr_x[2] = mlx_get_data_addr(_g->texture->xpm[2], \
		&(_g->texture->b_p_x), &(_g->texture->l_x), &(_g->mlx_s->dian));
	_g->texture->addr_x[3] = mlx_get_data_addr(_g->texture->xpm[3], \
		&(_g->texture->b_p_x), &(_g->texture->l_x), &(_g->mlx_s->dian));
	i = -1;
	while (++i < 4)
		if (_g->texture->addr_x[i] == NULL)
			exit_msg("Error: Error in xpm file\n");
}
