#include "cub3d.h"

int	lenlines(char **rows)
{
	int i = -1;
	while (rows[++i])
		;
	return i;
} 

void	exit_msg(char *msg)
{
	int	len;

	len = strlen(msg);	// ft_strlen();
	write(2, msg, len);
	exit(1);
}

void	define_grid_size(t_global *_g)
{
	int	for_height;
	int	for_width;

	for_width = (WIDTH / _g->maps->width_map);
	for_height = (HEIGHT / _g->maps->hieght_map);
	// GRID_SIZE = for_height < for_width ? for_height : for_width;
	GRID_SIZE = 64;
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
