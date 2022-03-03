/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:44:34 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/03 18:32:51 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/push_swap.h"

void rotate_a(t_stack *stack, int list_size)
{
	t_node *temp;

	if (list_size == 1)
		return ;
	temp = stack->stack_a;
	stack->stack_a = stack->stack_a->next;
	stack->stack_a->prev = NULL;
	ft_lstadd_back(&(stack->stack_a), temp);
}


