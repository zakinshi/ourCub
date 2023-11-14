/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:01:39 by mehdismac         #+#    #+#             */
/*   Updated: 2023/11/14 15:55:45 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minimap.h"

int	diget(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (-1);
}

int	get_color(char *color, t_cub3d *cub)
{
	char	**sp;
	int		len;

	sp = ft_split(color + 1, ',');
	len = lenlines(sp);
	if (len != 3)
		return (printf("More than argu request\n"), -1);
	if (diget(sp[0]) == -1 || diget(sp[1]) == -1 || diget(sp[2]) == -1)
		return (printf("color isn't found\n"), -1);
	cub->red = ft_atoi(sp[0]);
	cub->green = ft_atoi(sp[1]);
	cub->blue = ft_atoi(sp[2]);
	return (1);
}

int	color_shift(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	check_isdiget(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') \
			|| (str[i] >= 13 && str[i] <= 32) || str[i] == ','))
			return (-1);
		i++;
	}
	return (1);
}

int	pars_color(char *color, t_cub3d *cub)
{
	if (check_isdiget(color) == -1)
		return (-1);
	if (get_color(color, cub) == -1)
		return (-1);
	return (1);
}

