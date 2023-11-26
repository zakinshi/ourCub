/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:31:46 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/26 14:48:44 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	close_exit(int fd)
{
	close(fd);
	exit_msg("Error: Elements Not Valid\n");	
}

void	check_all_elements_of_map(int fd)
{
	char	*line;
	int		flag;

	flag = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_chr("1CFNSWE\n \t", line[0]))
		{
			if (line[1] && !ft_chr(" \t\nOAE10NWSE", line[1]))
				close_exit(fd);
		}
		else
			close_exit(fd);
		free(line);
	}
	close(fd);
}

int	free_txt(t_cub3d *cub)
{
	if (cub->no)
		free(cub->no);
	if (cub->ea)
		free(cub->ea);
	if (cub->we)
		free(cub->we);
	if (cub->so)
		free(cub->so);
	free(cub);
	return (-1);
}
