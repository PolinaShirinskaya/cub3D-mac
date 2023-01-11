/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:26:48 by adian             #+#    #+#             */
/*   Updated: 2022/12/13 13:53:39 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_check_char(t_main *data, int i, int j)
{
	if (data->map.fullmap[i - 1][j] == ' ' || \
		data->map.fullmap[i + 1][j] == ' ' || \
		data->map.fullmap[i][j + 1] == ' ' || \
		data->map.fullmap[i][j - 1] == ' ')
		return (1);
	return (0);
}

void	ft_check_map_border(t_main *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (ft_strchr("0", data->map.map[i][j]))
			{
				if (i == 0 || j == 0 || (i == data->map.height - 1) || \
				(j == (int)ft_strlen(data->map.map[i - 1])))
					ft_end_program(data, ERROR_MAP_BORDER, 1);
				if (ft_check_char(data, i, j))
					ft_end_program(data, ERROR_MAP_BORDER, 1);
			}
		}
	}
}

void	ft_addition_map(t_main *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (data->map.fullmap[i][++j])
		{
			if (data->map.fullmap[i][j] == ' ')
				data->map.fullmap[i][j] = '1';
		}
	}
}
