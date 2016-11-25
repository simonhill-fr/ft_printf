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

/*
**	Warning : size 'n' is value in bytes, the number of characters to be
**	included in the string is 'len'
*/

#include "libft.h"

size_t		get_wstrlen(const t_wchar *s, int n)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != L'\0')
	{
		if (n - ft_wchar_bytes(s[i]) >= 0)
		{
			n -= ft_wchar_bytes(s[i]);
			i++;
		}
		else
			return (i);
	}
	return (i);
}

t_wchar		*ft_wstrndup(const t_wchar *s, size_t n)
{
	t_wchar		*buff;
	size_t		i;
	size_t		len;

	len = get_wstrlen(s, n);
	buff = malloc(sizeof(t_wchar) * (len + 1));
	i = 0;
	if (!buff)
		return (0);
	while (s[i] != L'\0' && i < len)
	{
		buff[i] = s[i];
		i++;
	}
	buff[i] = L'\0';
	return (buff);
}
