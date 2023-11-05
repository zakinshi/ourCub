
#ifndef MINIMAP_H
# define MINIMAP_H

# include "mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <libc.h>
# include <string.h>
# include <limits.h>

# define RED				0xff0000
# define BLACK				0x000000
# define WHITE				0xFFFFFFF
# define GREEN				0x005000
# define BLUECIEL			0x87CEFA

# define WIDTH				800		// Width of the window
# define HEIGHT				600		// Height of the window
# define GRID_SIZE			64		// Size of each grid cell
# define MINIMAP_OFF		0


typedef	struct s_coord
{
	double x;
	double y;
} t_coord;

typedef	struct s_rays {

	double	angleVeiw;
	double wallhitX;
	double wallhitY;
	double distance;
	// int hitVertical;
	int facing_up;
	int facing_down;
	int facing_left;
	int facing_right;
	// int	WallHitContent;
}	t_rays;

typedef	struct s_player
{
	double x;
	double y;
	double	radius;
	int		turnDirection;		//-1 left 1 right 0 nothing
	int		walkDirection;		//-1 back 1 fornt 0 nothing
	double	rotationAngle;		// PI / 2;
	double	moveSpeed;			// 3.0
	double	rotationSpeed;		// 3 * (PI / 180)
}	t_player;

typedef struct s_mlx {

	void	*mlx_ptr;
	void	*win;

	void	*img;
	char	*addr;
	int		b_p_l;
	int		l_l;
	int		dian;
} t_mlx;

typedef struct global_s {

	char		**map;
	t_player	*player;
	t_mlx		*mlx_s;
	t_rays		**rays;
}	t_global;

void		draw_care(t_mlx *mlx_s, double x, double y, int size_care, int color);
char		**ft_split(char const *str, char c);
void		_Disk(t_mlx *mlx_s, int cx, int cy, int r);

t_player	*init_player(void);
void 		_player(t_global *_g, char **map);
int			moveHook(int key, void *formation);
int			initMove(void *formation);
void		updatePlayer(t_player *player, char **map);

void		my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void		image_driver(t_mlx *mlx_s);

// --> dda.c
double		abs_(double n);
double		disatnce_between2points(double x1, double y1, double x2, double y2);
void		_DaaLine(t_mlx *mlx_s, double x0, double y0, double x1, double y2, long color);

int			lenlines(char **rows);

void		draw_walls (t_mlx *mlx_s, char **map);

void		RaysCast(t_global *_g);

void		drawRays (t_global *_g);

int			isin_wall(double x, double y, char **map); 

//	--> hori_ray.c
double		horizontal_distance(t_global *_g, t_rays *ray, t_coord *wallhit, int i);

//	--> ver_ray.c
double	vertical_distance(t_global *_g, t_rays *ray, t_coord *wallhit, int i);

#endif