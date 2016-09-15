/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 12:24:05 by shill             #+#    #+#             */
/*   Updated: 2015/12/27 12:24:12 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*buf;

	buf = (char *)s;
	len = ft_strlen((char *)s);
	while (len != 0 && buf[len] != (char)c)
		len--;
	if (buf[len] == (char)c)
		return (&buf[len]);
	return (NULL);
}
