/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:38:59 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/08 00:07:24 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_mlx *mlx, double x, double y, char function)
{
	if (function == 'm')
	{
		mlx->x = 0;
		mlx->y = 0;
		mlx->zoom = 200;
		mlx->offset_x = -1.71;
		mlx->offset_y = -1.71;
		mlx->max_iterations = 100;
	}
	mlx->cx = x;
	mlx->cy = y;
	mlx->color = 0x0bd2024;
	mlx->bpp = 32;
	mlx->line_len = SIZE * 4;
	mlx->endian = 0;
	mlx->name = "julia";
}

void	draw_julia(t_mlx *mlx)
{
	int start_x = 0;
	int start_y = 0;
	int end_x = SIZE;
	int end_y = SIZE;

	double x;
	double y;

	mlx->x = start_x;
	while (mlx->x < end_x)
	{
		mlx->y = start_y;
		while (mlx->y < end_y)
		{
			x = mlx->x / mlx->zoom + mlx->offset_x;
			y = mlx->y / mlx->zoom + mlx->offset_y;
			if (x >= -2.0 && x <= 2.0 && y >= -2.0 && y <= 2.0)
			{
				calc_julia(mlx, x, y);
			}
			mlx->y++;
		}
		mlx->x++;
	}
	/*mlx->x = 0;
	mlx->y = 0;
	while (mlx->x < SIZE)
	{
		while (mlx->y < SIZE)
		{
			calc_julia(mlx);
			mlx->y++;
		}
		mlx->x++;
		mlx->y = 0;
	}*/
}

void	calc_julia(t_mlx *mlx)
{
	int		i;
	double	tmp;

	mlx->name = "julia";
	mlx->zx = mlx->x / mlx->zoom + mlx->offset_x;
	mlx->zy = mlx->y / mlx->zoom + mlx->offset_y;
	i = 0;
	while (++i < mlx->max_iterations)
	{
		tmp = mlx->zx;
		mlx->zx = mlx->zx * mlx->zx - mlx->zy * mlx->zy + mlx->cx;
		mlx->zy = 2 * mlx->zy * tmp + mlx->cy;
		if (mlx->zx * mlx->zx + mlx->zy * mlx->zy > __DBL_MAX__)
			break ;
	}
	if (i == mlx->max_iterations)
		put_color_to_pixel(mlx, mlx->x, mlx->y, 0x000000);
	else
		put_color_to_pixel(mlx, mlx->x, mlx->y, p_c_julia(i, mlx));
}
