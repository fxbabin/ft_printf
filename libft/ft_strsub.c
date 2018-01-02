/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:26:11 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:26:17 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	char	*tmp;

	if (!s)
		return (NULL);
	if (!(out = ft_strnew(len)))
		return (NULL);
	tmp = out;
	while (len-- && *(s + start))
		*(out++) = *(s++ + start);
	return (tmp);
}
