/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:19:34 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:19:38 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (size <= s1_len)
		return (s2_len + size);
	i = s1_len;
	while (*s2 && i < (size - 1))
		s1[i++] = *(s2++);
	s1[i] = '\0';
	return (s1_len + s2_len);
}
