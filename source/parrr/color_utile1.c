/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utile1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:49:45 by enaam             #+#    #+#             */
/*   Updated: 2023/11/19 11:02:40 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minimap.h"

int	to_return(char *color, t_cub3d *cub)
{
	int	clr;

	if (pars_color(color, cub) == -1)
		return (-1);
	if (cub->red > 255 || cub->green > 255 || cub->blue > 255)
		return (-1);
	if (cub->red < 0 || cub->green < 0 || cub->blue < 0)
		return (-1);
	else
		clr = color_shift(0, cub->red, cub->green, cub->blue);
	return (clr);
}

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

int	ft_cmp(char *ft, char *sd, size_t n)
{
	size_t	i;

	i = 0;
	while ((sd[i] || ft[i]) && (i < n))
	{
		if (ft[i] != sd[i])
			return (ft[i] - sd[i]);
		i++;
	}
	return (0);
}

void	loop_cmp(char **compass, char *line, int *j)
{
	int	i;

	i = 0;
	new_l(line);
	while (line[i] == 9 || (line[i] <= 32 && line[i] >= 13))
		i++;
	if (ft_chr("NOSOWEEA", line[i]))
	{
		compass[*j] = ft_dup(line + i);
		*j += 1;
	}
	free(line);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
