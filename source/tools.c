#include "minimap.h"

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
void	int_xpm(t_global *_g);
void	define_grid_size(t_global *_g)
{
	int	for_height;
	int	for_width;
	// int	for_texture;

	// int_xpm(_g);
	// xpm_driver(_g);
	for_width = (WIDTH / _g->maps->width_map);
	for_height = (HEIGHT / _g->maps->hieght_map);
	// GRID_SIZE = for_height < for_width ? for_height : for_width;

	// for_texture = WIDTH / _g->texture->x_width;
	// GRID_SIZE = for_texture < GRID_SIZE ? for_texture : GRID_SIZE;

	// if (for_texture < for_width){
	// 	if (for_texture < for_height)
	// 		GRID_SIZE = for_texture;
	// 	else
	// 		GRID_SIZE = for_height;
	// }
	// else
	// {
	// 	if (for_width < for_height)
	// 		GRID_SIZE = for_width;
	// 	else
	// 		GRID_SIZE = for_height;
	// }
	GRID_SIZE = 64;
	// printf("grid %d\n", GRID_SIZE);
}
