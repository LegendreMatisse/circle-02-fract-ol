/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:02:29 by mlegendr          #+#    #+#             */
/*   Updated: 2023/11/17 17:17:24 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_pre_a(char *line)
{
	char	*substr;
	int		i;

	if (!line || !line[0])
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	i += (line[i] == '\n');
	substr = ft_gnl_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (line[++i] && line[i] != '\n')
		substr[i] = line[i];
	if (line[i] == '\n')
		substr[i++] = '\n';
	return (substr);
}

char	*ft_substr_post_a(char *line)
{
	char	*substr;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
	{
		free(line);
		return (0);
	}
	i += (line[i] == '\n');
	substr = ft_gnl_calloc(ft_gnl_strlen(line) - i + 1, sizeof(char));
	if (!substr)
		return (NULL);
	j = 0;
	while (line[i + j])
	{
		substr[j] = line[i + j];
		j++;
	}
	free(line);
	return (substr);
}

char	*ft_make_full_line(char *buffer)
{
	char	*sub_str;

	if (!buffer)
		return (NULL);
	sub_str = ft_substr_pre_a(buffer);
	return (sub_str);
}

char	*ft_fill_buffer(char *line)
{
	char	*sub_str;

	if (!line)
		return (NULL);
	sub_str = ft_substr_post_a(line);
	return (sub_str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;
	int			eof;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (NULL);
	eof = 1;
	while (!(ft_gnl_strchr(line, '\n')) && eof != 0)
	{
		eof = read(fd, line, BUFFER_SIZE);
		if (eof == -1)
		{
			free(line);
			return (NULL);
		}
		line[eof] = '\0';
		buffer[fd] = ft_gnl_strjoin(buffer[fd], line);
	}
	free(line);
	line = ft_make_full_line(buffer[fd]);
	buffer[fd] = ft_fill_buffer(buffer[fd]);
	return (line);
}
