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

void	get_digits(const char **format, t_param *param)
{
	int 	n;

	while (ft_isdigit(n = **format))
	{
		param->width = param->width * 10 + n - 48;
		(*format)++;
	}
	if (**format == '.')
	{
		param->precision = 0;
		(*format)++;
		while (ft_isdigit(n = **format))
		{
			param->precision = param->precision * 10 + n - 48;
			(*format)++;
		}
	}
	if (param->precision > 0)
		param->zero = FALSE;
	(*format)--;
}

int		parse(const char *format, va_list ap, t_functab *func_array)
{
	t_param		*param;
	int 		ret;
	int			print;

	param = malloc(sizeof(t_param));
	print = 0;
	while (*format)
	{
		param = init_param(param);
		if (*format != '%')
			print += ft_putchar(*format);
		else
		{
			format++;
			while ((ret = func_array[(int)*format](ap, param)))
			{
				if (ret == DIGIT)
					get_digits(&format, param);
				else if (ret == EMPTY)
				{
					if (ft_isprint(*format))
					{
						if (param->width && !(param->minus))
						{
							if (param->precision == 0 && param->zero == TRUE)
								print_padding(param, param->width - 1, '0');
							else
								print_padding(param, param->width - 1, ' ');
						}
						print += ft_putchar(*format);
						if (param->width && param->minus)
							print_padding(param, param->width - 1, ' ');
						break;
					}
					else
						return(print);
				}
				format++;
			}
		}		
		print += param->ret;
		format++;
	}
	free(param);
	return (print);
}






