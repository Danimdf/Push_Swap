/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:45:53 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/02 19:18:19 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void order (t_stack *stack)
{
	int	list_size;

	list_size = ft_lstsize(stack->stack_a);
	if (list_size <= 3)
		order_three(stack, list_size);
}

void order_three(t_stack *stack, int list_size)
{
	swap_a(stack, list_size);
}
