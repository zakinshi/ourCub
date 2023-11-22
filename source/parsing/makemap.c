/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:51:28 by enaam             #+#    #+#             */
/*   Updated: 2023/11/22 22:12:09 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	replace_all(char *linemap, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		linemap[i] = line[i];
}

static char	*make_line_insize(char *line, int size)
{
	char	*lineinsize;

	lineinsize = malloc(sizeof(char) * (size + 1));
	if (lineinsize)
	{
		(void)line;
		ft_memset(lineinsize, '2', size);
		replace_all(lineinsize, line);
		return (lineinsize);
	}
	return (NULL);
}

char	**maping_themap( t_cub3d *cub)
{
	char	**mymap;
	int		i;

	i = -1;
	mymap = malloc(sizeof(char *) * (cub->len_l + 1));
	if (!mymap)
		exit_msg("Allocation of mymap(Failed)...\n");
	while (++i < cub->len_l)
	{
		mymap[i] = make_line_insize(cub->map[i], cub->long_l);
		if (!mymap[i])
			break ;
	}
	mymap[i] = NULL;
	free_2d_char(cub->map);
	return (mymap);
}
