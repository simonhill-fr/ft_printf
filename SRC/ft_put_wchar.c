/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:34:36 by shill             #+#    #+#             */
/*   Updated: 2016/11/09 17:34:40 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int		get_binary_size(unsigned int value)
{
 	size_t	i;

	if (value == 0)
		return (0);
	i = 1;
	while ((value /= 2))
		++i;
	return (i);
}

int		ft_put_wchar(unsigned int value)
{
//		unsigned int mask0 = 0;
        unsigned int mask1 = 49280;
        unsigned int mask2= 14712960;
        unsigned int mask3= 4034953344;
 
        unsigned int v = value;
        int size = get_binary_size(value);
//        int res = 0;
        unsigned char octet;
 
        if (size <= 7)
        {
                octet = value;
                write(1, &octet, 1);
                return (1);
        }
        else  if (size <= 11)
        {
                unsigned char o2 = (v << 26) >> 26; // recuperation des 6 premiers bits 110xxxxx 10(xxxxxx)
                unsigned char o1 = ((v >> 6) << 27) >> 27; // recuperation des 5 derniers bits 110(xxxxx) 10xxxxxx
       
                octet = (mask1 >> 8) | o1; // application des bits du premier octet sur le premier octet mask
                write(1, &octet, 1);
                octet = ((mask1 << 24) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
                write(1, &octet, 1);
                return(2);
        }
        else  if (size <= 16)
        {
                unsigned char o3 = (v << 26) >> 26; // recuperation des 6 premiers bits 1110xxxx 10xxxxxx 10(xxxxxx)
                unsigned char o2 = ((v >> 6) << 26) >> 26; // recuperation des 6 seconds bits 1110xxxx 10(xxxxxx) 10xxxxxx
                unsigned char o1 = ((v >> 12) << 28) >> 28; // recuperation des 4 derniers bits 1110(xxxx) 10xxxxxx 10xxxxxx
       
                octet = (mask2 >> 16) | o1; // application des bits du premier octet sur le premier octet mask
                write(1, &octet, 1);
                octet = ((mask2 << 16) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
                write(1, &octet, 1);
                octet = ((mask2 << 24) >> 24) | o3; // application des bits du troisieme octet sur le troisieme octet du mask
                write(1, &octet, 1);
                return(3);
        }
        else
        {
                unsigned char o4 = (v << 26) >> 26; // recuperation des 6 premiers bits 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
                unsigned char o3 = ((v >> 6) << 26) >> 26; // recuperation des 6 seconds bits 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
                unsigned char o2 = ((v >> 12) << 26) >> 26;  // recuperation des 6 seconds bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
                unsigned char o1 = ((v >> 18) << 29) >> 29; // recuperation des 3 seconds bits 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx
       
                octet = (mask3 >> 24) | o1; // application des bits du premier octet sur le premier octet mask
                write(1, &octet, 1);
                octet = ((mask3 << 8) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
                write(1, &octet, 1);
                octet = ((mask3 << 16) >> 24) | o3; // application des bits du troisieme octet sur le troisieme octet du mask
                write(1, &octet, 1);
                octet = ((mask3 << 24) >> 24) | o4; // application des bits du quatrieme octet sur le quatrieme octet du mask
                write(1, &octet, 1);
                return (4);
        }
        return (-1);
}


/*
char octet;
	unsigned int mask0 = 0;
    unsigned int mask1 = 0b1100000010000000;

    unsigned char o2 = v & 0b111111; // recuperation des 6 premiers bits 110xxxxx 10(xxxxxx)
	unsigned o1 = (v & 0b11111111000000) << 6 ; // recuperation des 5 derniers bits 110(xxxxx) 10xxxxxx

	octet = 0b11000000 | o1; // application des bits du premier octet sur le premier octet mask
	write(1, &octet, 1);
	octet = ((mask1 << 24) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
	write(1, &octet, 1);*/