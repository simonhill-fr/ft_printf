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

//precision on int is converted to width :
static	void	convert_int_precision_to_width(t_param *param)
{
	/*if (param->precision >= 0 && param->precision >= param->width) 
	{
		param->minus = FALSE;
		param->zero = TRUE;
		param->width = param->precision;
	}*/
	if (param->precision >= 0 && param->precision >= param->width)
	{
		
	}
}

static	void	set_prefix_len(t_param *param, int len)
{
	if (param->hash) 
		param->hash = len;
}

int	decimal(va_list ap, t_param *param)
{	
	intmax_t 	nb;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, SIGNED);
	set_prefix_len(param, 0);
	convert_int_precision_to_width(param);
	print_pre(param, nb, "");
	param->ret += ft_putnbr(nb);
	if (param->minus == TRUE && param->width)
		print_width(param, get_int_len(nb));
	return (0);
}

int	udecimal(va_list ap, t_param *param)
{	
	uintmax_t nb;
	t_ftab_cast	*ftab_cast;
	char		*str;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, UNSIGNED);
	set_prefix_len(param, 0);
	convert_int_precision_to_width(param);
	print_pre(param, nb, "");
	str = ft_itoadup(nb, 10);
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

int hexadecimal(va_list ap, t_param *param)
{
	uintmax_t	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, UNSIGNED);
	if (param->hash && nb != 0) //set length of prefix
		param->hash = 2;
	convert_int_precision_to_width(param);
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
	nb = ftab_cast[param->length](ap, UNSIGNED);
	if (param->hash) //set length of prefix
		param->hash = 2;
	convert_int_precision_to_width(param);
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
	nb = ftab_cast[param->length](ap, UNSIGNED);
	if (param->hash) //set length of prefix
		param->hash = 1;
	str = ft_itoadup(nb, 8);
	convert_int_precision_to_width(param);
	print_pre(param, ft_atoi(str), "0");	
	if (param->precision == 0 && nb == 0)
	{
		if (param->width == 0)
			return (0);
		str = ft_strdup(" ");
	}
	param->ret += ft_putstr(str);
	if (param->minus == TRUE && param->width)
		print_width(param, get_int_len(ft_atoi(str)));
	return (0);
}


