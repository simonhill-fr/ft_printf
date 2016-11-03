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