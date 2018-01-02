/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strquicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:24:23 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 19:00:58 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_arrayswap(char **array, int a, int b)
{
	char	*c;

	c = array[a];
	array[a] = array[b];
	array[b] = c;
}

static int		ft_partition(char **array, int left, int right)
{
	char	*pivot;

	pivot = ft_strdup(array[(left + right) / 2]);
	while (left <= right)
	{
		while (ft_strcmp(array[left], pivot) < 0)
			left++;
		while (ft_strcmp(array[right], pivot) > 0)
			right--;
		if (left <= right)
		{
			ft_arrayswap(array, left, right);
			left++;
			right--;
		}
	}
	return (left);
}

void			ft_strquicksort(char **array, int left, int right)
{
	int		index;

	if (left >= right || left < 0 || right < 0 || !array || !*array)
		return ;
	index = ft_partition(array, left, right);
	ft_strquicksort(array, left, index - 1);
	ft_strquicksort(array, index, right);
}
