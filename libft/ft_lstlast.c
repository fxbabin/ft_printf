/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:56:27 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 13:03:36 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *begin_list)
{
	if (!begin_list)
		return (begin_list);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}
