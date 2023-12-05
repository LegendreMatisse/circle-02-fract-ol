/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:12:08 by mlegendr          #+#    #+#             */
/*   Updated: 2023/02/08 17:02:36 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t st)
{
	size_t	i;

	i = 0;
	while (*src && i + 1 < st)
	{
		*dest++ = *src++;
		++i;
	}
	if (i < st)
		*dest = '\0';
	while (*src++)
		++i;
	return (i);
}
