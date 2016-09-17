/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 13:39:56 by shill             #+#    #+#             */
/*   Updated: 2016/09/15 13:46:46 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

#include <stdio.h> //REMOVE

#define TRUE 	1
#define FALSE 	0

typedef struct 		s_param
{
	int 			minus;
	int 			plus;
	int 			space;
	int 			zero;
	int 			hash;
	int 			width;
	int 			precision;
	int 			length;
}					t_param;

int	dec(va_list ap, t_param *param);
int	character(va_list ap, t_param *param);
int	string(va_list ap, t_param *param);

int	minus(va_list ap, t_param *param);
int plus(va_list ap, t_param *param);
int	space(va_list ap, t_param *param);
int	zero(va_list ap, t_param *param);
int	hash(va_list ap, t_param *param);




#endif
