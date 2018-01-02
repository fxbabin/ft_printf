/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:52:16 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/18 14:36:39 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstcreate(void *content, size_t cs)
{
	t_list	*t;

	if ((t = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	t->content = content;
	t->content_size = cs;
	t->next = NULL;
	return (t);
}
