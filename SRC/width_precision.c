/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:00:13 by shill             #+#    #+#             */
/*   Updated: 2016/11/25 17:00:15 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	width(const char **format, t_param *param, va_list ap)
{
	int		n;

	if (**format == '*')
	{
		param->width = va_arg(ap, int);
		if (param->width < 0)
		{
			param->minus = TRUE;
			param->width = ft_abs(param->width);
		}
		if (ft_isdigit(*(*format + 1)))
			param->width = 0;
		(*format)++;
	}
	while (ft_isdigit(n = **format))
	{
		param->width = param->width * 10 + n - 48;
		(*format)++;
	}
}

static void	precision(const char **format, t_param *param, va_list ap)
{
	int		n;

	if (**format == '.')
	{
		param->precision = 0;
		(*format)++;
		while (ft_isdigit(n = **format))
		{
			param->precision = param->precision * 10 + n - 48;
			(*format)++;
		}
		if (**format == '*')
		{
			if ((param->precision = va_arg(ap, int)) < 0)
				param->precision = -1;
			(*format)++;
		}
	}
	if (param->precision > 0)
		param->zero = FALSE;
	(*format)--;
}

void		width_precision(const char **format, t_param *param, va_list ap)
{
	width(format, param, ap);
	precision(format, param, ap);
}
