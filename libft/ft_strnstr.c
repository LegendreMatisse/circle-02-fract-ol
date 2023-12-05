/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:34:38 by mlegendr          #+#    #+#             */
/*   Updated: 2023/02/17 17:19:54 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *to_search, const char *to_find, size_t st)
{
	size_t	i;
	size_t	j;
	size_t	tf_len;

	i = 0;
	tf_len = ft_strlen(to_find);
	if (!ft_strlen(to_find))
		return ((char *)to_search);
	if (st == 0)
		return (NULL);
	while (to_search[i] && i < st)
	{
		j = 0;
		while (to_search[i + j] != '\0' && to_find[j] \
				&& to_search[i + j] == to_find[j] && i + j < st)
			j++;
		if (j == tf_len)
			return ((char *)to_search + i);
		i++;
	}
	return (0);
}
