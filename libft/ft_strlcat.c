/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <shill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 19:27:21 by shill             #+#    #+#             */
/*   Updated: 2015/11/27 15:26:09 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		buff;

	buff = ft_strlen(src);
	i = 0;
	while (dst[i] && i < size)
		i++;
	if (i < size)
		buff = buff + i;
	else
		buff = buff + size;
	if ((int)(size - ft_strlen(dst) - 1) > 0)
		ft_strncat(dst, src, size - ft_strlen(dst) - 1);
	return (buff);
}
