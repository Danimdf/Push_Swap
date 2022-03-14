/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:36:21 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/14 12:22:42 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

void	init_stack(t_node **stack, int value, int index)
{
	(*stack) = (t_node *)malloc(sizeof(t_node));
	if (!(*stack))
		error();
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
	(*stack)->data = value;
	printf("%d\n", index);
	(*stack)->index = index;
}

t_stack	*create_stacks(int argc, char **argv)
{
	t_stack *stacks;

	stacks = (t_stack *)malloc(sizeof(t_stack));
	if (!stacks)
		return (NULL);
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->argv = argv;
	stacks->argc = argc;
	return (stacks);
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;

	stacks = NULL;
	//init_stack(&stack);
	if (argc >= 2 || argv[1] != NULL)
	{
		stacks = create_stacks(argc, argv);
		validate_command_line(stacks);
	}
	else
		return (0);
	order(stacks);
	free(stacks);
}
