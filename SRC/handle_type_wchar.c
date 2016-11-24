/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_type_wchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:13:15 by shill             #+#    #+#             */
/*   Updated: 2016/11/07 19:13:17 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wfinal_print(t_param *param, wchar *str, char *prefix, int sign)
{
	if (param->hash)
		param->hash = ft_strlen(prefix);
	get_width_len(param, param->hash, ft_wstr_bytes(str));
	if (param->width && param->zero == FALSE && param->minus == FALSE)
		print_padding(param, param->width, ' ');
	if (param->hash)
		print_prefix(param, prefix);
	if (param->space || param->plus || param->negative)
		print_sign(param, sign);
	if (param->precision)
	{
		if (param->alpha == FALSE)
			print_padding(param, param->precision, '0');
		else if (param->empty_str == TRUE)
			print_padding(param, param->precision, ' ');
	}
	if (param->width && param->zero == TRUE)
		print_padding(param, param->width, '0');
	if (param->nulchar)
		param->ret += ft_putchar('\0');
	else
		param->ret += ft_wputstr(str);
	if (param->minus)
		print_padding(param, param->width, ' ');
}

int		w_character(va_list ap, t_param *param)
{
	wchar	*str;

	str = malloc(sizeof(wchar) * 2);
	str[0] = va_arg(ap, unsigned int);
	if (str[0] == L'\0')
		param->nulchar = TRUE;
	str[1] = L'\0';
	param->alpha = TRUE;
	wfinal_print(param, str, "", 0);
	return (END);
}

int		w_string(va_list ap, t_param *param)
{
	wchar	*str;

	str = va_arg(ap, unsigned int *);
	if (str == L'\0')
		str = ft_wstrdup((wchar *)L"(null)");
	param->alpha = TRUE;
	if (ft_wstrcmp(str, (wchar *)L"") == 0 && param->width == 0)
	{
		param->empty_str = TRUE;
	}
	if (param->precision != -1)
	{
		str = ft_wstrndup(str, param->precision);
		param->precision = -1;
	}
	wfinal_print(param, str, "", 0);
	return (0);
}
