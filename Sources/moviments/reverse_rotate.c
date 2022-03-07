/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:16:31 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/07 15:16:58 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate_a(t_stack **stack)
{
	int	value_remove;

	if ((*stack)->stack_a)
		rmv_back_and_add(&((*stack)->stack_a), &value_remove);
	write(2, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **stack)
{
	int	value_remove;

	if ((*stack)->stack_b)
		rmv_back_and_add(&((*stack)->stack_b), &value_remove);
	write(2, "rrb\n", 4);
}

void	reverse_rotate_r(t_stack **stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
	write(2, "rrb\n", 4);
}

void	rmv_back_and_add(t_node **stack_mv, int *value_move)
{
	t_node	*temp;

	temp = (*stack_mv);
	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		*value_move = temp->data;
		temp = temp->prev;
		free(temp->next);
		temp->next = NULL;
	}
	ft_lstadd_front(stack_mv, ft_lstnew(*value_move));
}
