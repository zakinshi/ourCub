/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:21:45 by enaam             #+#    #+#             */
/*   Updated: 2023/11/14 19:26:09 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minimap.h"

void	check_pars(char *s)
{
	int		i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] >= 13 && s[i] <= 32)
			s[i] = '2';
		i++;
	}
}

int len_line(int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[j] <= 32 && 13 <= line[j])
			j++;
		if (!ft_chr("FCNOSOWEEA\n", line[j]))
			i++;
		free(line);
	}
	return (i);
}

void	new_l(char *s)
{
	int i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
			s[i] = '\0';
	}
}

int check_fstlst(char *s)
{
	int i = 0;

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
	int i = 0;

	while (s[i])
	{
		if (s[i] == '0')
			return (0);
		i++;
	}
	return (1);
}
