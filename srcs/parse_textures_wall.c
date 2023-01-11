/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:40:03 by adian             #+#    #+#             */
/*   Updated: 2022/12/13 13:50:15 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_define_texture_wall(t_main *data, char *path, int type)
{
	char	*tmp;
	int		len;

	tmp = path;
	len = ft_strlen(tmp);
	if (!ft_strcmp(tmp + len - LEN_EXTENSION, EXTENSION))
		data->textures[type].img = mlx_xpm_file_to_image(\
		data->mlx.mlx, path, (int *)&data->textures[type].widht, \
		(int *)&data->textures[type].height);
	else
		ft_end_program(data, ERROR_EXTENSION_TEXTURE, 1);
	if (!data->textures[type].img || \
	data->textures[type].widht != TEXTURE_SIZE || \
	data->textures[type].height != TEXTURE_SIZE)
		ft_end_program(data, ERROR_OPEN_TEXTURE, 1);
	data->textures[type].addr = (int *)mlx_get_data_addr(\
	data->textures[type].img, &data->textures[type].bits_per_pixel, \
	&data->textures[type].line_length, &data->textures[type].endian);
	if (!data->textures[type].addr)
		ft_end_program(data, ERROR_MLX_GET_DATA_ADDR, 1);
}

void	ft_parse_textures_wall(t_main *data, char *line)
{
	int	texture_type;
	int	i;

	texture_type = -1;
	if (!ft_strncmp(line, NO, ft_strlen(NO)))
		texture_type = TEXTURE_NO;
	else if (!ft_strncmp(line, SO, ft_strlen(SO)))
		texture_type = TEXTURE_SO;
	else if (!ft_strncmp(line, WE, ft_strlen(WE)))
		texture_type = TEXTURE_WE;
	else if (!ft_strncmp(line, EA, ft_strlen(EA)))
		texture_type = TEXTURE_EA;
	else
		ft_end_program(data, ERROR_INVALID_TEXTURE, 1);
	i = 2;
	if (!ft_strchr(SEP, *(line + i)))
		ft_end_program(data, ERROR_SEPARATOR_TEXTURE, 1);
	while (line && *(line + i) && ft_strchr(SEP, *(line + i)))
		i++;
	ft_define_texture_wall(data, line + i, texture_type);
	data->textures_lines++;
}
