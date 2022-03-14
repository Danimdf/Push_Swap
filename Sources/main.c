/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:36:21 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/14 15:34:38 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stacks(t_node **stack)
{
	t_node	*tmp;

	if ((*stack) == NULL)
		return ;
	while ((*stack) != NULL)
	{
		tmp = (*stack)->next;
		free (*stack);
		(*stack) = tmp;
	}
}

void	error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

void	init_stack(t_stack *stack)
{
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->size_stack = 0;
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	init_stack(&stack);
	if (argc >= 2 || argv[1] != NULL)
		validate_command_line(&stack, argc, argv);
	else
		return (0);
	order(&stack);
	free_stacks(&(stack.stack_a));
	free_stacks(&(stack.stack_b));
}
