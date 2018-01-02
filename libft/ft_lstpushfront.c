/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:58:48 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/18 14:36:06 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpushfront(t_list **begin_list, void *content, size_t cs)
{
	t_list	*t;

	if (!begin_list)
		return ;
	if (*begin_list)
	{
		t = ft_lstcreate(content, cs);
		t->next = (*begin_list);
		(*begin_list) = t;
	}
	else
	{
		t = ft_lstcreate(content, cs);
		(*begin_list) = t;
	}
}
