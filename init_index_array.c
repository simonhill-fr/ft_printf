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

void	init_index_array(t_functab *func_array)
{
	int 	i;

	i = 0;
	while (i < 128)
	{
		func_array[i] = empty;
		i++;
	}
	func_array['%'] = placeholder;
	func_array['+'] = plus;
	func_array['-'] = minus;
	func_array[' '] = space;
	func_array['0'] = zero;
	func_array['#'] = hash;
	
	func_array['1'] = digit;
	func_array['2'] = digit;
	func_array['3'] = digit;
	func_array['4'] = digit;
	func_array['5'] = digit;
	func_array['6'] = digit;
	func_array['7'] = digit;
	func_array['8'] = digit;
	func_array['9'] = digit;

	func_array['d'] = dec;
	func_array['c'] = character;
	func_array['s'] = string;

	func_array['l'] = long_len;
 
}