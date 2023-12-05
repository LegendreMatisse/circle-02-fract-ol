/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:46:28 by mlegendr          #+#    #+#             */
/*   Updated: 2023/02/17 16:54:23 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t st)
{
	void	*moved;

	if (!dest && !src)
		return (0);
	moved = dest;
	if (src < dest)
	{
		src += st;
		dest += st;
		while (st--)
			*(char *)--dest = *(char *)--src;
	}
	else
		while (st--)
			*(char *)dest++ = *(char *)src++;
	return (moved);
}
