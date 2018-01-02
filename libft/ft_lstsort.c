/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:02:56 by fbabin            #+#    #+#             */
/*   Updated: 2017/12/18 14:37:12 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		**ft_lstalloc2(size_t size)
{
	t_list	**t;
	int		i;

	i = 0;
	if (size < 1)
		return (NULL);
	if ((t = (t_list**)malloc(size * sizeof(t_list*))) == NULL)
		return (NULL);
	ft_lstpushback(t, " ", 0);
	while (i++ < (int)size)
		ft_lstpushback(t, " ", 0);
	return (t);
}

static void			ft_merge(t_list **list, t_list **tmp, int left, int right)
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
		if (ft_strcmp(ft_lstatpos(*list, i)->content,
					ft_lstatpos(*list, j)->content) <= 0)
			ft_lstatpos(*tmp, k++)->content = ft_lstatpos(*list, i++)->content;
		else
			ft_lstatpos(*tmp, k++)->content = ft_lstatpos(*list, j++)->content;
	while (i <= mid)
		ft_lstatpos(*tmp, k++)->content = ft_lstatpos(*list, i++)->content;
	while (j <= right)
		ft_lstatpos(*tmp, k++)->content = ft_lstatpos(*list, j++)->content;
	while (--k >= 0)
		ft_lstatpos(*list, left + k)->content = ft_lstatpos(*tmp, k)->content;
}

static void			ft_sort(t_list **list, t_list **tmp, int left, int right)
{
	int		mid;

	if (left >= right)
		return ;
	mid = (right + left) / 2;
	ft_sort(list, tmp, left, mid);
	ft_sort(list, tmp, mid + 1, right);
	ft_merge(list, tmp, left, right);
}

void				ft_lstsort(t_list **list)
{
	t_list		**tmp;

	if (!list || !*list)
		return ;
	tmp = ft_lstalloc2(ft_lstsize(*list));
	ft_sort(list, tmp, 0, ft_lstsize(*list) - 1);
	free(tmp);
}
