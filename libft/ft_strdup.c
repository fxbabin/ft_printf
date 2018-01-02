/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:18:08 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:18:12 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = -1;
	if ((str = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = -1;
	while (s[++i] && (str[i] = s[i]))
		;
	return (str);
}
