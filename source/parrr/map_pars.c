/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdismac <mehdismac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:20:31 by enaam             #+#    #+#             */
/*   Updated: 2023/11/18 00:44:39 by mehdismac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minimap.h"

char	**store_map(int fd)
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
	fd = open("test", O_RDONLY);
	loop_map(map, len, fd);
	return (map);
}

void	long_line(t_cub3d *cub)
{
	int len;
	int i;

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

void	display(t_cub3d *cub)
{
	int i;
	for (i = 0; cub->map[i] ; i++)
		printf("%s\n", cub->map[i]);
	printf("\n\n\n\nskay = %d\nfloor = %d\n\n\n\n\n", cub->skay, cub->floor);
	// printf("playr_i = %d\nplayr_j = %d\n\n\n\n\n", cub->playr_i, cub->playr_j);
	printf("NO = %s\nSO = %s\nWE = %s\nEA = %s\n", cub->no, cub->so, cub->we, cub->ea);
}

void	check_player_place(t_cub3d *cub)
{
	int	i;
	int	j;

	cub->playr_i = -1;
	cub->playr_j = -1;
	i = -1;
	while (cub->map[++i])
	{
		j = -1;
		while (cub->map[i][++j])
		{
			if (ft_chr("NSWE", cub->map[i][j]))
			{
				cub->playr_i = i;
				cub->playr_j = j;
			}
		}
	}
}

int	ft_map(t_cub3d *cub, int fd)
{
	cub->map = store_map(fd);
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
