/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saf_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 17:19:44 by shill             #+#    #+#             */
/*   Updated: 2015/12/27 17:19:48 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_safe_malloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		exit(EXIT_FAILURE);
	ft_memset(mem, '\0', size);
	return (mem);
}
