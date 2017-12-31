/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_wc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:10:52 by misteir           #+#    #+#             */
/*   Updated: 2017/12/27 16:44:22 by misteir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		ft_wcharlen(wchar_t wc)
{
	int		i;

	i = 0;
	if (wc < 0 || (wc >= 0xd800 && wc < 0xe000))
		return (0);
	if (MB_CUR_MAX == 1 && wc > 255)
		return (0);
	if ((wc <= 127 && MB_CUR_MAX >= 1) || (wc <= 255 && MB_CUR_MAX == 1))
		i = 1;
	else if (wc <= 2047 && MB_CUR_MAX >= 2)
		i = 2;
	else if (wc <= 65535 && MB_CUR_MAX >= 3)
		i = 3;
	else if (wc <= 1114111 && MB_CUR_MAX >= 4)
		i = 4;
	return (i);
}

char	*ft_getwchar(wchar_t wc)
{
	char	*str;

	if (!(str = ft_strnew(ft_wcharlen(wc))))
		return (NULL);
	if ((wc <= 127 && MB_CUR_MAX >= 1) || (wc <= 255 && MB_CUR_MAX == 1))
		str[0] = wc;
	else if (wc <= 2047 && MB_CUR_MAX >= 2)
	{
		str[0] = (wc >> 6) | 0xC0;
		str[1] = (wc & 0x3F) | 0x80;
	}
	else if (wc <= 65535 && MB_CUR_MAX >= 3)
	{
		str[0] = (wc >> 12) | 0xE0;
		str[1] = (wc >> 6 & 0x3F) | 0x80;
		str[2] = (wc & 0x3F) | 0x80;
	}
	else if (wc <= 1114111 && MB_CUR_MAX >= 4)
	{
		str[0] = (wc >> 18) | 0xF0;
		str[1] = (wc >> 12 & 0x3F) | 0x80;
		str[2] = (wc >> 6 & 0x3F) | 0x80;
		str[3] = (wc & 0x3F) | 0x80;
	}
	return (str);
}

/*char	*ft_handle_char(va_list args, t_printf *t)
{
	char	*str;
	int		c;

	(void)t;
	if (t->mod1 == 'l')
		return (ft_handle_wchar(args, t));
	c = va_arg(args, int);
	if (c > 255)
		return (NULL);
	if (!(str = ft_strnew(1)))
		return (NULL);
	if (c == 0)
		c = -1;
	str[0] = c;
	return (str);
}*/

char	*ft_handle_wchar(va_list args, t_printf *t)
{
	wchar_t		tmp;

	if (t->flag == 'c' && t->mod1 != 'l')
	{
		tmp = va_arg(args, int);
		if (tmp > 255)
			return (NULL);
		return (ft_strdup((const char *)&tmp));
	}
	/*else if ((t->flag == 'c' && t->mod1 != 'l') || (t->flag == 'C'))
		tmp = va_arg(args, wchar_t);
	if (ft_wcharlen(tmp) == 0)
		return (NULL);
	
	return (ft_getwchar(tmp));*/
	return (NULL);
}
