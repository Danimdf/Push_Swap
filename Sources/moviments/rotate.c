/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:44:34 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/08 11:05:58 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_a(t_stack **stack, int list_size)
{
	t_node	*temp;

	if (list_size == 1)
		return ;
	temp = (*stack)->stack_a;
	(*stack)->stack_a = (*stack)->stack_a->next;
	(*stack)->stack_a->prev = NULL;
	ft_lstadd_back(&((*stack)->stack_a), temp);
	write(2, "ra\n", 3);
}

void	rotate_b(t_stack **stack, int list_size)
{
	t_node	*temp;

	if (list_size == 1)
		return ;
	temp = (*stack)->stack_b;
	(*stack)->stack_b = (*stack)->stack_b->next;
	(*stack)->stack_b->prev = NULL;
	ft_lstadd_back(&((*stack)->stack_b), temp);
	write(2, "rb\n", 3);
}

void	rotate_r(t_stack **stack, int list_size)
{
	rotate_a(stack, list_size);
	rotate_b(stack, list_size);
	write(2, "rr\n", 3);
}
