/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:40:48 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/14 14:42:10 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	order_six(t_stack **stacks, int list_size)
{
	int		min;
	t_node	*stack;

	stack = (*stacks)->stack_a;
	min = min_value((*stacks)->stack_a);
	while (stack != NULL)
	{
		if (stack->data == min)
		{
			push_b(stacks);
			break ;
		}
		stack = stack->next;
		rotate_a(stacks);
	}
	order_five(stacks, list_size);
	push_a(stacks);
}

void	order_seven(t_stack **stacks, int list_size)
{
	int		min;
	t_node	*stack;

	stack = (*stacks)->stack_a;
	min = min_value((*stacks)->stack_a);
	while (stack != NULL)
	{
		if (stack->data == min)
		{
			push_b(stacks);
			break ;
		}
		stack = stack->next;
		rotate_a(stacks);
	}
	order_six(stacks, list_size);
	push_a(stacks);
}