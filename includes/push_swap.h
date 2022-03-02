/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:28:48 by dmonteir          #+#    #+#             */
/*   Updated: 2022/03/02 19:17:51 by dmonteir         ###   ########.fr       */
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
	struct s_node *prev;
	struct s_node *next;
	int		data;
}	t_node;

typedef struct s_stack
{
	int		first_number_a;
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_stack;
}	t_stack;


int	main(int argv, char **argc);
long int	ft_atoim(const char *nptr);

//sort functions
void order_three(t_stack *stack, int list_size);

//moviments
void swap_a (t_stack *stack, int list_size);

//utils linked doubly list
void	ft_lstadd_back(t_node **lst, t_node *new);
void	*ft_lstnew(int content);
t_node	*ft_lstlast(t_node *lst);
int		t_lstsize(t_node *lst);

void error(void);
// Validation functions
int		is_value_duplicate (t_node *stack_a, int num);
void	validate_command_line(t_stack *stack, int argc, char *argv[]);
#endif