/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:23:11 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:23:16 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char			*tmp;

	tmp = dest;
	while (n-- && *src)
		*(dest++) = *(src++);
	while (n-- + 1)
		*(dest++) = '\0';
	return (tmp);
}
