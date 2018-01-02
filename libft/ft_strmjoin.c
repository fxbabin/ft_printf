/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:47:33 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/18 19:02:20 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmjoin(char *s1, const char *s2, int len1, int len2)
{
	char	*new;
	int		i;
	int		y;

	if (!(new = ft_strnew(len1 + len2)))
		return (NULL);
	i = -1;
	while (++i < len1)
		new[i] = s1[i];
	y = -1;
	while (++y < len2)
		new[i++] = s2[y];
	free(s1);
	return (new);
}
