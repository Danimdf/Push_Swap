/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:44:34 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/14 10:25:08 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_a_or_b_back(int value_move, t_node **stack_mv, int new_index)
{
	t_node	*temp;
	t_node	*new_back;

	if ((*stack_mv) == NULL)
		init_stack(stack_mv, value_move, new_index);
	else
	{
		new_back = (t_node *)malloc(sizeof(t_node));
		if (!new_back)
			error();
		new_back->data = value_move;
		new_back->index = new_index;
		temp = (*stack_mv);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_back;
		new_back->prev = temp;
		new_back->next = NULL;
	}
}

void	rotate_a(t_stack **stack)
{
	int	value_remove;
	int	new_index;

	if ((*stack)->stack_a && (*stack)->stack_a->next != NULL)
	{
		rmv_head(&((*stack)->stack_a), &value_remove, &new_index);
		stack_a_or_b_back(value_remove, &((*stack)->stack_a), new_index);
	}
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack)
{
	int	value_remove;
	int	new_index;

	if ((*stack)->stack_b)
	{
		rmv_head(&((*stack)->stack_b), &value_remove, &new_index);
		stack_a_or_b_back(value_remove, &((*stack)->stack_b), new_index);
	}
	write(1, "rb\n", 3);
}

void	rotate_r(t_stack **stack)
{
	rotate_a(stack);
	rotate_b(stack);
	write(1, "rr\n", 3);
}