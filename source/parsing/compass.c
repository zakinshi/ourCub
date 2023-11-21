/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:50:07 by enaam             #+#    #+#             */
/*   Updated: 2023/11/21 17:15:41 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	store_loop(char	**compass, int fd)
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

int	ft_compass(t_cub3d *cub, int fd)
{
	char	*compass[4];

	store_loop(compass, fd);
	if (!compass[0])
		return (printf("No compass found\n"), 0);
	if (loop_compass(compass, cub) == -1)
		return (printf("erorr compass\n"), 0);
	return (1);
}

static void	data_copy(t_global *_g, t_cub3d *cub)
{
	long_line(cub);
	cub->len_l = lenlines(cub->map);
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
	fd = open(_g->path, O_RDONLY);
	if (fd == -1)
		exit_msg("Folder Not Found..\n");
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
	data_copy(_g, cub);
	return (1);
}
