/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:50:42 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/02 20:43:55 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	node = lstlast(*lst);
	node->next = new;
}

t_stack	*lstnew(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node != NULL)
	{
		new_node->value = num;
		new_node->index = -1;
		new_node->next = NULL;
	}
	return (new_node);
}

int	lst_size(t_stack *head)
{
	size_t	i;
	t_stack	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	init_stack(t_stack **stack_x, char **data)
{
	t_stack	*new;
	int		i;
	long	num;

	i = 0;
	while (data[i])
	{
		new = NULL;
		num = ft_atol(data[i]);
		if (num > INT_MAX || num < INT_MIN)
			num_error(data, *stack_x);
		new = lstnew(num);
		lstadd_back(stack_x, new);
		i++;
	}
	indexing(stack_x);
}
