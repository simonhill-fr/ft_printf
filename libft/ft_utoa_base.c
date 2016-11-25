/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 10:56:20 by shill             #+#    #+#             */
/*   Updated: 2016/09/25 10:56:43 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define SLIDER "0123456789abcdefghijklmnopqrstuvwxyz"

static size_t	buff_len(uintmax_t input, unsigned int radix)
{
	size_t	i;

	if (input == 0)
		return (2);
	i = 1;
	while (radix > 1 && (input /= radix))
		++i;
	return (i);
}

void			ft_utoa_base(uintmax_t input, char *buffer, unsigned int radix)
{
	size_t	i;

	if (radix > 16)
		return ;
	i = buff_len(input, radix) - 1;
	buffer[i + 1] = '\0';
	if (input == 0)
		buffer[0] = '0';
	while ((input))
	{
		buffer[i] = SLIDER[input % radix];
		input /= radix;
		--i;
	}
}

char			*ft_utoadup(uintmax_t input, unsigned int radix)
{
	char	*buffer;

	if (radix <= 1
		|| radix >= (int)sizeof(SLIDER)
		|| !(buffer = malloc(sizeof(*buffer) * (buff_len(input, radix) + 1))))
		return (NULL);
	ft_utoa_base(input, buffer, radix);
	return (buffer);
}
