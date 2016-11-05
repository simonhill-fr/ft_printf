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

void	check_zero_exception(t_param *param, uintmax_t nb)
{
	if (nb == 0)
		param->hash = 0;
}

int	decimal(va_list ap, t_param *param)
{	
	intmax_t 	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, SIGNED);
	str = ft_itoadup(nb, 10);
	if (nb < 0)
	{
		param->negative = TRUE;
		final_print(param, str, "", -1);
	}
	else 
		final_print(param, str, "", 1);
	return (END);
}

int	udecimal(va_list ap, t_param *param)
{	
	uintmax_t 	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, UNSIGNED);
	check_zero_exception(param, nb);
	str = ft_utoadup(nb, 10);
	final_print(param, str, "", 0);
	return (END);
}

int hexadecimal(va_list ap, t_param *param)
{
	uintmax_t	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, UNSIGNED);
	check_zero_exception(param, nb);
	str = ft_utoadup(nb, 16);
	final_print(param, str, "0x", 0);	
	return (END);
}

int upper_hexadecimal(va_list ap, t_param *param)
{
	uintmax_t 	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, UNSIGNED);
	check_zero_exception(param, nb);
	str = ft_utoadup(nb, 16);
	ft_str_toupper(str);
	final_print(param, str, "0X", 0);
	return (END);	
}

int octal(va_list ap, t_param *param)
{
	uintmax_t	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, UNSIGNED);
	check_zero_exception(param, nb);
	str = ft_utoadup(nb, 8);
	final_print(param, str, "0", 0);
	return (END);
}


