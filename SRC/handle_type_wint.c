/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_type_wint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:57:59 by shill             #+#    #+#             */
/*   Updated: 2016/11/07 13:58:03 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		w_udecimal(va_list ap, t_param *param)
{
	param->length = INTMAX;
	return (udecimal(ap, param));
}

int		w_decimal(va_list ap, t_param *param)
{
	param->length = INTMAX;
	return (decimal(ap, param));
}

int		w_octal(va_list ap, t_param *param)
{
	param->length = INTMAX;
	return (octal(ap, param));
}
