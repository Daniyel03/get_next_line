/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:05:57 by dscholz           #+#    #+#             */
/*   Updated: 2023/10/25 16:06:00 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*reader(int fd, char *buf, char *line)
{
	int		len;
	char	*temp;

	len = 1;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			line = NULL;
			break ;
		}
		else if (len == 0)
			break ;
		buf[len] = '\0';
		if (!line)
			line = ft_strjoin("", "");
		temp = line;
		line = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (line);
}

char	*cutter(char *line)
{
	char	*temp;
	size_t	len;

	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
		len++;
	temp = ft_substr(line, len + 1, (ft_strlen(line) - len));
	if (*temp == '\0')
	{
		free(temp);
		temp = NULL;
	}
	if (ft_strchr(line, '\n'))
		line[len + 1] = '\0';
	else
		line[len] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*res;
	char		*buf;
	static char	*line[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	res = reader(fd, buf, line[fd]);
	if (!res)
	{
		free(line[fd]);
		line[fd] = NULL;
		free(buf);
		buf = NULL;
		return (0);
	}
	free(buf);
	buf = NULL;
	line[fd] = cutter(res);
	return (res);
}
