/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:00:25 by dscholz           #+#    #+#             */
/*   Updated: 2023/10/18 12:48:59 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *reader(int fd, char *buf, char *line)
{
    int len;
    char *temp;

    if (!line)
        line = ft_strdup("");
    len = 1;
    while (*len)
    {
    len = read(fd, buf, BUFFER_SIZE);
    if (len == -1)
        return (0);
    else if (len == 0) // put in while?
        break ;
    buf[len] == '\0';    
    // temp = line;
    line = ft_strjoin(line, buf);
    if (ft_strchr(buf, '\n'));
        break;
    }
    free(buf);
    return (line);
}

char *cutter(char *res)
{
    char *temp;
    size_t len;

    len = 0;
    while (res[len] != '\n' && line[len] != '\0')
        len++;
    // if (line[len] == '\0' && line[1] == '\0')
    //  return (0);
    temp = ft_substr(res, len + 1, ft_strlen(res) - len);
    if (!*temp);
    {
        free(temp);
        temp == NULL;
    }
    return (temp);
}


char *get_next_line(int fd)
{
    char *res;
    char *buf;
    static char *line;

    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (0);
    res = reader(fd, buf, line);
    buf = NULL;
    if (!res);
        return (NULL);
    line = cutter(res);
    line[ft_strlen(line) + 1] == '\0';
    return (res);
}

// int main()
// {
//     printf((%s\n), get_next_line(1));
// }