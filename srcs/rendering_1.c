/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:58:11 by adian             #+#    #+#             */
/*   Updated: 2022/12/07 17:41:40 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_define_side_step_x(t_main *data)
{
	if (data->ray.dir.x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side.x = (data->hero.position.x - data->map.x) * \
		data->ray.delta.x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side.x = (data->map.x + 1.0 - data->hero.position.x) * \
		data->ray.delta.x;
	}
}

static void	ft_define_side_step_y(t_main *data)
{
	if (data->ray.dir.y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side.y = (data->hero.position.y - data->map.y) * \
		data->ray.delta.y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side.y = (data->map.y + 1.0 - data->hero.position.y) * \
		data->ray.delta.y;
	}
}

static void	ft_ray_hit(t_main *data)
{
	int	hit_flag;

	hit_flag = 0;
	while (!hit_flag)
	{
		if (data->ray.side.x < data->ray.side.y)
		{
			data->ray.side.x += data->ray.delta.x;
			data->map.x += data->ray.step_x;
			data->ray.hit_y = 0;
		}
		else
		{
			data->ray.side.y += data->ray.delta.y;
			data->map.y += data->ray.step_y;
			data->ray.hit_y = 1;
		}
		if (data->map.map[data->map.y][data->map.x] == '1')
			hit_flag = 1;
	}
}

static void	ft_define_ray(t_main *data)
{
	double	camera_x;

	camera_x = 2.0 * data->ray.num / WINDOW_WIDHT - 1.0;
	data->ray.dir.x = data->hero.direction.x + data->plane.x * camera_x;
	data->ray.dir.y = data->hero.direction.y + data->plane.y * camera_x;
	data->map.x = (int)data->hero.position.x;
	data->map.y = (int)data->hero.position.y;
	data->ray.delta.x = fabs(1 / data->ray.dir.x);
	data->ray.delta.y = fabs(1 / data->ray.dir.y);
	ft_define_side_step_x(data);
	ft_define_side_step_y(data);
}

void	ft_rendering_img(t_main *data)
{
	ft_set_color_ceil_floor(data);
	data->ray.num = 0;
	while (data->ray.num < WINDOW_WIDHT)
	{
		ft_define_ray(data);
		ft_ray_hit(data);
		ft_define_wall(data);
		ft_define_wall_x(data);
		ft_render_wall(data);
		data->ray.num++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, \
	data->mlx.img.img, 0, 0);
}
