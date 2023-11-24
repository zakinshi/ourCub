/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utile2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:50:27 by enaam             #+#    #+#             */
/*   Updated: 2023/11/23 22:01:23 by zakbouha         ###   ########.fr       */
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

static void	map_loop(char *line, char **map, int *i, int len)
{
	int	j;

	j = 0;
	while (line[j] == 9 || \
		(line[j] <= 32 && line[j] >= 13))
		j++;
	if (*i && len > *i && !ft_chr("1", line[j]))
		exit_msg("Error: Maps Has a poster\n");
	if (*i && len <= *i && !ft_chr("1\n", line[j]))
		exit_msg("Error: Maps Has a poster\n");
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
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_loop(line, map, &i, len);
	}
	map[i] = NULL;
}

void	handel_condition(char *map, int i)
{
	int	len;

	len = ft_strlen(map);
	if (len <= i)
		exit_msg("Error: nothing in top of player or 0\n");
}
