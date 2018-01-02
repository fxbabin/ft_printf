/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:05:40 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:05:45 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmp;
	const char		*s;

	tmp = (unsigned char*)dst;
	s = (const char*)src;
	while (n--)
	{
		*(tmp++) = *(s++);
		if (*(tmp - 1) == (unsigned char)c)
			return ((void*)tmp);
	}
	return (NULL);
}
