/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:32:33 by misteir           #+#    #+#             */
/*   Updated: 2018/01/03 13:30:51 by fbabin           ###   ########.fr       */
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

void	addspaces(t_printf *t, char *buff, int nb, int start)
{
	int		i;

	i = -1;
	nb -= (t->plus) ? 1 : 0;
	while (nb-- > 0)
		ft_memcpy(buff + start + ++i, " ", 1);
}

void	addzeros(t_printf*t, char *buff, int nb, int start)
{
	int		i;

	i = -1;
	if (t->prec > 0 && t->nb > t->prec && t->minus == 0 && !t->neg)
	{
		addspaces(t, buff, t->nb - t->prec, 0);
		start += t->nb - t->prec;
		start -= (t->plus && !t->neg) ? 1 : 0;
		nb += (t->plus) ? 1 : 0;
	}
	nb += (t->plus && t->minus) ? 1 : 0;
	if (t->plus && !t->neg && nb--)
		ft_memcpy(buff + start + ++i, "+", 1);
	if (t->neg && nb--)
		ft_memcpy(buff + start + ++i, "-", 1);
	nb += ((t->nb - t->prec) == 1 && t->neg) ? 1 : 0;
	nb += (t->prec > t->nb && t->neg) ? 1 : 0;
	while (nb-- > 0)
		ft_memcpy(buff + start + ++i, "0", 1);
}

void		copyarg(t_printf *t, t_buff *b, const char *arg, int len)
{
	char	buff[len + 1];
	int		slen;

	slen = (t->flag == 'c') ? 1 : ft_strlen(arg);
	ft_bzero(&buff, len + 1);
	(t->prec > slen && ft_charinset(t->flag, "pibdDxXoOuU")) ? addzeros(t, buff, t->prec - slen, 0) : NULL;
	(t->zero == 1 && t->nb - slen > (int)ft_strlen(buff)) ? addzeros(t, buff, t->nb - slen, ft_strlen(buff)) : NULL;
	(t->nb > t->prec && t->minus == 0 && !buff[0]) ? addspaces(t, buff, t->nb - slen, 0) : NULL;
	(t->space && !t->zero && ft_charinset(t->flag, "dD") && arg[0] != '-') ? addspaces(t, buff, 1, 0) : NULL;
	(t->plus && !t->zero && !t->prec && ft_charinset(t->flag, "dD") && arg[0] != '-') ? ft_memcpy(buff, "+", 1) : NULL;
	ft_memcpy(buff + ft_strlen(buff), arg, slen);
	(t->nb > 0 && t->minus) ? addspaces(t, buff, t->nb - slen, ft_strlen(buff)) : NULL;
	if (t->prec != -1)
		bflush(b, buff, len);
}

int			getarglen(t_printf *t, const char *arg)
{
	int		len;

	len = (t->flag == 'c') ? 1 : ft_strlen(arg);
	len += (ft_charinset(t->flag, "xX") && t->hash == 1) ? 2 : 0; 
	len += (ft_charinset(t->flag, "oO") && t->hash == 1) ? 1 : 0; 
	len += (t->plus == 1 && arg[0] != '-') ? 1 : 0; 
	len += (t->space == 1 && !t->plus && arg[0] != '-' && ft_charinset(t->flag, "d")) ? 1 : 0; 
	len = (ft_charinset(t->flag, "sS") && t->prec < len && t->prec > 0) ? t->prec : len;
	len = (ft_charinset(t->flag, "idDoOxX") && t->prec > len) ? t->prec : len;
	len += (t->neg) ? 1 : 0; 
	len += (t->nb > len) ? (t->nb - len) : 0;
	return (len);
}

char		*getarg(t_printf *t, va_list args)
{
	char	*str;

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
	return (str);
}

void		ft_handler(t_buff *b, const char *fmt, va_list args, int idx)
{
	t_printf	t;
	char		*arg;
	int			arglen;

	(void)b;
	ft_xtractor(&t, fmt, idx);
	if (!(arg = getarg(&t, args)))
		return ;
	arglen = getarglen(&t, arg);
	copyarg(&t, b, arg, arglen);
	free(arg);
}
