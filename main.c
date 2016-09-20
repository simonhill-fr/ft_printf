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

t_param	*init_param() //Better if malloc wouldnt occur on every call
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
		(*format)++;
		while (ft_isdigit(n = **format))
		{
			param->precision = param->precision * 10 + n - 48;
			(*format)++;
		}
	}
	(*format)--;

}//would be better to index all digits to this function instead of 
// using if (ret == DIGIT)

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int 		ret;
	t_param		*param;
	t_functab 	*func_array;

	func_array = malloc(sizeof(t_functab) * 128);
	init_index_array(func_array);

	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format);
		else
		{
			param = init_param();
			while ((ret = func_array[(int)*format](ap, param)))
			{
				if (ret == DIGIT)
					get_digits(&format, param);
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
	int 	i = 2;
	
	ft_printf("p=%hd\n", i);
//	   printf("o=%hd\n", i);
	return (0);
}


