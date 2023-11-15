/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:24:26 by enaam             #+#    #+#             */
/*   Updated: 2023/11/15 14:48:48 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minimap.h"

int	check_firstlast_line(char **arr)
{
	int	i;

	i = 0;
	if (!read_l(arr[i]))
		return (printf("%s\n", "error in first line") ,0);
	while (arr[i])
		i++;
	if (!read_l(arr[i - 1]))
		return (printf("%s\n", "error in last line") ,0);
	return (1);
}

void	spc_to_tow(char **line)
{
	int i;

	i = -1;
	while (line[++i])
		check_pars(line[i]);
}

int edge_map(char **line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!check_fstlst(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int case_matrs(t_cub3d *cub, char zero)
{
	// spc = 2
	if (zero == '0' && cub->next_i != '1' && \
		cub->next_i != '0' && !ft_chr("NSWE", cub->next_i))
		return (printf("error in next i\n") ,0);
	if ((zero == '0' || ft_chr("NSWE", zero)) && cub->next_j == '2')
		return (printf("error in zero\n") ,0);
	if (zero == '0' && cub->old_i != '1' && \
		cub->old_i != '0' && !ft_chr("NSWE", cub->old_i))
		return (printf("error in old i\n"), 0);
	return (1);
}

int	matrise(t_cub3d *cub)
{
	int i = 1;
	int j;

	while (cub->map[i] && cub->map[i + 1])
	{
		j = 0;
		while (cub->map[i][j] && cub->map[i][j + 1])
		{
			if (cub->map[i][j] == '0')
			{
				cub->next_i = cub->map[i + 1][j];
				cub->next_j = cub->map[i][j + 1];
				cub->old_i = cub->map[i - 1][j];
			}
			if (!case_matrs(cub, cub->map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}