/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:24:48 by matisse           #+#    #+#             */
/*   Updated: 2024/01/07 23:27:20 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_secondary_arg_check(int argc, char **argv, double *x, double *y)
{
	if (argc == 4)
	{
		*x = ft_atof(argv[2]);
		*y = ft_atof(argv[3]);
	}
	if (!argv[2] || !argv[3])
	{
		*x = 10;
		*y = 10;
	}
	else
	{
		*x = 0;
		*y = 0;
	}
}
