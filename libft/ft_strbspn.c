/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 20:54:41 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/20 21:02:45 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		ft_strbspn(const char *s, const char *charset)
{
	int		i;

	i = -1;
	while (s[++i] && ft_charinset(s[i], charset))
		;
	if (!s[i])
		return (1);
	return (0);
}
