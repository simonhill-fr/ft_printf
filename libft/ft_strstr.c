/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 01:11:44 by shill             #+#    #+#             */
/*   Updated: 2015/11/26 11:47:40 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(const char *str, const char *to_find, int i, int j)
{
	while (str[i] == to_find[j] && str[i] != '\0')
	{
		i++;
		j++;
	}
	if (to_find[j] == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i])
	{
		if (ft_check_char(str, to_find, i, j) == 1)
			return ((char*)str + i);
		else
			i++;
	}
	return (NULL);
}
