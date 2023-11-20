/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:49:59 by enaam             #+#    #+#             */
/*   Updated: 2023/11/20 19:00:34 by zakbouha         ###   ########.fr       */
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

void	condition_compass_1(char *compass, t_cub3d *cub)
{
	int		i;
	char	*sp;

	i = 0;
	sp = NULL;
	if (!ft_cmp("NO ", compass, 3))
	{
		sp = stor_comp(compass, sp, &i);
		cub->no = sp + i;
	}
	else if (!ft_cmp("SO ", compass, 3))
	{
		sp = stor_comp(compass, sp, &i);
		cub->so = sp + i;
	}
}

void	condition_compass(char *compass, t_cub3d *cub)
{
	int		i;
	char	*sp;

	i = 0;
	sp = NULL;
	condition_compass_1(compass, cub);
	if (!ft_cmp("WE ", compass, 3))
	{
		sp = stor_comp(compass, sp, &i);
		cub->we = sp + i;
	}
	else if (!ft_cmp("EA ", compass, 3))
	{
		sp = stor_comp(compass, sp, &i);
		cub->ea = sp + i;
	}
}

int	loop_compass(char **color, t_cub3d *cub)
{
	int	i;

	i = 0;
	while (color[i])
	{
		condition_compass(color[i], cub);
		i++;
	}
	return (1);
}
