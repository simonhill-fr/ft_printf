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

static int	get_int_len(long long n)
{
	long long	len;

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

static void	ft_put_long_nbr(long long n)
{
	if (n == -9223372036854775807 - 1)
		ft_putstr("-9223372036854775808");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_put_long_nbr(-n);
	}
	else if (n >= 10)
	{
		ft_put_long_nbr(n / 10);
		ft_put_long_nbr(n % 10);
	}
	else if (n < 10)
		ft_putchar(n + '0');
}

// Need to code atoi_base!
/*static void	ft_put_hex(long long i)
{
	int 	n;

	n = 0;
	while (ft_pow(16, n) < i)
		n++;
	n--;
	d = (i / ft_pow(16, n))
	ft_putchar('')

}*/

int	integer(va_list ap, t_param *param)
{	
//	union u_types type;
	long long type;

	if (param->length == INT)
		type = va_arg(ap, int);
	if (param->length == CHAR)
		type = va_arg(ap, int);
	if (param->length == SHORT)
		type = (short)va_arg(ap, int);
	if (param->length == LONG)
		type = va_arg(ap, long);
	if (param->length == LONG_LONG)
		type = va_arg(ap, long long);
	if (param->length == SIZE_T)
		type = va_arg(ap, size_t);
	if (param->length == INTMAX)
		type = va_arg(ap, intmax_t);

	print_width(param, get_int_len(type));
	if (type >= 0 && param->plus == TRUE)
		ft_putchar('+');
	else if (type > 0 && param->space == TRUE)
		ft_putchar(' ');
	ft_put_long_nbr(type);
	return (0);
}

int hexadecimal(va_list ap, t_param *param)
{
	long long type;

	if (param->length == INT)
		type = va_arg(ap, unsigned int);
	if (param->length == CHAR)
		type = va_arg(ap, unsigned int);
	if (param->length == SHORT)
		type = (unsigned short)va_arg(ap, unsigned int);
	if (param->length == LONG)
		type = va_arg(ap, unsigned long);
	if (param->length == LONG_LONG)
		type = va_arg(ap, unsigned long long);
	if (param->length == SIZE_T)
		type = va_arg(ap, size_t);
	if (param->length == INTMAX)
		type = va_arg(ap, intmax_t);



	print_width(param, get_int_len(type));
	if (type > 0 && param->plus == TRUE)
		ft_putchar('+');
	else if (type > 0 && param->space == TRUE)
		ft_putchar(' ');
//	ft_put_hex(type);
	ft_put_long_nbr(type); // will be replaced by put_hex()
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
