/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 16:54:53 by shill             #+#    #+#             */
/*   Updated: 2016/09/18 16:54:57 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width(t_param *param, int n)
{
	int		i;

	i = 1 + n;
	while (i <= param->width)
	{
		ft_putchar(' ');
		i++;
	}
}

/*int		print_decimal(size_t n, t_param *param)
{
	if (n > 0 && param->plus == TRUE)
		ft_putchar('+');
	else if (n > 0 && param->space == TRUE)
		ft_putchar(' ');
	ft_putnbr(n);
	return (0);

}*/