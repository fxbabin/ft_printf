/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:28:56 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/17 16:51:22 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_zeros(double nb, int prec)
{
	char	*str;
	int		i;
	int		x;

	i = -1;
	x = 0;
	if (!(str = ft_strnew(prec)))
		return (NULL);
	while (nb <= 0.1)
	{
		str[++i] = '0';
		nb *= 10;
		x++;
	}
	while (prec - x)
	{
		nb *= 10;
		str[++i] = (int)nb + 48;
		nb -= (int)nb;
		prec--;
		if (!(prec - x) && (int)(nb * 10) >= 5)
			str[i]++;
	}
	return (str);
}

char			*ft_ftoa(double nb, int prec)
{
	char		*str;
	double		dec;
	double		add;
	int			tmp;

	if (!(str = ft_strnew(0)))
		return (NULL);
	if (prec == 0)
		prec = 6;
	add = 0.1;
	tmp = prec;
	while (tmp--)
		add /= 10;
	nb += (nb < 0) ? -add : add;
	dec = nb - ((long long)nb);
	dec *= (nb < 0) ? -1 : 1;
	str = ft_strjoinclr(str, ft_lltoa((long long)nb), 0);
	if (prec)
	{
		str = ft_strjoinclr(str, ".", 1);
		str = ft_strjoinclr(str, ft_zeros(dec, prec), 0);
	}
	return (str);
}
