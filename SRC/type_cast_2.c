/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_cast_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:20:50 by shill             #+#    #+#             */
/*   Updated: 2016/11/24 17:20:52 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	cast_longlong(va_list ap, int is_signed)
{
	if (is_signed == TRUE)
		return (va_arg(ap, long long));
	else
		return (va_arg(ap, unsigned long long));
}

uintmax_t	cast_sizet(va_list ap, int is_signed)
{
	(void)is_signed;
	return (va_arg(ap, size_t));
}

uintmax_t	cast_intmax(va_list ap, int is_signed)
{
	if (is_signed == TRUE)
		return (va_arg(ap, intmax_t));
	else
		return (va_arg(ap, uintmax_t));
}
