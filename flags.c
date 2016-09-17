/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 17:47:08 by shill             #+#    #+#             */
/*   Updated: 2016/09/17 17:47:10 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	minus(va_list ap, t_param *param)
{
	param->minus = TRUE;
	return (1);
}

int plus(va_list ap, t_param *param)
{
	param->plus = TRUE;
	param->space = FALSE;
	return (1);
}

int	space(va_list ap, t_param *param)
{
	if (param->plus == FALSE)
		param->space = TRUE;
	return (1);
}

int	zero(va_list ap, t_param *param)
{
	param->zero = TRUE;
	return (1);
}

int	hash(va_list ap, t_param *param)
{
	param->hash = TRUE;
	return (1);
}