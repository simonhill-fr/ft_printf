/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:13:28 by shill             #+#    #+#             */
/*   Updated: 2016/11/03 11:13:31 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ftab_cast	*init_cast_array(void)
{
	t_ftab_cast	*ftab_cast;

	ftab_cast = malloc(sizeof(t_ftab_cast) * 7);

	ftab_cast[INT] = cast_uint;
	ftab_cast[CHAR] = cast_uint;
	ftab_cast[SHORT] = cast_uint;
	ftab_cast[LONG] = cast_ulong;
	ftab_cast[LONG_LONG] = cast_ulonglong;
	ftab_cast[SIZE_T] = cast_sizet;
	ftab_cast[INTMAX] = cast_uintmax;

	return (ftab_cast);

}



uintmax_t cast_uint(va_list ap)
{
	return (va_arg(ap, unsigned int));
}

uintmax_t cast_ulong(va_list ap)
{
	return (va_arg(ap, unsigned long));
}

uintmax_t cast_ulonglong(va_list ap)
{
	return (va_arg(ap, unsigned long long));
}

uintmax_t cast_sizet(va_list ap)
{
	return (va_arg(ap, size_t));
}

uintmax_t cast_uintmax(va_list ap)
{
	return (va_arg(ap, uintmax_t));
}

