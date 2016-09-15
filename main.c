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

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format);
		else if (*format == '%' && *++format == 'd')
		{
			ft_putnbr(va_arg(ap, int));
			format++;
		}

		format++;
	}
	va_end(ap);
	return (0);




}


int 	main()
{
	ft_printf("asf 1%d\n", 1);

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
