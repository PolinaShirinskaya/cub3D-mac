/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:56:49 by adian             #+#    #+#             */
/*   Updated: 2022/12/13 13:50:56 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_set_color_ceil_floor(t_main *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WINDOW_HEIGHT / 2)
	{
		j = -1;
		while (++j < WINDOW_WIDHT)
			my_mlx_pixel_put(data, j, i, data->ceil_color);
	}
	while (++i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDHT)
			my_mlx_pixel_put(data, j, i, data->floor_color);
	}
}

void	ft_define_wall(t_main *data)
{
	if (!data->ray.hit_y)
		data->wall.perp_distance = data->ray.side.x - data->ray.delta.x;
	else
		data->wall.perp_distance = data->ray.side.y - data->ray.delta.y;
	data->wall.height = (int)(WINDOW_HEIGHT / data->wall.perp_distance);
	data->wall.start = WINDOW_HEIGHT / 2 - data->wall.height / 2;
	if (data->wall.start < 0)
		data->wall.start = 0;
}

void	ft_define_wall_x(t_main *data)
{
	double	wall_x;

	if (!data->ray.hit_y)
		wall_x = data->hero.position.y + data->wall.perp_distance * \
		data->ray.dir.y;
	else
		wall_x = data->hero.position.x + data->wall.perp_distance * \
		data->ray.dir.x;
	wall_x -= floor(wall_x);
	data->wall.x = (int)(wall_x * TEXTURE_SIZE);
	if ((!data->ray.hit_y && data->ray.dir.x > 0)
		|| (data->ray.hit_y && data->ray.dir.y < 0))
		data->wall.x = TEXTURE_SIZE - data->wall.x - 1;
}

static int	ft_find_pixel_wall(t_main *data, int x, int y)
{
	int	*wall;

	if (!data->ray.hit_y)
	{
		if (data->ray.dir.x >= 0)
			wall = (int *)data->textures[TEXTURE_EA].addr;
		else
			wall = (int *)data->textures[TEXTURE_WE].addr;
	}
	else
	{
		if (data->ray.dir.y >= 0)
			wall = (int *)data->textures[TEXTURE_SO].addr;
		else
			wall = (int *)data->textures[TEXTURE_NO].addr;
	}
	return (wall[TEXTURE_SIZE * y + x]);
}

void	ft_render_wall(t_main *data)
{
	double	step_y;
	int		color;
	int		i;

	data->wall.y = 0;
	if (data->wall.perp_distance < 1)
		data->wall.y = (64.0 - 64.0 * data->wall.perp_distance) / 2;
	step_y = (double)TEXTURE_SIZE / (double)data->wall.height;
	i = 0;
	while (i < data->wall.height && i < WINDOW_HEIGHT)
	{
		color = ft_find_pixel_wall(data, data->wall.x, \
		(int)data->wall.y);
		my_mlx_pixel_put(data, data->ray.num, data->wall.start + i, color);
		data->wall.y += step_y;
		i++;
	}
}
