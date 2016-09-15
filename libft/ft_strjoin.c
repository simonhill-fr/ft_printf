/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 20:18:56 by shill             #+#    #+#             */
/*   Updated: 2015/12/27 20:30:02 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	join = ft_strnew(len);
	if (!join)
		return (0);
	join = ft_strcat(join, s1);
	join = ft_strcat(join, s2);
	return (join);
}
