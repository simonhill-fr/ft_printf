/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_index_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 16:27:41 by shill             #+#    #+#             */
/*   Updated: 2016/09/18 16:27:43 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_index_flags(t_functab *func_array)
{
	func_array['%'] = placeholder;
	func_array['+'] = plus;
	func_array['-'] = minus;
	func_array[' '] = space;
	func_array['0'] = zero;
	func_array['#'] = hash;
}

static void	init_index_digits(t_functab *func_array)
{
	func_array['1'] = digit;
	func_array['2'] = digit;
	func_array['3'] = digit;
	func_array['4'] = digit;
	func_array['5'] = digit;
	func_array['6'] = digit;
	func_array['7'] = digit;
	func_array['8'] = digit;
	func_array['9'] = digit;
	func_array['.'] = digit;
}

static void	init_index_types(t_functab *func_array)
{
	func_array['d'] = decimal;
	func_array['D'] = w_decimal;
	func_array['i'] = decimal;
	func_array['o'] = octal;
	func_array['O'] = w_octal;
	func_array['u'] = udecimal;
	func_array['U'] = w_udecimal;
	func_array['x'] = hexadecimal;
	func_array['X'] = upper_hexadecimal;
	func_array['c'] = character;
	func_array['C'] = w_character;
	func_array['s'] = string;
	func_array['S'] = w_string;
	func_array['p'] = pointer;
	func_array['b'] = binary;
}

static void	init_index_length(t_functab *func_array)
{
	func_array['h'] = short_len;
	func_array['l'] = long_len;
	func_array['z'] = sizet_len;
	func_array['j'] = intmax_len;
}

void		init_index_array(t_functab *func_array)
{
	int		i;

	i = 0;
	while (i < 128)
	{
		func_array[i] = empty;
		i++;
	}
	init_index_flags(func_array);
	init_index_digits(func_array);
	init_index_types(func_array);
	init_index_length(func_array);
}
