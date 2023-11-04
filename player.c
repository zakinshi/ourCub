#include "minimap.h"

t_player	*init_player(void)
{

	t_player *player;

	player = malloc(sizeof(t_player));
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->radius	= 3;
	player->turnDirection = 0;
	player->walkDirection = 0;
	player->rotationAngle = M_PI;
	player->moveSpeed = 5.0;
	player->rotationSpeed = 4 * (M_PI / 180);

	return player;
}

int	moveHook(int key, void *formation)
{

	t_player *player;

	player = (t_player *)formation;
	if (key == 126)			// up 126
		player->walkDirection = 1;
	else if (key == 125)	// down 125
		player->walkDirection = -1;
	else if (key == 124)	// right 124
		player->turnDirection = 1;
	else if (key == 123)	// left 123
		player->turnDirection = -1;
	return 0;
}

int	initMove(void *formation)
{

	t_player *player;

	player = (t_player *)formation;
	player->walkDirection = 0; 
	player->turnDirection = 0;
	return 0;
}

int	isin_wall(double x, double y, char **map)
{
	int	i;
	int	j;

	i = (y - MINIMAP_OFF) / GRID_SIZE;
	j = (x - MINIMAP_OFF) / GRID_SIZE;
	if (i > 7)
		return 1;
	if (map && map[i] && map[i][j] && map[i][j] == '1')
		return (1);
	return (0);
}

void	updatePlayer(t_player *player, char **map)
{
	double copyX = player->x, copyY = player->y;
	double moveStep = player->walkDirection * player->moveSpeed;
	player->x += cos(player->rotationAngle) * moveStep;
	player->y += sin(player->rotationAngle) * moveStep;

	player->rotationAngle += player->turnDirection * player->rotationSpeed;
	if (isin_wall(player->x, player->y, map))
	{
		player->y = copyY;
		player->x = copyX;
	}
}

void _player(t_global *_g, char **map)
{

	t_mlx *mlx_s;
	t_player *player;

	mlx_s = _g->mlx_s;
	player = _g->player;
	updatePlayer(player, map);
	_Disk(mlx_s, player->x, player->y, player->radius);
	_DaaLine(mlx_s, player->x, player->y,\
				player->x + cos(player->rotationAngle) * 20,\
				player->y + sin(player->rotationAngle) * 20);
	// drawRays(_g);
	initMove(player);
	_g->mlx_s = mlx_s;
	_g->player = player;
	// add_lile line for the now the redirection
}

