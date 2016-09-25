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

/*static void	ft_put_long_nbr(long long n)
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
}*/

int	integer(va_list ap, t_param *param)
{	
	intmax_t nb;

	nb = va_arg(ap, uintmax_t);
	print_width(param, get_int_len(nb));
	
	ft_putnbr(nb);
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
