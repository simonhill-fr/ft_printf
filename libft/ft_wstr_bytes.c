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

/*
**	Returns number of bytes used by unicode wide-char string
*/

#include "libft.h"

size_t				ft_wstr_bytes(const t_wchar *str)
{
	int		i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (str[i] != L'\0')
	{
		ret += ft_wchar_bytes(str[i]);
		i++;
	}
	return (ret);
}
