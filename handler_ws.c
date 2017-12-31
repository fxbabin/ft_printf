/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 00:30:34 by misteir           #+#    #+#             */
/*   Updated: 2017/12/30 00:43:45 by misteir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_wstrlen(wchar_t *wstr)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (wstr[++i])
	{
		if (ft_wcharlen(wstr[i]) == 0)
			return (-1);
		len += ft_wcharlen(wstr[i]);
	}
	return (len);
}

static char		*ft_getwstr(wchar_t *wstr)
{
	char	*str;
	char	*tmp;
	int		i;

	i = -1;
	if (!(str = ft_strnew(ft_wstrlen(wstr))))
		return (NULL);
	while (wstr[++i])
	{
		tmp = ft_getwchar(wstr[i]);
		ft_strcat(str, tmp);
		free(tmp);
	}
	return (str);
}

/*char	*ft_handle_str(va_list args, t_printf *t)
{
	char	*str;

	(void)t;
	if (t->mod1 == 'l')
		return (ft_handle_wstr(args, t));
	str = va_arg(args, char*);
	if (str)
		return (ft_strdup(str));
	return (ft_strdup("(null)"));
}*/

char			*ft_handle_wstr(va_list args, t_printf *t)
{
	wchar_t		*tmp;
	char		*tm;
	int			i;
	int			y;

	i = -1;
	y = 0;
	if (t->mod1 != 'l' && t->flag == 's')
	{
		tm = va_arg(args, char*);
		if (!tm)
			return (ft_strdup("(null)"));
		return (ft_strdup(tm));
	}
	tmp = va_arg(args, wchar_t*);
	if (!tmp)
		return (ft_strdup("(null)"));
	if (ft_wstrlen(tmp) == -1)
		return (NULL);
	while (tmp[++i])
	{
		if ((y + ft_wcharlen(tmp[i])) > t->prec)
			break ;
		else
			y += ft_wcharlen(tmp[i]);
	}
	t->prec = (t->prec != -1) ? y : t->prec;
	return (ft_getwstr(tmp));
}
