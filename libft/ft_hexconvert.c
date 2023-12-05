/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexconvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:50:58 by mlegendr          #+#    #+#             */
/*   Updated: 2023/11/17 17:00:03 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_hexconvert(unsigned long num, char x)
{
	if (num >= 16)
	{
		ft_hexconvert(num / 16, x);
		ft_hexconvert(num % 16, x);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (x == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			else if (x == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_printhex(unsigned long num, char x)
{
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_hexconvert(num, x);
	return (ft_hexlen(num));
}
