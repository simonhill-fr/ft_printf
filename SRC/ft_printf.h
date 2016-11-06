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
#define	SET			1
#define	CLEAR		0
#define	SIGNED		1
#define	UNSIGNED	0

/*
RETURN VALUES
*/
#define	END			0
#define DIGIT		-2
#define EMPTY		-1

#define INT 		0
#define	CHAR 		1
#define SHORT 		2
#define LONG		3
#define LONG_LONG	4
#define SIZE_T		5
#define INTMAX		6

typedef struct 		s_param
{
	int				ret;
	int 			minus;
	int 			plus;
	int 			space;
	int				negative;
	int 			zero;
	int 			hash;
	int 			width;
	int 			precision;
	int 			length;
	int				nulchar;
	int				alpha;
	int				empty_str;
}					t_param;

typedef	int (*t_functab)(va_list, t_param *);
typedef	uintmax_t (*t_ftab_cast)(va_list, int);


union	u_types
{
	int 			i;
	long 			l;
	long long 		ll;
	size_t 			szt;
	intmax_t		imax;
};

int				ft_printf(const char *format, ...);

int				decimal(va_list ap, t_param *param);
int				udecimal(va_list ap, t_param *param);
int				character(va_list ap, t_param *param);
int				string(va_list ap, t_param *param);
int				hexadecimal(va_list ap, t_param *param);
int				upper_hexadecimal(va_list ap, t_param *param);
int				octal(va_list ap, t_param *param);

int				placeholder(va_list ap, t_param *param);
int 			empty(va_list ap, t_param *param);
int 			digit(va_list ap, t_param *param);

int				minus(va_list ap, t_param *param);
int 			plus(va_list ap, t_param *param);
int				space(va_list ap, t_param *param);
int				zero(va_list ap, t_param *param);
int				hash(va_list ap, t_param *param);

uintmax_t 		cast_int(va_list ap, int is_signed);
uintmax_t 		cast_char(va_list ap, int is_signed);
uintmax_t 		cast_short(va_list ap, int is_signed);
uintmax_t 		cast_long(va_list ap, int is_signed);
uintmax_t 		cast_longlong(va_list ap, int is_signed);
uintmax_t 		cast_sizet(va_list ap, int is_signed);
uintmax_t 		cast_intmax(va_list ap, int is_signed);

void			init_index_array(t_functab *func_array);
void			init_integer_array(t_functab *int_array);
t_ftab_cast		*init_cast_array(void);

void			final_print(t_param *param, char *str, char *prefix, int sign);

int 			short_len(va_list ap, t_param *param);
int 			long_len(va_list ap, t_param *param);
int 			sizet_len(va_list ap, t_param *param);
int 			intmax_len(va_list ap, t_param *param);

int				get_int_len(uintmax_t n);


#endif
