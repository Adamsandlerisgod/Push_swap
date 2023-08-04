/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:11:59 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/02 15:56:02 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	r_rotate(t_stack **stack_x)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack_x;
	while ((*stack_x)->next != NULL)
	{
		last = *stack_x;
		*stack_x = (*stack_x)->next;
	}
	(*stack_x)->next = tmp;
	last->next = NULL;
}

void	r_ra(t_stack **stack_x)
{
	r_rotate(stack_x);
	ft_putstr_fd("rra\n", 1);
}

void	r_rb(t_stack **stack_x)
{
	r_rotate(stack_x);
	ft_putstr_fd("rrb\n", 1);
}

void	r_rr(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
