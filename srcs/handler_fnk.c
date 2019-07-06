/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_fnk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 21:21:31 by fbabin            #+#    #+#             */
/*   Updated: 2019/07/06 14:15:00 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_other(t_buff *b, t_printf *t, char flag)
{
	ft_padding_b(b, t, 1);
	bflush(b, &flag, 1);
	ft_padding_a(b, t, 1);
}

void		ft_handle_colors_bis(t_buff *b, int nb, char end)
{
	char	str[23];

	ft_bzerop((char*)&str, 23);
	ft_lltoa_static((char *)&str, (long long)nb);
	bflush(b, str, ft_strlenp(str));
	bflush(b, &end, 1);
}

void		ft_handle_colors(t_buff *b, t_printf *t, va_list args)
{
	int		nb;

	nb = va_arg(args, int);
	nb = (nb > 0xffffff) ? 0xffffff : nb;
	(t->hash) ? bflush(b, "\e[3m", 4) : 0;
	(t->plus) ? bflush(b, "\e[1m", 4) : 0;
	(t->minus) ? bflush(b, "\e[4m", 4) : 0;
	if (nb == RESET)
		bflush(b, "\e[0;38;255;255;255m", 19);
	else
	{
		bflush(b, "\e[38;2;", 7);
		ft_handle_colors_bis(b, (nb & 0xff0000) >> (8 * 2), ';');
		ft_handle_colors_bis(b, (nb & 0xff00) >> (8), ';');
		ft_handle_colors_bis(b, (nb & 0xff), 'm');
	}
}

void		ft_handle_n(t_buff *b, t_printf *t, va_list args)
{
	void	*tmp;

	if (!(tmp = va_arg(args, void*)))
		return ;
	if (t->mod1 == 'j')
		*((intmax_t*)tmp) = ((intmax_t)b->len);
	else if (t->mod1 == 'z')
		*((size_t*)tmp) = ((size_t)b->len);
	else if (!(t->mod2) && (t->mod1 == 'h'))
		*((short*)tmp) = ((short)b->len);
	else if (t->mod2 == 'h')
		*((signed char*)tmp) = ((signed char)b->len);
	else if (!(t->mod2) && (t->mod1 == 'l'))
		*((long*)tmp) = ((long)b->len);
	else if (t->mod2 == 'l')
		*((long long*)tmp) = ((long long)b->len);
	else
		*((int*)tmp) = ((int)b->len);
}
