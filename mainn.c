/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misteir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 14:41:57 by misteir           #+#    #+#             */
/*   Updated: 2017/12/29 19:41:52 by misteir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	addzeros(char *buff, char *str, int nb)
{
	int		i;

	i = -1;
	while (nb-- > 0)
		ft_memcpy(buff + ++i, "0", 1);
}

void	addspaces(char *buff, char *str, int nb, int start)
{
	int		i;

	i = -1;
	while (nb-- > 0)
		ft_memcpy(buff + start + ++i, " ", 1);
}

int		main(void)
{
	char	buff[10];
	char	b[10];

	ft_strcpy((char*)&b, "tata");
	printf("%s\n", b);
	addspaces(buff, b, 8 - ft_strlen(b), 0);
	//ft_memcpy(buff, b, );
	printf("%s\n", buff);
	return (0);
}
