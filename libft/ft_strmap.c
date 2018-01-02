/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:20:03 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:20:07 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*out;
	int		i;

	i = -1;
	if (!s || !f)
		return (NULL);
	if (!(out = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s && s[++i])
		out[i] = f(s[i]);
	return (out);
}
