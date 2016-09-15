/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 20:54:10 by shill             #+#    #+#             */
/*   Updated: 2015/12/27 21:47:38 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int					i;
	unsigned long int	j;

	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
	{
		if (s[i] == '\0')
			return (ft_strdup(""));
		i++;
	}
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (i == 0 && j == ft_strlen(s) - 1)
		return (ft_strdup(s));
	j = j - i;
	return (ft_strsub(s, i, j + 1));
}
