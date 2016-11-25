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
**	Returns number of bytes used by unicode wide-character
*/

#include "libft.h"

int		ft_wchar_bytes(t_wchar value)
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
