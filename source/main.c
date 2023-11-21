/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:57:33 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/21 18:21:08 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	driver(t_global	*_g)
{
	image_driver(_g->mlx_s);
	update_player(_g->player, _g->maps);
	rays_cast(_g);
	draw_all(_g);
	mlx_destroy_image(_g->mlx_s->mlx_ptr, _g->mlx_s->img);
	return (0);
}

static int	init_all(t_global *_g)
{
	t_map	*maps;

	maps = malloc(sizeof(t_map));
	if (!_g)
		return (printf("Maps Malloc Failled.. \n"), 0);
	_g->maps = maps;
	if (!parsing_(_g))
		return (0);
	printf("no %s\n", _g->maps->north);
	free(_g->maps->north);
	free(_g->maps->south);
	free(_g->maps->west);
	free(_g->maps->east);
	free_2d_char(_g->maps->map);
	free(_g->maps);
	free(_g);
	exit (0);
	init_player(_g);
	init_mlx_s(_g);
	return (1);
}

static int	main_driver(char *path)
{
	t_global	*_g;

	_g = malloc(sizeof(t_global));
	if (!_g)
		return (printf("_g malloc failled.. \n"), -1);
	_g->path = path;
	if (!init_all(_g))
		return (-1);
	mlx_loop_hook(_g->mlx_s->mlx_ptr, driver, _g);
	all_my_hooks(_g);
	mlx_loop(_g->mlx_s->mlx_ptr);
	return (0);
}

void	leaks()
{
	system("leaks Cub3D");
}

int	main(int ac, char **av)
{
	atexit(leaks);
	int	i;

	if (ac != 2)
		exit_msg("Warnning :\n\t./Cub3D ./[Path_map]\n");
	i = ft_strlen(av[1]);
	while (i >= 0 && av[1][--i] != '.')
		;
	if (ft_cmp(av[1] + i, ".cub", 4))
		exit_msg("Warnning :\n\t./Cub3D not found .cub\n");
	return (main_driver(av[1]));
}
