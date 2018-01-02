/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:13:41 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 14:57:19 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	int		i;

	i = -1;
	if (!s)
	{
		ft_putstr_fd("(null)\n", fd);
		return ;
	}
	while (s[++i])
		;
	write(fd, s, i);
}
