/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:44:34 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/14 14:46:27 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rmv_head_and_add_back(t_stack **stack, t_node **stack_mv, \
int *value_move, int *new_index)
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
	stack_a_or_b_back(stack, value_move, stack_mv, new_index);
}

void	stack_a_or_b_back(t_stack **stack, int *value_move, t_node **stack_mv, \
int *new_index)
{
	if ((*stack_mv) == (*stack)->stack_a)
		ft_lstadd_back(&(*stack)->stack_a, ft_lstnew(*value_move, *new_index));
	else
		ft_lstadd_back(&(*stack)->stack_b, ft_lstnew(*value_move, *new_index));
}

void	rotate_a(t_stack **stack)
{
	int	value_remove;
	int	new_index;

	if ((*stack)->stack_a)
		rmv_head_and_add_back(stack, &((*stack)->stack_a), &value_remove, \
		&new_index);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack)
{
	int	value_remove;
	int	new_index;

	if ((*stack)->stack_b)
		rmv_head_and_add_back(stack, &((*stack)->stack_a), &value_remove, \
		&new_index);
	write(1, "rb\n", 3);
}

void	rotate_r(t_stack **stack)
{
	rotate_a(stack);
	rotate_b(stack);
	write(1, "rr\n", 3);
}
