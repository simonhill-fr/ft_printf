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

/*#include "SRC/ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <locale.h>

int 	main()
{
	setlocale(LC_ALL, "en_US.UTF-8");

	return (0);
}*/
	



#include <wchar.h>
#include <stddef.h>
#include <unistd.h>
//#include <Endian.h>
	
/*# define LOCALIZED_WIDE_CHARACTERS_STRING	L"\xE2809C\x41\xE2809C\n\n\0"
# pragma message							"__BIG_ENDIAN  is used."*/
# define LOCALIZED_WIDE_CHARACTERS_STRING	L"\x9C80E2\x3b1\x9C80E2\n\n\0"
# pragma message							"__LITTLE_ENDIAN  is used."
/*# define LOCALIZED_WIDE_CHARACTERS_STRING	L"\xE2009C80\x41\xE2009C80\n\n\0"
# pragma message							"__PDP_ENDIAN  is used."*/
/*#else
# error										An unknown endianness is used.*/

size_t	ft_wcslen(wchar_t *wcs)
{
	size_t	sz;

	sz = 0;
	while (*(wcs++))
		sz++;
	return (sz);
}

int		main(void)
{
	wchar_t	*wcs;

	wcs = LOCALIZED_WIDE_CHARACTERS_STRING;
	return (write(1, wcs, (ft_wcslen(wcs) * sizeof(wchar_t))));
}




































/*


//x
ft_printf("mine:%#x<\n", 42);
   printf("them:%#x<\n", 42);
ft_printf("mine:%#llx<\n", 9223372036854775807);
   printf("them:%#llx<\n", 9223372036854775807);

ft_printf("mine:%#x<\n", 0);
   printf("them:%#x<\n", 0);

ft_printf("mine:%#x<\n", 42);
   printf("them:%#x<\n", 42);

ft_printf("mine:%#8x<\n", 42);
   printf("them:%#8x<\n", 42);

ft_printf("mine:%#08x<\n", 42);
   printf("them:%#08x<\n", 42);

ft_printf("mine:%#-08x<\n", 42);
   printf("them:%#-08x<\n", 42);


ft_printf("mine:%#X<\n", 42);
   printf("them:%#X<\n", 42);
ft_printf("mine:%#llX<\n", 9223372036854775807);
   printf("them:%#llX<\n", 9223372036854775807);

ft_printf("mine:%#X<\n", 0);
   printf("them:%#X<\n", 0);

ft_printf("mine:%#X<\n", 42);
   printf("them:%#X<\n", 42);

ft_printf("mine:%#8X<\n", 42);
   printf("them:%#8X<\n", 42);

ft_printf("mine:%#08X<\n", 42);
   printf("them:%#08X<\n", 42);

ft_printf("mine:%#-08X<\n", 42);
   printf("them:%#-08X<\n", 42);



//d
ft_printf("mine:%#d<\n", 42);
   printf("them:%#d<\n", 42);

ft_printf("mine:%#lld<\n", 9223372036854775807);
   printf("them:%#lld<\n", 9223372036854775807);

ft_printf("mine:%#d<\n", 0);
   printf("them:%#d<\n", 0);

ft_printf("mine:%#d<\n", 42);
   printf("them:%#d<\n", 42);

ft_printf("mine:%#8d<\n", 42);
   printf("them:%#8d<\n", 42);

ft_printf("mine:%#08d<\n", 42);
   printf("them:%#08d<\n", 42);

ft_printf("mine:%#-08d<\n", 42);
   printf("them:%#-08d<\n", 42);



ft_printf("mine:%#u<\n", 42);
   printf("them:%#u<\n", 42);

ft_printf("mine:%#llu<\n", 9223372036854775807);
   printf("them:%#llu<\n", 9223372036854775807);

ft_printf("mine:%#u<\n", 0);
   printf("them:%#u<\n", 0);

ft_printf("mine:%#u<\n", 42);
   printf("them:%#u<\n", 42);

ft_printf("mine:%#8u<\n", 42);
   printf("them:%#8u<\n", 42);

ft_printf("mine:%#08u<\n", 42);
   printf("them:%#08u<\n", 42);

ft_printf("mine:%#-08u<\n", 42);
   printf("them:%#-08u<\n", 42);



ft_printf("mine:%#o<\n", 42);
   printf("them:%#o<\n", 42);

ft_printf("mine:%#llo<\n", 9223372036854775807);
   printf("them:%#llo<\n", 9223372036854775807);

ft_printf("mine:%#o<\n", 0);
   printf("them:%#o<\n", 0);

ft_printf("mine:%#o<\n", 42);
   printf("them:%#o<\n", 42);

ft_printf("mine:%#8o<\n", 42);
   printf("them:%#8o<\n", 42);

ft_printf("mine:%#08o<\n", 42);
   printf("them:%#08o<\n", 42);

ft_printf("mine:%#-08o<\n", 42);
   printf("them:%#-08o<\n", 42);



*/



















