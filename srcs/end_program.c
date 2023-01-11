/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:27:26 by adian             #+#    #+#             */
/*   Updated: 2022/12/13 13:37:17 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_mlx_elements(t_main *data)
{
	int	i;

	i = -1;
	while (++i < WALL_TEXTURE)
	{
		if (data->textures[i].img)
			mlx_destroy_image(data->mlx.mlx, data->textures[i].img);
	}
	if (data->mlx.img.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.img.img);
	if (data->mlx.mlx_win)
		mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
}

void	ft_end_program(t_main *data, char *error_mess, int error_num)
{
	(void)(data);
	if (data)
	{
		if (data->file.line)
			free (data->file.line);
		if (data->tokens)
			ft_free_tokens(data);
		if (data->map.map)
			free_two_array_char(data->map.map);
		if (data->map.fullmap)
			free_two_array_char(data->map.fullmap);
		free_mlx_elements(data);
	}
	if (error_num)
		ft_putstr_fd(error_mess, STDERR_FILENO);
	exit(error_num);
}
