/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 16:31:19 by shill             #+#    #+#             */
/*   Updated: 2016/09/17 16:31:23 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Proble matique : gestion des types differents de int et de float. 
Since n, the number to be printed has to be typed, and that it is not possible
to predict the type in advance, this results in having to either create an if forest 
in the dec() function, or to create a specific function for each 7 possible type
of integer. This brings the problem of the func_array() function-pointer indexing.
First idea that comes to mind : creating a simple hashtable-like function to
determine the index of the function to be executed. For that purpose, the 
hash table will have to take as argument a char * string to hash it into an
unique int. Is this possible? How? */


#define SHORT 	1
#define LONG	2

static int	get_int_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
} //add to libft ?

/*void cast_short(va_list ap, int *n)
{
	*n = va_arg(ap, short));
}*/

int	dec(va_list ap, t_param *param)
{	
	int		n;

	if (param->length == SHORT)
	{
		n = (short)va_arg(ap, int);
	}// not possible as n is of type int
	
	n = va_arg(ap, int);
	print_width(param, get_int_len(n));
	if (n > 0 && param->plus == TRUE)
		ft_putchar('+');
	else if (n > 0 && param->space == TRUE)
		ft_putchar(' ');
	ft_putnbr(n);
	return (0);
}

int	character(va_list ap, t_param *param)
{
	ft_putchar(va_arg(ap, int));
	return (0);
}

int	string(va_list ap, t_param *param)
{
	char 	*str;

	str = va_arg(ap, char *);
	if (param->precision)
	{
		print_width(param, param->precision);
		str = ft_strndup(str, param->precision);
		ft_putstr(str);
		return (0);
	}
	print_width(param, ft_strlen(str));
	ft_putstr(str);
	return (0);
}
