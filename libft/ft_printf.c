/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:36:05 by mlegendr          #+#    #+#             */
/*   Updated: 2023/11/17 17:00:21 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printf_format(va_list va_str, char format)
{
	int	printedchars;

	printedchars = 0;
	if (format == 's')
		printedchars += ft_printstr(va_arg(va_str, char *));
	else if (format == 'c')
		printedchars += ft_printchar(va_arg(va_str, int));
	else if (format == 'p')
		printedchars += ft_printptr(va_arg(va_str, unsigned long long));
	else if (format == 'd' || format == 'i')
		printedchars += ft_printnbr(va_arg(va_str, int));
	else if (format == 'u')
		printedchars += ft_print_uitoa(va_arg(va_str, unsigned int));
	else if (format == 'x' || format == 'X')
		printedchars += ft_printhex(va_arg(va_str, unsigned int), format);
	else if (format == '%')
		printedchars += ft_printchar('%');
	return (printedchars);
}

int	ft_printf(const char *str, ...)
{
	int		printedchars;
	size_t	i;
	va_list	va_str;

	printedchars = 0;
	i = 0;
	va_start(va_str, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printedchars += ft_printf_format(va_str, str[i + 1]);
			i++;
		}
		else
			printedchars += ft_printchar(str[i]);
		i++;
	}
	va_end(va_str);
	return (printedchars);
}
