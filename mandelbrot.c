/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:42:47 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/06 16:43:16 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandel(t_mlx *mlx, char function)
{
	if (function == 'm')
	{
		mlx->x = 0;
		mlx->y = 0;
		mlx->zoom = 275;
		mlx->offset_x = -2;
		mlx->offset_y = -1.30;
		mlx->max_iterations = 50;
	}
	mlx->color = 0x0bd2024;
	mlx->bpp = 32;
	mlx->line_len = SIZE * 4;
	mlx->endian = 0;
	mlx->name = "mandelbrot";
}

void	calc_mandl(t_mlx *mlx)
{
	int		i;
	double	tmp;

	i = 0;
	mlx->zx = 0.0;
	mlx->zy = 0.0;
	mlx->cx = (mlx->x / mlx->zoom) + mlx->offset_x;
	mlx->cy = (mlx->y / mlx->zoom) + mlx->offset_y;
	while (++i < mlx->max_iterations)
	{
		tmp = mlx->zx * mlx->zx - mlx->zy * mlx->zy + mlx->cx;
		mlx->zy = 2. * mlx->zx * mlx->zy + mlx->cy;
		mlx->zx = tmp;
		if (mlx->zx * mlx->zx + mlx->zy * mlx->zy >= __DBL_MAX__)
			break ;
	}
	if (i == mlx->max_iterations)
		put_color_to_pixel(mlx, mlx->x, mlx->y, 0x000000);
	else
		put_color_to_pixel(mlx, mlx->x, mlx->y, pick_color(i, mlx));
}

void	draw_mandl(t_mlx *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	while (mlx->x < SIZE)
	{
		while (mlx->y < SIZE)
		{
			calc_mandl(mlx);
			mlx->y++;
		}
		mlx->x++;
		mlx->y = 0;
	}
}
