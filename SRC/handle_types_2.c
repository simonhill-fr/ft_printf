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

	str = ft_strnew(1);
	str[0] = va_arg(ap, int);
	final_print(param, str, "", 0);	
	return (END);
}

int	string(va_list ap, t_param *param)
{
	char 	*str;

	str = va_arg(ap, char *);
	if (!(str))
	{
		param->ret += ft_putstr("(null)");
		return (END);
	}
	param->alpha = TRUE;
	if (param->precision != -1)
		str = ft_strndup(str, param->precision);
	final_print(param, str, "", 0);
	return (0);
}