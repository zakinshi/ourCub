/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:20:31 by enaam             #+#    #+#             */
/*   Updated: 2023/11/23 18:02:17 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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
		exit_msg("Error: erorr in playr\n");
}

int	ft_map(t_cub3d *cub, int fd)
{
	cub->map = store_map(fd, cub);
	if (!cub->map || !cub->map[0] || !cub->map[1])
		return (return_msg("No Map Found..\n"));
	if (!check_condition(cub->map))
		return (free_2d_char(cub->map), -1);
	if (matrise(cub) == -1)
		return (free_2d_char(cub->map), -1);
	spc_to_tow(cub->map);
	check_player_place(cub);
	long_line(cub);
	close (fd);
	return (1);
}
