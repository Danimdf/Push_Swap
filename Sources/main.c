/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:36:21 by dmonteir          #+#    #+#             */
/*   Updated: 2022/02/17 14:45:42 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//conjunto de estruturas
//aponta pra si mesma, é o prev
//gdb
//b (função) (linha)
//run->r
//s -> entra na função
//n -> executa a função e retorna o resultado
//c -> ele vai ate o proximo breakpoint
//p -> printa o endereço da variavel e o valor
//ptype -> mostra o tipo


//botar false no bool no create


void	init_stack(t_stack *stack) {
	stack = (t_stack *)malloc(sizeof(stack));
}

int	main(int argv, char **argc)
{
	int numbers;
	t_stack	stack;

	if (argc >= 2 || argc[1] != NULL)
	{
		validate_command_line(argc);
	} else
	{
		write (2, "ERROR\n", 6);
		exit(1);
	}

	init_stack(&stack);
}