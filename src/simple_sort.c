/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:19:39 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/03 15:10:39 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack **stack_a)
{
	t_stack	*top;

	top = *stack_a;
	if (top->index < top->next->index)
	{
		r_ra(stack_a);
		if ((in_order(stack_a)) != 1)
			sa(stack_a);
		return ;
	}
	else if (top->index > top->next->index
		&& top->index < top->next->next->index)
		sa(stack_a);
	else
	{
		ra(stack_a);
		top = *stack_a;
		if (top->index > top->next->index
			&& top->index < top->next->next->index)
			sa(stack_a);
	}
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, ft_get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		r_ra(stack_a);
	if ((in_order(stack_a)) != 1)
	{
		pb(stack_a, stack_b);
		sort_3(stack_a);
		pa(stack_b, stack_a);
	}
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, ft_get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		r_ra(stack_a);
		r_ra(stack_a);
	}
	else if (distance == 4)
		r_ra(stack_a);
	if ((in_order(stack_a)) != 1)
	{
		pb(stack_a, stack_b);
		sort_4(stack_a, stack_b);
		pa(stack_b, stack_a);
	}
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (in_order(stack_a))
		return ;
	size = lst_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
