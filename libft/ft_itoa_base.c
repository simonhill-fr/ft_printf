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

static  int get_char(int c)
{
	if (c >= 10 && c <= 15)
		return (c + 87);
	else
		return (c + 48);
}

static	char	*do_conversion(unsigned int x, int base, int n, char *str)
{
	int	d;
	int	i;

	i = 0;
	while (n >= 0)
	{
		d = x / (ft_pow(base, n));
		x = x - d * ft_pow(base, n);
		str[i] = get_char(d);
		n--;
		i++;
	}
	return (str);
}

char	*ft_itoa_base(unsigned int x, int base)
{
	int		n;
	char	*str;

	n = 0;
	if (x == 0)
		return (ft_strdup("0"));
	while (ft_pow(base, n) < x)
		n++;
	n--;
	str = ft_strnew(n);
	str = do_conversion(x, base, n, str);
	return (str);
}
