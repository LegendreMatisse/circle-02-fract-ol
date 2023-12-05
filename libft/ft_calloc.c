/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:36:19 by mlegendr          #+#    #+#             */
/*   Updated: 2023/02/10 18:22:51 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elements, size_t size)
{
	void	*pointer;

	pointer = (void *)malloc(elements * size);
	if (!pointer)
		return (pointer);
	ft_bzero(pointer, size * elements);
	return (pointer);
}
