/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:49:59 by enaam             #+#    #+#             */
/*   Updated: 2023/11/22 21:16:27 by zakbouha         ###   ########.fr       */
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

static char	*stor_comp(char *compass, char *sp, int *i)
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

static void	condition_compass_1(char *compass, t_cub3d *cub, int *flag)
{
	int		i;
	char	*sp;

	i = 0;
	sp = NULL;
	if (!ft_cmp("NO", compass, 2) || !ft_cmp("SO", compass, 2))
	{
		sp = stor_comp(compass, sp, &i);
		if (!ft_cmp("NO", compass, 2))
			cub->no = ft_dup(sp + i);
		else
			cub->so = ft_dup(sp + i);
		*flag = 1;
		free(sp);
	}
}

static int	waith_spc_c(char *color)
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
	if (!ft_cmp("WE", compass, 2) || !ft_cmp("EA", compass, 2))
	{
		sp = stor_comp(compass, sp, &i);
		if (!ft_cmp("WE", compass, 2))
			cub->we = ft_dup(sp + i);
		else
			cub->ea = ft_dup(sp + i);
		free(sp);
		flag = 1;
	}
	if (!flag)
		return (-1);
	return (1);
}
