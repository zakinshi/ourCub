/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:40:45 by enaam             #+#    #+#             */
/*   Updated: 2023/11/21 17:47:57 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	xpm_driver(t_global *_g)
{
	_g->texture->xpm[0] = mlx_xpm_file_to_image(_g->mlx_s->mlx_ptr, \
		_g->maps->north, &_g->texture->x_width, &_g->texture->x_hight);
	_g->texture->xpm[1] = mlx_xpm_file_to_image(_g->mlx_s->mlx_ptr, \
		_g->maps->south, &_g->texture->x_width, &_g->texture->x_hight);
	_g->texture->xpm[2] = mlx_xpm_file_to_image(_g->mlx_s->mlx_ptr, \
		_g->maps->east, &_g->texture->x_width, &_g->texture->x_hight);
	_g->texture->xpm[3] = mlx_xpm_file_to_image(_g->mlx_s->mlx_ptr, \
		_g->maps->west, &_g->texture->x_width, &_g->texture->x_hight);
	_g->texture->addr_x[0] = mlx_get_data_addr(_g->texture->xpm[0], \
		&(_g->texture->b_p_x), &(_g->texture->l_x), &(_g->mlx_s->dian));
	_g->texture->addr_x[1] = mlx_get_data_addr(_g->texture->xpm[1], \
		&(_g->texture->b_p_x), &(_g->texture->l_x), &(_g->mlx_s->dian));
	_g->texture->addr_x[2] = mlx_get_data_addr(_g->texture->xpm[2], \
		&(_g->texture->b_p_x), &(_g->texture->l_x), &(_g->mlx_s->dian));
	_g->texture->addr_x[3] = mlx_get_data_addr(_g->texture->xpm[3], \
		&(_g->texture->b_p_x), &(_g->texture->l_x), &(_g->mlx_s->dian));
}

unsigned int	get_pixel(t_global *_g, int x, int y, int i)
{
	char			*dst;
	unsigned int	color;

	color = 0;
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
		dst = _g->texture->addr_x[i] + (y * _g->texture->l_x + \
			x * (_g->texture->b_p_x / 8));
		color = *(unsigned int *)dst;
	}
	return (color);
}

unsigned int	text_comp(t_global *_g, int i)
{
	unsigned int	color;
	double			rotation_angle;

	rotation_angle = _g->rays[i]->angle_veiw;
	color = 0;
	if (!_g->rays[i]->hit_vertical && (rotation_angle <= 6.28 \
		&& rotation_angle >= 3.14))
		color = get_pixel(_g, _g->texture->textureoffsetx, \
			_g->texture->textureoffsety, 0);
	else if (!_g->rays[i]->hit_vertical && (rotation_angle >= 0 \
		&& rotation_angle <= 3.14))
		color = get_pixel(_g, _g->texture->textureoffsetx, \
			_g->texture->textureoffsety, 1);
	else if (_g->rays[i]->hit_vertical && ((rotation_angle >= 0 \
		&& rotation_angle <= 1.60) \
		|| (rotation_angle >= 4.69 && rotation_angle <= 7)))
		color = get_pixel(_g, _g->texture->textureoffsetx, \
			_g->texture->textureoffsety, 2);
	else if (_g->rays[i]->hit_vertical && (rotation_angle >= 1.57 \
		&& rotation_angle <= 4.71))
		color = get_pixel(_g, _g->texture->textureoffsetx, \
			_g->texture->textureoffsety, 3);
	return (color);
}

void	texture_offset(t_global *_g, int i)
{
	unsigned int	textcolor;
	int				j;
	int				disftop;

	j = _g->texture->walltoppixl;
	if (_g->rays[i]->hit_vertical)
		_g->texture->textureoffsetx = fmod(_g->rays[i]->wallhity * \
		(_g->texture->x_hight / GRID_SIZE), GRID_SIZE);
	else
		_g->texture->textureoffsetx = fmod(_g->rays[i]->wallhitx * \
		(_g->texture->x_width / GRID_SIZE), GRID_SIZE);
	while (j < _g->texture->wallbotmpixl)
	{
		disftop = j + (_g->texture->wallstripht / 2) - (HEIGHT / 2);
		_g->texture->textureoffsety = (disftop * \
			(float)GRID_SIZE) / _g->texture->wallstripht;
		textcolor = text_comp(_g, i);
		my_mlx_pixel_put(_g->mlx_s, i, j, textcolor);
		j++;
	}
}

void	calcule_text(t_global *_g, int i)
{
	_g->texture->per_dist = _g->rays[i]->distance * \
		cos(_g->rays[i]->angle_veiw - _g->player->rotation_angle);
	_g->texture->distpropln = (WIDTH / 2) / tan(_g->fov_angle / 2);
	_g->texture->projwallht = (GRID_SIZE / _g->texture->per_dist) * \
		_g->texture->distpropln;
	_g->texture->wallstripht = _g->texture->projwallht;
	_g->texture->walltoppixl = (HEIGHT / 2) - (_g->texture->wallstripht / 2);
	if (_g->texture->walltoppixl < 0)
		_g->texture->walltoppixl = 0;
	_g->texture->wallbotmpixl = (HEIGHT / 2) + (_g->texture->wallstripht / 2);
	if (_g->texture->wallbotmpixl > HEIGHT)
		_g->texture->wallbotmpixl = HEIGHT;
	sky_floor_color(_g, i, _g->texture->walltoppixl, _g->texture->wallbotmpixl);
}
