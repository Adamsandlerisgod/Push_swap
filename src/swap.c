/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:55:43 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/02 17:50:37 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack **stack_x)
{
	t_stack	*temp;

	temp = (*stack_x)->next;
	(*stack_x)->next = temp->next;
	temp->next = *stack_x;
	*stack_x = temp;
}

void	sa(t_stack **stack_x)
{
	swap(stack_x);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_x)
{
	swap(stack_x);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
