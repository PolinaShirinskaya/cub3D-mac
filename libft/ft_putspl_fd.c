/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspl_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:11:20 by adian             #+#    #+#             */
/*   Updated: 2022/12/13 14:26:36 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putspl_fd(char **split, int fd)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (split[i])
	{
		len += write(fd, split[i], ft_strlen(split[i]));
		len += write(fd, "\n", 1);
		i++;
	}
	return (len);
}
