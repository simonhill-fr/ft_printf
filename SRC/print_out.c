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
	char	c;

	c = ' ';
	if (param->zero == TRUE)
		c = '0';
	i = 1 + n;
	while (i <= param->width)
	{
		param->ret += ft_putchar(c);
		i++;
	}
	if (n >= 0 && param->plus == TRUE)
		param->ret += ft_putchar('+');
	else if (n > 0 && param->space == TRUE)
		param->ret += ft_putchar(' ');
}
