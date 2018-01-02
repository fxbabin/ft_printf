/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:59:57 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 13:06:48 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **begin_list)
{
	t_list		*p_prev;
	t_list		*p_next;

	p_prev = NULL;
	if (!begin_list || !*begin_list)
		return ;
	while (*begin_list)
	{
		p_next = (*begin_list)->next;
		(*begin_list)->next = p_prev;
		p_prev = (*begin_list);
		*begin_list = p_next;
	}
	*begin_list = p_prev;
}
