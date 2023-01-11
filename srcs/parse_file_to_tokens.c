/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_to_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:00:52 by adian             #+#    #+#             */
/*   Updated: 2022/12/13 13:48:01 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_check_gnl_res(t_main *data)
{
	if (data->file.res == -2)
		ft_end_program(data, ERROR_MALLOC_GNL, 1);
	else if (data->file.res == -1)
		ft_end_program(data, ERROR_GNL, 1);
}

static	void	ft_read_file(t_main *data)
{
	data->file.res = ft_gnl_sh(&data->file.line, 1000, data->file.fd);
	ft_check_gnl_res(data);
	if (data->file.line[ft_strlen(data->file.line) - 1] == '\n')
		data->file.line[ft_strlen(data->file.line) - 1] = '\0';
	while (data->file.res)
	{
		ft_add_token(&data->tokens, ft_new_token(data));
		data->file.res = ft_gnl_sh(&data->file.line, 1000, data->file.fd);
		ft_check_gnl_res(data);
		if (data->file.line[ft_strlen(data->file.line) - 1] == '\n')
				data->file.line[ft_strlen(data->file.line) - 1] = '\0';
	}
	ft_add_token(&data->tokens, ft_new_token(data));
	if (!data->tokens)
		ft_end_program(data, ERROR_EMPTY_FILE, 1);
}

static void	ft_skip_texture(t_main *data)
{
	t_token	*tmp;
	int		count_texture;

	tmp = data->tokens;
	count_texture = 0;
	while (1)
	{
		if (tmp->type == TOKEN_TEXTURE)
			count_texture++;
		else if (tmp->type == TOKEN_MAP && count_texture != FULL_TEXTURE)
			ft_end_program(data, ERROR_TEXTURE_AFTER_MAP, 1);
		else if (tmp->type == TOKEN_MAP && count_texture == FULL_TEXTURE)
			return ;
		tmp = tmp->next;
	}
}

static void	ft_map_is_continuous(t_main *data)
{
	t_token	*tmp;

	tmp = ft_find_token(&data->tokens, TOKEN_MAP);
	if (!tmp)
		return ;
	while (tmp)
	{
		if (tmp->type != TOKEN_MAP)
			ft_end_program(data, ERROR_DISCONTINUOUS_MAP, 1);
		tmp = tmp->next;
	}
}

void	ft_parse_file_to_tokens(t_main *data)
{
	ft_read_file(data);
	ft_prepare_tokens(data);
	if (ft_count_type_tokens(&data->tokens, TOKEN_TEXTURE) != FULL_TEXTURE)
		ft_end_program(data, ERROR_NOT_FULL_TEXTURE, 1);
	if (ft_count_type_tokens(&data->tokens, TOKEN_MAP) < 3)
		ft_end_program(data, ERROR_TOO_SMALL_MAP, 1);
	ft_skip_texture(data);
	ft_map_is_continuous(data);
}
