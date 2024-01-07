/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:38:59 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/07 17:22:52 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_mlx *mlx, int x, int y)
{
	if (x == 10)
		mlx->cx = -0.745429;
	if (y == 10)
		mlx->cy = 0.05;
	else
	{
		mlx->cx = x;
		mlx->cy = y;
	}
	mlx->x = 0;
	mlx->y = 0;
	mlx->color = 0x0bd2024;
	mlx->zoom = 275;
	mlx->offset_x = -1.21;
	mlx->offset_y = -1.21;
	mlx->max_iterations = 100;
	mlx->bpp = 32;
	mlx->line_len = SIZE * 4;
	mlx->endian = 0;
}

void	draw_julia(t_mlx *mlx, double x, double y)
{
	mlx->x = 0;
	mlx->y = 0;
	while (mlx->x < SIZE)
	{
		while (mlx->y < SIZE)
		{
			calc_julia(mlx, x, y);
			mlx->y++;
		}
		mlx->x++;
		mlx->y = 0;
	}
}

void	calc_julia(t_mlx *mlx, double x, double y)
{
	int		i;
	double	tmp;

	mlx->name = "julia";
	mlx->cx = x;
	mlx->cy = y;
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
