/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:01:44 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/02 15:55:52 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **stack_x)
{
	t_stack	*tmp;
	t_stack	*first;

	tmp = (*stack_x)->next;
	first = *stack_x;
	*stack_x = lstlast(*stack_x);
	(*first).next = NULL;
	(*stack_x)->next = first;
	*stack_x = tmp;
}

void	ra(t_stack **stack_x)
{
	rotate(stack_x);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_x)
{
	rotate(stack_x);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
