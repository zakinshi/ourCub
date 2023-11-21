#ifndef MINIMAP_H
# define MINIMAP_H

# include "../cub3d.h"

#define MINI_WIDTH		600
#define MINI_HEIGHT		150
#define	MINI_GRID		64

typedef struct s_minilx {

	void	*mlx_ptr;
	void	*win;
	void	*mn_img;
	char	*mn_addr;
	int		b_p_l;
	int		l_l;
	int		dian;
}	t_minilx;

void		minimap_mlx_pixel_put(t_minilx *data, int x, int y, int color);
void		minimap_image(t_minilx *mlx_s);

//			--> gridWall.c
void		draw_walls(t_global *_g, t_minilx *mn_mlx_s);

//			--> tools.c
void		draw_circle(t_minilx *mlx_s, int x, int y, int r);
void		_disk(t_minilx *mlx_s, int cx, int cy, int r);

void		_daa_line_mini(t_minilx *mlx_s, double x0, double y0, double x1, double y1, long color);
void		_player(t_global *_g, t_minilx *mn_mlx_s);

int			_transp(char color);

#endif