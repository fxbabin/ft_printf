/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:40:56 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 15:14:30 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **begin_list)
{
	t_list		*tmp;

	if (!begin_list)
		return ;
	while (*begin_list)
	{
		tmp = (*begin_list)->next;
		free(*begin_list);
		*begin_list = tmp;
	}
}
