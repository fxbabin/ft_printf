/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:32:33 by misteir           #+#    #+#             */
/*   Updated: 2018/02/15 23:47:59 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_zeros(t_buff *b, t_printf *t, int len)
{
	int		n;

	n = 0;
	if (t->prec > 0 && ft_charinset(t->flag, "dDioOxXuUp"))
		n = t->prec - len;
	else if (t->nb > 0 && t->zero == 1)
	{
		n = t->nb - len;
		n -= (t->neg || t->plus) ? 1 : 0;
		n -= (t->hash && ft_charinset(t->flag, "xXp")) ? 2 : 0;
	}
	n -= (t->hash && ft_charinset(t->flag, "oO")) ? 1 : 0;
	while (n-- > 0)
		bflush(b, "0", 1);
}

void		add_spaces(t_buff *b, t_printf *t, int len)
{
	int		n;

	if (ft_charinset(t->flag, "dDi") && t->space && t->neg == 0 && t->plus == 0)
	{
		bflush(b, " ", 1);
		t->nb--;
	}
	if (t->zero == 1)
		return ;
	n = t->nb - len;
	n += (len == 0 && t->hash && !t->zero && (t->flag == 'o')) ? 1 : 0;
	n -= (ft_charinset(t->flag, "idDoOxXuU")
		&& t->prec > len) ? t->prec - len : 0;
	n -= (ft_charinset(t->flag, "idoODxXuUp")
		&& (t->neg || t->plus || t->hash)) ? 1 : 0;
	n -= (t->hash && ft_charinset(t->flag, "pxX")) ? 1 : 0;
	while (n-- > 0)
		bflush(b, " ", 1);
}

void		ft_padding_b(t_buff *b, t_printf *t, int len)
{
	if (!t->minus)
		add_spaces(b, t, len);
	if (t->hash && ft_charinset(t->flag, "oOxXp"))
	{
		bflush(b, "0", 1);
		if (t->flag != 'o' && t->flag != 'O' && t->flag != 'p')
			bflush(b, &t->flag, 1);
		if (t->flag == 'p')
			bflush(b, "x", 1);
	}
	if (t->neg)
		bflush(b, "-", 1);
	if (ft_charinset(t->flag, "dDi") && t->plus && !t->neg)
		bflush(b, "+", 1);
	add_zeros(b, t, len);
}

void		ft_padding_a(t_buff *b, t_printf *t, int len)
{
	if (t->nb > 0 && t->minus)
		add_spaces(b, t, len);
}

void		ft_handler(t_buff *b, t_printf *t, va_list args)
{
	if (ft_charinset(t->flag, "sS"))
		ft_handle_wstr(b, t, args);
	else if (ft_charinset(t->flag, "cC"))
		ft_handle_wchar(b, t, args);
	else if (ft_charinset(t->flag, "dDi"))
		ft_handle_num(b, t, args);
	else if (ft_charinset(t->flag, "xXoOuUpb"))
		ft_handle_unum(b, t, args);
	else if (ft_charinset(t->flag, "fF"))
		ft_handle_float(b, t, args);
	else if (ft_charinset(t->flag, "k"))
		ft_handle_colors(b, t, args);
	else if (ft_charinset(t->flag, "n"))
		ft_handle_n(b, t, args);
	else
		ft_handle_other(b, t, t->flag);
}
