/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdismac <mehdismac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:08:50 by mehdismac         #+#    #+#             */
/*   Updated: 2023/11/18 00:43:52 by mehdismac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minimap.h"

void	loop_cmp(char **compass, char *line, int *j)
{
	int	i;

	i = 0;
	new_l(line);
	while (line[i] == 9 || \
		(line[i] <= 32 && line[i] >= 13))
		i++;
	if (ft_chr("NOSOWEEA", line[i]))
	{
		compass[*j] = ft_dup(line + i);
		*j += 1;
	}
	free(line);
}

void	store_loop(char	**compass, int fd)
{
	char	*line;
	int 	j;

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
		return (0);
	return (1);
}

int parsing_()
{
	t_cub3d	*cub;
	int fd;

	cub = malloc(sizeof(t_cub3d));
	fd = open("test", O_RDONLY);
	if (!ft_map(cub, fd))
		return (0);
	close(fd);
	fd = open("test", O_RDONLY);
	if (!ft_compass(cub, fd))
		return (0);
	close(fd);
	fd = open("test", O_RDONLY);
	if (!ft_color(cub, fd))
		return (0);
	long_line(cub);
	cub->len_l = lenlines(cub->map);
	return (1);
}
