/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:37:49 by mlegendr          #+#    #+#             */
/*   Updated: 2023/02/10 16:16:10 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str_1, const void *str_2, size_t st)
{
	unsigned char	*s1c;
	unsigned char	*s2c;
	size_t			i;

	if (st == 0)
		return (0);
	i = 0;
	s1c = (unsigned char *)str_1;
	s2c = (unsigned char *)str_2;
	while (i < st)
	{
		if (*s1c != *s2c)
			return (*s1c - *s2c);
		++s1c;
		++s2c;
		++i;
	}
	if (i == st)
	{
		--s1c;
		--s2c;
	}
	return (*s1c - *s2c);
}
