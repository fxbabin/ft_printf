/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:25:10 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 16:52:38 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_matchlen(const char *str, const char *old)
{
	int		i;

	i = 0;
	while (str[i] && old[i] && str[i] == old[i])
		i++;
	return (i);
}

static int		ft_strocc(const char *s1, const char *s2)
{
	int		i;
	int		n;

	n = 0;
	while (*s1)
	{
		i = 0;
		while (s1[i] == s2[i])
			i++;
		if (s2[i] == '\0')
			n++;
		s1++;
	}
	return (n);
}

char			*ft_strreplace(char *str, const char *old, const char *fresh)
{
	char	*out;
	char	*tmp;
	int		i;
	int		n;

	if (!str || !old || !fresh)
		return (NULL);
	if ((out = ft_strnew(ft_strlen(str) - (ft_strocc(str, old) * ft_strlen(old))
		+ (ft_strocc(str, old) * ft_strlen(fresh)) + 1)) == NULL)
		return (NULL);
	tmp = out;
	while (*str)
	{
		i = ft_matchlen(str, old);
		if (old[i] == '\0')
		{
			n = -1;
			while (fresh[++n])
				*(out++) = fresh[n];
			str += i;
		}
		else
			*(out++) = *(str++);
	}
	return (tmp);
}
