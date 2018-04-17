/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 21:43:07 by misteir           #+#    #+#             */
/*   Updated: 2018/04/18 00:01:35 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		bflush(t_buff *b, const char *str, int n)
{
	int		i;

	i = 0;
	if (b->err == 1)
		return ;
	while ((b->pos + n) > BUFF_SIZE)
	{
		i = (BUFF_SIZE - b->pos);
		ft_memcpy((b->buff) + b->pos, str, i);
		if (b->sprintf)
			b->str = ft_strjoinclr(b->str, b->buff, 1);
		else
			write(b->fd, &(b->buff), b->pos + i);
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

void		ft_readf(const char *fmt, t_buff *b, va_list args)
{
	t_printf	t;
	int			idx;
	int			i;

	i = -1;
	idx = 0;
	while (fmt[++i])
	{
		if (fmt[i] == '%' && b->err == 0)
		{
			bflush(b, fmt, i);
			b->err_len = i;
			fmt += i + 1;
			idx = ft_xtractor(&t, fmt, args);
			if (!fmt[idx])
				break ;
			ft_handler(b, &t, args);
			fmt += idx + 1;
			i = -1;
		}
	}
	bflush(b, fmt, i);
}

int			ft_vfprintf(int fd, const char *format, va_list args)
{
	t_buff		b;

	if (!format)
		return (-1);
	ft_memset(&b, 0, sizeof(t_buff));
	b.fd = fd;
	ft_readf(format, &b, args);
	write(b.fd, &(b.buff), b.pos);
	return ((b.err == 1) ? -1 : b.len);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	int			ret;

	va_start(args, format);
	ret = ft_vfprintf(fd, format, args);
	va_end(args);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int			ret;

	va_start(args, format);
	ret = ft_vfprintf(1, format, args);
	va_end(args);
	return (ret);
}
