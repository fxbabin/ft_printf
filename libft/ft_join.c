/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:35:39 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 16:53:28 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char **tab, char *sep)
{
	char	*str;
	int		i;
	int		y;
	int		x;

	i = -1;
	x = 1;
	if (!tab || !*tab || !sep)
		return (NULL);
	while (tab[++i])
	{
		y = -1;
		while (tab[i][++y])
			x++;
	}
	if (!(str = (char*)malloc(((i - 1) * ft_strlen(sep) + x) * sizeof(char))))
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		ft_strcat(str, tab[i]);
		if (tab[i + 1])
			ft_strcat(str, sep);
	}
	return (str);
}
