/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:32:46 by adian             #+#    #+#             */
/*   Updated: 2022/10/18 20:36:44 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*first;

	if (!lst)
		return ;
	first = *lst;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	while ((*lst)->next)
		(*lst) = (*lst)->next;
	(*lst)->next = new;
	*lst = first;
}
