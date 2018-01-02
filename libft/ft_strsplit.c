/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:25:38 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/08 22:25:43 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordnumber(const char *str, char c)
{
	int	w;
	int	i;

	w = 0;
	i = -1;
	while (str[++i])
		if ((str[i] != c) && (str[i + 1] == c || str[i + 1] == '\0'))
			w++;
	return (w);
}

static int		ft_assign(char **tab, const char *str, int z, char c)
{
	int	i;
	int	s;
	int	w;

	w = 0;
	s = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] != c)
			s++;
		if ((s > 0) && (str[i + 1] == c || str[i + 1] == '\0'))
		{
			if ((tab[w] = (char*)malloc((s + 1) * sizeof(char))) == NULL)
				return (0);
			z = -1;
			while (++z < s)
				tab[w][z] = str[i - s + z + 1];
			tab[w++][z] = '\0';
			s = 0;
		}
	}
	return (0);
}

char			**ft_strsplit(const char *str, char c)
{
	char	**tab;
	int		z;

	z = 0;
	if (!str)
		return (NULL);
	if ((tab = (char**)malloc((ft_wordnumber(str, c) + 1) * sizeof(char*)))
			== NULL)
		return (NULL);
	ft_assign(tab, str, z, c);
	tab[ft_wordnumber(str, c)] = NULL;
	return (tab);
}
