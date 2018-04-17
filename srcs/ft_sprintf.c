/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 21:43:07 by misteir           #+#    #+#             */
/*   Updated: 2018/04/17 23:56:43 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_vsprintf(char **str, const char *format, va_list args)
{
	t_buff		b;

	if (!format)
		return (-1);
	ft_memset(&b, 0, sizeof(t_buff));
	if (!(*str = ft_strnew(0)))
		return (0);
	b.str = *str;
	b.sprintf = 1;
	ft_readf(format, &b, args);
	b.str = ft_strjoinclr(b.str, b.buff, 1);
	*str = b.str;
	return ((b.err == 1) ? -1 : b.len);
}

int			ft_sprintf(char **str, const char *format, ...)
{
	va_list		args;
	int			ret;

	va_start(args, format);
	ret = ft_vsprintf(str, format, args);
	va_end(args);
	return (ret);
}
