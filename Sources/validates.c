/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:45:00 by dmonteir          #+#    #+#             */
/*   Updated: 2022/02/18 14:08:31 by dmonteir         ###   ########.fr       */
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

void	line_is_digit(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (is_char_digit(argv[i]) == 1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	validate_command_line(int argc, char **argv)
{
	line_is_digit(argc, argv);
}