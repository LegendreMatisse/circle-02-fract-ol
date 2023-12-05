/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:02:38 by mlegendr          #+#    #+#             */
/*   Updated: 2023/11/17 17:01:37 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptrlen(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

void	ft_putptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	printedchars;

	printedchars = 0;
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		printedchars = printedchars + 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		printedchars = printedchars + 2;
		ft_putptr(ptr);
		printedchars = printedchars + ft_ptrlen((uintptr_t)ptr);
	}
	return (printedchars);
}
