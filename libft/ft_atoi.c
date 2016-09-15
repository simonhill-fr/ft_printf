/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:13:02 by shill             #+#    #+#             */
/*   Updated: 2016/07/25 15:18:36 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int	ft_atoi(char *str)
{
	int		res;
	int		i;
	int		sign;
	int		d;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		d = str[i] - '0';
		if (res > (INT_MAX - d) / 10)
			return (sign == 1) ? INT_MAX : INT_MIN;
		res = res * 10 + d;
		i++;
	}
	return (res * sign);
}
