/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:25:15 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/19 18:25:58 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>

int	ft_push(t_stack *pile_a, t_stack *pile_b, char *line)
{
	if (ft_cmp(line, "pa\n") == 0)
	{
		if (pile_b != NULL)
		{
			return (1);
		}
	}
	else if (ft_cmp(line, "pb\n") == 0)
	{
		if (pile_a != NULL)
		{
			return (2);
		}
	}
	return (0);
}

t_stack	*ft_ope_b(t_stack *pile, char *line)
{
	if (ft_cmp(line, "sb\n") == 0)
		pile = ft_swap_checker(pile);
	else if (ft_cmp(line, "rb\n") == 0)
		pile = ft_reverse_check(pile);
	else if (ft_cmp(line, "rrb\n") == 0)
		pile = ft_reverse_last_checker(pile);
	return (pile);
}

t_stack	*ft_ope_a(t_stack *pile, char *line)
{
	if (ft_cmp(line, "sa\n") == 0)
		pile = ft_swap_checker(pile);
	else if (ft_cmp(line, "ra\n") == 0)
		pile = ft_reverse_check(pile);
	else if (ft_cmp(line, "rra\n") == 0)
		pile = ft_reverse_last_checker(pile);
	return (pile);
}

t_stack	*ft_check(t_stack *pile_a, t_stack *pile_b)
{
	int		ret;
	char	*line;

	ret = get_next_line(0, &line);
	while (ret > 0 )
	{
		ft_print_error(line);
		if (ft_push(pile_a, pile_b, line) == 1)
		{
			pile_a = ft_swap_between_tmp(pile_a, pile_b->value);
			pile_b = ft_free_t_stack(pile_b);
		}
		else if (ft_push(pile_a, pile_b, line) == 2)
		{
			pile_b = ft_swap_between_tmp(pile_b, pile_a->value);
			pile_a = ft_free_t_stack(pile_a);
		}
		pile_b = ft_ope_b(pile_b, line);
		pile_a = ft_ope_a(pile_a, line);
		free(line);
		ret = get_next_line(0, &line);
	}
	free(line);
	ft_result_checker(pile_a, pile_b);
	return (pile_a);
}

int	main(int argc, char **argv)
{
	t_stack	*pile_a;
	t_stack	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	if (argc == 1 || argc == 2)
		exit(EXIT_FAILURE);
	if (argc <= 2)
		pile_a = ft_argc_min(argv, pile_a);
	else
		pile_a = ft_argc_max(argv, argc, pile_a);
	ft_verif_double(pile_a);
	/*if ((ft_is_order(pile_a)) == 0 )
	{
		clear_t_stack(pile_a);
		exit(EXIT_FAILURE);
	}*/
	ft_check(pile_a, pile_b);
	return (0);
}
