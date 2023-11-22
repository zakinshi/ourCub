/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:21:45 by enaam             #+#    #+#             */
/*   Updated: 2023/11/22 22:25:12 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_pars(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 9 || (s[i] >= 13 && s[i] <= 32))
			s[i] = '2';
		i++;
	}
}

int	len_line(int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		j = 0;
		while ((line[j] <= 32 && 13 <= line[j]) \
			|| line[j] == 9)
			j++;
		if (ft_chr("01", line[j]))
			i++;
		free(line);
	}
	return (i);
}

void	new_l(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
		{
			s[i] = '\0';
			return ;
		}
	}
}

int	check_fstlst(char *s)
{
	int	i;

	i = 0;
	if (s[i] != '1' && s[i] != '2')
		return (printf("%s\n", "error in first edge"), 0);
	while (s[i])
		i++;
	if (s[i - 1] != '1' && s[i - 1] != '2')
		return (printf("%s\n", "error in last edge"), 0);
	return (1);
}

int	read_l(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '0' || ft_chr("NESW", s[i]))
			return (0);
		i++;
	}
	return (1);
}
