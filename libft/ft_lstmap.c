/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 13:36:02 by shill             #+#    #+#             */
/*   Updated: 2016/01/09 13:36:11 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list		*tmp;

	if (*alst != NULL)
	{
		tmp = *alst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*alst = new;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*fresh;

	fresh = NULL;
	while (lst)
	{
		ft_lstadd_end(&fresh, f(lst));
		lst = lst->next;
	}
	return (fresh);
}
