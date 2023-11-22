/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:55:23 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/22 22:13:57 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_bonus.h"

void	minimap_mlx_pixel_put(t_minilx *data, int x, int y, int color)
{
	char	*dst;

	if ((x > 0 && x < MINI_WIDTH) && (y > 0 && y < MINI_HEIGHT))
	{
		dst = data->mn_addr + (y * data->l_l + x * (data->b_p_l / 8));
		*(int *)dst = color;
	}
}

void	minimap_image(t_minilx *mn_mlx_s)
{
	mn_mlx_s->mn_img = \
		mlx_new_image(mn_mlx_s->mlx_ptr, MINI_WIDTH, MINI_HEIGHT);
	if (!mn_mlx_s->mn_img)
		exit_msg("Allocation Failed for mn_mlx_s->mn_img");
	mn_mlx_s->mn_addr = mlx_get_data_addr(mn_mlx_s->mn_img, &(mn_mlx_s->b_p_l), \
		&(mn_mlx_s->l_l), &(mn_mlx_s->dian));
	if (!mn_mlx_s->mn_addr)
		exit_msg("Allocation Failed for mn_mlx_s->mn_addr");
}
