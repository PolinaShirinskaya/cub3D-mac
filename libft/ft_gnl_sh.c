/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_sh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:57:35 by adian             #+#    #+#             */
/*   Updated: 2022/11/25 11:43:13 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gnl_sh(char **line, int memory, int fd)
{
	char	*buffer;
	char	ch;
	int		i;
	int		rb;

	i = 0;
	rb = 0;
	buffer = (char *)malloc(memory * sizeof(char));
	if (!buffer)
		return (-1);
	rb = read(fd, &ch, 1);
	while (rb && ch && ch != '\n')
	{
		if (ch && ch != '\n')
			buffer[i] = ch;
		rb = read(fd, &ch, 1);
		i++;
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = ft_strdup(buffer);
	free(buffer);
	return (rb);
}
