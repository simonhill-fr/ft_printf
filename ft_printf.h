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
	int				placeholder_number;
	int 			minus;
	int 			plus;
	int 			space;
	int 			zero;
	int 			hash;
	int 			width;
	int 			pres;
	int 			length;
	struct s_param	*next;
}					t_param;


#endif
