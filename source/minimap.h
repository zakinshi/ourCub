
#ifndef MINIMAP_H
# define MINIMAP_H

// # include "mlx.h"
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

# define WIDTH				1920		// Width of the window
# define HEIGHT				1024		// Height of the window
// # define GRID_SIZE			52		// Size of each grid cell
# define MINIMAP_OFF		0
# define MINIMAP_FCTR		1
# define FOV_ANGLE			60 * (M_PI / 180)
# define WallStripWidth		1.00

int	GRID_SIZE;

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
	int		hieght_map; // len_l
	int		width_map; // long_l
	int		py; // i
	int		px; // j
	int		SIZE_GRID;
	char	*north;
	char	*east;
	char	*west;
	char	*south;
}	t_map;

typedef	struct s_text
{
	double	per_dist;
	double	distpropln;
	double	projwallht;
	double		wallstripht;
	int		walltoppixl;
	int		wallbotmpixl;
	int		textureoffsetx;
	int		textureoffsety;
	unsigned int *walltext;
	int	x_width;
	int	x_hight;
	void	*xpm[4];
	char	*addr_x[4];
	int		b_p_x;
	int		l_x;
}	t_text;

typedef struct s_cub3d
{
	char	**map;
	int		len_l;
	int		long_l;
	int		skay;
	int		playr_i;
	int		playr_j;
	int		floor;
	int		blue;
	int		red;
	int		green;
	char	next_i;
	char	old_i;
	char	next_j;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*path;
}	t_cub3d;

typedef struct global_s {

	t_player	*player;
	t_mlx		*mlx_s;
	t_rays		**rays;
	t_map		*maps;
	char		*path;
	t_text		*texture;
	t_cub3d		*cub;
}	t_global;

// ****** FOLDER -- source
// 			--> ft_mlx.c
void		my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void		image_driver(t_mlx *mlx_s);
void		init_mlx_s(t_global *_g);
void		exit_msg(char *msg);
// 			--> main.c
// 			--> tools.c
void		define_grid_size(t_global *_g);
int			lenlines(char **rows);
// 			--> hook.c
int			mouse_move(int x, int y, t_global *_g);
int			move_hook(int key, t_global *_g);
void		all_my_hooks(t_global *_g);
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
void		update_player(t_player *player, t_map *maps);
int			isin_wall(double x, double y, t_map *maps);
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


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif


char	*get_next_line(int fd);
char	*ft_dup(char *s);
int		check_firstlast_line(char **arr);
void	display(t_cub3d *cub);
void	spc_to_tow(char **line);
int		edge_map(char **line);
int		read_l(char *s);
int		check_fstlst(char *s);
void	new_l(char *s);
int		len_line(int fd);
void	check_pars(char *s);
int		case_matrs(t_cub3d *cub, char paus);
int		count_word(char const *s, char c);
int		matrise(t_cub3d *cub);
char	*ft_cpy(char *dst, char *src);
char	*ft_join(char *s1, char *s2);
char	*ft_chr(char *s, char c);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	**store_map(int fd);
int		check_isdiget(char *str);
int		color_shift(int t, int r, int g, int b);
int		get_color(char *color, t_cub3d *cub);
int		lenlines(char **rows);
int		pars_color(char *color, t_cub3d *cub);
int		ft_cmp(char *ft, char *sd, size_t n);
int		ft_compass(t_cub3d *cub, int fd);
int		ft_map(t_cub3d *cub, int fd);
int		parsing_();
int		ft_color(t_cub3d *cub, int fd);
void	long_line(t_cub3d *cub);
int		to_return(char *color, t_cub3d *cub);
int		diget(char *str);
int		loop_spc(char *compass);
void	loop_cmp(char **compass, char *line, int *j);
void	loop_cf(char **color, char *line, int *j);
int		loop_compass(char **color, t_cub3d *cub);
int		check_condition(char **map);
void	loop_map(char **map, int len, int fd);

void	calcule_text(t_global *_g, int i);
void	texture_offset(t_global *_g, int i);
void	xpm_driver(t_global *_g);

size_t	ft_strlen(char *s);
char	*make_copy(char *copy, char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*find_newline(char *search_in);
void	my_free(void *to_free);

#endif
