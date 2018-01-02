/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:56:51 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 19:08:34 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*out;

	if (!lst || !f)
		return (NULL);
	if ((tmp = ft_lstnew(lst->content, lst->content_size)) == NULL)
		return (NULL);
	tmp = f(lst);
	out = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	return (out);
}
