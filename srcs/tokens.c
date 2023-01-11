/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:00:15 by adian             #+#    #+#             */
/*   Updated: 2022/12/13 14:25:35 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_define_type_token(t_token *token)
{
	if (*token->line2 == 'N' || *token->line2 == 'S' || \
	*token->line2 == 'E' || *token->line2 == 'W' || \
	*token->line2 == 'C' || *token->line2 == 'F')
		return (TOKEN_TEXTURE);
	else
		return (TOKEN_MAP);
}

static int	ft_define_separate_token(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (!ft_strchr(SEP, str[i]))
			return (0);
	}
	return (1);
}

void	ft_prepare_tokens(t_main *data)
{
	t_token	*token;

	token = data->tokens;
	while (token)
	{
		if (ft_define_separate_token(token->line1))
			token->type = TOKEN_SEPARATORS;
		else
		{
			token->line2 = ft_strtrim(token->line1, SEP);
			if (!token->line2)
				ft_end_program(data, ERROR_FT_STRTRIM, 1);
			token->type = ft_define_type_token(token);
		}
		token = token->next;
	}
}
