/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:14:33 by fbabin            #+#    #+#             */
/*   Updated: 2017/11/14 16:46:33 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_in(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}

static int		ft_wordnb(char *str, char *charset)
{
	int	w;
	int	i;

	w = 0;
	i = -1;
	while (str[++i])
		if ((ft_in(str[i], charset) == 0) && ((ft_in(str[i + 1], charset) == 1)
					|| str[i + 1] == '\0'))
			w++;
	return (w);
}

static int		ft_assign(char **tab, char *str, int z, char *charset)
{
	int	i;
	int	s;
	int	w;

	w = 0;
	s = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_in(str[i], charset) == 0)
			s++;
		if ((s > 0) && ((ft_in(str[i + 1], charset)) || str[i + 1] == '\0'))
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

char			**ft_split(char *str, char *charset)
{
	char	**tab;
	int		z;

	z = 0;
	if (!str || !charset)
		return (NULL);
	if ((tab = (char**)malloc((ft_wordnb(str, charset) + 1) * sizeof(char*)))
			== NULL)
		return (NULL);
	ft_assign(tab, str, z, charset);
	tab[ft_wordnb(str, charset)] = NULL;
	return (tab);
}
