/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:11:55 by zakbouha          #+#    #+#             */
/*   Updated: 2023/11/23 16:30:21 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	disatnce_between2points(double x1, double y1, double x2, double y2)
{
	double	deltax2;
	double	deltay2;

	deltax2 = x2 - x1;
	deltay2 = y2 - y1;
	deltax2 = deltax2 * deltax2;
	deltay2 = deltay2 * deltay2;
	return (sqrt(deltax2 + deltay2));
}

void	exit_size_error(int width, int height)
{
	if (width != 64 || height != 64)
		exit_msg("width or height of xpm is bigger of 64 try[64]\n");
}

double	abs_(double n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
