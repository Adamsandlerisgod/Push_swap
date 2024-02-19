/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:34:03 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/04 13:38:03 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	double_check(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j] != NULL)
		{
			if (ft_atol(array[i]) == ft_atol(array[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	join_error_handle(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i] != NULL)
	{
		j = 0;
		if (ft_strlen(array[i]) > 11)
			return (0);
		if (array[i][j] == '+' || array[i][j] == '-')
		{
			j++;
			if (!(ft_isdigit(array[i][j])))
				return (0);
		}
		while (array[i][j] != '\0')
		{
			if (!(ft_isdigit(array[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*join_av(char **av, int ac)
{
	int		i;
	char	*result;
	char	*tmp;

	i = 1;
	result = ft_strdup("");
	if (result == NULL)
		error_malloc(NULL);
	while (i < ac)
	{
		tmp = result;
		result = ft_strjoin(tmp, av[i]);
		if (result == NULL)
			error_malloc(tmp);
		free(tmp);
		tmp = result;
		result = ft_strjoin(tmp, " ");
		if (result == NULL)
			error_malloc(tmp);
		free(tmp);
		i++;
	}
	return (result);
}

char	**split_join(int ac, char **av)
{
	char	*split;
	char	**tab;

	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (tab == NULL)
			error_malloc(NULL);
	}
	else 
	{
		split = join_av(av, ac);
		if (split == NULL)
			error_malloc(NULL); 
		tab = ft_split(split, ' ');
		if (tab == NULL)
			error_malloc(split);
		free(split);
	}
	if ((join_error_handle(tab) == 0) || (double_check(tab) == 0))
		digit_error(tab);
	return (tab);
}
