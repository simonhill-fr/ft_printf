/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrbytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:45:20 by shill             #+#    #+#             */
/*   Updated: 2016/11/23 15:45:22 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_bytes(unsigned int value)
{
 	size_t	i;

	if (value == 0)
		return (0);
	i = 1;
	while ((value /= 2))
		++i;
	if (i <= 7)
		return (1);
	else if (i <= 11)
		return (2);
	else if (i <= 16)
		return (3);
	else
		return (4);
}

size_t				ft_wstrbytes(const wchar *str)
{
	int		i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (str[i] != L'\0')
	{
		ret += get_bytes(str[i]);
		i++;
	}
	return (ret);
}
