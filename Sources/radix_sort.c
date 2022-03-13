/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:03:25 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/12 21:01:26 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		//temp->index = i;
		temp = temp->next;
		i++;
	}
	sorted(stacks, &array);

	free(array);
}

void	sorted(t_stack **stack, int **array)
{
	int	i;
	int	j;
	int	size;
	int	temp;

	size = (*stack)->size_stack;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if ((*array)[j] > (*array)[j + 1])
			{
				temp = (*array)[j];
				(*array)[j] = (*array)[j + 1];
				(*array)[j + 1] = temp;
			}
			printf("%d\n", (*array)[j]);
			j++;
		}
		i++;
	}
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
	bits = 0;
	//printf("%d\n", (*stacks)->stack_a->data);
	//printf("%d\n", stack->data);
	size = ft_lstsize((*stacks)->stack_a);
	//print_me(stack);

	while (((*stacks)->size_stack >> bits) != 0)
		bits++;
	//printf("%d\n", bits);
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
	//print_me(stack);
	//print_me((*stacks)->stack_b);
}
