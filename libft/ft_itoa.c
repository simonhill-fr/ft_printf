/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 15:44:25 by shill             #+#    #+#             */
/*   Updated: 2015/12/28 15:46:42 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	int				i;
	int				ab;

	if (n == (-2147483647 - 1))
		return (ft_strdup("-2147483648"));
	len = getlen(n);
	str = ft_strnew(len);
	ab = ft_abs(n);
	if (!str)
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		str[i] = 48 + ab % 10;
		ab = ab / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = 48;
	return (str);
}
