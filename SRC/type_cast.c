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

	ftab_cast[INT] = cast_int;
	ftab_cast[CHAR] = cast_char;
	ftab_cast[SHORT] = cast_short;
	ftab_cast[LONG] = cast_long;
	ftab_cast[LONG_LONG] = cast_longlong;
	ftab_cast[SIZE_T] = cast_sizet;
	ftab_cast[INTMAX] = cast_intmax;
	return (ftab_cast);
}



uintmax_t cast_int(va_list ap, int is_signed)
{
	if (is_signed == TRUE)
		return (va_arg(ap, int));
	else
		return (va_arg(ap, unsigned int));
}

uintmax_t cast_char(va_list ap, int is_signed)
{
	if (is_signed == TRUE)
		return ((char)va_arg(ap, int));
	else
		return ((unsigned char)va_arg(ap, unsigned int));
}

uintmax_t cast_short(va_list ap, int is_signed)
{
	if (is_signed == TRUE)
		return ((short)va_arg(ap, int));
	else
		return ((unsigned short)va_arg(ap, unsigned int));
}

uintmax_t cast_long(va_list ap, int is_signed)
{
	if (is_signed == TRUE)
		return (va_arg(ap, long));
	else
		return (va_arg(ap, unsigned long));
}

uintmax_t cast_longlong(va_list ap, int is_signed)
{
	if (is_signed == TRUE)
		return (va_arg(ap, long long));
	else
		return (va_arg(ap, unsigned long long));
}

uintmax_t cast_sizet(va_list ap, int is_signed)
{
	(void)is_signed;
	return (va_arg(ap, size_t));
}

uintmax_t cast_intmax(va_list ap, int is_signed)
{
	if (is_signed == TRUE)
		return (va_arg(ap, intmax_t));
	else
		return (va_arg(ap, uintmax_t));
}

