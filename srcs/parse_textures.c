/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:51:26 by adian             #+#    #+#             */
/*   Updated: 2022/12/13 13:50:24 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_check_uniqueness(t_main *data, char *texture)
{
	if (*texture == 'N' && !data->textures_flags.fl_no)
		data->textures_flags.fl_no = 1;
	else if (*texture == 'S' && !data->textures_flags.fl_so)
		data->textures_flags.fl_so = 1;
	else if (*texture == 'W' && !data->textures_flags.fl_we)
		data->textures_flags.fl_we = 1;
	else if (*texture == 'E' && !data->textures_flags.fl_ea)
		data->textures_flags.fl_ea = 1;
	else if (*texture == 'F' && !data->textures_flags.fl_f)
		data->textures_flags.fl_f = 1;
	else if (*texture == 'C' && !data->textures_flags.fl_c)
		data->textures_flags.fl_c = 1;
	else
		ft_end_program(data, ERROR_UNIQ_TEXTURES, 1);
}

void	ft_parse_textures(t_main *data)
{
	t_token	*tmp;

	tmp = data->tokens;
	while (tmp && data->textures_lines != FULL_TEXTURE)
	{
		if (tmp->type == TOKEN_TEXTURE)
		{
			ft_check_uniqueness(data, tmp->line2);
			if (*tmp->line2 == 'N' || *tmp->line2 == 'S' || \
			*tmp->line2 == 'E' || *tmp->line2 == 'W')
				ft_parse_textures_wall(data, tmp->line2);
			else if (*tmp->line2 == 'C' || *tmp->line2 == 'F')
				ft_parse_textures_floor_ceil(data, tmp->line2);
		}
		tmp = tmp->next;
	}
}
