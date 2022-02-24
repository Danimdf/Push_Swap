/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:36:21 by dmonteir          #+#    #+#             */
/*   Updated: 2022/02/23 14:58:29 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(void) {
	write (2, "ERROR\n", 6);
	exit(1);
}

void	init_stack(t_stack *stack) {
	stack = (t_stack *)malloc(sizeof(stack));
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc >= 2 || argv[1] != NULL)
	{
		validate_command_line(argc, argv);
	} else
	{
		printf("oii1");
		error();
	}
	init_stack(&stack);
}