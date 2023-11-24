/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:38:27 by enaam             #+#    #+#             */
/*   Updated: 2023/11/24 11:44:56 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define RED				0xff0000
# define BLACK				0x000000
# define BUFFER_SIZE		5
# define WHITE				0xFFFFFFF
# define GREEN				0x005000
# define BLUECIEL			0x87CEFA

# define WIDTH				1080
# define HEIGHT				720
# define GRID_SIZE			64
# define MINIMAP_OFF		0
# define MINIMAP_FCTR		0.1

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_rays 
{
	double	angle_veiw;
	double	wallhitx;
	double	wallhity;
	double	distance;
	int		hit_vertical;
	int		facing_up;
	int		facing_down;
	int		facing_left;
	int		facing_right;
	int		index;
}	t_rays;

typedef struct s_player
{
	double	x;
	double	y;
	double	radius;
	int		turn_direction;
	int		side_walk;
	int		walk_direction;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;	
}	t_player;

typedef struct s_mlx 
{
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
	int		py;
	int		px;
	int		*lenofline;
	char	*north;
	char	*east;
	char	*west;
	char	*south;
}	t_map;

typedef struct s_text
{
	double			per_dist;
	double			distpropln;
	double			projwallht;
	int				walltoppixl;
	int				wallbotmpixl;
	int				textureoffsetx;
	int				textureoffsety;
	unsigned int	*walltext;
	int				x_width;
	int				x_hight;
	void			*xpm[4];
	char			*addr_x[4];
	int				b_p_x;
	int				l_x;
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
	char	old_j;
	char	next_j;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*path;
	int		*lenofline;
}	t_cub3d;

typedef struct global_s
{
	t_player	*player;
	t_mlx		*mlx_s;
	t_rays		**rays;
	t_map		*maps;
	t_text		*texture;
	char		*path;
	double		fov_angle;
}	t_global;

// ****** FOLDER -- source
// 		--> ft_mlx.c
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void	image_driver(t_mlx *mlx_s);
void	init_mlx_s(t_global *_g);
void	exit_msg(char *msg);
int		return_msg(char *msg);

// 		--> main.c
void	all_free(t_global *_g);

// 		--> tools.c
int		lenlines(char **rows);
void	free_rays(t_rays **s);
int		get_direction(int x, t_coord last_coord);

// 		--> hook.c
int		mouse_move(int x, int y, t_global *_g);
int		move_hook(int key, t_global *_g);
void	all_my_hooks(t_global *_g);

//		--> draw.c
void	draw_all(t_global *_g);

// ****** FOLDER -- minimap
//		--> minimap.c
void	draw_minimap(t_global *_g);	

//		--> player.c
void	update_player(t_player *player, t_map *maps);
int		isin_wall(double x, double y, t_map *maps);
void	init_player(t_global *_g);

// ****** FOLDER -- projection
// 		--> calcul_text.c
void	calcule_text(t_global *_g, int i);
void	texture_offset(t_global *_g, int i);
void	xpm_driver(t_global *_g);

//		--> 3dwall.c
void	_fake3d_wall(t_global *_g);
int		_trgb(int t, int r, int g, int b);
void	sky_floor_color(t_global *_g, int i, \
		int wall_top_pixel, int wall_bottom_pixel);
void	_addr_x(t_global *_g);

//		--> dda.c
double	abs_(double n);
double	disatnce_between2points(double x1, double y1, double x2, double y2);

// ****** FOLDER -- raycasting
// 		--> raycasting.c
void	rays_cast(t_global *_g);

// 		--> tools.c
void	free_2d_char(char **s);
void	struct_copy(t_coord *copy_in, t_coord copy_to);
double	norm_angle(double my_angle);

//		--> hori_ray.c
double	horizontal_distance(t_global *_g, t_rays *ray, t_coord *wallhit);

//		--> ver_ray.c
double	vertical_distance(t_global *_g, t_rays *ray, t_coord *wallhit);

// ****** FOLDER -- parsing
// 		--> get_next_line.c
char	*get_next_line(int fd);
void	my_free(void *to_free);

// 		--> get_next_line_utile.c
char	*ft_chr(char *s, char c);
char	*ft_cpy(char *dst, char *src);
char	*ft_dup(char *s);
char	*make_copy(char *copy, char *s);
char	*ft_join(char *s1, char *s2);
// char	*ft_strjoin(char *s1, char *s2);

// 		--> color_utile.c
int		check_isdiget(char *str);
int		get_color(char *color, t_cub3d *cub);
int		pars_color(char *color, t_cub3d *cub);
int		waith_spc(char **color, int i);

// 		--> color_utile1.c
int		to_return(char *color, t_cub3d *cub);
int		diget(char *str);
int		ft_cmp(char *ft, char *sd, size_t n);
size_t	ft_strlen(char *s);
void	store_loop_cf(char **color, int fd);

// 		--> color.c
void	loop_cf(char **color, char *line, int *j);
int		ft_color(t_cub3d *cub, int fd);

// 		--> compass_utile.c
int		loop_spc(char *compass);
int		condition_compass(char *compass, t_cub3d *cub);

// 		--> compass_utile1.c
int		loop_compass(char **color, t_cub3d *cub);
void	loop_cmp(char **compass, char *line, int *j);

// 		--> compass.c
int		ft_compass(t_cub3d *cub, int fd);
int		parsing_(t_global *_g);

// 		--> libft.c
int		ft_atoi(const char *str);
int		count_word(char const *s, char c);
char	**ft_split(char const *s, char c);

// 		--> makemap.c
char	**maping_themap( t_cub3d *cub);

// 		--> map_pars.c
char	**store_map(int fd, t_cub3d *cub);
void	long_line(t_cub3d *cub);
int		ft_map(t_cub3d *cub, int fd);

// 		--> pars_utile.c
void	check_pars(char *s);
int		len_line(int fd);
void	new_l(char *s);
int		check_fstlst(char *s);
int		read_l(char *s);

// 		--> pars_utile1.c
int		check_firstlast_line(char **arr);
void	spc_to_tow(char **line);
int		edge_map(char **line);
int		case_matrs(t_cub3d *cub, char paus);
int		matrise(t_cub3d *cub);

// 		--> pars_utile2.c
int		check_condition(char **map);
void	loop_map(char **map, int len, int fd);

// 
void	exit_size_error(int width, int height);

//
void	handel_condition_bns(char *map, int i);

#endif
