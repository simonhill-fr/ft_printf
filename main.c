/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 11:42:33 by shill             #+#    #+#             */
/*   Updated: 2016/09/15 11:42:36 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //REMOVE
#include <stdarg.h>

int	ft_printf(int max, ...)
{
	int 		i = 0;
	int			nb = 0;

	va_list		ap;
	va_start(ap, max);
	while (i < max)
	{
		nb = va_arg(ap, int);
		printf("%d\n", nb);
		i++;
	}
	va_end(ap);
	return (0);




}


int 	main()
{
//	ft_printf(50, 66, 55);
	printf("asf\n");


	return (0);

}
