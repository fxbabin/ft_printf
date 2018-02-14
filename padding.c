/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:32:33 by misteir           #+#    #+#             */
/*   Updated: 2018/02/14 01:25:01 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		ft_displaynode(t_printf *t)
{
	printf("prec -> %d\n", t->prec);
	printf("nb -> %d\n", t->nb);
	printf("flag -> %c\n", t->flag);
	printf("zero -> %d\n", t->zero);
	printf("plus -> %d\n", t->plus);
	printf("minus -> %d\n", t->minus);
	printf("hash -> %d\n", t->hash);
	printf("space -> %d\n", t->space);
	printf("mod1 -> %c\n", t->mod1);
	printf("mod2 -> %c\n", t->mod2);
	printf("neg -> %d\n", t->neg);

}

void		add_zeros(t_buff *b, t_printf *t, int len)
{
	int		n;

	n = 0;
	if (t->prec > 0 && ft_charinset(t->flag, "dDioOxXuU"))
		n = t->prec - len;
	else if (t->nb > 0 && t->zero == 1)
	{
		n = t->nb - len;
		n -= (t->neg || t->plus) ? 1 : 0;
		n -= (t->hash && ft_charinset(t->flag, "xX")) ? 2 : 0;
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
	if (t->zero == 1 || (t->prec > t->nb && !t->minus))
		return ;
	//ft_displaynode(t);
	n = t->nb - len;
	n -= (ft_charinset(t->flag, "idDoOxXuU") && t->prec > len) ? t->prec - len : 0;
	n -= (ft_charinset(t->flag, "idDoOxXuU") && (t->neg || t->plus || t->hash)) ? 1 : 0;
	n -= (t->hash && ft_charinset(t->flag, "xX")) ? 1 : 0;
	while (n-- > 0)
		bflush(b, " ", 1);
}

void		ft_padding_b(t_buff *b, t_printf *t, int len)
{
	if (!t->minus)
		add_spaces(b, t, len);
	if (!ft_charinset(t->flag, "sScC"))
	{
		if (t->hash && ft_charinset(t->flag, "oOxX"))
		{
			bflush(b, "0", 1);
			if (t->flag != 'o' && t->flag != 'O')
				bflush(b, &t->flag, 1);
		}
		if (t->neg)
			bflush(b, "-", 1);
		if (ft_charinset(t->flag, "dDi") && t->plus && !t->neg)
			bflush(b, "+", 1);
		add_zeros(b, t, len);
	}
}

void		ft_padding_a(t_buff *b, t_printf *t, int len)
{
	if (t->nb > 0 && t->minus)
		add_spaces(b, t, len);
}

void	ft_handle_other(t_buff *b, t_printf *t, char flag)
{
	ft_padding_b(b, t, 1);
	bflush(b, &flag, 1);
	ft_padding_a(b, t, 1);
}

void	ft_handler(t_buff *b, t_printf *t, va_list args)
{
	if (ft_charinset(t->flag, "sS"))
		ft_handle_wstr(b, t, args);
	else if (ft_charinset(t->flag, "cC"))
		ft_handle_wchar(b, t, args);
	else if (ft_charinset(t->flag, "dDi"))
		ft_handle_num(b, t, args);
	else if (ft_charinset(t->flag, "xXoOuU"))
		ft_handle_unum(b, t, args);
	else
		ft_handle_other(b, t, t->flag);
}
