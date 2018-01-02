/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:59:28 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 20:02:18 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_begin(t_list **begin_list, void *content_ref, int (*cmp)())
{
	t_list		*l_next;

	while (cmp((*begin_list)->content, content_ref) == 0)
	{
		l_next = (*begin_list)->next;
		free(*begin_list);
		(*begin_list) = l_next;
	}
}

void			ft_lstremoveif(t_list **begin_list, void *content_ref,
					int (*cmp)())
{
	t_list		*l_tmp;
	t_list		*l_curr;
	t_list		*l_next;

	if (!begin_list || !*begin_list || !content_ref || !cmp)
		return ;
	ft_begin(begin_list, content_ref, cmp);
	l_curr = (*begin_list);
	l_next = (*begin_list)->next;
	while (l_next)
	{
		if (cmp(l_next->content, content_ref) == 0)
		{
			l_tmp = l_next;
			l_next = l_next->next;
			free(l_tmp);
			l_curr->next = l_next;
		}
		else
		{
			l_curr = l_next;
			l_next = l_next->next;
		}
	}
}
