/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:45:53 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/12 13:31:02 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	order_five(t_stack **stacks, int list_size)
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
		rotate_a(stacks, list_size);
	}
	order_four(stacks, list_size);
	push_a(stacks);
	//print_me((*stacks)->stack_a);
}

void	order_four(t_stack **stacks, int list_size)
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
		rotate_a(stacks, list_size);
	}
	print_me((*stacks)->stack_a);
	print_me((*stacks)->stack_b);
	//printf("%d\n", (*stacks)->stack_b->index);
	order_three(stacks, list_size);
	push_a(stacks);
	print_me((*stacks)->stack_a);
	print_me((*stacks)->stack_b);
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

void	order_two(t_stack **stack, int list_size)
{
	if ((*stack)->stack_a->data > (*stack)->stack_a->next->data)
		swap_a(stack, list_size);
}

void	order(t_stack *stack)
{
	int	list_size_a;
	int	list_size_b;

	list_size_a = ft_lstsize(stack->stack_a);
	list_size_b = ft_lstsize(stack->stack_b);
	if (list_size_a == 2)
		order_two(&stack, list_size_a);
	else if (list_size_a == 3)
		order_three(&stack, list_size_a);
	else if (list_size_a == 4)
		order_four(&stack, list_size_a);
	else if (list_size_a == 5)
		order_five(&stack, list_size_a);
	else
		radix_sort(&stack, list_size_a, list_size_b);
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
