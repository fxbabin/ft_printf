/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 21:43:07 by misteir           #+#    #+#             */
/*   Updated: 2017/12/30 18:22:46 by misteir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_buff_init(t_buff *b)
{
	ft_bzero(b->buff, BUFF_SIZE + 1);
	b->len = 0;
	b->pos = 0;
}

void	bflush(t_buff *b, const char *str, int n)
{
	int		i;

	i = 0;
	while ((b->pos + n) > BUFF_SIZE)
	{
		i = (BUFF_SIZE - b->pos);
		ft_memcpy((b->buff) + b->pos, str, i);
		write(1, &(b->buff), b->pos + i);
		ft_bzero(b->buff, BUFF_SIZE + 1);
		b->pos = 0;
		b->len += i;
		str += i;
		n -= i;
	}
	ft_memcpy((b->buff) + b->pos, str, n);
	b->len += n;
	b->pos += n;
}


void	ft_readf(const char *fmt, t_buff *b, va_list args)
{
	int		idx;
	int		i;

	i = -1;
	idx = 0;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
		{
			bflush(b, fmt, i);
			fmt += i + 1;
			idx = ft_strspn(fmt, " #.+-0123456789lhzj");
			if (!fmt[idx])
				break ;
			ft_handler(b, fmt, args, idx);
			fmt += idx + 1;
			i = -1;
		}
	}
	bflush(b, fmt, i);
}

int		ft_printf(const char *format, ...)
{
	t_buff		b;
	va_list		args;

	ft_buff_init(&b);
	va_start(args, format);
	ft_readf(format, &b, args);
	va_end(args);
	write(1, &(b.buff), b.pos);
	return (b.len);
}
