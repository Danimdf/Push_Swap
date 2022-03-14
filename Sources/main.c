/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:36:21 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/13 21:08:42 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(void)
{
	write (2, "ERROR\n", 6);
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
		error();
	order(&stack);
}
