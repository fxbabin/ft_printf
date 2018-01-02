/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:26:27 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:26:31 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*nstr;
	int		len;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	while (len && (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		len--;
	if (!(nstr = ft_strnew(len)))
		return (NULL);
	s += i;
	i = -1;
	while (++i < len)
		nstr[i] = *(s++);
	nstr[i] = '\0';
	return (nstr);
}
