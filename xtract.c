/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtract.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:11:01 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/26 10:37:47 by misteir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void		ft_xtractor(t_printf *t, const char *fmt, int len)
{
	int			i;

	i = -1;
	ft_bzero(t, sizeof(t_printf));
	t->flag = fmt[ft_strspn(fmt, " #+-.0123456789hljz")];
	while (fmt[++i] && i < len)
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
		t->prec = ft_xtract_float(fmt);
	}
	if (t->prec == -1)
		t->zero = 0;
	if (t->mod1 != t->mod2)
		t->mod2 = 0;
	t->zero = (t->minus) ? 0 : t->zero;
	t->nb = ft_xtract_number(fmt);
	t->nb = (t->prec > t->nb) ? 0 : t->nb;
}
