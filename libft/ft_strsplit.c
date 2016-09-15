/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 21:53:51 by shill             #+#    #+#             */
/*   Updated: 2015/12/27 21:54:20 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_len(char const *s, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = (char **)malloc(sizeof(char *) * (word_len(s, c) + 1));
	if (!tab)
		return (NULL);
	j = 0;
	k = 0;
	while (s[k])
	{
		while (s[k] == c)
			k++;
		i = k;
		while (s[k] && s[k] != c)
			k++;
		if (k > i)
		{
			tab[j] = ft_strndup(s + i, k - i);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
