/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:21:15 by shill             #+#    #+#             */
/*   Updated: 2016/11/24 16:21:18 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		walk(const char **format, t_param *param, int *print, va_list ap)
{
	if (param->fret == DIGIT)
		width_precision(format, param, ap);
	else if (param->fret == EMPTY)
	{
		if (ft_isprint(**format))
		{
			if (param->width && !(param->minus))
			{
				if (param->precision == 0 && param->zero == TRUE)
					print_padding(param, param->width - 1, '0');
				else
					print_padding(param, param->width - 1, ' ');
			}
			*print += ft_putchar(**format);
			if (param->width && param->minus)
				print_padding(param, param->width - 1, ' ');
			return (END);
		}
		else
			return (END);
	}
	(*format)++;
	return (1);
}

int		parse(const char *format, va_list ap, t_functab *f_arr, t_param *param)
{
	int			print;

	print = 0;
	while (*format)
	{
		param = init_param(param);
		if (*format != '%')
			print += ft_putchar(*format);
		else
		{
			if (*(format + 1) == '\0')
				return (0);
			format++;
			while ((param->fret = f_arr[(int)*format](ap, param)))
			{
				if (walk(&format, param, &print, ap) == END)
					break ;
			}
		}
		print += param->ret;
		format++;
	}
	return (print);
}
