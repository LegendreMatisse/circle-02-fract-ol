/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:38:34 by mlegendr          #+#    #+#             */
/*   Updated: 2023/12/20 15:39:25 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*This function is meant to color in a pixel on on the image.
* The calculation is as follows:
* y * mlx->line_length / 4 calculates the row, and is divided by 4 
* because line_length is in bytes, and we need the bit.
* + x to calculate the row.*/
void	put_color_to_pixel(t_mlx *mlx, int x, int y, int color)
{
	int	*buffer;

	buffer = mlx->addr;
	buffer[(y * mlx->line_len / 4) + x] = color;
}

/*This function is simple, it just runs the correct function based on choice.*/
int	draw_fractal(t_mlx *mlx, char *choice, char function)
{
	if (ft_strncmp(choice, "mandelbrot", 11) == 0)
	{
		init_mandel(mlx, function);
		draw_mandl(mlx);
	}
	else if (ft_strncmp(choice, "julia", 6) == 0)
	{
		init_julia(mlx, mlx->cx, mlx->cy, function);
		draw_julia(mlx);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

/*A simple function that picks a color based on 
* wether the number is divisible by 7 or 89.*/
int	pick_color(int i, t_mlx *mlx)
{
	if (i % 7 == 0)
		return (0x0ffff00);
	else if (i % 89 == 0)
		return (0x0004488);
	else
		return (mlx->color * i);
}

int	pick_color_julia(int i, t_mlx *mlx)
{
	double	norm_iter;
	int		r;
	int		g;
	int		b;

	norm_iter = (double)i / (double)mlx->max_iterations;
	r = (sin(norm_iter * 2.0 * M_PI + 0.0) * 127.5 + 127.5);
	g = (sin(norm_iter * 2.0 * M_PI + 2.0 * M_PI / 3.0) * 127.5 + 127.5);
	b = (sin(norm_iter * 2.0 * M_PI + 4.0 * M_PI / 3.0) * 127.5 + 127.5);
	return ((r << 16) + (g << 8) + b);
}
