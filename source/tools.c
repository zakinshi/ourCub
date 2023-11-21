/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:17:44 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/21 13:19:41 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	lenlines(char **rows)
{
	int	i;

	i = -1;
	while (rows[++i])
		;
	return (i);
}

void	exit_msg(char *msg)
{
	int	len;

	len = ft_strlen(msg);
	write(2, msg, len);
	exit(1);
}

void	free_2d_char(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(&s[i]);
		i++;
	}
	free(s);
}

void	free_rays(t_rays **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(&s[i]);
		i++;
	}
	free(s);
}
