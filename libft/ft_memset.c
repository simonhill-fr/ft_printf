/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:15:38 by shill             #+#    #+#             */
/*   Updated: 2015/11/28 18:44:44 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*i;
	size_t			index;

	i = (unsigned char *)b;
	index = 0;
	while (index < len)
	{
		*i = (unsigned char)c;
		i++;
		index++;
	}
	return (b);
}
