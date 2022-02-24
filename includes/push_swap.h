/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:28:48 by dmonteir          #+#    #+#             */
/*   Updated: 2022/02/24 10:56:05 by dmonteir         ###   ########.fr       */
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
	t_node	*stack_a;
	t_node	*stack_b;
}	t_stack;


int	main(int argv, char **argc);


void error(void);
// Validation functions
int		is_value_duplicate (int argc, int *num);
void	validate_command_line(int argc, char *argv[]);
void	digit_is_ok(int argc, char **argv);
#endif