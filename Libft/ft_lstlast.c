/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:57:21 by dmonteir          #+#    #+#             */
/*   Updated: 2022/01/19 19:43:52 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
		 = lst->prev;
	}
	if (lst->next == NULL)
		return (lst);
	return (NULL);
}
