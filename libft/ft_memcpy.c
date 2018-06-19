/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:07:19 by fbabin            #+#    #+#             */
/*   Updated: 2018/06/19 16:31:17 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while ((int)(i * 8) <= (int)(n - 8))
	{
		*((int64_t *)dst + i) = *((const int64_t *)src + i);
		i++;
	}
	i *= 2;
	if ((int)(i * 4) <= (int)(n - 4))
	{
		*((int *)dst + i) = *((const int *)src + i);
		i++;
	}
	i *= 4;
	while (i < n)
	{
		*((char *)dst + i) = *((const char *)src + i);
		i++;
	}
	return (dst);
}
