/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:49:59 by enaam             #+#    #+#             */
/*   Updated: 2023/11/20 21:17:30 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	loop_spc(char *compass)
{
	int	i;

	i = 0;
	while ((compass[i] >= 13 && compass[i] <= 32) \
		|| compass[i] == 9)
		i++;
	return (i);
}

char	*stor_comp(char *compass, char *sp, int *i)
{
	int	j;

	j = 0;
	sp = ft_dup(compass + 2);
	*i = loop_spc(sp);
	if (!*(sp + *i))
	{
		printf("erorr in compass\n");
		exit (0);
	}
	j = open(sp + *i, O_RDONLY);
	if (j == -1)
	{
		printf("erorr in compass\n");
		exit (0);
	}
	else
		close(j);
	return (sp);
}

void	condition_compass_1(char *compass, t_cub3d *cub, int *flag)
{
	int		i;
	char	*sp;

	i = 0;
	sp = NULL;
	if (!ft_cmp("NO ", compass, 3))
	{
		sp = stor_comp(compass, sp, &i);
		cub->no = sp + i;
		*flag = 1;
	}
	else if (!ft_cmp("SO ", compass, 3))
	{
		sp = stor_comp(compass, sp, &i);
		cub->so = sp + i;
		*flag = 1;
	}
}

int	condition_compass(char *compass, t_cub3d *cub)
{
	int		i;
	char	*sp;
	int		flag = 0;

	i = 0;
	sp = NULL;
	condition_compass_1(compass, cub, &flag);
	if (!ft_cmp("WE ", compass, 3))
	{
		sp = stor_comp(compass, sp, &i);
		cub->we = sp + i;
		flag = 1;
	}
	else if (!ft_cmp("EA ", compass, 3))
	{
		sp = stor_comp(compass, sp, &i);
		cub->ea = sp + i;
		flag = 1;
	}
	if (!flag)
		return (-1);
	return (1);
}

int	loop_compass(char **color, t_cub3d *cub)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (condition_compass(color[i], cub) == -1)
			return (-1);
		i++;
	}
	return (1);
}
