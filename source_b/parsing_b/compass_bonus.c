/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:50:07 by enaam             #+#    #+#             */
/*   Updated: 2023/11/26 14:46:28 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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
		printf("Error: (More || last) than argu request in compass\n");
		exit (0);
	}
	compass[j] = NULL;
}

int	ft_compass(t_cub3d *cub, int fd)
{
	char	**compass;

	compass = malloc(sizeof(char *) * 5);
	if (!compass)
		return_msg("Allocation Failed in compass..\n");
	store_loop(compass, fd);
	if (!compass[0])
		return (free_2d_char(compass), exit_msg("No compass found\n"));
	if (loop_compass(compass, cub) == -1)
		return (free_2d_char(compass), exit_msg("erorr compass\n"));
	free_2d_char(compass);
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

int	init_cub(t_cub3d *cub, char *path)
{
	int	fd;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(cub);
		exit_msg("Error: fd -1");
	}
	cub->no = NULL;
	cub->so = NULL;
	cub->ea = NULL;
	cub->we = NULL;
	return (fd);
}

int	parsing_(t_global *_g)
{
	t_cub3d	*cub;
	int		fd;

	cub = malloc(sizeof(t_cub3d));
	if (!cub)
		return (return_msg("Allocation failed CUB..\n"));
	fd = init_cub(cub, _g->path);
	cub->path = _g->path;
	check_all_elements_of_map(fd);
	fd = open(_g->path, O_RDONLY);
	if (ft_compass(cub, fd) == -1)
		return (free_txt(cub), -1);
	close(fd);
	fd = open(_g->path, O_RDONLY);
	if (!ft_color(cub, fd))
		return (free_txt(cub));
	close(fd);
	fd = open(_g->path, O_RDONLY);
	if (ft_map(cub, fd) == -1)
		return (free_txt(cub));
	data_copy(_g, cub);
	free(cub);
	return (1);
}
