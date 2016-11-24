/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_types_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:27:13 by shill             #+#    #+#             */
/*   Updated: 2016/11/03 13:27:15 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	character(va_list ap, t_param *param)
{
	char	*str;

	if (param->length == LONG)
		return (w_character(ap, param));
	str = ft_strnew(1);
	str[0] = va_arg(ap, int);
	if (str[0] == '\0')
		param->nulchar = TRUE;
	param->alpha = TRUE;
	if (param->precision == 0 && param->width > 0 && param->zero == TRUE)
	{
		param->alpha = FALSE;
		param->zero = TRUE;
	}
	final_print(param, str, "", 0);
	return (END);
}

int	string(va_list ap, t_param *param)
{
	char	*str;

	if (param->length == LONG)
		return (w_string(ap, param));
	str = va_arg(ap, char *);
	if (!(str))
		str = ft_strdup("(null)");
	param->alpha = TRUE;
	if (ft_strcmp(str, "") == 0 && param->width == 0)
	{
		param->empty_str = TRUE;
	}
	if (param->precision != -1)
	{
		str = ft_strndup(str, param->precision);
		param->precision = -1;
	}
	if (param->precision == 0 && param->width > 0 && param->zero == TRUE)
	{
		param->alpha = FALSE;
		param->zero = TRUE;
	}
	final_print(param, str, "", 0);
	return (0);
}

int	pointer(va_list ap, t_param *param)
{
	t_ftab_cast	*ftab_cast;
	uintmax_t	nb;
	char		*str;

	param->length = INTMAX;
	param->hash = TRUE;
	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, UNSIGNED);
	str = ft_utoadup(nb, 16);
	check_zero_exception(param, nb, str, PTR);
	final_print(param, str, "0x", 0);
	return (END);
}
