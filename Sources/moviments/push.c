/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:20:55 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/14 12:21:12 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rmv_head(t_node **stack_mv, int *value_move, int *new_index)
{
	t_node	*temp;

	temp = (*stack_mv);
	if (temp != NULL)
	{
		if (temp->next == NULL)
		{
			*value_move = temp->data;
			*new_index = temp->index;
			(*stack_mv)->prev = NULL;
			free(*stack_mv);
			*stack_mv = NULL;
		}
		else
		{
			*value_move = temp->data;
			*new_index = temp->index;
			(*stack_mv) = (*stack_mv)->next;
			(*stack_mv)->prev = NULL;
			free(temp);
		}
	}
}

void	stack_a_or_b_front(int value_move, t_node **stack_mv, int new_index)
{
	t_node	*temp;
	t_node	*new_head;

	if ((*stack_mv) == NULL)
		init_stack(stack_mv, value_move, new_index);
	else
	{
		new_head = (t_node *)malloc(sizeof(t_node));
		if (!new_head)
			error();
		temp = (*stack_mv);
		*stack_mv = new_head;
		new_head->next = temp;
		temp->prev = (*stack_mv);
		new_head->data = value_move;
		new_head->index = new_index;
	}
}

void	push_a(t_stack **stack)
{
	int	value_remove;
	int	new_index;

	if ((*stack)->stack_a)
	{
		rmv_head(&((*stack)->stack_b), &value_remove, &new_index);
		stack_a_or_b_front(value_remove, &((*stack)->stack_a), new_index);
	}
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stack)
{
	int	value_remove;
	int	new_index;

	if ((*stack)->stack_b)
	{
		rmv_head(&((*stack)->stack_a), &value_remove, &new_index);
		stack_a_or_b_front(value_remove, &((*stack)->stack_b), new_index);
	}
	write(1, "pb\n", 3);
}
