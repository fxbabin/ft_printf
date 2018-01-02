/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:00:29 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 13:03:03 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!begin_list)
		return (0);
	tmp = begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
