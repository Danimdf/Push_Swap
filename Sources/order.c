/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:45:53 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/08 12:08:31 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	order(t_stack *stack)
{
	int	list_size;

	list_size = ft_lstsize(stack->stack_a);
	if (list_size == 2)
		order_two(&stack, list_size);
	else if (list_size == 3)
		order_three(stack, list_size);
	/* else if (list_size <= 5)
		order_five(&stack, list_size); */
}

/* void order_five(t_stack **stack, int list_size)
{

} */
void	order_two(t_stack **stack, int list_size)
{
	if ((*stack)->stack_a->data > (*stack)->stack_a->next->data)
		swap_a(stack, list_size);
}

void	order_three(t_stack **stk, int list_size)
{
	if ((*stk)->stack_a->next->data < (*stk)->stack_a->data)
		next_smaller(stk, list_size);
	else if ((*stk)->stack_a->data < (*stk)->stack_a->next->data)
	{
		if ((*stk)->stack_a->data < (*stk)->stack_a->next->next->data)
		{
			swap_a(stk, list_size);
			rotate_a(stk, list_size);
		}
		else
			reverse_rotate_a(stk);
	}
}

void	next_smaller(t_stack **stk, int list_size)
{
	if ((*stk)->stack_a->next->next->data > (*stk)->stack_a->next->data && \
	(*stk)->stack_a->next->next->data > (*stk)->stack_a->data)
		swap_a(stk, list_size);
	else if ((*stk)->stack_a->next->next->data < \
	(*stk)->stack_a->next->data && \
	(*stk)->stack_a->next->next->data < (*stk)->stack_a->data)
	{
		swap_a(stk, list_size);
		reverse_rotate_a(stk);
	}
	else if ((*stk)->stack_a->next->next->data > \
	(*stk)->stack_a->next->data && \
	(*stk)->stack_a->next->next->data < (*stk)->stack_a->data)
		rotate_a(stk, list_size);
}

void	print_me(t_node *swap)
{
	while (swap)
	{
		printf("%d\n", swap->data);
		swap = swap->next;
	}
	printf("-----------\n");
}
