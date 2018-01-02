/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:38:33 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/20 16:35:37 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(long long nb)
{
	int		i;

	if (nb == 0)
		return (1);
	i = (nb < 0) ? 1 : 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char			*ft_lltoa(long long nb)
{
	char	*str;
	int		i;
	int		neg;

	neg = (nb < 0) ? -1 : 1;
	i = ft_count(nb);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		str[i] = ft_abs(nb % 10) + '0';
		nb /= 10;
	}
	if (neg < 0)
		str[0] = '-';
	return (str);
}
