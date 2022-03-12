/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:03:25 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/12 17:25:12 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_bits(t_node **stack_a)
{
	t_node	*stack;
	int		max;
	int		max_bits;

	stack = (*stack_a);
	max = stack->index;
	max_bits = 0;
	//printf("%d\n", stack->index);
	while (stack)
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

void	make_index_of_stack(t_stack **stacks, t_node **stack)
{
	int		*array;
	t_node	*temp;
	size_t	i;

	array = (int *)malloc(sizeof(int) * (*stacks)->size_stack);
	if (!array)
		error();
	i = 0;
	temp = (*stack);
	while (temp != NULL)
	{
		array[i] = temp->data;
		temp->index = i;
		temp = temp->next;
		i++;
	}
	free(array);
}

void	radix_sort(t_stack **stacks)
{
	int		i;
	int		j;
	int		bits;
	int		size;
	t_node	*stack;

	i = 0;
	stack = (*stacks)->stack_a;
	//printf("%d\n", (*stacks)->stack_a->data);
	//printf("%d\n", stack->data);
	bits = get_max_bits(&(*stacks)->stack_a);
	size = ft_lstsize((*stacks)->stack_a);
	//print_me(stack);

	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			stack = (*stacks)->stack_a;
			//printf("%d\n", stack->index);
			if (((stack->index >> i) & 1) == 1)
				rotate_a(stacks);
			else
				push_b(stacks);
			//stack = stack->next;
			j++;
		}
		//printf("oiii1");
		while (ft_lstsize((*stacks)->stack_b) != 0)
			push_a(stacks);
		i++;
	}
	print_me((*stacks)->stack_a);
	//print_me((*stacks)->stack_b);
}
