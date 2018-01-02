/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:39:20 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 20:20:40 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *fresh)
{
	t_list	*t;

	if (!alst || !fresh)
		return ;
	if (*alst)
	{
		t = fresh;
		t->next = (*alst);
		(*alst) = t;
	}
	else
		(*alst) = fresh;
}
