/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:50:07 by enaam             #+#    #+#             */
/*   Updated: 2023/11/20 21:18:38 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	store_loop(char	**compass, int fd)
{
	char	*line;
	int		j;

	j = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		loop_cmp(compass, line, &j);
	}
	if (j != 4)
	{
		printf("More than argu request in compass\n");
		exit (0);
	}
	compass[j] = NULL;
}

char	**store_compass(int fd)
{
	char	**compass;

	compass = malloc(5 * sizeof(char *));
	if (!compass)
		return (NULL);
	//ft_lstadd_back(&g_cub.grbg_colct, ft_grbg_new(compass));
	store_loop(compass, fd);
	return (compass);
}

int	ft_compass(t_cub3d *cub, int fd)
{
	char	**compass;

	compass = store_compass(fd);
	if (!compass || !compass[0])
		return (printf("No compass found\n"), 0);
	if (loop_compass(compass, cub) == -1)
		return (printf("erorr compass\n"), 0);
	return (1);
}

void	data_copy(t_global *_g, t_cub3d *cub)
{
	_g->maps->floor_color = cub->floor;
	_g->maps->hieght_map = cub->len_l;
	_g->maps->map = maping_themap(cub);
	_g->maps->sky_color = cub->skay;
	_g->maps->width_map = cub->long_l;
	_g->maps->px = cub->playr_j;
	_g->maps->py = cub->playr_i;
	_g->maps->north = cub->no;
	_g->maps->south = cub->so;
	_g->maps->west = cub->we;
	_g->maps->east = cub->ea;
}

int	parsing_(t_global *_g)
{
	t_cub3d	*cub;
	int		fd;

	cub = malloc(sizeof(t_cub3d));
	if (!cub)
		return (0);
	//ft_lstadd_back(&g_cub.grbg_colct, ft_grbg_new(cub));
	fd = open(_g->path, O_RDONLY);
	cub->path = _g->path;
	if (!ft_map(cub, fd))
		return (0);
	close(fd);
	fd = open(_g->path, O_RDONLY);
	if (!ft_compass(cub, fd))
		return (0);
	close(fd);
	fd = open(_g->path, O_RDONLY);
	if (!ft_color(cub, fd))
		return (0);
	long_line(cub);
	cub->len_l = lenlines(cub->map);
	data_copy(_g, cub);
	return (1);
}
