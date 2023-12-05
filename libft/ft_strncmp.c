/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:36:04 by mlegendr          #+#    #+#             */
/*   Updated: 2023/02/10 15:27:54 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str_1, const char *str_2, size_t st)
{
	size_t	i;

	if (st == 0)
		return (0);
	i = 0;
	while (*str_1 && *str_2 && i < st)
	{
		if (*str_1 != *str_2)
			return (*(unsigned char *)str_1 - *(unsigned char *)str_2);
		++str_1;
		++str_2;
		i++;
	}
	if (i == st)
	{
		--str_1;
		--str_2;
	}
	return (*(unsigned char *)str_1 - *(unsigned char *)str_2);
}
