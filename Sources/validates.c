/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:45:00 by dmonteir          #+#    #+#             */
/*   Updated: 2022/02/28 17:39:57 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_char_digit(char *str)
{
	size_t i;

	i = 0;
	while(i < ft_strlen(str))
	{
		if(!ft_isdigit(str[i]))
			return(1);
		i++;
	}
	return (0);
}

int	is_value_duplicate (t_node *stack_a, int num)
{
	while (stack_a)
	{
		if (stack_a->data == num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	validate_command_line(t_stack *stack, int argc, char *argv[])
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoim(argv[i]);
		if (is_char_digit(argv[i]) == 1)
			error();
		else if (is_value_duplicate(stack->stack_a, num) == 1)
			error();
		ft_lstadd_back(&(stack->stack_a), ft_lstnew(num));
		i++;
	}
	stack->size_stack = argc - 1;
}
