/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:24:56 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:25:00 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	if (*(s + len) == (char)c)
		return ((char*)s + len);
	while (len--)
	{
		if (*(s + len) == (unsigned char)c)
			return ((char*)s + len);
	}
	return (NULL);
}
