/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:58:25 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/18 14:28:52 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpushback(t_list **begin_list, void *content, size_t cs)
{
	t_list		*tmp;

	if (!begin_list)
		return ;
	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstcreate(content, cs);
	}
	else
		*begin_list = ft_lstcreate(content, cs);
}
