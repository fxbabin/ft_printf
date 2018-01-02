/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:10:14 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 19:03:25 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_merge(int **array, int **tmp, int left, int right)
{
	int		i;
	int		j;
	int		k;
	int		mid;

	mid = (right + left) / 2;
	i = left;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= right)
		if (*array[i] <= *array[j])
			*tmp[k++] = *array[i++];
		else
			*tmp[k++] = *array[j++];
	while (i <= mid)
		*tmp[k++] = *array[i++];
	while (j <= right)
		*tmp[k++] = *array[j++];
	while (--k >= 0)
		*array[left + k] = *tmp[k];
}

static void		ft_sort(int **array, int **tmp, int left, int right)
{
	int		mid;

	if (left >= right || left < 0 || right < 0)
		return ;
	mid = (right + left) / 2;
	ft_sort(array, tmp, left, mid);
	ft_sort(array, tmp, mid + 1, right);
	ft_merge(array, tmp, left, right);
}

void			ft_mergesort(int **array, int left, int right)
{
	int		**tmp;

	if (left < 0 || right < 0 || !array || !*array)
		return ;
	if (!(tmp = (int**)ft_memalloc2(right + 1, 1)))
		return ;
	ft_sort(array, tmp, left, right);
	free(tmp);
}
