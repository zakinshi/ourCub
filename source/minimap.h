
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
# define MINIMAP_FCTR		0.2
# define FOV_ANGLE			60 * (M_PI / 180)
# define WallStripWidth		1.00

typedef	struct s_coord
{
	double x;
	double y;
}	t_coord;

typedef	struct s_rays {

	double	angle_veiw;
	double	wallhitx;
	double	wallhity;
	double	distance;
	int		hit_vertical;
	int		facing_up;
	int		facing_down;
	int		facing_left;
	int		facing_right;
	// int	WallHitContent;
}	t_rays;

typedef	struct s_player
{
	double	x;
	double	y;
	double	radius;
	int		turn_direction;		//-1 left 1 right 0 nothing
	int		side_walk;			//-1 left 1 right 0 nothing
	int		walk_direction;		//-1 back 1 fornt 0 nothing
	double	rotation_angle;		// PI / 2;
	double	move_speed;			// 3.0
	double	rotation_speed;		// 3 * (PI / 180)
}	t_player;

typedef struct s_mlx {

	void	*mlx_ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		b_p_l;
	int		l_l;
	int		dian;
}	t_mlx;

typedef struct s_map
{
	char	**map;
	int		floor_color;
	int		sky_color;
	int		hieght_map;
	int		width_map;
}	t_map;

typedef struct global_s {

	t_player	*player;
	t_mlx		*mlx_s;
	t_rays		**rays;
	t_map		*maps;
}	t_global;

// ****** FOLDER -- source
// 			--> ft_mlx.c
void		my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void		image_driver(t_mlx *mlx_s);
void		init_mlx_s(t_global *_g);
int			move_hook(int key, void *formation);
// 			--> main.c
int			lenlines(char **rows);
// 			--> split.c
char		**ft_split(char const *str, char c);
int			ft_count_words(char const *str, char c);
//			--> draw.c
void		draw_all(t_global *_g);
void		color_sky_floor(t_global *_g);
void		draw_minimap(t_global *_g);

// ****** FOLDER -- minimap
//			--> gridWall.c
void		draw_walls (t_mlx *mlx_s, char **map);
void		draw_rect(t_mlx *mlx_s, double x, double y, int size_width, int size_height, int color);
//			--> player.c
int			init_move(void *formation);
void		update_player(t_player *player, char **map);
int			isin_wall(double x, double y, char **map);
void		_player(t_global *_g);
void		init_player(t_global *_g);
//			--> tools.c
void		draw_circle(t_mlx *mlx_s, int x, int y, int r);
void		_disk(t_mlx *mlx_s, int cx, int cy, int r);

// ****** FOLDER -- projection
//			--> 3dwall.c
void		_fake3d_wall(t_global *_g);
int			_trgb(int t, int r, int g, int b);
//			--> dda.c
void		_daa_line(t_mlx *mlx_s, double x0, double y0, double x1, double y1, long color);
double		disatnce_between2points(double x1, double y1, double x2, double y2);

// ****** FOLDER -- raycasting
// 			--> raycasting.c
void		rays_cast(t_global *_g);
// 			--> tools.c
void		draw_rays(t_global *_g);
void		struct_copy(t_coord *copy_in, t_coord copy_to);
double		norm_angle(double my_angle);
//			--> hori_ray.c
double		horizontal_distance(t_global *_g, t_rays *ray, t_coord *wallhit);
//			--> ver_ray.c
double		vertical_distance(t_global *_g, t_rays *ray, t_coord *wallhit);

#endif
