/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:37:54 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/20 20:55:44 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcspn(const char *s, const char *charset)
{
	int		i;

	i = -1;
	while (s[++i] && !ft_charinset(s[i], charset))
		;
	return (i);
}
