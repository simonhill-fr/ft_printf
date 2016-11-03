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
#include <stdio.h>

// TEST: %x %d %u %X %o

int 	main()
{
//	printf("%jd\n", (intmax_t)ft_pow(256, 4));
	int test = 0;
	ft_printf("mine:%011o<\n", 542);
	   printf("them:%011o<\n", 542);



	return (0);
}