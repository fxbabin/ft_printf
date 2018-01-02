/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:22:46 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:22:50 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char		*tmp1;
	const unsigned char		*tmp2;

	tmp1 = (const unsigned char *)s1;
	tmp2 = (const unsigned char *)s2;
	while (n-- && (*tmp1 || *tmp2))
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		tmp1++;
		tmp2++;
	}
	return (0);
}
