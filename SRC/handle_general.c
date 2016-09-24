/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_general.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 16:39:06 by shill             #+#    #+#             */
/*   Updated: 2016/09/18 16:41:25 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		placeholder(va_list ap, t_param *param)
{
	(void)(ap);
	if (param->minus == TRUE)
	{
		ft_putchar('%');
		print_width(param, 1);
	}
	else if (param->minus == FALSE)
	{
		print_width(param, 1);
		ft_putchar('%');
	}
	return (END);
}

int		empty(va_list ap, t_param *param)
{
	(void)(ap);
	(void)(param);
	return (EMPTY);
}

int		digit(va_list ap, t_param *param)
{
	(void)(ap);
	(void)(param);
	return (DIGIT);
}
