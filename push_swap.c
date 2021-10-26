/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:27:59 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/19 18:28:01 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*pile_a;
	t_stack	*pile_b;
	int		arg;

	arg = 0;
	pile_a = NULL;
	pile_b = NULL;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (argc <= 2)
		pile_a = ft_argc_min(argv, pile_a);
	else
		pile_a = ft_argc_max(argv, argc, pile_a);
	ft_verif_double(pile_a);
	arg = ft_lstsize(pile_a);
	if ((ft_is_order(pile_a)) == 0 )
	{
		clear_t_stack(pile_a);
		exit(EXIT_FAILURE);
	}
	pile_a = tri_pile(pile_a, pile_b, arg);
	return (0);
}
