/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:23:27 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:23:32 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	const unsigned char		*tmp1;
	const unsigned char		*tmp2;

	if (!n || !s1 || !s2)
		return (1);
	tmp1 = (const unsigned char *)s1;
	tmp2 = (const unsigned char *)s2;
	while (n-- && (*tmp1 || *tmp2))
	{
		if (*tmp1 != *tmp2)
			return (0);
		tmp1++;
		tmp2++;
	}
	return (1);
}
