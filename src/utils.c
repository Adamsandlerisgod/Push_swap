/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:26:38 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/02 15:42:25 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	in_order(t_stack **stack_a)
{
	t_stack	*top;

	top = *stack_a;
	while (top && top->next)
	{
		if (top->value > top->next->value)
			return (0);
		top = top->next;
	}
	return (1);
}

int	get_distance(t_stack **stack_a, int index)
{
	t_stack	*top;
	int		i;

	i = 0;
	top = *stack_a;
	while (top->index != index)
	{
		i++;
		top = top->next;
	}
	return (i);
}

int	ft_get_min(t_stack **stack, int val)
{
	t_stack	*top;
	int		min;

	top = *stack;
	min = top->index;
	while (top->next)
	{
		top = top->next;
		if ((top->index < min) && top->index != val)
			min = top->index;
	}
	return (min);
}
