/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:45:00 by dmonteir          #+#    #+#             */
/*   Updated: 2022/02/22 08:25:37 by dmonteir         ###   ########.fr       */
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

/* int	is_value_duplicate (char *str)
{
	 size_t i;

	i = 0;
	printf("%s\n", str);
	//exit(0);
	while (i < ft_strlen(str))
	 {
		if (i < str)
		{
			printf("%c\n", str[i]);
			return (1);
		}
		i++;
	}
	return (0);
} */

void	digit_is_ok(int argc, char **argv)
{
	int	i;
	long	int_num;

	i = 1;
	while (i < argc)
	{
		int_num = ft_atoil(argv[i]);
		if (is_char_digit(argv[i]) == 1)
			error();
		/* else if (is_value_duplicate(argv[i]) == 1)
			error(); */
		else if (int_num > INT_MAX || int_num < INT_MIN)
			error();
		i++;
	}
}

void	validate_command_line(int argc, char **argv)
{
	digit_is_ok(argc, argv);
}