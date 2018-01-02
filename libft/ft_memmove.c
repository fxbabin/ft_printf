/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:09:06 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:09:11 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;

	if (dest <= src)
		ft_memcpy(dest, src, n);
	else
	{
		d = dest + n - 1;
		s = src + n - 1;
		while (n--)
			*(d--) = *(s--);
	}
	return (dest);
}
