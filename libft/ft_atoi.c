/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:24:08 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/09 21:27:05 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	int					a;
	unsigned long long	limit;

	limit = 0;
	a = 0;
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	str += (*str == '-' || *str == '+') ? 1 : 0;
	while (*str && ft_isdigit(*str))
	{
		limit = limit * 10 + (*(str) - '0');
		if (limit > 9223372036854775807)
			return ((sign == 1) ? -1 : 0);
		a = (a * 10) + (*(str++) - '0');
	}
	return (sign * a);
}
