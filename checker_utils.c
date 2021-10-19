/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:24:26 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/19 18:24:28 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen_const(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_cmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == ' ')
		{
			ft_putstr("ERROR DON'T USE SPACE");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (ft_error(s1) != 1)
	{
		ft_putstr("ERROR");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

t_stack	*ft_swap_checker(t_stack *pile)
{
	if (pile != NULL && ft_lstsize(pile) >= 2)
		pile = ft_swap_check(pile);
	return (pile);
}

t_stack	*ft_reverse_check(t_stack *pile)
{
	if (pile != NULL && ft_lstsize(pile) >= 2)
		pile = ft_reverse_tmp(pile);
	return (pile);
}

t_stack	*ft_reverse_last_checker(t_stack *pile)
{
	if (pile != NULL && ft_lstsize(pile) >= 2)
		pile = ft_reverse_last_check(pile);
	return (pile);
}
