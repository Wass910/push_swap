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


char    *ft_substr(char *s, int start, int len)
{
        int             i;
        char    *str;

        if (!s || !*s || start > ft_strlen(s))
                return (ft_strdup(""));
        i = 0;
        if (!(str = malloc(sizeof(*str) * (len + 1))))
                return (NULL);
        i = 0;
        while (i < len)
        {
                str[i] = s[i + start];
                i++;
        }
        str[i] = '\0';
        return (str);
}

void    *ft_calloc(int count, int size)
{
        void                    *result;
        unsigned char   *tmp;
        int                             i;
        int                             n;

        i = 0;
        if (count == 0)
                return (ft_strdup(""));
        if (!(result = malloc(count * size)))
                return (NULL);
        tmp = result;
        n = count * size;
        while (n > 0)
        {
                *tmp = (unsigned char)i;
                tmp[i] = '\0';
                tmp++;
                n--;
        }
        return (result);
}

char    *ft_strchr(char *s, int c)
{
        int             i;
        int             a;

        a = 0;
        i = 0;
        while (s[a] != '\0')
                a++;
        if (c == '\0')
                return (s + a);
        while (s[i] != '\0')
        {
                if (s[i] == c)
                        return (s + i);
                i++;
        }
        return (NULL);
}

int             ft_count(char *s1, char *s2)
{
        int i;
        int e;

        i = 0;
        e = 0;
        while (s1[i] != '\0')
                i++;
        while (s2[e] != '\0')
        {
                e++;
                i++;
        }
        i = i + 2;
        return (i);
}

char    *ft_strjoin_free(char *s1, char *s2, int f)
{
        int             e;
        int             i;
        char    *str;

        f = 0;
        e = 0;
        i = ft_count(s1, s2);
        if (!(str = malloc(sizeof(*str) * i)))
                return (NULL);
        i = 0;
        while (s1[i] != '\0')
        {
                str[i] = s1[i];
                i++;
        }
        while (s2[e] != '\0')
        {
                str[i] = s2[e];
                i++;
                e++;
        }
        free(s1);
        str[i] = '\0';
        return (str);
}

char    *ft_strdup(char *s)
{
        int             i;
        char    *str;
        int             e;

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

int             ft_strlen(char *s)
{
        int     i;

        i = 0;
        while (s[i] != '\0')
        {
                i++;
        }
        return (i);
}

int             read_line(int fd, char **dest)
{
        char    *buff;
        int             ret;

        if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
                return (-1);
        while (!ft_strchr(*dest, '\n') && (ret = read(fd, buff, BUFFER_SIZE)))
        {
                if (ret == -1)
                        return (-1);
                buff[ret] = '\0';
                if ((*dest = ft_strjoin_free(*dest, buff, 1)) == NULL)
                        return (-1);
        }
        free(buff);
        return (ret);
}

char    *ft_no_leaks(char *dest, int i)
{
        char    *tmp;

        if (dest[i] == '\n')
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

int             get_next_line(int fd, char **line)
{
        static char     *dest;
        int                     ret;
        int                     i;

        i = 0;
        if (BUFFER_SIZE <= 0 || !line || fd < 0)
                return (-1);
        if (!(dest))
                dest = ft_calloc(1, 1);
        if ((ret = read_line(fd, &dest)) == -1)
                return (-1);
        while (dest[i] != '\n' && dest[i] != '\0')
                i++;
        *line = ft_substr(dest, 0, i);
        dest = ft_no_leaks(dest, i);
        if (!dest && !ret)
        {
                free(dest);
                return (0);
        }
        return (1);
}