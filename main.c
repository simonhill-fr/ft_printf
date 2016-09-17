/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 11:42:33 by shill             #+#    #+#             */
/*   Updated: 2016/09/15 11:42:36 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_param	*init_param()
{
	t_param *param;

	param = malloc(sizeof(t_param));
	param->minus = FALSE;
	param->plus = FALSE;
	param->space = FALSE;
	param->zero = FALSE;
	param->hash = FALSE;
	param->width = 0;
	param->precision = 0;
	param->length = 0;
	return (param);

}

int	placeholder(va_list ap, t_param *param) //if c == % .Useless.
{
	return (1);
}

int ft_width(va_list ap, t_param *param)
{
/*	int 	n;

	n = va_arg(ap, int);
	param->width = param->width * 10 + n;*/
	printf("enter\n");
	ft_putchar(va_arg(ap, int));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	t_param		*param;
	int (*findex[128])(va_list, t_param *); //function pointer array

//	param = malloc(sizeof(t_param));

	(findex['%']) = placeholder;
	(findex['+']) = plus;
	(findex['-']) = minus;
	(findex[' ']) = space;
	(findex['0']) = zero;
	(findex['#']) = hash;

	(findex['d']) = dec;
	(findex['c']) = character;
	(findex['s']) = string;

	(findex['1']) = ft_width;
	(findex['2']) = ft_width;
	(findex['3']) = ft_width;
	(findex['4']) = ft_width;
	(findex['5']) = ft_width;
	(findex['6']) = ft_width;
	(findex['7']) = ft_width;
	(findex['8']) = ft_width;
	(findex['9']) = ft_width;

	va_list		ap;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format);
		else
		{
			param = init_param();
			while (findex[(int)*format](ap, param))
			{
//				printf("%c\n", *format);
				format++;
			}
			free(param);
		}
		format++;
	}
	va_end(ap);
	return (0);
}


int 	main()
{
	char	*str = "string";
//	printf("%5d", 8);
	ft_printf("%2d\n", 8);


	return (0);
}


