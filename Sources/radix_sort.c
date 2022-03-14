/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:03:25 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/14 08:14:50 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_stack **stacks, t_node **stack_a)
{
	int		i;
	int		j;
	int		size;
	t_node	*stack;
	t_node	*temp;

	i = 0;
	size = (*stacks)->size_stack;
	stack = (*stacks)->stack_a;
	while (sorted(stacks) == 1)
	{
		j = 0;
		while (j < size)
		{
			temp = (*stack_a)->next;
			if (temp == NULL)
				break ;
			if (((stack->index >> i) & 1) == 1)
				rotate_a(stacks);
			else
				push_b(stacks);
			stack = temp;
			j++;
		}
		while (ft_lstsize((*stacks)->stack_b) != 0)
			push_a(stacks);
		i++;
	}
	print_me((*stacks)->stack_a);
}

int	sorted(t_stack **stacks)
{
	int		boolean;
	t_node	*first;
	t_node	*second;

	boolean = 0;
	first = (*stacks)->stack_a;
	second = (*stacks)->stack_a;
	//slow = (*stack_a)->next;
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
