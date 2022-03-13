/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:45:53 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/12 20:13:34 by dmonteir         ###   ########.fr       */
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
		rotate_a(stacks);
	}
	order_four(stacks, list_size);
	push_a(stacks);
	print_me((*stacks)->stack_a);
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
		rotate_a(stacks);
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
	print_me((*stk)->stack_a);
	if ((*stk)->stack_a->data < (*stk)->stack_a->next->data && \
	(*stk)->stack_a->next->data < (*stk)->stack_a->next->next->data)
		return;
	if ((*stk)->stack_a->next->data < (*stk)->stack_a->data)
		next_smaller(stk, list_size);
	else if ((*stk)->stack_a->data < (*stk)->stack_a->next->data)
	{
		if ((*stk)->stack_a->data < (*stk)->stack_a->next->next->data && \
		(*stk)->stack_a->next->data > (*stk)->stack_a->next->next->data)
		{
			swap_a(stk, list_size);
			rotate_a(stk);
		}
		else
			reverse_rotate_a(stk);
	}
	print_me((*stk)->stack_a);
}

void	order_two(t_stack **stack, int list_size)
{
	if ((*stack)->stack_a->data > (*stack)->stack_a->next->data)
		swap_a(stack, list_size);
	print_me((*stack)->stack_a);
}

void	order(t_stack *stack)
{
	int	list_size_a;

	list_size_a = ft_lstsize(stack->stack_a);
	make_index_of_stack(&stack, &stack->stack_a);
	if (list_size_a == 2)
		order_two(&stack, list_size_a);
	else if (list_size_a == 3)
		order_three(&stack, list_size_a);
	else if (list_size_a == 4)
		order_four(&stack, list_size_a);
	else if (list_size_a == 5)
		order_five(&stack, list_size_a);
	else if (list_size_a == 6)
		order_six(&stack, list_size_a);
	else if (list_size_a == 7)
		order_seven(&stack, list_size_a);
	else
		radix_sort(&stack);
}

void	print_me(t_node *swap)
{
	while (swap)
	{
		printf("%d\n", swap->index);
		swap = swap->next;
	}
	printf("-----------\n");
}
