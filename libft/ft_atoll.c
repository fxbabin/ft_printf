/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:10:53 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/20 17:24:53 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoll(const char *str)
{
	int				sign;
	long long		a;

	a = 0;
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	str += (*str == '-' || *str == '+') ? 1 : 0;
	while (*str && ft_isdigit(*str))
		a = (a * 10) + (*(str++) - '0');
	return (sign * a);
}

#include <stdio.h>

int		main(void)
{
	int		i;

	i = -1;
	while (++i < 10)
	{
		printf("%lld ", ft_atoll(ft_lltoa(-9223372036854775803 - i)));
		printf("%lld\n", atoll(ft_lltoa(-9223372036854775803 - i)));
	}
	return (0);
}
