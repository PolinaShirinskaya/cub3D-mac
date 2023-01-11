/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_two_array_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:49:42 by adian             #+#    #+#             */
/*   Updated: 2022/11/07 10:50:41 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**malloc_two_array_char(char **array)
{
	char	**res;
	int		i;

	res = (char **)malloc(sizeof(char *) * \
	(size_two_array_char(array) + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < size_two_array_char(array) + 1)
		res[i] = NULL;
	return (res);
}
