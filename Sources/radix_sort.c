/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:03:25 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/14 14:34:59 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_stack **stacks)
{
	int		i;
	int		j;
	int		size;
	t_node	*stack;
	//t_node	*temp;
	int		bits;

	i = 0;
	size = (*stacks)->size_stack;
	stack = (*stacks)->stack_a;
	bits = get_bits(&stack);
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			stack = (*stacks)->stack_a;
			//temp = stack->next;
			if (stack == NULL)
				break ;
			if (((stack->index >> i) & 1) == 1)
				rotate_a(stacks);
			else
				push_b(stacks);
			//stack = temp;
			//printf("%d\n", stack->index);
			j++;
		}
		//printf("%d\n", i);
		//print_me((*stacks)->stack_a);
		//print_me((*stacks)->stack_b);
		while (ft_lstsize((*stacks)->stack_b) != 0)
			push_a(stacks);
		//print_me((*stacks)->stack_a);
		i++;
	}
	print_me((*stacks)->stack_a);
}

int	not_sorted(t_stack **stacks)
{
	int		boolean;
	t_node	*first;
	t_node	*second;

	boolean = 0;
	first = (*stacks)->stack_a;
	second = (*stacks)->stack_a;
	while (second->next != NULL)
	{
		second = second->next;
		if (first->index > second->index)
		{
			boolean = 1;
			break ;
		}
		first = first->next;
	}
	return (boolean);
}

int	get_bits(t_node **stack)
{
	t_node	*head;
	int		max;
	int		max_bits;

	head = (*stack);
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	//printf("%d\n", max_bits);
	return (max_bits);
}