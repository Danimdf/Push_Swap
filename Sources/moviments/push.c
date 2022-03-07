/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:20:55 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/07 14:28:59 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rmv_head_and_add(t_stack **stack, t_node **stack_a, int *value_move)
{
	t_node	*temp;

	temp = (*stack_a);
	if (temp != NULL)
	{
		if (temp->next == NULL)
		{
			*value_move = temp->data;
			(*stack_a)->prev = NULL;
			free(*stack_a);
			*stack_a = NULL;
		}
		else
		{
			*value_move = temp->data;
			(*stack_a) = (*stack_a)->next;
			(*stack_a)->prev = NULL;
			free(temp);
		}
	}
	ft_lstadd_front(&(*stack)->stack_b, ft_lstnew(*value_move));
}

void	push_b(t_stack **stack)
{
	int	value_remove;

	if ((*stack)->stack_a)
		remove_head_and_add(stack, &((*stack)->stack_a), &value_remove);
	write(2, "pb\n", 3);
}

void	push_a(t_stack **stack)
{
	int	value_remove;

	if ((*stack)->stack_b)
		remove_head_and_add(stack, &((*stack)->stack_b), &value_remove);
	write(2, "pa\n", 3);
}
