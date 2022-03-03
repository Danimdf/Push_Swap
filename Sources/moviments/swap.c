/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:56:24 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/03 08:21:19 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_a (t_stack *stack, int list_size)
{
	int temp;

	if (list_size == 1)
		return ;
	temp = stack->stack_a->data;
	stack->stack_a->data = stack->stack_a->next->data;
	stack->stack_a->next->data = temp;
	write(2, "sa\n", 3);
}

void	swap_b (t_stack *stack, int list_size)
{
	int temp;

	if (list_size == 1)
		return ;
	temp = stack->stack_b->data;
	stack->stack_b->data = stack->stack_b->next->data;
	stack->stack_b->next->data = temp;
	write(2, "sb\n", 3);
}

void	swap_s (t_stack *stack, int list_size)
{
	swap_a(stack, list_size);
	swap_b(stack, list_size);
	write(2, "ss\n", 3);
}
