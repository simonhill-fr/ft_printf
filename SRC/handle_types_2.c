/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_types_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:27:13 by shill             #+#    #+#             */
/*   Updated: 2016/11/03 13:27:15 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	character(va_list ap, t_param *param)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = va_arg(ap, int);
	if (str[0] == '\0')
		param->nulchar = TRUE;
	param->alpha = TRUE;
	final_print(param, str, "", 0);	
	return (END);
}

int	string(va_list ap, t_param *param)
{
	char 	*str;

	str = va_arg(ap, char *);
	if (!(str))
		str = ft_strdup("(null)");
	param->alpha = TRUE;
	if (ft_strcmp(str, "") == 0 && param->width == 0)
	{
		param->empty_str = TRUE;
	}
	if (param->precision != -1){
		str = ft_strndup(str, param->precision);
		param->precision = -1;
	}

	final_print(param, str, "", 0);
	return (0);
}

int	pointer(va_list ap, t_param *param)
{
	param->length = INTMAX;
	param->hash = TRUE;
	uintmax_t	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, UNSIGNED);	
	str = ft_utoadup(nb, 16);
	check_zero_exception(param, nb, str, TRUE);
	final_print(param, str, "0x", 0);	
	return (END);
}