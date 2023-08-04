/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:22:10 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/02 20:44:11 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*top;
	t_stack	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	top = *stack;
	if (top)
	{
		while (top)
		{
			if ((top->index == -1) && (!has_min || top->value < min->value))
			{
				min = top;
				has_min = 1;
			}
			top = top->next;
		}
	}
	return (min);
}

void	indexing(t_stack **stack)
{
	t_stack	*top;
	int		index;

	index = 0;
	top = get_next_min(stack);
	while (top)
	{
		top->index = index++;
		top = get_next_min(stack);
	}
}
