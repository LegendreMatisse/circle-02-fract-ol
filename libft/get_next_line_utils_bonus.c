/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:02:29 by mlegendr          #+#    #+#             */
/*   Updated: 2023/11/17 17:16:55 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_gnl_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_gnl_strchr(char *str, int a)
{
	size_t	i;

	if (!str)
		return (NULL);
	if (a == '\0')
	{
		i = ft_gnl_strlen((char *)str);
		return (&str[i]);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)a)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

void	*ft_gnl_calloc(const size_t elements, const size_t size)
{
	size_t	i;
	void	*pointer;

	pointer = (void *)malloc(elements * size);
	if (!pointer)
		return (pointer);
	i = 0;
	while (i < elements)
	{
		((unsigned char *)pointer)[i] = '\0';
		i++;
	}
	return (pointer);
}

char	*ft_gnl_strjoin(char *buffer, char *line)
{
	char	*joined_str;
	size_t	full_len;

	if (!buffer)
		buffer = ft_gnl_calloc(1, sizeof(char));
	if (!buffer || !line)
		return (NULL);
	full_len = ft_gnl_strlen(buffer) + ft_gnl_strlen(line) + 1;
	joined_str = ft_gnl_calloc(full_len, sizeof(char));
	if (!joined_str)
		return (NULL);
	joined_str = ft_real_join(joined_str, buffer, line);
	free(buffer);
	return (joined_str);
}

/*~~ Dread it? Run from it? The 25 line limit arrives all the same... ~~*/
char	*ft_real_join(char *joined_str, char *buffer, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer)
	{
		joined_str[j] = buffer[i];
		i++;
		j++;
	}
	i = 0;
	while (line[i] && line)
	{
		joined_str[j] = line[i];
		i++;
		j++;
	}
	return (joined_str);
}
