/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 11:42:33 by shill             #+#    #+#             */
/*   Updated: 2016/09/15 11:42:36 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_param	*init_param(t_param *param)
{
	param->ret = 0;
	param->minus = FALSE;
	param->plus = FALSE;
	param->space = FALSE;
	param->negative = FALSE;
	param->zero = FALSE;
	param->hash = FALSE;
	param->width = 0;
	param->precision = -1;
	param->length = 0;
	param->len_flag = CLEAR;
	param->nulchar = FALSE;
	param->alpha = FALSE;
	param->empty_str = FALSE;
	return (param);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_functab	*func_array;
	t_param		*param;
	int			total;

	func_array = malloc(sizeof(t_functab) * 128);
	if (!(func_array))
		exit(EXIT_FAILURE);
	init_index_array(func_array);
	va_start(ap, format);
	param = malloc(sizeof(t_param));
	if (!param)
		exit(EXIT_FAILURE);
	total = parse(format, ap, func_array, param);
	va_end(ap);
	ft_memdel((void*)&param);
	ft_memdel((void*)&func_array);
	return (total);
}
