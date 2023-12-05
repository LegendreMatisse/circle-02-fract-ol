/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:32:15 by mlegendr          #+#    #+#             */
/*   Updated: 2023/02/08 14:49:53 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t st)
{
	void	*new_dest;

	if (!dest && !src)
		return (0);
	new_dest = dest;
	while (st--)
		*(char *)dest++ = *(char *)src++;
	return (new_dest);
}
