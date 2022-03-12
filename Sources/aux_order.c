/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:07:56 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/12 13:31:21 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min_value(t_node *stack)
{
	int	min;

	min = 0;
	if (stack)
	{
		min = stack->data;
		while (stack != NULL)
		{
			if (stack->data < min)
				min = stack->data;
			stack = stack->next;
		}
	}
	return (min);
}

void	next_smaller(t_stack **stk, int list_size)
{
	if ((*stk)->stack_a->next->next->data > (*stk)->stack_a->next->data && \
	(*stk)->stack_a->next->next->data > (*stk)->stack_a->data)
		swap_a(stk, list_size);
	else if ((*stk)->stack_a->next->next->data < \
	(*stk)->stack_a->next->data && \
	(*stk)->stack_a->next->next->data < (*stk)->stack_a->data)
	{
		swap_a(stk, list_size);
		reverse_rotate_a(stk);
	}
	else if ((*stk)->stack_a->next->next->data > \
	(*stk)->stack_a->next->data && \
	(*stk)->stack_a->next->next->data < (*stk)->stack_a->data)
		rotate_a(stk, list_size);
}
