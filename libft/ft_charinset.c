/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charinset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 21:30:58 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/01 21:31:32 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_charinset(char c, const char *charset)
{
	int		i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}
