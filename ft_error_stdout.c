/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_stdout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:45:49 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/05 14:51:16 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	ft_verif_double(t_stack *pile)
{
	t_stack	*pile_tmp;
	int		val;

	while (pile)
	{
		pile_tmp = pile->next;
		val = pile->value;
		while (pile_tmp)
		{
			if (val == pile_tmp->value)
			{
				printf("ERROR\n");
				clear_t_stack(pile);
				exit(EXIT_FAILURE);
			}
			pile_tmp = pile_tmp->next;
		}
		pile = pile->next;
	}
	return ;
}

void	ft_print_error(char *line)
{
	if (ft_cmp(line, "pa\n") == 0)
		return ;
	else if (ft_cmp(line, "pb\n") == 0)
		return ;
	else if (ft_cmp(line, "sb\n") == 0)
		return ;
	else if (ft_cmp(line, "sa\n") == 0)
		return ;
	else if (ft_cmp(line, "rb\n") == 0)
		return ;
	else if (ft_cmp(line, "ra\n") == 0)
		return ;
	else if (ft_cmp(line, "rra\n") == 0)
		return ;
	else if (ft_cmp(line, "rrb\n") == 0)
		return ;
	else
	{
		printf("ERROR");
		exit(EXIT_FAILURE);
	}
}

int	depiler(t_stack *pile)
{
	return (pile->value);
}

void	ft_result_checker(t_stack *pile_a, t_stack *pile_b)
{
	if ((ft_is_order(pile_a)) == 0 && !pile_b)
	{
		pile_a = clear_t_stack(pile_a);
		pile_b = clear_t_stack(pile_b);
		printf("OK");
	}
	else
	{
		pile_a = clear_t_stack(pile_a);
		pile_b = clear_t_stack(pile_b);
		printf("KO");
	}
}
