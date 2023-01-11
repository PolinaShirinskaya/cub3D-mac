/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_two_array_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:52:45 by adian             #+#    #+#             */
/*   Updated: 2022/11/07 10:53:08 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_two_array_char(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array && array[i])
		{
			free (array[i]);
			i++;
		}
		free (array);
	}
}
