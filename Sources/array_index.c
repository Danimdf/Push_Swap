/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 08:55:58 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/14 14:17:38 by dmonteir         ###   ########.fr       */
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
		temp = temp->next;
		i++;
	}
	sorted_array(stacks, &array);
	make_index(stacks, stack, array);
	free (array);
}

void	make_index(t_stack **stacks, t_node **stack_a, int *array)
{
	int		i;
	t_node	*stack;
	int		size;

	size = (*stacks)->size_stack;
	i = 0;
	while (i < size)
	{
		stack = (*stack_a);
		while (stack != NULL)
		{
			if (array[i] == stack->data)
			{
				stack->index = i;
				break;
			}
			//printf("%d\n", stack->index);
			stack = stack->next;
		}
		i++;
	}
	//print_me((*stacks)->stack_a);
}

void	sorted_array(t_stack **stack, int **array)
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
			j++;
		}
		i++;
	}
}
