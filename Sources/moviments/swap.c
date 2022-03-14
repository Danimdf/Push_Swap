/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:56:24 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/14 11:27:08 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_a(t_stack **stack)
{
	int	temp;
	int	temp_index;

	if ((*stack)->size_stack == 1)
		return ;
	temp = (*stack)->stack_a->data;
	(*stack)->stack_a->data = (*stack)->stack_a->next->data;
	(*stack)->stack_a->next->data = temp;
	temp_index = (*stack)->stack_a->index;
	(*stack)->stack_a->index = (*stack)->stack_a->next->index;
	(*stack)->stack_a->next->index = temp_index;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack)
{
	int	temp;
	int	temp_index;

	if ((*stack)->size_stack == 1)
		return ;
	temp = (*stack)->stack_b->data;
	(*stack)->stack_b->data = (*stack)->stack_b->next->data;
	(*stack)->stack_b->next->data = temp;
	temp_index = (*stack)->stack_b->index;
	(*stack)->stack_b->index = (*stack)->stack_b->next->index;
	(*stack)->stack_b->next->index = temp_index;
	write(1, "sb\n", 3);
}

void	swap_s(t_stack **stack)
{
	swap_a(stack);
	swap_b(stack);
	write(1, "ss\n", 3);
}
