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
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		*x = 0;
		*y = 0;
	}
	else
	{
		if (argc < 4)
		{
			*x = -0.745429;
			*y = 0.05;
		}
		else
		{
			*x = ft_atof(argv[2]);
			*y = ft_atof(argv[3]);
			if (*x < -4 || *x > 4 || *y < -4 || *y > 4)
			{
				ft_exit_w_mess("Invalid input. Try any value between -4 and 4.", NULL, 1);
			}
		}
	}
}
