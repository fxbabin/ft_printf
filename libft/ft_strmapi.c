/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:20:16 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:20:23 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*out;

	if (!s || !f)
		return (NULL);
	i = -1;
	if (!(out = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s && s[++i])
		out[i] = f(i, s[i]);
	out[i] = '\0';
	return (out);
}
