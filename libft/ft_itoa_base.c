/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:47:17 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/25 16:58:50 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int nb, int len)
{
	int		i;

	if (nb == 0)
		return (1);
	i = (nb < 0 && len == 10) ? 1 : 0;
	while (nb)
	{
		nb /= len;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int nb, const char *base)
{
	char	*str;
	int		i;
	int		neg;
	int		len;

	len = ft_strlen(base);
	neg = (nb < 0) ? -1 : 1;
	i = ft_count(nb, len);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		str[i] = base[ft_abs(nb % len)];
		nb /= len;
	}
	if (neg < 0 && len == 10)
		str[0] = '-';
	return (str);
}
