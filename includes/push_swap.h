/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:28:48 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/14 14:45:02 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../Libft/libft.h"
# include "stdbool.h"

//oprev que ta no b vai jogar pra

typedef struct s_node
{
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
	int				data;
}	t_node;

typedef struct s_stack
{
	int		first_number_a;
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_stack;
}	t_stack;

int		main(int argv, char **argc);
long	int	ft_atoim(const char *nptr);
//void	print_me(t_node *swap);

//sort functions
void	order(t_stack *stack);
void	order_two(t_stack **stack, int list_size);
void	order_three(t_stack **stk, int list_size);
void	next_smaller(t_stack **stk, int list_size);
void	order_four(t_stack **stacks, int list_size);
void	order_five(t_stack **stack, int list_size);
void	order_six(t_stack **stacks, int list_size);
void	order_seven(t_stack **stacks, int list_size);
void	radix_sort(t_stack **stacks);

//moviments
void	swap_a(t_stack **stack, int list_size);
void	swap_b(t_stack **stack, int list_size);
void	swap_s(t_stack **stack, int list_size);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rotate_r(t_stack **stack);
void	reverse_rotate_a(t_stack **stack);
void	reverse_rotate_b(t_stack **stack);
void	reverse_rotate_r(t_stack **stack);
void	push_a(t_stack **stack);
void	push_b(t_stack **stack);

//auxiliaries
void	make_index_of_stack(t_stack **stacks, t_node **stack);
int		return_node(t_stack **stack, int i);
void	rmv_head_and_add(t_stack **stack, t_node **stack_mv, int *value_move, \
int *new_index);
void	rmv_head_and_add_back(t_stack **stack, t_node **stack_mv, \
int *value_move, int *new_index);
void	rmv_back_and_add(t_node **stack_mv, int *value_move, int *new_index);
int		min_value(t_node *stack);
void	stack_a_or_b_front(t_stack **stack, int *value_move, t_node **stack_mv, \
int *new_index);
void	stack_a_or_b_back(t_stack **stack, int *value_move, t_node **stack_mv, \
int *new_index);
void	sorted_array(t_stack **stack, int **array);
void	make_index(t_stack **stacks, t_node **stack_a, int *array);
int		stack_ok(t_node **stack, int size, int *array);
int		get_bits(t_node **stack);
int		not_sorted(t_stack **stacks);

//utils linked doubly list
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstnew(int content, int new_index);
t_node	*ft_lstlast(t_node *lst);
int		ft_lstsize(t_node *lst);

void	error(void);
// Validation functions
int		is_value_duplicate(t_node *stack_a, int num);
void	validate_command_line(t_stack *stack, int argc, char *argv[]);
#endif
