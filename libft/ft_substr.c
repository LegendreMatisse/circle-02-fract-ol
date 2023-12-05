/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:03:31 by mlegendr          #+#    #+#             */
/*   Updated: 2023/02/10 18:28:04 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len + (size_t)(start) < ft_strlen(s))
		str = malloc(sizeof(*s) * (len + 1));
	if (len + (size_t)(start) >= ft_strlen(s))
		str = malloc(sizeof(*s) * (ft_strlen(s) - (size_t)(start) + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = *(s + start + i);
		i++;
	}
	str[i] = '\0';
	return (str);
}
