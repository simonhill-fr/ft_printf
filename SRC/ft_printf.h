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
#include "../libft/libft.h"

#include <stdio.h> //REMOVE
#include <limits.h> // REMOVE

#define TRUE 		1
#define FALSE 		0
	
#define DIGIT		2
#define EMPTY		-1

//replace by enum
#define INT 		0
#define	CHAR 		1
#define SHORT 		2
#define LONG		3
#define LONG_LONG	4
#define SIZE_T		5
#define INTMAX		6

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

union	u_types
{
	int 			i;
	long 			l;
	long long 		ll;
	size_t 			szt;
	intmax_t		imax;
};

int		ft_printf(const char *format, ...);

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

int 	short_len(va_list ap, t_param *param);
int 	long_len(va_list ap, t_param *param);
int 	sizet_len(va_list ap, t_param *param);
int 	intmax_len(va_list ap, t_param *param);


#endif
