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

void	dec(va_list ap)
{	
	ft_putnbr(va_arg(ap, int));
}

void	character(va_list ap)
{
	ft_putchar(va_arg(ap, int));
}

void	string(va_list ap)
{
	ft_putstr(va_arg(ap, char *));
}

int	ft_printf(const char *format, ...)
{
	void (*findex[128])(va_list); //function pointer array


	(findex['d']) = dec;
	(findex['c']) = character;
	(findex['s']) = string;

	va_list		ap;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format);
		else if (*format == '%')
		{
			format++;
			findex[(int)*format](ap);
		}
		format++;
	}
	va_end(ap);
	return (0);
}


int 	main()
{
	char	*str = "string";
	ft_printf("number:%d %c %s\n", 1, 'E', str);
//	ft_printf("number:%c", 'g');
	return (0);
}


/*

int 	arg_nb(char *s); //returns the number of %placeholders

typedef struct 		s_flag
{
	int				placeholder_number;
	int				type;
	void			*value;
	struct s_flag	*next;
}					t_flag;

void	read_input(char *s)
{
	
}


*/
