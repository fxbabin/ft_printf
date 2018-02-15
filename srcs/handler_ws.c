/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 00:30:34 by misteir           #+#    #+#             */
/*   Updated: 2018/02/15 23:28:26 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_wstrlen(wchar_t *wstr, int prec)
{
	int		i;
	int		len;
	int		nc;

	i = -1;
	len = 0;
	nc = 0;
	while (wstr[++i])
	{
		len += ft_wcharlen(wstr[i]);
		if (prec > 0 && len >= prec)
			return ((len == prec) ? nc + 1 : nc);
		if (ft_wcharlen(wstr[i]) == 0)
			return (-1);
		nc++;
	}
	return (nc);
}

void			ft_handle_nullstr(t_buff *b, t_printf *t)
{
	int		len;

	len = (t->prec > 0 && t->prec < 6) ? t->prec : 6;
	len = (t->prec == -1) ? 0 : len;
	ft_padding_b(b, t, len);
	if (t->prec != -1)
		bflush(b, "(null)", len);
	ft_padding_a(b, t, len);
}

int				get_wlen(int prec, wchar_t *tmp, int t)
{
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (prec != -1 && tmp[++i] && t--)
		len += ft_wcharlen(tmp[i]);
	return (len);
}

void			ft_handle_wstr_2(t_buff *b, t_printf *t, va_list args)
{
	int			i;
	int			len;
	wchar_t		*tmp;
	int			slen;

	tmp = va_arg(args, wchar_t*);
	if (!tmp)
	{
		ft_handle_nullstr(b, t);
		return ;
	}
	i = -1;
	len = ft_wstrlen(tmp, t->prec);
	if (len == -1)
	{
		b->err = 1;
		b->pos -= b->err_len;
		return ;
	}
	slen = get_wlen(t->prec, tmp, len);
	ft_padding_b(b, t, slen);
	while (t->prec != -1 && tmp[++i] && len--)
		ft_getwchar(b, tmp[i], ft_wcharlen(tmp[i]));
	ft_padding_a(b, t, slen);
}

void			ft_handle_wstr(t_buff *b, t_printf *t, va_list args)
{
	int			len;
	char		*tm;

	if (t->mod1 != 'l' && t->flag == 's')
	{
		tm = va_arg(args, char*);
		if (!tm)
		{
			ft_handle_nullstr(b, t);
			return ;
		}
		len = (t->prec > 0 && t->prec < (int)ft_strlen(tm)) ?
			t->prec : ft_strlen(tm);
		len = (t->prec == -1) ? 0 : len;
		ft_padding_b(b, t, len);
		if (t->prec != -1)
			bflush(b, tm, len);
		ft_padding_a(b, t, len);
	}
	else
		ft_handle_wstr_2(b, t, args);
}
