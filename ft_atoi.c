/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:44:19 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/05 14:45:27 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	signe;

	signe = 1;
	nb = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		signe = signe * (-1);
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * signe);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_putstr(char *s, int n)
{
	int			i;
	static char	dest[2333333];
	static int ret = 0;

	i = 0;
	//if (!(dest))
    //    dest = ft_calloc(1, 1);
	if (n == 1)
		return dest;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		dest[ret] = s[i];
		ret++;
		i++;
	}
	//dest[ret] = '\0';
	if (n == 1)
		return dest;
	//printf("%s\n", dest);
	return (NULL);
}