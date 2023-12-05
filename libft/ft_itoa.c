/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:34:31 by ahooghe           #+#    #+#             */
/*   Updated: 2023/01/27 16:06:55 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	char	*ft_normal_itoa(int n, size_t len)
{
	char	*str;
	int		n_value;

	n_value = n;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = 0 + '0';
	if (n < 0)
	{
		n_value = -n;
		str[0] = '-';
	}
	while (n_value != 0)
	{
		str[--len] = n_value % 10 + '0';
		n_value = n_value / 10;
	}
	str[ft_intlen(n)] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	if (n == -2147483647 - 1)
		return (ft_strdup("-2147483648"));
	else
		return (ft_normal_itoa(n, ft_intlen(n)));
}
