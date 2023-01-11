/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:15:27 by adian             #+#    #+#             */
/*   Updated: 2022/12/13 14:26:51 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_splfree(char **split)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (!split)
		return ;
	while (split[i])
		i++;
	while (k < i)
	{
		free(split[k]);
		split[k] = NULL;
		k++;
	}
	free(split);
	split = NULL;
}
