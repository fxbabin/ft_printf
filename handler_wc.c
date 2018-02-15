/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_wc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:10:52 by misteir           #+#    #+#             */
/*   Updated: 2018/02/15 23:27:22 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wcharlen(wchar_t wc)
{
	int		i;

	i = 0;
	if (wc < 0 || (wc >= 0xd800 && wc < 0xe000))
		return (0);
	if (MB_CUR_MAX == 1 && wc > 255)
		return (0);
	if ((wc <= 127 && MB_CUR_MAX >= 1) || (wc <= 255 && MB_CUR_MAX == 1))
		i = 1;
	else if (wc <= 2047 && MB_CUR_MAX >= 2)
		i = 2;
	else if (wc <= 65535 && MB_CUR_MAX >= 3)
		i = 3;
	else if (wc <= 1114111 && MB_CUR_MAX >= 4)
		i = 4;
	return (i);
}

void	ft_getwchar(t_buff *b, wchar_t wc, int len)
{
	char	tmp[5];

	ft_bzero(&tmp, 5);
	if ((wc <= 127 && MB_CUR_MAX >= 1) || (wc <= 255 && MB_CUR_MAX == 1))
		tmp[0] = wc;
	else if (wc <= 2047 && MB_CUR_MAX >= 2)
	{
		tmp[0] = (wc >> 6) | 0xC0;
		tmp[1] = (wc & 0x3F) | 0x80;
	}
	else if (wc <= 65535 && MB_CUR_MAX >= 3)
	{
		tmp[0] = (wc >> 12) | 0xE0;
		tmp[1] = (wc >> 6 & 0x3F) | 0x80;
		tmp[2] = (wc & 0x3F) | 0x80;
	}
	else if (wc <= 1114111 && MB_CUR_MAX >= 4)
	{
		tmp[0] = (wc >> 18) | 0xF0;
		tmp[1] = (wc >> 12 & 0x3F) | 0x80;
		tmp[2] = (wc >> 6 & 0x3F) | 0x80;
		tmp[3] = (wc & 0x3F) | 0x80;
	}
	bflush(b, (const char *)&tmp, len);
}

void	ft_handle_wchar(t_buff *b, t_printf *t, va_list args)
{
	wchar_t		tmp;
	int			wlen;

	if (t->flag == 'c' && t->mod1 != 'l')
	{
		if ((tmp = va_arg(args, int)) > 255)
			return ;
		ft_padding_b(b, t, 1);
		bflush(b, ((const char*)&tmp), 1);
		ft_padding_a(b, t, 1);
	}
	else if ((t->flag == 'c' && t->mod1 == 'l') || (t->flag == 'C'))
	{
		tmp = va_arg(args, wchar_t);
		wlen = ft_wcharlen(tmp);
		if (wlen == 0)
		{
			b->err = 1;
			b->pos -= b->err_len;
			return ;
		}
		ft_padding_b(b, t, wlen);
		ft_getwchar(b, tmp, wlen);
		ft_padding_a(b, t, wlen);
	}
}
