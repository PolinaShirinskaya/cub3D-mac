/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_floor_ceil.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:22:21 by adian             #+#    #+#             */
/*   Updated: 2022/12/13 13:49:52 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_invalid_rgb(t_main *data, \
			char **tmp1, char **tmp2, char *mess)
{
	free_two_array_char(tmp1);
	free_two_array_char(tmp2);
	ft_end_program(data, mess, 1);
}

static char	**ft_prepare_rgb(t_main *data, char *line)
{
	char	**tmp1;
	char	**tmp2;
	int		i;

	tmp1 = ft_split(line, ',');
	tmp2 = malloc_two_array_char(tmp1);
	if (size_two_array_char(tmp1) != 3 || !tmp2)
		ft_invalid_rgb(data, tmp1, tmp2, ERROR_FORMAT_RGB);
	i = 0;
	while (tmp1 && tmp1[i])
	{
		tmp2[i] = ft_strtrim(tmp1[i], SEP);
		if (!tmp2[i])
			ft_invalid_rgb(data, tmp1, tmp2, ERROR_FT_STRTRIM);
		i++;
	}
	free_two_array_char(tmp1);
	return (tmp2);
}

static void	ft_define_rgb(t_main *data, char *line)
{
	char	**tmp;
	int		i;

	tmp = ft_prepare_rgb(data, line);
	i = 0;
	while (tmp && tmp[i])
	{
		if (!ft_str_isdigit(tmp[i]) || ft_strlen(tmp[i]) > 3)
		{
			free_two_array_char(tmp);
			ft_end_program(data, ERROR_FORMAT_RGB, 1);
		}
		i++;
	}
	data->colors.r = (unsigned int)ft_atoi(tmp[0]);
	data->colors.g = (unsigned int)ft_atoi(tmp[1]);
	data->colors.b = (unsigned int)ft_atoi(tmp[2]);
	free_two_array_char(tmp);
}

void	ft_parse_textures_floor_ceil(t_main *data, char *line)
{
	char	*tmp;

	tmp = line + 1;
	while (tmp && *tmp && ft_strchr(SEP, *tmp))
		tmp++;
	ft_define_rgb(data, tmp);
	if (data->colors.r > 255 || data->colors.g > 255 || \
	data->colors.b > 255)
		ft_end_program(data, ERROR_FORMAT_RGB, 1);
	if (*line == 'C')
		data->ceil_color = ((data->colors.r << 16) | \
		(data->colors.g << 8) | data->colors.b);
	else if (*line == 'F')
		data->floor_color = ((data->colors.r << 16) | \
		(data->colors.g << 8) | data->colors.b);
	data->textures_lines++;
}
