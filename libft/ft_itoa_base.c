/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 10:56:20 by shill             #+#    #+#             */
/*   Updated: 2016/09/25 10:56:43 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>//REMOVE

//#define	RADIX		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

static  int		get_char(int c)
{
	
	if (c >= 10 && c <= 15)
		return (c + 87);
	else
		return (c + 48);
}

static	char	*do_conversion(unsigned long x, int base, int n, char *str)
{
	unsigned long long	d;
	int					i;

	i = 0;
	while (n >= 0)
	{
		d = x / (ft_pow(base, n));
		x = x - d * ft_pow(base, n);
		if (d == 16)
		{
			str[i] = '1';
			str[i + 1] = '0';
			i++;;
		}
		else
			str[i] = get_char(d);
		n--;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa_base(unsigned long x, int base)
{
	int		n;
	char	*str;

	n = 0;
	if (x == 0)
		return (ft_strdup("0"));
	while (ft_pow(base, n) < x)
		n++;
	n--;
	str = ft_strnew(n);
	str = do_conversion(x, base, n, str);
		
	return (str);
}


/* ------- OTHER VERSION ------- */
/*static size_t	nbrlen(int input, unsigned int radix)
{
  size_t	i;

  i = 1;
  if (input < 0)
    ++i;
  while (radix > 1 && (input /= radix))
    ++i;
  return (i);
}

void		ft_itoa_base(long input, char *buffer, unsigned int radix)
{
  size_t	i;

  i = nbrlen(input, radix) - 1;
  buffer[i] = '\0';
  if (input < 0)
    buffer[0] = '-';
  while ((input))
    {
      buffer[i] = RADIX[ft_abs(input) % radix];
      input /= radix;
      --i;
    }
}

char *		itoadup(int input, unsigned int radix)
{
  char *	buffer;

  if (radix <= 1
      || radix >= (int)sizeof(RADIX)
      || !(buffer = malloc(sizeof(*buffer)
			   * ((nbrlen(input, radix) - 1) + 2))))
    return (NULL);
  ft_itoa_base(input, buffer, radix);
  return (buffer);
}
*/
