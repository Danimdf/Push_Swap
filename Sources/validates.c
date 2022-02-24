/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:45:00 by dmonteir          #+#    #+#             */
/*   Updated: 2022/02/24 11:08:54 by dmonteir         ###   ########.fr       */
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

/* int	is_value_duplicate (int argc, int *num)
{
	int	i;
	//int	j;
	//int	aux;
	int *tmp;

	i = 1;
	//printf("%d\n", argc);
	tmp = (int *) ft_calloc(argc, sizeof(int));
	while (i < argc)
	{
		tmp[i] = *num;
		i++;
	}
	printf("%d\n", *tmp); */
	/* while (i < argc)
	 {
		j = i;
		while (j < argc)
		{
			if (num[i] > num[j])
			{
				aux = num[i];
				num[i] = num[j];
				num[j] = aux;
				printf("%d\n", *num);
			}
			j++;
		}
		i++;
	} */
/* 	while(j < argc)
		{
			j = i + 1;
			if (num[i] == num[j])
				return(1);
			j++;
		} */

void	digit_is_ok(int argc, char *argv[])
{
	int	i;
	//intclear
		int_num;

	i = 1;
	while (i < argc)
	{
		if (is_char_digit(argv[i]) == 1)
			error();
		/* else if (is_value_duplicate(argc, &int_num) == 1)
			error(); */
		i++;
	}
}

void	validate_command_line(int argc, char **argv)
{
	digit_is_ok(argc, argv);
	//is_value_duplicate(argc, argv);
}