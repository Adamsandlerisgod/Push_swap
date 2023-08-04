/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:40:26 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/03 18:07:47 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printlist(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("value: %d || index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
}

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
	if ((ac < 2))
		exit (1);
	error_handling(ac, argv);
	split = split_join(ac, argv);
	init_stack(&stack_a, split);
	if ((in_order(&stack_a)) != 1)
		sort(&stack_a, &stack_b);
	free_stack(stack_a);
	free_2d_array(split);
}
