/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:17:13 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/16 18:18:11 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

char		*ft_substr(char *s,  int len)
{
	int i = 0;
	char	*str;

	if(!s || !*s || ft_strlen(s) < 0)
		return(ft_strdup(""));
	if (!(str = malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while(i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return(str);
}

int		ft_count(char *s1, char *s2)
{
	int i = 0;
	int e = 0;

	while(s1[i] != '\0')
		i++;
	while(s2[e] != '\0')
	{
		e++;
		i++;
	}
	i = i + 2;
	return (i);
}


char	*ft_strjoin_free(char *s1, char *s2)
{
	int e = 0;
	int i = ft_count(s1, s2);
	char *str;

	if(!(str = malloc(sizeof(char) * i)))
		return NULL;
	i = 0;
	while(s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while(s2[e] != '\0')
	{
		str[i] = s2[e];
		i++;
		e++;
	}
	free(s1);
	str[i] = '\0';
	return str;
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;
	int		e;

	e = 0;
	i = 0;
	while (s[i] != '\0')
		i++;
	if (!(str = malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	while (e < i)
	{
		str[e] = s[e];
		e++;
	}
	str[e] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int i = 0;

	while(s[i] != '\0')
	{
		if(s[i] == c)
			return(s + i);
		i++;
	}
	return NULL;
}

int	ft_read_line(int fd, char **dest)
{
	char	*buff;
	int ret;

	if(!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return(-1);
	while (!ft_strchr(*dest, '\n') && (ret = read(fd, buff, BUFFER_SIZE)))
	{
		if(ret == -1)
			return (-1);
		buff[ret] = '\0';
		if((*dest = ft_strjoin_free(*dest, buff)) == NULL)
			return -1;
	}
	free(buff);
	return ret;
}

char	*ft_no_leaks(char *dest, int i)
{
	char *tmp;
	if(dest[i] == '\n')
	{
		tmp = dest;
		dest = ft_strdup(tmp + i + 1);
		free(tmp);
	}
	else
	{
		free(dest);
		dest = NULL;
	}
	return (dest);
}

int	get_next_line(char **line)
{
	static char	*dest;
	int ret;
	int i;

	i = 0;
	printf("oui");
	if(BUFFER_SIZE <= 0 || !line)
		return(-1);
	if(dest == NULL)
		dest = malloc(sizeof(char));
	if((ret = ft_read_line(1, &dest)) == -1)
		return(-1);
	while(dest[i] != '\n' && dest[i] != '\0')
		i++;
	*line = ft_substr(dest,  i);
	dest = ft_no_leaks(dest, i);
	if (!dest && !ret)
	{
		free(dest);
		return (0);
	}
	return 1;
}