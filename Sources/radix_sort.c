/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:03:25 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/12 13:32:35 by dmonteir         ###   ########.fr       */
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
