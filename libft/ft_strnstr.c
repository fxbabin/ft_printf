/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:24:02 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:24:06 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (!*s1 || !n)
		return (NULL);
	if (!*s2)
		return ((char *)s1);
	while (*s1 && n-- >= ft_strlen(s2))
	{
		if (!ft_strncmp((char*)s1, (char*)s2, ft_strlen(s2)))
			return ((char*)s1);
		s1++;
	}
	return (0);
}
