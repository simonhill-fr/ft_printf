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

/* */


static int	get_int_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
} //add to libft ?


int print_long_int(va_list ap, t_param *param)
{
	long n;

	n = va_arg(ap, long);
	print_width(param, get_int_len(n));
	if (n > 0 && param->plus == TRUE)
		ft_putchar('+');
	else if (n > 0 && param->space == TRUE)
		ft_putchar(' ');
	ft_putnbr(n);
	return (0);
}

int	dec(va_list ap, t_param *param)
{	
	int		n;

	if (param->length == CHAR)
	{
		n = va_arg(ap, int);
		return (0);
	}
	if (param->length == SHORT)
	{
		n = (short)va_arg(ap, int);
		return (0);
	}
	else if (param->length == LONG)
	{
		print_long_int(ap, param);
		return (0);
	}
	/*else if (param->length == LONGLONG)
	{
		print_longlong_int(ap, param);
	}
	else if (param->length == SYZE_T)
	{
		print_sizet_int(ap, param);

	}*/

	
	n = va_arg(ap, int);
	print_width(param, get_int_len(n));
	if (n > 0 && param->plus == TRUE)
		ft_putchar('+');
	else if (n > 0 && param->space == TRUE)
		ft_putchar(' ');
	ft_putnbr(n);
	return (0);
}

int	character(va_list ap, t_param *param)
{
	ft_putchar(va_arg(ap, int));
	return (0);
}

int	string(va_list ap, t_param *param)
{
	char 	*str;

	str = va_arg(ap, char *);
	if (param->precision)
	{
		print_width(param, param->precision);
		str = ft_strndup(str, param->precision);
		ft_putstr(str);
		return (0);
	}
	print_width(param, ft_strlen(str));
	ft_putstr(str);
	return (0);
}
