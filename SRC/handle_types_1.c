/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 16:31:19 by shill             #+#    #+#             */
/*   Updated: 2016/09/17 16:31:23 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_int_len(uintmax_t n)
{
	uintmax_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
} //add to libft ?

int	integer(va_list ap, t_param *param)
{	
	intmax_t nb;

	nb = va_arg(ap, uintmax_t);
	if (param->minus == FALSE)
		print_width(param, get_int_len(nb));	
	ft_putnbr(nb);
	if (param->minus == TRUE)
		print_width(param, get_int_len(nb));
	return (0);
}

int hexadecimal(va_list ap, t_param *param)
{
	uintmax_t nb;
	
	nb = va_arg(ap, uintmax_t);
	print_width(param, get_int_len(nb));
	ft_putstr(ft_itoa_base(42, 16));
	return (0);
}

int	character(va_list ap, t_param *param)
{
	(void)(param);
	ft_putchar(va_arg(ap, int));
	return (0);
}

int	string(va_list ap, t_param *param)
{
	char 	*str;

	str = va_arg(ap, char *);
	if (param->precision)
		str = ft_strndup(str, param->precision);
	if (param->minus == FALSE)
		print_width(param, ft_strlen(str));	
	ft_putstr(str);
	if (param->minus == TRUE)
		print_width(param, ft_strlen(str));
	return (0);
}
