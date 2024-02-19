/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:40:26 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/04 13:37:57 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (lst_size(*stack_a) > 5)
		radix_sort(stack_a, stack_b);
	else
		simple_sort(stack_a, stack_b);
}

int	main(int ac, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**split;

	split = NULL;
	stack_a = NULL;
	stack_b = NULL;
	error_handling(ac, argv);
	split = split_join(ac, argv);
	init_stack(&stack_a, split);
	if ((in_order(&stack_a)) != 1)
		sort(&stack_a, &stack_b);
	free_stack(stack_a);
	free_2d_array(split);
}
