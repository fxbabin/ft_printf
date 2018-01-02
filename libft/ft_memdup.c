/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:08:51 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/20 23:05:22 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s, size_t i)
{
	void	*str;

	if (!s)
		return (NULL);
	if (!(str = (void*)malloc(i)))
		return (NULL);
	ft_memcpy(str, s, i);
	return (str);
}
