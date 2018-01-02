/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:40:34 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 15:27:42 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstatpos(t_list *begin_list, unsigned int nbr)
{
	unsigned int		i;
	t_list				*tmp;

	i = -1;
	if (!begin_list)
		return (begin_list);
	tmp = begin_list;
	while (++i < nbr)
	{
		if (tmp == NULL)
			return (NULL);
		tmp = tmp->next;
	}
	return (tmp);
}
