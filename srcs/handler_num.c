/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 10:33:11 by misteir           #+#    #+#             */
/*   Updated: 2018/06/19 16:41:04 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_getbase(char *base, char flag)
{
	ft_bzero(base, 17);
	if (flag == 'o' || flag == 'O')
		ft_memcpy(base, "01234567", 8);
	else if (flag == 'x' || flag == 'p')
		ft_memcpy(base, "0123456789abcdef", 16);
	else if (flag == 'X')
		ft_memcpy(base, "0123456789ABCDEF", 16);
	else if (flag == 'b')
		ft_memcpy(base, "01", 2);
	else
		ft_memcpy(base, "0123456789", 10);
}

long long			proper_cast(t_printf *t, va_list args)
{
	if (t->mod1 == 'j')
		return ((long long)va_arg(args, intmax_t));
	else if (t->mod1 == 'z')
		return ((long long)va_arg(args, size_t));
	else if (!(t->mod2) && (t->mod1 == 'h'))
		return ((long long)((short)va_arg(args, int)));
	else if (t->mod2 == 'h')
	{
		if (t->flag == 'D')
			return ((long long)((unsigned short)va_arg(args, int)));
		return ((long long)((char)va_arg(args, int)));
	}
	else if (!(t->mod2) && (t->mod1 == 'l'))
		return ((long long)va_arg(args, long));
	else if (t->mod2 == 'l')
		return ((long long)va_arg(args, long long));
	return ((long long)va_arg(args, int));
}

unsigned long long	proper_ucast(t_printf *t, va_list args)
{
	unsigned int	n;

	if (t->mod1 == 'j')
		return ((unsigned long long)va_arg(args, intmax_t));
	else if (t->mod1 == 'z')
		return ((unsigned long long)va_arg(args, size_t));
	else if (!(t->mod2) && (t->mod1 == 'h'))
		n = (unsigned int)((unsigned short)va_arg(args, unsigned int));
	else if (t->mod2 == 'h')
		n = (unsigned int)((unsigned char)va_arg(args, unsigned int));
	else if (!(t->mod2) && (t->mod1 == 'l'))
		return ((unsigned long long)va_arg(args, unsigned long));
	else if (t->mod2 == 'l')
		return ((unsigned long long)va_arg(args, unsigned long long));
	else
		n = (unsigned int)va_arg(args, unsigned int);
	return ((unsigned long long)n);
}

void				ft_handle_num(t_buff *b, t_printf *t, va_list args)
{
	char		str[21];
	int			len;

	t->mod1 = (t->flag < 96) ? 'l' : t->mod1;
	ft_bzero((char*)&str, 21);
	ft_lltoa_static((char*)&str, proper_cast(t, args));
	t->neg = (str[0] == '-') ? 1 : 0;
	len = ft_strlen(str) - t->neg;
	len = (t->prec == -1 && ft_atoi(str) == 0) ? 0 : len;
	ft_padding_b(b, t, len);
	bflush(b, (t->neg) ? str + 1 : str, len);
	ft_padding_a(b, t, len);
}

void				ft_handle_unum(t_buff *b, t_printf *t, va_list args)
{
	char		base[17];
	char		str[23];
	int			len;

	t->hash = (t->flag == 'p') ? 1 : t->hash;
	ft_getbase(base, t->flag);
	t->mod1 = (t->flag < 96 && t->flag != 'X') ? 'l' : t->mod1;
	t->mod2 = (t->flag < 96 && t->flag != 'X') ? 0 : t->mod2;
	t->mod1 = (t->flag == 'p') ? 'l' : t->mod1;
	ft_bzero((char*)&str, 23);
	ft_llutoa_base_static((char*)&str, proper_ucast(t, args), base);
	len = ft_strlen(str);
	len = (t->prec == -1 && ft_atoi(str) == 0 && str[0] == '0') ? 0 : len;
	len = (t->hash && (t->flag == 'o' || t->flag == 'O') &&
			ft_atoi(str) == 0 && str[0] == '0') ? 0 : len;
	t->hash = (!ft_charinset(t->flag, "poO") &&
			ft_atollu(str) == 0 && str[0] == '0') ? 0 : t->hash;
	ft_padding_b(b, t, len);
	bflush(b, str, len);
	ft_padding_a(b, t, len);
}
