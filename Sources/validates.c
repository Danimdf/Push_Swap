/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:45:00 by dmonteir          #+#    #+#             */
/*   Updated: 2022/02/22 11:59:46 by dmonteir         ###   ########.fr       */
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

int	is_value_duplicate (int argc, long *num)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int	aux;


	i = 0;
	printf("%ld\n", num);
	printf("oiii3");
	while (i < argc)
	 {
		 printf("oiii2");
		j = 0;
		while (j < argc)
		{
			if (num[i] < num[j])
			{
				aux = num[i];
				num[i] = num[j];
				num[j] = aux;
			}
			j++;
		}
		i++;
		printf("oiii1");
	}
	k = 0;
	while (k < argc)
	{
		printf("%s\n", num[k]);
		k++;
	}
	return (0);
}

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
		else if (is_value_duplicate(argc, int_num) == 0)
			error();
		else if (int_num > INT_MAX || int_num < INT_MIN)
			error();
		i++;
	}
}

void	validate_command_line(int argc, char **argv)
{
	digit_is_ok(argc, argv);
	//is_value_duplicate(argc, argv);
}