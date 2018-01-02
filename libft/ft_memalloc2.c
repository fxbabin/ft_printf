/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:05:11 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:05:15 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		**ft_memalloc2(size_t size, size_t len)
{
	void	**t;
	size_t	i;

	i = -1;
	if (size < 1 || len < 1)
		return (NULL);
	if ((t = (void**)malloc(size * sizeof(void*))) == NULL)
		return (NULL);
	while (++i < size)
		if ((t[i] = (void*)malloc(len * sizeof(void))) == NULL)
			return (NULL);
	return (t);
}
