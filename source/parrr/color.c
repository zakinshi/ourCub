/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:34:50 by enaam             #+#    #+#             */
/*   Updated: 2023/11/20 22:56:55 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	color_cond(char **color, t_cub3d *cub, int i, int *flag)
{
	if (!ft_cmp("F", color[i], 1))
	{
		cub->floor = to_return(color[i], cub);
		if (cub->floor == -1)
			return (-1);
		*flag = 1;
	}
	else if (!ft_cmp("C", color[i], 1))
	{
		cub->skay = to_return(color[i], cub);
		if (cub->skay == -1)
			return (-1);
		*flag = 1;
	}
	return (1);
}

int     loop_color(char **color, t_cub3d *cub) 
{
    int i = 0;
    int flag = 0;

    while (color[i])
    {
		if (waith_spc(color, i) == -1)
			return (-1);
        if (!color_cond(color, cub, i, &flag))
			return (-1);
        if (!flag)
            return (-1);
        i++;
        flag = 0;
    }
    return (1);
}

void	loop_cf(char **color, char *line, int *j)
{
	int		i;

	i = 0;
	new_l(line);
	while ((line[i] <= 32 && line[i] >= 13) \
		|| line[i] == 9)
		i++;
	if (ft_chr("CF", line[i]))
	{
		color[*j] = ft_dup(line + i);
		*j += 1;
	}
	free(line);
}

void	store_loop_cf(char **color, int fd)
{
	int		j;
	char	*line;

	j = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		loop_cf(color, line, &j);
	}
	if (j != 2)
	{
		printf("More than argu request in color\n");
		exit (0);
	}
	color[j] = NULL;
}

char	**store_cf(int fd)
{
	char	**color;

	color = malloc(3 * sizeof(char *));
	if (!color)
		return (NULL);
	//ft_lstadd_back(&g_cub.grbg_colct, ft_grbg_new(color));
	store_loop_cf(color, fd);
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
