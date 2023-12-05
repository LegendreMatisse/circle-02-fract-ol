/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:32:40 by mlegendr          #+#    #+#             */
/*   Updated: 2023/02/10 16:05:14 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *str, int a, size_t st)
{
	unsigned char	*str_c;
	unsigned char	a_c;

	str_c = (unsigned char *)str;
	a_c = (unsigned char)a;
	while (st--)
	{
		if (*str_c == a_c)
			return ((void *)str_c);
		++str_c;
	}
	return (NULL);
}
