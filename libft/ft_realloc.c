/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:14:18 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:14:22 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!size && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if ((new = ft_memalloc(size)) == NULL)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new, ptr, size);
		ptr = NULL;
		free(ptr);
	}
	return (new);
}
