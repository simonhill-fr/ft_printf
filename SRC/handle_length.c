/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 14:20:52 by shill             #+#    #+#             */
/*   Updated: 2016/09/21 14:20:54 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	short_len(va_list ap, t_param *param)
{	
	if (param->length == SHORT)
	{
		param->length = CHAR;
		return (1);
	}
	param->length = SHORT;
	return (1);

}

int 	long_len(va_list ap, t_param *param)
{
	if (param->length == LONG)
	{
		param->length = LONG_LONG;
		return (1);
	}
	param->length = LONG;
	return (1);
}

int 	sizet_len(va_list ap, t_param *param)
{
	param->length = SIZE_T;
	return (1);
}

int 	intmax_len(va_list ap, t_param *param)
{
	param->length = INTMAX;
	return (1);
}
