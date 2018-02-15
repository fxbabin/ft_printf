/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtract.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:11:01 by fbabin            #+#    #+#             */
/*   Updated: 2018/02/15 23:44:28 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_xtract_number(t_printf *t, const char *fmt)
{
	int		i;
	int		a;

	a = 0;
	i = 0;
	if (fmt[i - 1] == '.')
		return (1);
	while (fmt[i] && ft_isdigit(fmt[i]))
		a = (a * 10) + (fmt[i++] - '0');
	t->nb = a;
	return (i);
}

static int		ft_xtract_float(t_printf *t, const char *fmt)
{
	int		i;
	int		a;

	a = 0;
	i = 1;
	if (!fmt[i] || (!ft_isdigit(fmt[i]) || fmt[i] == '0'))
	{
		t->prec = -1;
		return (i);
	}
	while (fmt[i] && ft_isdigit(fmt[i]))
		a = (a * 10) + (fmt[i++] - '0');
	t->prec = a;
	return (i);
}

void			handle_wildcards(t_printf *t, va_list args, char before)
{
	int		nb;

	nb = va_arg(args, int);
	if (nb < 0 && before != '.')
		t->minus = 1;
	if (before == '.')
	{
		if (nb < 0)
			t->prec = 0;
		else if (nb == 0)
			t->prec = -1;
		else
			t->prec = ft_abs(nb);
	}
	else
		t->nb = ft_abs(nb);
}

void			ft_xtractor_bis(t_printf *t, const char *fmt, va_list args,
					int *i)
{
	if (fmt[*i] == '.')
	{
		*i += ft_xtract_float(t, fmt + *i);
	}
	else if (ft_isdigit(fmt[*i]))
	{
		if (!(t->zero) && ft_isdigit(fmt[*i]))
			t->zero = (fmt[*i] > '0') ? 2 : 1;
		*i += ft_xtract_number(t, fmt + *i);
	}
	else
	{
		t->plus = (!(t->plus) && fmt[*i] == '+') ? 1 : t->plus;
		t->minus = (!(t->minus) && fmt[*i] == '-') ? 1 : t->minus;
		t->hash = (!(t->hash) && fmt[*i] == '#') ? 1 : t->hash;
		t->space = (!(t->space) && fmt[*i] == ' ') ? 1 : t->space;
		if (!(t->mod2) && (t->mod1) && ft_charinset(fmt[*i], "hl"))
			t->mod2 = (fmt[*i] == t->mod1) ? fmt[*i] : t->mod2;
		if ((!(t->mod1) || fmt[*i] == 'l') && ft_charinset(fmt[*i], "hljz"))
			t->mod1 = fmt[*i];
		if (fmt[*i] == '*')
			handle_wildcards(t, args, (*i == 0) ? 'a' : fmt[*i - 1]);
		*i = *i + 1;
	}
}

int				ft_xtractor(t_printf *t, const char *fmt, va_list args)
{
	int			i;

	i = 0;
	ft_bzero(t, sizeof(t_printf));
	while (fmt[i] && ft_charinset(fmt[i], " *#+-.0123456789hljz"))
		ft_xtractor_bis(t, fmt, args, &i);
	t->flag = fmt[i];
	if (ft_charinset(t->flag, "dDioOxX") && t->prec == -1)
		t->zero = 0;
	if (t->mod1 != t->mod2)
		t->mod2 = 0;
	t->zero = (ft_charinset(t->flag, "idDuUoOxX")
			&& (t->minus || t->prec > 0)) ? 0 : t->zero;
	return (i);
}
