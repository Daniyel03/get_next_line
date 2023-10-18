/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:00:25 by dscholz           #+#    #+#             */
/*   Updated: 2023/10/17 19:54:23 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char *reader(int fd, char *buf, char *temp)
{
    int len;

    len = 1;
    while (*len)
    len = read(fd, buf, BUFFER_SIZE);
    if (len == -1)
        return (0);
    else if (len == 0) // put in while?
        break ;
    buf[len] == '\0';

    

}

char *get_next_line(int fd)
{
    char *res;
    char *buf;
    static char *temp;

    temp = ft_strdup("");
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (0);
    res = reader(fd, buf, temp);
}

// int main()
// {
//     printf((%s\n), get_next_line(1));
// }