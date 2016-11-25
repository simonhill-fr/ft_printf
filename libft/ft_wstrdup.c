/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:20:35 by shill             #+#    #+#             */
/*   Updated: 2015/12/01 16:40:00 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_wchar	*ft_wstrdup(const t_wchar *s1)
{
	t_wchar	*buff;
	int		i;

	buff = malloc(sizeof(t_wchar) * (ft_wstrlen(s1) + 1));
	i = 0;
	if (!buff)
		return (0);
	while (s1[i] != L'\0')
	{
		buff[i] = s1[i];
		i++;
	}
	buff[i] = L'\0';
	return (buff);
}
