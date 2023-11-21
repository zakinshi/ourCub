/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:49:59 by enaam             #+#    #+#             */
/*   Updated: 2023/11/21 10:49:20 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	loop_spc(char *compass)
{
	int	i;

	i = 0;
	while ((compass[i] >= 11 && compass[i] <= 32) \
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
	if (!ft_cmp("NO", compass, 2))
	{
		sp = stor_comp(compass, sp, &i);
		cub->no = sp + i;
		*flag = 1;
	}
	else if (!ft_cmp("SO", compass, 2))
	{
		sp = stor_comp(compass, sp, &i);
		cub->so = sp + i;
		*flag = 1;
	}
}

int	waith_spc_c(char *color)
{
	int	len;

	len = -1;
	while (color[++len] > 32)
		;
	if (len != 2)
		return (-1);
	return (1);
}

int	condition_compass(char *compass, t_cub3d *cub)
{
	int		i;
	char	*sp;
	int		flag;

	i = 0;
	flag = 0;
	sp = NULL;
	if (waith_spc_c(compass) == -1)
		return (-1);
	condition_compass_1(compass, cub, &flag);
	if (!ft_cmp("WE", compass, 2))
	{
		sp = stor_comp(compass, sp, &i);
		cub->we = sp + i;
		flag = 1;
	}
	else if (!ft_cmp("EA", compass, 2))
	{
		sp = stor_comp(compass, sp, &i);
		cub->ea = sp + i;
		flag = 1;
	}
	if (!flag)
		return (-1);
	return (1);
}
