/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:58:29 by fbabin            #+#    #+#             */
/*   Updated: 2019/07/06 14:05:48 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memsetp(void *b, int c, size_t len)
{
	char	*tmp;

	tmp = (char*)b;
	while (len--)
		*(tmp++) = (unsigned char)c;
	return (b);
}

void	ft_bzerop(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while ((int)(i * 8) <= (int)(n - 8))
	{
		*((int64_t *)s + i) = 0;
		i++;
	}
	i *= 2;
	if ((int)(i * 4) <= (int)(n - 4))
	{
		*((int *)s + i) = 0;
		i++;
	}
	i *= 2;
	if ((int)(i * 2) <= (int)(n - 2))
	{
		*((short *)s + i) = 0;
		i++;
	}
	i *= 2;
	if (i < n)
		*((char *)s + i) = 0;
}

void	*ft_memcpyp(void *dst, const void *src, size_t n)
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

int		ft_charinsetp(char c, const char *charset)
{
	int		i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

int		ft_isspacep(char c)
{
	c = (unsigned char)c;
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\r')
		return (1);
	return (0);
}
