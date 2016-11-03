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
}

void	print_pre(t_param *param, uintmax_t nb, char *prefix)
{
	if (nb == 0)
		param->hash = FALSE;
	if (param->width == 0 || param->minus == TRUE)
	{
		if (param->hash == TRUE)
			param->ret += ft_putstr(prefix);
		return ;
	}
	if (param->zero == TRUE)
	{
		if (param->hash)
			param->ret += ft_putstr(prefix);
		print_width(param, get_int_len(nb));
		return ;
	}
	print_width(param, get_int_len(nb));
	if (param->hash)
		param->ret += ft_putstr(prefix);
}

int	decimal(va_list ap, t_param *param)
{	
	intmax_t nb;

	nb = va_arg(ap, intmax_t);
	if (param->minus == FALSE)
		print_width(param, get_int_len(nb));	
	param->ret += ft_putnbr(nb);
	if (param->minus == TRUE)
		print_width(param, get_int_len(nb));
	return (0);
}

int	udecimal(va_list ap, t_param *param)
{	
	uintmax_t nb;

	nb = va_arg(ap, uintmax_t);
	if (param->minus == FALSE)
		print_width(param, get_int_len(nb));	
	param->ret += ft_putnbr(nb);
	if (param->minus == TRUE)
		print_width(param, get_int_len(nb));
	return (0);
}

int hexadecimal(va_list ap, t_param *param)
{
	uintmax_t	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap);
	print_pre(param, nb, "0x");
	str = ft_itoadup(nb, 16);
	if (param->precision == 0 && nb == 0)
	{
		if (param->width == 0)
			return (0);
		str = ft_strdup(" ");
	}
	param->ret += ft_putstr(str);
	if (param->minus == TRUE && param->width)
		print_width(param, get_int_len(nb));
	return (0);
}

int upper_hexadecimal(va_list ap, t_param *param)
{
	uintmax_t 	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap);
	print_pre(param, nb, "0X");
	str = ft_itoadup(nb, 16);
	if (param->precision == 0 && nb == 0)
	{
		if (param->width == 0)
			return (0);
		str = ft_strdup(" ");
	}
	ft_str_toupper(str);
	param->ret += ft_putstr(str);
	if (param->minus == TRUE && param->width)
		print_width(param, get_int_len(nb));
	return (0);
}

int octal(va_list ap, t_param *param)
{
	uintmax_t	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = 0;
	nb = ftab_cast[param->length](ap);

	print_pre(param, nb, "0");
	str = ft_itoadup(nb, 8);
	if (param->precision == 0 && nb == 0)
	{
		if (param->width == 0)
			return (0);
		str = ft_strdup(" ");
	}
	param->ret += ft_putstr(str);

	if (param->minus == TRUE && param->width)
		print_width(param, get_int_len(nb));
	return (0);
}


