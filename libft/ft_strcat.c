/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:14:51 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:14:57 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*tmp;

	tmp = s1;
	while (*s1 && *(s1++))
		;
	while (*s2 && (*s1++ = *s2++))
		;
	*s1 = '\0';
	return (tmp);
}
