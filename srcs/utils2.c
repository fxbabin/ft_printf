/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:30:29 by fbabin            #+#    #+#             */
/*   Updated: 2019/07/06 14:37:03 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_absp(int nb)
{
	return ((nb < 0) ? -nb : nb);
}

int						ft_isdigitp(int c)
{
	return (c >= '0' && c <= '9');
}

size_t					ft_strlenp(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

int						ft_atoip(const char *str)
{
	int					sign;
	int					a;
	unsigned long long	limit;

	limit = 0;
	a = 0;
	while (ft_isspacep(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	str += (*str == '-' || *str == '+') ? 1 : 0;
	while (*str && ft_isdigitp(*str))
	{
		limit = limit * 10 + (*(str) - '0');
		if (limit > 9223372036854775807)
			return ((sign == 1) ? -1 : 0);
		a = (a * 10) + (*(str++) - '0');
	}
	return (sign * a);
}

unsigned long long		ft_atollup(const char *str)
{
	int						sign;
	unsigned long long		a;

	a = 0;
	while (ft_isspacep(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	str += (*str == '-' || *str == '+') ? 1 : 0;
	while (*str && ft_isdigitp(*str))
		a = (a * 10) + (*(str++) - '0');
	return (sign * a);
}
