/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:49:35 by enaam             #+#    #+#             */
/*   Updated: 2023/11/22 21:15:57 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_vergule(char *color)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (color[++i])
		if (color[i] == ',')
			j++;
	if (j != 2)
		return (0);
	return (1);
}

int	get_color(char *color, t_cub3d *cub)
{
	char	**sp;
	int		len;

	if (!count_vergule(color))
		return (printf("','"), -1);
	sp = ft_split(color + 1, ',');
	len = lenlines(sp);
	if (len != 3)
		return (printf("More than argu request"), -1);
	if (diget(sp[0]) == -1 || diget(sp[1]) == -1 || diget(sp[2]) == -1)
		return (printf("color isn't found"), -1);
	cub->red = ft_atoi(sp[0]);
	cub->green = ft_atoi(sp[1]);
	cub->blue = ft_atoi(sp[2]);
	free_2d_char(sp);
	return (1);
}

int	check_isdiget(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') \
			|| (str[i] >= 13 && str[i] <= 32) || str[i] == ',' || str[i] == 9))
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

int	waith_spc(char **color, int i)
{
	int	len;

	len = -1;
	while (color[i][++len] > 32)
		;
	if (len != 1)
		return (-1);
	return (1);
}
