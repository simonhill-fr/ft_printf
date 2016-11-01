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
	char		*prefix;

	prefix = ft_strdup("0x");
	nb = 0;
	if (param->length == INT)
		nb = va_arg(ap, unsigned int);
	else if (param->length == LONG)
		nb = va_arg(ap, unsigned long);
	else if (param->length == LONG_LONG)
		nb = va_arg(ap, unsigned long long);
	else if (param->length == SIZE_T)
		nb = va_arg(ap, size_t);
	else if (param->length == INTMAX)
		nb = (uintmax_t)va_arg(ap, intmax_t);

	print_pre(param, nb, prefix);
	str = ft_itoa_base(nb, 16);
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
	int			i;

	nb = 0;
	if (param->length == INT)
		nb = va_arg(ap, unsigned int);
	else if (param->length == LONG)
		nb = va_arg(ap, unsigned long);
	else if (param->length == LONG_LONG)
		nb = va_arg(ap, unsigned long long);
	if (param->minus == FALSE)
		print_width(param, get_int_len(nb));
	str = ft_itoa_base(nb, 16);
	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	if (param->hash == TRUE)
		param->ret = ft_putstr("0X");
	param->ret += ft_putstr(str);
	if (param->minus == TRUE)
		print_width(param, get_int_len(nb));
	return (0);
}

int octal(va_list ap, t_param *param)
{
	uintmax_t	nb;
	char		*str;
	char		*prefix;

	prefix = ft_strdup("0");
	nb = 0;
	if (param->length == INT)
		nb = va_arg(ap, unsigned int);
	else if (param->length == LONG)
		nb = va_arg(ap, unsigned long);
	else if (param->length == LONG_LONG)
		nb = va_arg(ap, unsigned long long);
	else if (param->length == SIZE_T)
		nb = va_arg(ap, size_t);
	else if (param->length == INTMAX)
		nb = (uintmax_t)va_arg(ap, intmax_t);

	print_pre(param, nb, prefix);
	str = ft_itoa_base(nb, 8);
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

int	character(va_list ap, t_param *param)
{
	if (param->minus == FALSE && param->width > 0)
		print_width(param, 1);
	param->ret += ft_putchar(va_arg(ap, int));
	if (param->minus == TRUE)
		print_width(param, 1);
	return (0);
}

int	string(va_list ap, t_param *param)
{
	char 	*str;

	str = va_arg(ap, char *);
	if (!(str))
	{
		param->ret += ft_putstr("(null)");
		return (0);
	}

	if (param->precision != -1)
		str = ft_strndup(str, param->precision);
	if (param->minus == FALSE)
		print_width(param, ft_strlen(str));	
	param->ret += ft_putstr(str);
	if (param->minus == TRUE)
		print_width(param, ft_strlen(str));
	return (0);
}
