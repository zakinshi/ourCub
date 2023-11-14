/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:08:50 by mehdismac         #+#    #+#             */
/*   Updated: 2023/11/14 19:49:19 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minimap.h"

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

int	loop_spc(char *compass)
{
	int	i;

	i = 0;
	while (compass[i] <= 32)
		i++;
	return (i);
}

int	condition_compass(char *compass, t_cub3d *cub)
{
	char	*sp;
	int		i;
	int		flag = 0;

	if (!ft_cmp("NO ", compass, 3))
	{
		sp = ft_dup(compass + 2);
		i = loop_spc(compass + 2);
		cub->no = sp + i;
		flag = 1;
	}
	else if (!ft_cmp("SO ", compass, 3))
	{
		sp = ft_dup(compass + 2);
		i = loop_spc(compass + 2);
		cub->so = sp + i;
		flag = 1;
	}
	else if (!ft_cmp("WE ", compass, 3))
	{
		sp = ft_dup(compass + 2);
		i = loop_spc(compass + 2);
		cub->we = sp + i;
		flag = 1;
	}
	else if (!ft_cmp("EA ", compass, 3))
	{
		sp = ft_dup(compass + 2);
		i = loop_spc(compass + 2);
		cub->ea = sp + i;
		flag = 1;
	}
	if (!flag)
		return (printf("erorr compass\n"), -1);
	return (1);
}

int	 loop_compass(char **color, t_cub3d *cub)
{
	int i = 0;

	while (color[i])
	{
		if (condition_compass(color[i], cub) == -1)
			return (-1);
		i++;
	}
	return (1);
}

void	store_loop(char	**compass, int fd)
{
	char	*line;
	int 	i;
	int 	j;

	j = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new_l(line);
		i = 0;
		while (line[i] <= ' ' && line[i] >= 13)
			i++;
		if (ft_chr("NOSOWEEA", line[i]))
		{
			compass[j] = ft_dup(line + i);
			j++;
		}
		free(line);
	}
	compass[j] = NULL;
}

char	**store_compass(int fd)
{
	char	**compass;
	int		len;

	compass = malloc(5 * sizeof(char *));
	if (!compass)
		return (NULL);
	store_loop(compass, fd);
	len = lenlines(compass);
	if (len > 4)
		return (printf("More than argu request\n"), NULL);
	return (compass);
}

int	ft_compass(t_cub3d *cub, int fd)
{
	char	**compass;

	compass = store_compass(fd);
	if (!compass || !compass[0])
		return (printf("No compass found\n"), 0);
	if (loop_compass(compass, cub) == -1)
		return (0);
	return (1);
}

void	data_copy(t_global *_g, t_cub3d *cub)
{
	_g->maps->floor_color = cub->floor;
	_g->maps->hieght_map = cub->len_l;
	_g->maps->map = cub->map;
	_g->maps->sky_color = cub->skay;
	_g->maps->width_map = cub->long_l;
	_g->maps->px = cub->playr_j;
	_g->maps->py = cub->playr_i;
	
}

int parsing_(t_global *_g)
{
	t_cub3d	*cub;
	int fd;

	cub = malloc(sizeof(t_cub3d));
	fd = open("source/parrr/test", O_RDONLY);
	if (!ft_map(cub, fd))
		return (0);
	close(fd);
	fd = open("source/parrr/test", O_RDONLY);
	if (!ft_compass(cub, fd))
		return (0);
	close(fd);
	fd = open("source/parrr/test", O_RDONLY);
	if (!ft_color(cub, fd))
		return (0);
	long_line(cub);
	cub->len_l = lenlines(cub->map);
	data_copy(_g, cub);
	return (1);
}
