/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:32:33 by misteir           #+#    #+#             */
/*   Updated: 2018/01/03 00:03:00 by fbabin           ###   ########.fr       */
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
	//if (arg[0] == '-')
	//	ft_memcpy(buff + ++i, "-", 1);
	if (t->prec > 0 && t->prec < t->nb && t->minus == 0)
	{
		
		addspaces(t, buff, t->nb - t->prec, 0);
		start += t->nb - t->prec;
		start -= (t->plus && !t->neg) ? 1 : 0;
		//start -= (!t->plus && t->neg) ? 1 : 0;
		nb += (t->plus) ? 1 : 0;
		//nb++;
	}
	//start -= (t->plus && !t->neg) ? 1 : 0;
	//nb -= (t->plus && t->nb < t->prec) ? 0 : 1;
	nb += (t->plus && t->minus) ? 1 : 0;
	if (t->plus && !t->neg && nb--)
		ft_memcpy(buff + start + ++i, "+", 1);
	if (t->neg && nb--)
		ft_memcpy(buff + start + ++i, "-", 1);
	while (nb-- > 0)
		ft_memcpy(buff + start + ++i, "0", 1);
}

/*void		s(char *str, const char *arg, int i1, int i2)
  {
  str[i1] = '-';
  str[i2] = '0';
  (void)arg;
  }*/

void		copyarg(t_printf *t, t_buff *b, const char *arg, int len)
{
	char	buff[len + 1];
	int		slen;
	//int		x;

	slen = (t->flag == 'c') ? 1 : ft_strlen(arg);
	//x = (t->nb > 0 && t->minus == 0) ? t->nb - slen : 0;
	//x += (t->space) ? 1 : 0;
	ft_bzero(&buff, len + 1);
	//if (t->prec)
	//	addzeros(&buff, arg
	//(t->prec > 0 && t->nb > t->prec && ft_charinset(t->flag, "pibdDxXoOuU")) ? addspaces(buff, t->nb - t->prec, 0) : NULL;
	(t->prec > slen && ft_charinset(t->flag, "pibdDxXoOuU")) ? addzeros(t, buff, t->prec - slen, 0) : NULL;
	(t->zero == 1 && t->nb - slen > (int)ft_strlen(buff)) ? addzeros(t, buff, t->nb - slen, ft_strlen(buff)) : NULL;
	//printf("|%s|\n", buff);
	(t->nb > t->prec && t->minus == 0 && !buff[0]) ? addspaces(t, buff, t->nb - slen, 0) : NULL;
	
	//ft_displaynode(t);
	(t->space && !t->zero && ft_charinset(t->flag, "dD") && arg[0] != '-') ? addspaces(t, buff, 1, 0) : NULL;
	(t->plus && !t->zero && !t->prec && ft_charinset(t->flag, "dD") && arg[0] != '-') ? ft_memcpy(buff, "+", 1) : NULL;
	//(t->zero == 1 && arg[0] == '-' && buff[0] == '0') ? s(buff, arg, 0, ft_strspn(buff, "-")) : NULL ;
	//(t->neg == 1) ? ft_memcpy(buff, "-", 1) : NULL;
	//printf("%s\n", buff);
	ft_memcpy(buff + ft_strlen(buff), arg, slen);
	//printf("%s\n", buff);
	//(t->prec > 0 && ft_charinset(t->flag, "pibdDxXoOuU")) ? ft_memcpy(buff + t->prec - slen, arg, slen) : NULL;
	(t->nb > 0 && t->minus) ? addspaces(t, buff, t->nb - slen, ft_strlen(buff)) : NULL;
	//printf("%s %d\n", buff, slen);
	bflush(b, buff, len);
	//printf("%d %d\n", len, b->pos);
	//printf("%s\n", (char*) &buff);
}

int			getarglen(t_printf *t, const char *arg)
{
	int		len;

	len = (t->flag == 'c') ? 1 : ft_strlen(arg);
	len += (ft_charinset(t->flag, "xX") && t->hash == 1) ? 2 : 0; 
	len += (ft_charinset(t->flag, "oO") && t->hash == 1) ? 1 : 0; 
	len += (t->plus == 1 && arg[0] != '-') ? 1 : 0; 
	//len += (t->neg == 1) ? 1 : 0; 
	len += (t->space == 1 && !t->plus && arg[0] != '-' && ft_charinset(t->flag, "d")) ? 1 : 0; 
	len = (ft_charinset(t->flag, "sS") && t->prec < len && t->prec > 0) ? t->prec : len;
	len = (ft_charinset(t->flag, "idDoOxX") && t->prec > len) ? t->prec : len;
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
	//printf("%s %d\n", str, t->prec);
	t->neg = (str[0] == '-' && ft_charinset(t->flag, "dD") && t->zero == 1 && t->nb > (int)ft_strlen(str)) ? 1 : 0;
	//printf("%s\n", str);
	(t->neg) ? ft_memcpy(str, str + 1, ft_strlen(str)) : NULL;
	//printf("%s\n", str);
	if (t->prec > 0 && t->prec < (int)ft_strlen(str) && ft_charinset(t->flag, "sS"))
		str[t->prec] = '\0';
	//printf("%s %d\n", str, t->prec);
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
	//printf("%s %d\n", arg, arglen);
	//printf("%d\n", arglen);
	copyarg(&t, b, arg, arglen);
	//printf("%s\n", arg);
	//printf("%s\n", va_arg(args, char*));
	free(arg);
}
