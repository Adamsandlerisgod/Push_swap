/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:01:01 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/03 15:30:55 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_bits(t_stack **stack_x)
{
	t_stack	*top;
	int		max;
	int		max_bit;

	top = *stack_x;
	max = top->index;
	max_bit = 0;
	while (top)
	{
		if (top->index > max)
			max = top->index;
		top = top->next;
	}
	while ((max >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = -1;
	top_a = *stack_a;
	size = lst_size(top_a);
	max_bits = get_max_bits(stack_a);
	while (i++ < max_bits && (in_order(stack_a) != 1))
	{
		j = 0;
		while (j++ < size)
		{
			top_a = *stack_a;
			if (((top_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (lst_size(*stack_b) != 0)
			pa(stack_b, stack_a);
	}
}
