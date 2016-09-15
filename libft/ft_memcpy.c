/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:56:14 by shill             #+#    #+#             */
/*   Updated: 2015/12/27 12:29:01 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*b;
	char	*c;
	size_t	i;

	b = (char*)dst;
	c = (char*)src;
	i = 0;
	while (i < n)
	{
		*b = *c;
		b++;
		c++;
		i++;
	}
	return (dst);
}
