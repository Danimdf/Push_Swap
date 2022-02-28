/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:31:24 by dmonteir          #+#    #+#             */
/*   Updated: 2022/02/28 17:19:32 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*ptr;

	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	ptr = ft_lstlast(*lst);
	ptr->next = new;
	new->prev = lst;
}
