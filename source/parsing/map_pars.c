/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:20:31 by enaam             #+#    #+#             */
/*   Updated: 2023/11/21 12:20:32 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**store_map(int fd, t_cub3d *cub)
{
	char	**map;
	int		len;

	len = len_line(fd);
	if (!len)
		return (NULL);
	map = malloc((len + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	close(fd);
	fd = open(cub->path, O_RDONLY);
	loop_map(map, len, fd);
	return (map);
}

void	long_line(t_cub3d *cub)
{
	int	len;
	int	i;

	i = 0;
	cub->long_l = ft_strlen(cub->map[i]);
	while (cub->map[i])
	{
		len = ft_strlen(cub->map[i]);
		if (len > cub->long_l)
			cub->long_l = len;
		i++;
	}
}

static void	check_player_place(t_cub3d *cub)
{
	int	i;
	int	j;
	int	flag;

	cub->playr_i = -1;
	cub->playr_j = -1;
	i = -1;
	flag = 0;
	while (cub->map[++i])
	{
		j = -1;
		while (cub->map[i][++j])
		{
			if (ft_chr("NSWE", cub->map[i][j]))
			{
				cub->playr_i = i;
				cub->playr_j = j;
				flag++;
			}
		}
	}
	if (flag != 1)
		exit_msg("erorr in playr\n");
}

int	ft_map(t_cub3d *cub, int fd)
{
	cub->map = store_map(fd, cub);
	if (!cub->map || !cub->map[0] || !cub->map[1])
		return (printf("No map found\n"), 0);
	if (!check_condition(cub->map))
		return (0);
	if (!matrise(cub))
		return (0);
	check_player_place(cub);
	long_line(cub);
	return (1);
}
