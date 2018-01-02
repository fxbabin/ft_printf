/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 22:15:35 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/20 22:41:01 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_partition(int *array, int left, int right)
{
	int		pivot;

	pivot = array[(left + right) / 2];
	while (left <= right)
	{
		while (array[left] < pivot)
			left++;
		while (array[right] > pivot)
			right--;
		if (left <= right)
		{
			ft_swap(&(array[left]), &(array[right]));
			left++;
			right--;
		}
	}
	return (left);
}

void			ft_quicksort(int *array, int left, int right)
{
	int		index;

	if (left >= right || left < 0 || right < 0 || !array)
		return ;
	index = ft_partition(array, left, right);
	ft_quicksort(array, left, index - 1);
	ft_quicksort(array, index, right);
}
