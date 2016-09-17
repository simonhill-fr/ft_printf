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

int	placeholder(va_list ap, t_param *param) //if c == %
{
	/*create t_param for current placeholder
	init params
	add to list*/
	return (1);
}

int	minus(va_list ap, t_param *param)
{
	param->minus = TRUE;
	return (1);
}

int	dec(va_list ap, t_param *param)
{	
	ft_putnbr(va_arg(ap, int));
	return (0);
}

int	character(va_list ap, t_param *param)
{
	ft_putchar(va_arg(ap, int));
	return (0);
}

int	string(va_list ap, t_param *param)
{
	ft_putstr(va_arg(ap, char *));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_param		*param;
	int (*findex[128])(va_list, t_param *); //function pointer array

	param = malloc(sizeof(t_param));

	(findex['%']) = placeholder;
	(findex['d']) = dec;
	(findex['c']) = character;
	(findex['s']) = string;

	va_list		ap;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format);
		else 
			while (findex[(int)*format](ap, param))
			{
				format++;
			}
		format++;
	}
	va_end(ap);
	return (0);
}


int 	main()
{
	char	*str = "string";
//	printf("number:%+d %c %s\n", 1, 'E', str);
	ft_printf("number:%d %c %s\n", 1, 'E', str);


	return (0);
}

/*
Pour connaitre la fin de la lecture dun placeholder, les fonctions pourraient etre
de type int, celles qui soccupent du type (d, s, c...) renverraient 0 pour
siginier la fin du placeholder*/

