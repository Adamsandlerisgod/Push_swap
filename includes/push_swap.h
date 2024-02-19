/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:08:04 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/07 18:20:00 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}			t_stack;

char	**split_join(int ac, char **av);
void	init_stack(t_stack **stack_x, char **data);
void	indexing(t_stack **stack);
int		lst_size(t_stack *head);
t_stack	*lstlast(t_stack *lst);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);

/*Commands*/
void	ra(t_stack **stack_x);
void	rb(t_stack **stack_x);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	r_ra(t_stack **stack_x);
void	r_rb(t_stack **stack_x);
void	r_rr(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);

/*Error Handling */
void	error_handling(int ac, char **argv);
void	error_malloc(char *array);
void	digit_error(char **array);
void	num_error(char **array, t_stack *stack);
void	free_2d_array(char **array);
void	free_stack(t_stack *stack);

/*Utils*/
int		in_order(t_stack **stack_a);
int		get_distance(t_stack **stack_a, int index);
int		ft_get_min(t_stack **stack, int val);
int		ft_isspace(char a);
int		extra_check(char *line);

#endif