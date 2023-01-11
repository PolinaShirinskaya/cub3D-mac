/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:27:58 by adian             #+#    #+#             */
/*   Updated: 2022/12/13 13:52:09 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_point	ft_set_point(double x, double y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void	my_mlx_pixel_put(t_main *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDHT && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = data->mlx.img.addr + (y * data->mlx.img.line_length + \
		x * (data->mlx.img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
