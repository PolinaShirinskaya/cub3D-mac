/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:20:20 by adian             #+#    #+#             */
/*   Updated: 2022/12/13 13:46:41 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_close_window(t_main *data)
{
	ft_end_program(data, NULL, 0);
	return (0);
}

void	ft_rotate_right(t_main *data)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = data->hero.direction.x;
	tmp_plane_x = data->plane.x;
	data->hero.direction.x = data->hero.direction.x * cos(ROTATE_SPEED) - \
	data->hero.direction.y * sin(ROTATE_SPEED);
	data->hero.direction.y = tmp_dir_x * sin(ROTATE_SPEED) + \
	data->hero.direction.y * cos(ROTATE_SPEED);
	data->plane.x = data->plane.x * cos(ROTATE_SPEED) - \
	data->plane.y * sin(ROTATE_SPEED);
	data->plane.y = tmp_plane_x * sin(ROTATE_SPEED) + \
	data->plane.y * cos(ROTATE_SPEED);
	ft_rendering_img(data);
}

void	ft_rotate_left(t_main *data)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = data->hero.direction.x;
	tmp_plane_x = data->plane.x;
	data->hero.direction.x = data->hero.direction.x * cos(-ROTATE_SPEED) - \
	data->hero.direction.y * sin(-ROTATE_SPEED);
	data->hero.direction.y = tmp_dir_x * sin(-ROTATE_SPEED) + \
	data->hero.direction.y * cos(-ROTATE_SPEED);
	data->plane.x = data->plane.x * cos(-ROTATE_SPEED) - \
	data->plane.y * sin(-ROTATE_SPEED);
	data->plane.y = tmp_plane_x * sin(-ROTATE_SPEED) + \
	data->plane.y * cos(-ROTATE_SPEED);
	ft_rendering_img(data);
}
