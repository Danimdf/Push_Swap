/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:45:53 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/07 13:25:41 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	order (t_stack *stack)
{
	int	list_size;

	list_size = ft_lstsize(stack->stack_a);
	if (list_size <= 3)
		order_three(&stack);
}

void	order_three(t_stack **stack)
{
	//swap_a(stack, list_size);
	//print_me((*stack)->stack_a);
	//rotate_a(stack, list_size);
	//reverse_rotate(stack->stack_a);
	push_a(stack);
	//print_me((*stack)->stack_b);
}


void print_me(t_node *swap)
{
    while (swap)
    {
        printf("%d\n", swap->data);
        swap = swap->next;
	}
	printf("-----------\n");
}