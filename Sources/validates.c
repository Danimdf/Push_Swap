/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:45:00 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/14 12:27:18 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_char_digit(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_value_duplicate(t_node *stack_a, int num)
{
	while (stack_a)
	{
		if (stack_a->data == num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	validate_command_line(t_stack *stacks)
{
	int	i;
	int	num;
	int	first_num;

	i = 1;
	while (i < stacks->argc)
	{
		num = ft_atoim(stacks->argv[i]);
		first_num = ft_atoim(stacks->argv[1]);
		stacks->first_number_a = first_num;
		if (is_char_digit(stacks->argv[i]) == 1)
			error();
		else if (is_value_duplicate(stacks->stack_a, num) == 1)
			error();
		stack_a_or_b_back(num, &(stacks->stack_a), 0);
		i++;
	}
}
