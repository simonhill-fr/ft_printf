/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 18:17:03 by shill             #+#    #+#             */
/*   Updated: 2016/01/10 18:17:13 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar		*ft_wstrndup(const wchar *s, size_t n)
{
	wchar		*buff;
	size_t		i;

	buff = malloc(sizeof(wchar) * (n + 1));
	i = 0;
	if (!buff)
		return (0);
	while (s[i] != L'\0' || i >= n)
	{
		buff[i] = s[i];
		i++;
	}
	buff[i] = L'\0';
	return (buff);
}
