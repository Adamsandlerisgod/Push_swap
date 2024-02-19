/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:34 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/07 18:53:03 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	digit_error(char **array)
{
	free_2d_array(array);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	num_error(char **array, t_stack *stack)
{
	free_2d_array(array);
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_malloc(char *array)
{
	if (array)
		free(array);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	digit_error_handle(char **array)
{
	int	i;
	int	check;
	int	j;

	i = 1;
	while (array[i] != NULL)
	{
		j = 0;
		check = 0;
		while (array[i][j] != '\0')
		{
			if (ft_isdigit(array[i][j]))
			{
				check = 1;
				break ;
			}
			j++;
		}
		if (!(extra_check(array[i])))
			return (0);
		if (check == 0)
			return (0);
		i++;
	}
	return (1);
}

void	error_handling(int ac, char **argv)
{
	int	i;

	i = 1;
	if ((ac < 2))
		exit (1);
	if (!(digit_error_handle(argv)))
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	while (i < ac)
	{
		if (ft_strlen(argv[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		i++;
	}
}
