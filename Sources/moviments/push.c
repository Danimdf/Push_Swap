/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:20:55 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/12 11:51:53 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rmv_head_and_add(t_stack **stack, t_node **stack_mv, int *value_move, int *new_index)
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
	if ((*stack_mv) == (*stack)->stack_a)
		ft_lstadd_front(&(*stack)->stack_b, ft_lstnew(*value_move));
	else
		ft_lstadd_front(&(*stack)->stack_a, ft_lstnew(*value_move));
}

void	push_b(t_stack **stack)
{
	int	value_remove;
	int	new_index;

	if ((*stack)->stack_a)
		rmv_head_and_add(stack, &((*stack)->stack_a), &value_remove, &new_index);
	//print_me((*stack)->stack_a);
	write(2, "pb\n", 3);
}

void	push_a(t_stack **stack)
{
	int	value_remove;
	int	new_index;

	if ((*stack)->stack_b)
		rmv_head_and_add(stack, &((*stack)->stack_b), &value_remove, &new_index);
	//print_me((*stack)->stack_a);
	write(2, "pa\n", 3);
}
