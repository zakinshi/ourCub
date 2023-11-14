/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:34:50 by enaam             #+#    #+#             */
/*   Updated: 2023/11/13 16:31:58 by enaam            ###   ########.fr       */
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

int	 loop_color(char **color, t_cub3d *cub)
{
	int i = 0;
	int flag = 0;

	while (color[i])
	{
		if (!ft_cmp("F ", color[i], 2))
		{
			cub->floor = to_return(color[i], cub);
			if (cub->floor == -1)
				return (-1);
			flag = 1;
		}
		else if (!ft_cmp("C ", color[i], 2))
		{
			cub->skay = to_return(color[i], cub);
			if (cub->skay == -1)
				return (-1);
			flag = 1;
		}
		if (!flag)
			return (-1);
		i++;
		flag = 0;
	}
	return (1);
}

void	store_loop_cf(char **color, int fd)
{
	int 	i;
	int 	j;
	char	*line;

	j = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new_l(line);
		i = 0;
		while (line[i] <= 32 && line[i] >= 13)
			i++;
		if (ft_chr("CF", line[i]))
		{
			color[j] = ft_dup(line + i);
			j++;
		}
		free(line);
	}
	color[j] = NULL;
}

char	**store_cf(int fd)
{
	char	**color;
	int		len;

	color = malloc(3 * sizeof(char *));
	if (!color)
		return (NULL);
	store_loop_cf(color, fd);
	len = lenlines(color);
	if (len > 2)
		return (printf("More than argu request\n"), NULL);
	return (color);
}

int	ft_color(t_cub3d *cub, int fd)
{
	char	**color;

	color = store_cf(fd);
	if (!color || !color[0])
		return (printf("No color found\n"), 0);
	if (loop_color(color, cub) == -1)
		return (printf("error in color\n"), 0);
	return (1);
}
