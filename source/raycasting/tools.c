/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:53:29 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/21 11:56:24 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	struct_copy(t_coord *copy_in, t_coord copy_to)
{
	copy_in->x = copy_to.x;
	copy_in->y = copy_to.y;
}

double	norm_angle(double my_angle)
{
	my_angle = fmod(my_angle, (2.00 * M_PI));
	if (my_angle < 0)
		my_angle += (2 * M_PI);
	return (my_angle);
}
