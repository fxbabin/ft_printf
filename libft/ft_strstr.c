/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:25:56 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:26:01 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;

	if (!*s2)
		return ((char*)s1);
	while (*s1)
	{
		i = 0;
		while (s1[i] && s2[i] && s1[i] == s2[i])
			i++;
		if (s2[i] == '\0')
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
