/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:03:25 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/13 21:07:48 by dmonteir         ###   ########.fr       */
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
	stack = (*stack_a);
	while (sorted(stack_a))
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
}

int	sorted(t_node **stack_a)
{
	int		boolean;
	t_node	*temp;
	t_node	*slow;

	boolean = 0;
	temp = (*stack_a);
	slow = (*stack_a)->next;
	while (slow)
	{
		if (temp->index > slow->index)
			boolean = 1;
		else if (boolean == 1)
			break ;
		temp = temp->next;
		slow = slow->next;
	}
	return (boolean);
}
