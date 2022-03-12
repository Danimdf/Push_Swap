/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:45:53 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/12 11:55:22 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void make_index_of_stack(t_stack **stacks, t_node **stack)
{
	int		*array;
	t_node	*temp;
	size_t	i;

	array = (int *)malloc(sizeof(int) * (*stacks)->size_stack);
	if (!array)
		error();
	i = 0;
	temp = (*stack);
	while(temp != NULL)
	{
		array[i] = temp->data;
		temp->index = i;
		temp = temp->next;
		i++;
	}
	free(array);
}

int	get_max_bits(t_node **stack_a)
{
	t_node	*stack;
	int		max;
	int		max_bits;

	stack = (*stack_a);
	max = stack->index;
	max_bits = 0;
	//printf("%d\n", stack->index);

	while (stack != NULL)
	{
		//printf("oii");
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
		//stack->index++;
		//printf("%d\n", max);
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	//printf("%d\n", max_bits);
	return (max_bits);
}

void	radix_sort(t_stack **stacks, int list_size_a, int list_size_b)
{
	int		i;
	int		j;
	int		max_bits;
	t_node	*stack;



	stack = (*stacks)->stack_a;
	i = 0;
	make_index_of_stack(stacks, &(*stacks)->stack_a);
	max_bits = get_max_bits(&(*stacks)->stack_a);
	//print_me(stack);
	while (i < max_bits)
	{
		j = 0;
		while (stack != NULL)
		{
			if (((stack->index >> i) & 1) == 0)
				rotate_a(stacks, list_size_a);
			else
				push_b(stacks);
			//printf("oii2\n");;
			stack = stack->next;
		}
		//printf("oiii1");
		while (list_size_b != 0)
			push_a(stacks);
		i++;
	}
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

int	min_value(t_node *stack)
{
	int	min;

	min = 0;
	if (stack)
	{
		min = stack->data;
		while (stack != NULL)
		{
			if (stack->data < min)
				min = stack->data;
			stack = stack->next;
		}
	}
	return (min);
}


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
