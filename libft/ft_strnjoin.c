/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 01:09:54 by shill             #+#    #+#             */
/*   Updated: 2016/02/21 01:15:12 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*join;
	int		len;

	len = ft_strlen(s1) + n;
	join = ft_strnew(len);
	if (!join)
		return (0);
	join = ft_strcat(join, s1);
	join = ft_strncat(join, s2, n);
	return (join);
}
