/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:39:56 by adian             #+#    #+#             */
/*   Updated: 2022/12/13 14:25:09 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_move_on(t_main *data)
{
	char	tmp;

	tmp = data->map.map[(int)(data->hero.position.y + data->hero.direction.y \
		* (MOVE))][(int)(data->hero.position.x)];
	if (tmp != '1')
		data->hero.position.y += data->hero.direction.y * MOVE_STEP;
	tmp = data->map.map[(int)(data->hero.position.y)] \
		[(int)(data->hero.position.x + data->hero.direction.x * (MOVE))];
	if (tmp != '1')
		data->hero.position.x += data->hero.direction.x * MOVE_STEP;
	ft_rendering_img(data);
}

static void	ft_move_back(t_main *data)
{
	char	tmp;

	tmp = data->map.map[(int)(data->hero.position.y - data->hero.direction.y \
		* (MOVE))][(int)(data->hero.position.x)];
	if (tmp != '1')
		data->hero.position.y -= data->hero.direction.y * MOVE_STEP;
	tmp = data->map.map[(int)(data->hero.position.y)] \
		[(int)(data->hero.position.x - data->hero.direction.x * (MOVE))];
	if (tmp != '1')
		data->hero.position.x -= data->hero.direction.x * MOVE_STEP;
	ft_rendering_img(data);
}

static void	ft_move_right(t_main *data)
{
	int	tmp;

	tmp = data->map.map[(int)(data->hero.position.y + data->plane.y \
		* (MOVE))][(int)(data->hero.position.x)];
	if (tmp != '1')
		data->hero.position.y += data->plane.y * MOVE_STEP;
	tmp = data->map.map[(int)(data->hero.position.y)] \
		[(int)(data->hero.position.x + data->plane.x * (MOVE))];
	if (tmp != '1')
		data->hero.position.x += data->plane.x * MOVE_STEP;
	ft_rendering_img(data);
}

static void	ft_move_left(t_main *data)
{
	int	tmp;

	tmp = data->map.map[(int)(data->hero.position.y - data->plane.y \
		* (MOVE))][(int)(data->hero.position.x)];
	if (tmp != '1')
		data->hero.position.y -= data->plane.y * MOVE_STEP;
	tmp = data->map.map[(int)(data->hero.position.y)] \
		[(int)(data->hero.position.x - data->plane.x * (MOVE))];
	if (tmp != '1')
		data->hero.position.x -= data->plane.x * MOVE_STEP;
	ft_rendering_img(data);
}

int	ft_press_key(int keycode, t_main *data)
{
	if (keycode == KEY_ESC)
		ft_end_program(data, NULL, 0);
	else if (keycode == MOVE_ON)
		ft_move_on(data);
	else if (keycode == MOVE_BACK)
		ft_move_back(data);
	else if (keycode == MOVE_RIGHT)
		ft_move_right(data);
	else if (keycode == MOVE_LEFT)
		ft_move_left(data);
	else if (keycode == ROTATE_RIGHT)
		ft_rotate_right(data);
	else if (keycode == ROTATE_LEFT)
		ft_rotate_left(data);
	return (0);
}
