/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:25:24 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:25:29 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*new;
	int		len;
	int		i;

	i = -1;
	len = -1;
	while (str[++len])
		;
	if ((new = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	while (len--)
		new[++i] = str[len];
	return (new);
}
