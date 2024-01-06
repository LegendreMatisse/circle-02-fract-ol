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

void	calc_mandl(t_mlx *mlx)
{
	int		i;
	double	tmp;

	mlx->name = "mandel";
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

void	*draw_mandl(void *mlx_void)
{
    t_mlx	*mlx;

	mlx = (t_mlx *)mlx_void;
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
	return (NULL);
}
