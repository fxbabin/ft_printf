/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:18:46 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/20 16:43:31 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(unsigned long long nb)
{
	int		i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char			*ft_llutoa(unsigned long long nb)
{
	char	*str;
	int		i;

	i = ft_count(nb);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		str[i] = ft_abs(nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
