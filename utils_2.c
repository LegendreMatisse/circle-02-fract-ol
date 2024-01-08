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
#include <stdio.h>

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
			if (!ft_isfloat(argv[2]) || !ft_isfloat(argv[3]))
				ft_exit_w_mess("Try any value between -4 and 4.", NULL, 1);
			*x = ft_atof(argv[2]);
			*y = ft_atof(argv[3]);
			if (*x < -4 || *x > 4 || *y < -4 || *y > 4)
				ft_exit_w_mess("Try any value between -4 and 4.", NULL, 1);
		}
	}
}

int	ft_isfloat(const char *str)
{
	int	i;
	int	has_dot;
	int	has_digit;

	i = 0;
	has_dot = 0;
	has_digit = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (ft_isdigit(str[i]))
			has_digit = 1;
		else
			return (0);
		i++;
	}
	return (has_digit);
}

void zoom(t_mlx *mlx, char direction)
{
	if (direction == '+')
	{
		printf("zoom: %f\n", mlx->zoom);
		mlx->zoom = mlx->zoom + 10;
	}
	else
	{
		printf("zoom: %f\n", mlx->zoom);
		mlx->zoom = mlx->zoom - 10;
	}
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, SIZE, SIZE);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_len,
			&mlx->endian);
	draw_fractal(mlx, mlx->name, mlx->cx, mlx->cy);
	mlx_loop(mlx->mlx);
}
