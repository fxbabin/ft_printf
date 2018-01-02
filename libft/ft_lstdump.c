/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:53:28 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 16:13:16 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdump(t_list **list)
{
	t_list		*l;

	if (!list || !*list)
	{
		ft_putstr("(null)\n");
		return ;
	}
	l = *list;
	while ((*list))
	{
		if ((*list)->content)
			ft_putstr((char*)(*list)->content);
		else
			ft_putstr(" (null) ");
		ft_putstr(" -> ");
		*list = (*list)->next;
	}
	ft_putstr(" NULL\n");
	*list = l;
}
