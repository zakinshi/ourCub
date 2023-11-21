/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utile2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:50:27 by enaam             #+#    #+#             */
/*   Updated: 2023/11/21 12:35:59 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_condition(char **map)
{
	if (!check_firstlast_line(map))
		return (0);
	spc_to_tow(map);
	if (!edge_map(map))
		return (0);
	return (1);
}

static void	map_loop(char *line, char **map, int *i)
{
	int	j;

	j = 0;
	while (line[j] == 9 || \
		(line[j] <= 32 && line[j] >= 13))
		j++;
	if (*i && line[j] == '\n')
		exit_msg("empty line in map\n");
	if (ft_chr("01", line[j]))
	{
		new_l(line);
		map[*i] = ft_dup(line);
		*i += 1;
	}
	free(line);
}

void	loop_map(char **map, int len, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (len > i)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_loop(line, map, &i);
	}
	map[i] = NULL;
}
