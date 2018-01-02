/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:57:18 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 16:10:52 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list **begin_list1, t_list *begin_list2)
{
	t_list		*tmp;

	if (!begin_list1 || !begin_list2)
		return ;
	tmp = *begin_list1;
	if (!tmp)
		tmp = begin_list2;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = begin_list2;
	}
}
