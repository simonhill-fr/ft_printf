/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_type_num2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:05:00 by shill             #+#    #+#             */
/*   Updated: 2016/11/24 17:05:01 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		octal(va_list ap, t_param *param)
{
	uintmax_t	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;
	int			display_prefix;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, UNSIGNED);
	str = ft_utoadup(nb, 8);
	display_prefix = FALSE;
	if (param->hash && nb == 0)
	{
		param->hash = FALSE;
		display_prefix = TRUE;
	}
	if (param->hash && param->precision > 0)
	{
		param->hash = FALSE;
		display_prefix = FALSE;
	}
	check_zero_exception(param, nb, str, display_prefix);
	final_print(param, str, "0", 0);
	return (END);
}

int		binary(va_list ap, t_param *param)
{
	uintmax_t	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;
	int			display_prefix;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, UNSIGNED);
	str = ft_utoadup(nb, 2);
	display_prefix = FALSE;
	if (param->hash && nb == 0)
	{
		param->hash = FALSE;
		display_prefix = TRUE;
	}
	if (param->hash && param->precision > 0)
	{
		param->hash = FALSE;
		display_prefix = FALSE;
	}
	check_zero_exception(param, nb, str, display_prefix);
	final_print(param, str, "0b", 0);
	return (END);
}