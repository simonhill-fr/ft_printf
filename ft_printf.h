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

#define TRUE 		1
#define FALSE 		0
	
#define DIGIT		2
#define EMPTY		-1

#define CHAR 		0
#define SHORT 		1
#define LONG		2
#define LONGLONG	3
#define SIZE_T		4
#define INTMAX		5

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

typedef	int (*t_functab)(va_list, t_param *);

int		integer(va_list ap, t_param *param);
int		character(va_list ap, t_param *param);
int		string(va_list ap, t_param *param);

int		placeholder(va_list ap, t_param *param);
int 	empty(va_list ap, t_param *param);
int 	digit(va_list ap, t_param *param);

int		minus(va_list ap, t_param *param);
int 	plus(va_list ap, t_param *param);
int		space(va_list ap, t_param *param);
int		zero(va_list ap, t_param *param);
int		hash(va_list ap, t_param *param);

void	init_index_array(t_functab *func_array);
void	init_integer_array(t_functab *int_array);
void	print_width(t_param *param, int n);

int 	long_len(va_list ap, t_param *param);


#endif
