/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:56:24 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/13 22:51:55 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_a(t_stack **stack, int list_size)
{
	int	temp;
	int	temp_index;

	if (list_size == 1)
		return ;
	temp = (*stack)->stack_a->data;
	(*stack)->stack_a->data = (*stack)->stack_a->next->data;
	(*stack)->stack_a->next->data = temp;
	temp_index = (*stack)->stack_a->index;
	(*stack)->stack_a->index = (*stack)->stack_a->next->index;
	(*stack)->stack_a->next->index = temp_index;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack, int list_size)
{
	int	temp;
	int	temp_index;

	if (list_size == 1)
		return ;
	temp = (*stack)->stack_b->data;
	(*stack)->stack_b->data = (*stack)->stack_b->next->data;
	(*stack)->stack_b->next->data = temp;
	temp_index = (*stack)->stack_b->index;
	(*stack)->stack_b->index = (*stack)->stack_b->next->index;
	(*stack)->stack_b->next->index = temp_index;
	write(1, "sb\n", 3);
}

void	swap_s(t_stack **stack, int list_size)
{
	swap_a(stack, list_size);
	swap_b(stack, list_size);
	write(1, "ss\n", 3);
}
