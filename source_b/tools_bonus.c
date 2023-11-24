/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:17:44 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/25 00:34:29 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	lenlines(char **rows)
{
	int	i;

	i = -1;
	while (rows[++i])
		;
	return (i);
}

int	exit_msg(char *msg)
{
	int	len;

	len = ft_strlen(msg);
	write(2, msg, len);
	exit(1);
}

int	return_msg(char *msg)
{
	int	len;

	len = ft_strlen(msg);
	write(2, msg, len);
	return (-1);
}

int	get_direction(int x, t_coord last_coord)
{
	if (x > last_coord.x)
		return (1);
	if (x < last_coord.x)
		return (-1);
	return (0);
}
