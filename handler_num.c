/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 10:33:11 by misteir           #+#    #+#             */
/*   Updated: 2017/12/31 12:09:24 by misteir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_getbase(char *base, char flag)
{
	ft_bzero(base, 16);
	if (flag == 'o')
		ft_memcpy(base, "01234567", 8);
	else if (flag == 'x')
		ft_memcpy(base, "0123456789abcdef", 16);
	else if (flag == 'X')
		ft_memcpy(base, "0123456789ABCDEF", 16);
	else
		ft_memcpy(base, "0123456789", 10);
}

char	*ft_handle_num(va_list args, t_printf *t)
{
	char		base[16];

	ft_getbase(base, t->flag);
	if (!(t->mod1))
		return (ft_itoa_base(va_arg(args, int), base));
	else if (!(t->mod2) && (t->mod1 == 'h'))
		return (ft_itoa_base((short)va_arg(args, int), base));
	else if (t->mod2 == 'h')
		return (ft_itoa_base((signed char)va_arg(args, int), base));
	else if (!(t->mod2) && (t->mod1 == 'l'))
		return (ft_ltoa_base(va_arg(args, long), base));
	else if (t->mod2 == 'l')
		return (ft_lltoa_base(va_arg(args, long long), base));
	else if (t->mod1 == 'j')
		return (ft_lltoa_base(va_arg(args, intmax_t), base));
	else if (t->mod1 == 'z')
		return (ft_lltoa_base(va_arg(args, size_t), base));
	return (NULL);
}
