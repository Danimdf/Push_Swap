/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:16:31 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/14 11:44:05 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rmv_back_and_add(t_node **stack_mv, int *value_move, int *new_index)
{
	t_node	*temp;

	temp = (*stack_mv);
	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		*value_move = temp->data;
		*new_index = temp->index;
		temp = temp->prev;
		free(temp->next);
		temp->next = NULL;
	}
}

void	reverse_rotate_a(t_stack **stack)
{
	int	value_remove;
	int	new_index;

	if ((*stack)->stack_a)
	{
		rmv_back_and_add(&((*stack)->stack_a), &value_remove, &new_index);
		stack_a_or_b_front(value_remove, &((*stack)->stack_a), new_index);
	}
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **stack)
{
	int	value_remove;
	int	new_index;

	if ((*stack)->stack_b)
	{
		rmv_back_and_add(&((*stack)->stack_b), &value_remove, &new_index);
		stack_a_or_b_front(value_remove, &((*stack)->stack_b), new_index);
	}
	write(1, "rrb\n", 4);
}

void	reverse_rotate_r(t_stack **stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
	write(1, "rrr\n", 4);
}
