/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinclr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 21:31:48 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/01 21:32:22 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinclr(char *s1, char *s2, int b)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(str, s1);
	if (b == 0 || b == 1)
		free(s1);
	ft_strcat(str, s2);
	if (b == 0 || b == 2)
		free(s2);
	s1 = str;
	return (s1);
}
