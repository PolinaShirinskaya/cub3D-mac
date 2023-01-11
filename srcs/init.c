/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:53:01 by adian             #+#    #+#             */
/*   Updated: 2022/12/13 13:43:36 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_define_default_data(t_main *data)
{
	data->ceil_color = DEF_CEIL_COLOR;
	data->floor_color = DEF_FLOOR_COLOR;
	data->map.height = 0;
	data->map.width = 0;
	data->map.x = 0;
	data->map.y = 0;
	data->textures_flags.fl_no = 0;
	data->textures_flags.fl_so = 0;
	data->textures_flags.fl_we = 0;
	data->textures_flags.fl_ea = 0;
	data->textures_flags.fl_f = 0;
	data->textures_flags.fl_c = 0;
	data->floor_color = 0;
	data->ceil_color = 0;
	data->hero.position = ft_set_point(0, 0);
	data->hero.direction = ft_set_point(0, 0);
	data->plane = ft_set_point(0, 0);
}

void	ft_init_mlx(t_main *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		ft_end_program(data, ERROR_MLX_INIT, 1);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, WINDOW_WIDHT, \
	WINDOW_HEIGHT, WINDOW_TITLE);
	if (!data->mlx.mlx_win)
		ft_end_program(data, ERROR_MLX_NEW_WINDOW, 1);
	data->mlx.img.img = mlx_new_image(data->mlx.mlx, WINDOW_WIDHT, \
	WINDOW_HEIGHT);
	if (!data->mlx.img.img)
		ft_end_program(data, ERROR_MLX_NEW_IMAGE, 1);
	data->mlx.img.addr = mlx_get_data_addr(data->mlx.img.img, \
	&data->mlx.img.bits_per_pixel, &data->mlx.img.line_length, \
	&data->mlx.img.endian);
	if (!data->mlx.img.addr)
		ft_end_program(data, ERROR_MLX_GET_DATA_ADDR, 1);
}

void	ft_init_data(t_main *data, char *filename)
{
	int	i;

	data->file.filename = filename;
	data->file.fd = 0;
	data->textures_lines = 0;
	data->mlx.mlx = NULL;
	data->mlx.mlx_win = NULL;
	data->mlx.img.img = NULL;
	data->mlx.img.addr = NULL;
	data->mlx.img.bits_per_pixel = 0;
	data->mlx.img.line_length = 0;
	data->mlx.img.endian = 0;
	data->tokens = NULL;
	i = -1;
	while (++i < WALL_TEXTURE)
	{
		data->textures[i].img = NULL;
		data->textures[i].addr = NULL;
	}
	data->map.map = NULL;
	data->map.fullmap = NULL;
}
