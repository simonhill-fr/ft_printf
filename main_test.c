/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:41:58 by shill             #+#    #+#             */
/*   Updated: 2016/09/24 15:42:09 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SRC/ft_printf.h"
#include <limits.h>

int 	main()
{
/*	int a, b;
	a = ft_printf("%#16x\n", 2500);
	   b = printf("%#16x\n", 2500);

	printf("(%d),(%d)\n", a, b);
*/
//	printf("%ju\n", UINTMAX_MAX);
//	printf("%lu\n", ULONG_MAX);

	printf("%x\n", -42);
	printf("%s\n", ft_itoa_base(-42, 16));
	return (0);
}