/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:34 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/03 18:49:45 by whendrik         ###   ########.fr       */
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

void	error_handling(int ac, char **argv)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(argv[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		i++;
		// printf("str: %s || \"strlen of arg[%d] = %d\" \n", argv[i], i, ft_strlen(argv[i]));
	}
}
