/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:32:33 by misteir           #+#    #+#             */
/*   Updated: 2018/02/12 14:53:27 by fbabin           ###   ########.fr       */
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

void		add_spaces(t_buff *b, t_printf *t, int len)
{
	int		n;

	if (ft_charinset(t->flag, "sScC"))
	{
		n = t->nb - len;
		while (n-- > 0)
			bflush(b, " ", 1);
	}
}

void		ft_padding_b(t_buff *b, t_printf *t, int len)
{
	if (t->nb > 0 && !t->minus)
		add_spaces(b, t, len);
}

void		ft_padding_a(t_buff *b, t_printf *t, int len)
{
	if (t->nb > 0 && t->minus)
		add_spaces(b, t, len);
}

void	getarg(t_buff *b, t_printf *t, va_list args)
{
	if (ft_charinset(t->flag, "sS"))
		ft_handle_wstr(b, t, args);
	if (ft_charinset(t->flag, "cC"))
		ft_handle_wchar(b, t, args);
	//else
	//	ft_handle_other
	/*	char	*str;

		str = NULL;
		if (ft_charinset(t->flag, "cC"))
		str = ft_handle_wchar(args, t);
		else if (ft_charinset(t->flag, "sS"))
		str = ft_handle_wstr(args, t);
		else if (ft_charinset(t->flag, "dD"))
		str = ft_handle_num(args, t);
		else
		{
		str = ft_strdup(&(t->flag));
		str[1] = '\0';
		}
		t->neg = (str[0] == '-' && ft_charinset(t->flag, "dD") && ((t->zero == 1 && t->nb > (int)ft_strlen(str)) || t->prec > 0)) ? 1 : 0;
		(t->neg) ? ft_memcpy(str, str + 1, ft_strlen(str)) : NULL;
		if (t->prec > 0 && t->prec < (int)ft_strlen(str) && ft_charinset(t->flag, "sS"))
		str[t->prec] = '\0';
		return (str);*/
}

void		ft_handler(t_buff *b, t_printf *t, va_list args)
{
	(void)b;
	(void)t;
	(void)args;

	//char		*arg;
	//int			arglen;

	//ft_xtractor(&t, fmt, idx);
	getarg(b, t, args)
		/*	return ;
			arglen = getarglen(&t, arg);
			copyarg(&t, b, arg, arglen);
			free(arg);*/
		;
}
