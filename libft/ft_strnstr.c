/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 14:10:01 by shill             #+#    #+#             */
/*   Updated: 2015/12/26 14:10:07 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (!(*s2))
		return ((char *)s1);
	if (!(*s1) || n == 0)
		return (NULL);
	if (*s1 == *s2)
	{
		if (ft_strnstr(s1 + 1, s2 + 1, n - 1) - 1 == s1)
			return ((char *)s1);
	}
	return (ft_strnstr(s1 + 1, s2, n - 1));
}
