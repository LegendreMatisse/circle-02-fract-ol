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

void	init_julia(t_mlx *mlx, double x, double y)
{
	mlx->x = 0;
	mlx->y = 0;
	mlx->cx = x;
	mlx->cy = y;
	mlx->color = 0x0bd2024;
	//mlx->zoom = 275;
	//mlx->offset_x = -1.21;
	//mlx->offset_x = -1.21 - 250 / mlx->zoom;
	//mlx->offset_y = -1.21;
	//mlx->offset_y = -1.21 - 250 / mlx->zoom;
	mlx->max_iterations = 42;
	mlx->bpp = 32;
	mlx->line_len = SIZE * 4;
	mlx->endian = 0;
	mlx->name = "julia";
}

void	draw_julia(t_mlx *mlx)
{
	mlx->x = 0;
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
	}
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
		put_color_to_pixel(mlx, mlx->x, mlx->y, pick_color(i, mlx));
}
