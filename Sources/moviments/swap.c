/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:56:24 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/02 20:04:20 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void swap_a (t_stack *stack_a, int list_size)
{
	t_node *temp;
	t_node *first;
	t_node *second;
	if (list_size == 1)
		return ;
	first = &stack_a;
	second = first->next;
	temp = second->next;
	printf("%d\n", second);
}
/*─
	t_stack	*first;
	t_stack	*second;

	first = (*stack);
	second = first->next;
	tmp = second->next;
	second->next = NULL;
	second->prev = NULL;
	first->next = tmp;
	first->prev = second;
	if (tmp)
		tmp->prev = first;
	second->next = first;
	*stack = second; */


/* void swap_b (int list_size)
{
	if (list_size == 1)
		return ;

} */