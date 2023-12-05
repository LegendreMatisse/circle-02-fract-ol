/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:14:42 by mlegendr          #+#    #+#             */
/*   Updated: 2023/11/17 17:11:00 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(unsigned int num)
{
	size_t	len;

	len = 0;
	if (num <= 0)
		len = 1;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_utioa(unsigned int num)
{
	char	*c_num;
	size_t	len;

	len = ft_intlen(num);
	c_num = (char *)malloc(sizeof(char) * (len + 1));
	if (!c_num)
		return (0);
	c_num[len] = '\0';
	while (num != 0)
	{
		c_num[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (c_num);
}

int	ft_print_uitoa(unsigned int num)
{
	int		printedchars;
	char	*c_num;

	printedchars = 0;
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		printedchars = printedchars + 1;
	}
	else
	{
		c_num = ft_utioa(num);
		ft_putstr_fd(c_num, 1);
		printedchars = printedchars + ft_strlen(c_num);
		free(c_num);
		c_num = NULL;
	}
	return (printedchars);
}
