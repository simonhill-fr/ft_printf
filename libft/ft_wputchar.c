/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:34:36 by shill             #+#    #+#             */
/*   Updated: 2016/11/25 15:18:23 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	two_bytes(unsigned int v)
{
	unsigned char octet;
	unsigned char o2;
	unsigned char o1;

	o2 = v & 0b111111;
	o1 = (v >> 6) & 0b11111;
	octet = 0b11000000 | o1;
	write(1, &octet, 1);
	octet = 0b10000000 | o2;
	write(1, &octet, 1);
	return (2);
}

static int	three_bytes(unsigned int v)
{
	unsigned char octet;
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;

	o3 = v & 0b111111;
	o2 = (v >> 6) & 0b111111;
	o1 = (v >> 12) & 0b1111;
	octet = 0b11100000 | o1;
	write(1, &octet, 1);
	octet = 0b10000000 | o2;
	write(1, &octet, 1);
	octet = 0b10000000 | o3;
	write(1, &octet, 1);
	return (3);
}

static int	four_bytes(unsigned int v)
{
	unsigned char octet;
	unsigned char o4;
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;

	o4 = v & 0b111111;
	o3 = (v >> 6) & 0b111111;
	o2 = (v >> 12) & 0b111111;
	o1 = (v >> 18) & 0b111;
	octet = 0b11110000 | o1;
	write(1, &octet, 1);
	octet = 0b10000000 | o2;
	write(1, &octet, 1);
	octet = 0b10000000 | o3;
	write(1, &octet, 1);
	octet = 0b10000000 | o4;
	write(1, &octet, 1);
	return (4);
}

static int	get_binary_size(unsigned int value)
{
	size_t	i;

	if (value == 0)
		return (0);
	i = 1;
	while ((value /= 2))
		++i;
	return (i);
}

int			ft_wputchar(unsigned int value)
{
	int				size;
	unsigned char	octet;

	size = get_binary_size(value);
	if (size <= 7)
	{
		octet = value;
		write(1, &octet, 1);
		return (1);
	}
	else if (size <= 11)
		return (two_bytes(value));
	else if (size <= 16)
		return (three_bytes(value));
	else
		return (four_bytes(value));
	return (-1);
}
