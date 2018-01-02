/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:30:03 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/02 21:57:58 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countll(unsigned long nb, int len, int neg)
{
	int		i;

	if (nb == 0)
		return (1);
	i = (neg == -1 && len == 10) ? 1 : 0;
	while (nb)
	{
		nb /= len;
		i++;
	}
	return (i);
}

char			*ft_lltoa_base(long long nb, const char *base)
{
	char		*str;
	int			i;
	int			neg;
	int			len;
	long long	x;

	x = (long long)nb;
	len = ft_strlen(base);
	neg = (nb < 0) ? -1 : 1;
	i = ft_countll(x, len, neg);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		str[i] = base[ft_abs(x % len)];
		x /= len;
	}
	if (neg < 0 && len == 10)
		str[0] = '-';
	return (str);
}
