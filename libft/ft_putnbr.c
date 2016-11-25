/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 15:24:30 by shill             #+#    #+#             */
/*   Updated: 2015/12/28 15:28:05 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(intmax_t n)
{
	int	ret;

	ret = 0;
	if (n == (intmax_t)ft_pow(256, sizeof(intmax_t)))
	{
		if (n < -9223372036854775807)
			ret += ft_putstr("-9223372036854775808");
		else if (n < -2147483647)
			ret += ft_putstr("-2147483648");
		return (ret);
	}
	else if (n < 0)
	{
		ret += ft_putchar('-');
		ret += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ret += ft_putnbr(n / 10);
		ret += ft_putnbr(n % 10);
	}
	else if (n < 10)
		ret += ft_putchar(n + '0');
	return (ret);
}
