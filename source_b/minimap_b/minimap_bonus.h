/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:20:18 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/23 16:46:26 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "../cub3d_bonus.h"

# define MINI_WIDTH		450
# define MINI_HEIGHT	100
# define MINI_GRID		64

typedef struct s_minilx {
	void	*mlx_ptr;
	void	*win;
	void	*mn_img;
	char	*mn_addr;
	int		b_p_l;
	int		l_l;
	int		dian;
}	t_minilx;

void		minimap_image(t_minilx *mlx_s);
//			--> gridWall.c
void		draw_walls(t_global *_g, t_minilx *mn_mlx_s);
//			--> tools.c
void		draw_circle(t_minilx *mlx_s, int x, int y, int r);
void		_disk(t_minilx *mlx_s, int cx, int cy, int r);
void		_daa_line_mini(t_minilx *mlx_s, t_coord pos0, \
				t_coord pos1, long color);
void		_player(t_global *_g, t_minilx *mn_mlx_s);
int			_transp(char color);
void		draw_minimap(t_global *_g);
void		minimap_mlx_pixel_put(t_minilx *data, int x, int y, int color);
#endif
