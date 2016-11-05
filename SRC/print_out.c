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

int		get_width_len(t_param *param, int prefix_len, int nb_len)
{
	int width_len;

	width_len = nb_len;
	if (param->plus || param->space || param->negative)
		width_len += 1;
	if (param->precision > width_len)
	{
		param->precision -= width_len;	
		width_len += param->precision;
	}
	else if (param->precision < width_len)
		param->precision = 0;
	if (param->hash)
		width_len += prefix_len;
	if (param->width > width_len)
	{
		param->width -= width_len;
		width_len += param->width;
	}
	else if (param->width < width_len)
		param->width = 0;
	return width_len;
}

void	print_padding(t_param *param, int len, char c)
{
	int		i;

	i = 0;
	while (i < len)
	{
		param->ret += ft_putchar(c);
		i++;
	}
}

void	print_prefix(t_param *param, char *prefix)
{
	param->ret += ft_putstr(prefix);
}

void	print_sign(t_param *param, int nb)
{
	if ((param->space == TRUE && nb < 0) || (param->plus == TRUE && nb < 0)
		|| param->negative)
		param->ret += ft_putchar('-');
	else if (param->plus == TRUE && nb > 0)
		param->ret += ft_putchar('+');
	else if (param->space == TRUE && nb > 0)
		param->ret += ft_putchar(' ');
}

void	final_print(t_param *param, char *str, char *prefix, int sign)
{
	if (param->hash)
		param->hash = ft_strlen(prefix);
	get_width_len(param, param->hash, ft_strlen(str));
	if (param->width && param->zero == FALSE && param->minus == FALSE)
		print_padding(param, param->width, ' ');
	if (param->hash)
		print_prefix(param, prefix);
	if (param->precision && param->alpha == FALSE)
		print_padding(param, param->precision, '0');
	if (param->width && param->zero == TRUE)
		print_padding(param, param->width, '0');
	if (param->space || param->plus || param->negative)
		print_sign(param, sign);
	param->ret += ft_putstr(str);
	if (param->minus)
		print_padding(param, param->width, ' ');
	//remember to free
}
