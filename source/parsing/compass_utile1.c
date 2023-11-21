/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass_utile1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:43:10 by enaam             #+#    #+#             */
/*   Updated: 2023/11/21 18:28:34 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	loop_compass(char **compass, t_cub3d *cub)
{
	int	i;

	i = 0;
	while (compass[i])
	{
		if (condition_compass(compass[i], cub) == -1)
			return (-1);
		i++;
	}
	return (1);
}

void	loop_cmp(char **compass, char *line, int *j)
{
	int	i;

	i = 0;
	new_l(line);
	while (line[i] == 9 || (line[i] <= 32 && line[i] >= 13))
		i++;
	if (ft_chr("NOSOWEEA", line[i]))
	{
		compass[*j] = ft_dup(line + i);
		*j += 1;
	}
	free(line);
}
