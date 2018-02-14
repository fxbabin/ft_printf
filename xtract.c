/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtract.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:11:01 by fbabin            #+#    #+#             */
/*   Updated: 2018/02/14 23:40:43 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int		ft_xtract_number(const char *fmt)
{
	int		sign;
	int		a;

	a = 0;
	while (ft_isspace(*fmt) || *fmt == '+' || *fmt == '-' || *fmt == '#'
			|| *fmt == '0')
		fmt++;
	sign = (*fmt == '-') ? -1 : 1;
	fmt += (*fmt == '-' || *fmt == '+') ? 1 : 0;
	while (*fmt && ft_isdigit(*fmt))
		a = (a * 10) + (*(fmt++) - '0');
	return (sign * a);
}*/

static int		ft_xtract_number(const char *fmt)
{
	int		sign;
	int		a;

	a = 0;
	while (ft_isspace(*fmt) || *fmt == '+' || *fmt == '-' || *fmt == '#'
			|| *fmt == '0')
		fmt++;
	sign = (*fmt == '-') ? -1 : 1;
	fmt += (*fmt == '-' || *fmt == '+') ? 1 : 0;
	while (*fmt && ft_isdigit(*fmt))
		a = (a * 10) + (*(fmt++) - '0');
	return (sign * a);
}

static int		ft_xtract_float(const char *fmt)
{
	int		a;

	a = 0;
	while ((ft_isspace(*fmt) || *fmt == '+' || *fmt == '-' || *fmt == '#'
				|| ft_isdigit(*fmt)) && *fmt != '.')
		fmt++;
	if ((!*fmt || *fmt == '.') && (fmt[1] == '0' || !ft_isdigit(fmt[1])))
		return (-1);
	fmt++;
	fmt += (*fmt == '-' || *fmt == '+') ? 1 : 0;
	while (*fmt && ft_isdigit(*fmt))
		a = (a * 10) + (*(fmt++) - '0');
	return (a);
}

#include <stdio.h>

void            ft_displaynode(t_printf *t)
{
	printf("prec -> %d\n", t->prec);
	printf("nb -> %d\n", t->nb);
	printf("flag -> %c\n", t->flag);
	printf("zero -> %d\n", t->zero);
	printf("plus -> %d\n", t->plus);
	printf("minus -> %d\n", t->minus);
	printf("hash -> %d\n", t->hash);
	printf("wild -> %d\n", t->wild);
	printf("space -> %d\n", t->space);
	printf("mod1 -> %c\n", t->mod1);
	printf("mod2 -> %c\n", t->mod2);
	printf("neg -> %d\n", t->neg);

}

void		handle_wildcards(t_printf *t, va_list args, char before)
{
	int		nb;

	nb = va_arg(args, int);
	if (nb < 0 && before != '.')
		t->minus = 1;
	//nb = ft_abs(nb);
	if (before == '.')
	{
		t->wild = 2;
		if (nb < 0)
			t->prec = 0;
		else if (nb == 0)
			t->prec = -1;
		else
			t->prec = ft_abs(nb);
	}
	else
	{
		t->nb = ft_abs(nb);
		t->wild = 1;
	}
	//printf("\nbefore : %c nb %d prec %d tnb %d\n", before, nb, t->prec, t->nb);
}

int			ft_xtractor(t_printf *t, const char *fmt, va_list args)
{
	int			i;

	i = -1;
	ft_bzero(t, sizeof(t_printf));
	//ft_displaynode(t);
	while (fmt[++i] && ft_charinset(fmt[i], " *#+-.0123456789hljz"))
	{

		if (!(t->zero) && ft_isdigit(fmt[i]))
			t->zero = (fmt[i] > '0') ? 2 : 1;
		t->plus = (!(t->plus) && fmt[i] == '+') ? 1 : t->plus;
		t->minus = (!(t->minus) && fmt[i] == '-') ? 1 : t->minus;
		t->hash = (!(t->hash) && fmt[i] == '#') ? 1 : t->hash;
		t->space = (!(t->space) && fmt[i] == ' ') ? 1 : t->space;
		if (!(t->mod2) && (t->mod1) && ft_charinset(fmt[i], "hl"))
			t->mod2 = (fmt[i] == t->mod1) ? fmt[i] : t->mod2;
		if ((!(t->mod1) || fmt[i] == 'l') && ft_charinset(fmt[i], "hljz"))
			t->mod1 = fmt[i];
		if (fmt[i] == '*')
			handle_wildcards(t, args, (i == 0) ? 'a' : fmt[i - 1]);
		
		if (t->wild == 0)
		{
			t->prec = ft_xtract_float(fmt );
		}

	}
	t->flag = fmt[i];
	if (ft_charinset(t->flag, "dDioOxX") && t->prec == -1)
		t->zero = 0;
	if (t->mod1 != t->mod2)
		t->mod2 = 0;
	t->zero = (ft_charinset(t->flag, "idDuUoOxX") && (t->minus || t->prec > 0)) ? 0 : t->zero;
	if (t->wild == 0 || t->nb == 0)
		t->nb = ft_xtract_number(fmt);
	//t->nb = (t->prec > t->nb) ? 0 : t->nb;
	return (i);
}
