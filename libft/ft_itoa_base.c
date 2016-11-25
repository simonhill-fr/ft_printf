/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 10:56:20 by shill             #+#    #+#             */
/*   Updated: 2016/09/25 10:56:43 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This function was created for ft_printf, and is not tested for radix != 10
**	It does not return '-' in case input number is positive
*/

#define SLIDER "0123456789abcdefghijklmnopqrstuvwxyz"
#define MAX (intmax_t)ft_pow(256, sizeof(intmax_t))

static size_t	buff_len(intmax_t input, unsigned int radix)
{
	size_t	i;

	if (input == MAX)
		return (19);
	if (input == 0)
		return (2);
	i = 1;
	input = ft_abs(input);
	while (radix > 1 && (input /= radix))
		++i;
	return (i);
}

void			ft_itoa_base(intmax_t input, char *buffer, unsigned int radix)
{
	size_t	i;

	if (input == MAX)
	{
		ft_strcpy(buffer, "9223372036854775808");
		return ;
	}
	if (radix > 16)
		return ;
	i = buff_len(input, radix) - 1;
	if (input == 0)
		buffer[0] = '0';
	buffer[i + 1] = '\0';
	input = ft_abs(input);
	while ((input))
	{
		buffer[i] = SLIDER[input % radix];
		input /= radix;
		--i;
	}
}

char			*ft_itoadup(intmax_t input, unsigned int radix)
{
	char	*buffer;

	if (radix <= 1
		|| radix >= (int)sizeof(SLIDER)
		|| !(buffer = malloc(sizeof(*buffer) * (buff_len(input, radix) + 1))))
		return (NULL);
	ft_itoa_base(input, buffer, radix);
	return (buffer);
}
