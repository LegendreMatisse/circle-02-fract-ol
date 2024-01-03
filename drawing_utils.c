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
 *The calculation is as follows:
 *y * mlx->line_length / 4 calculates the row, and is divided by 4 because line_length is in bytes, and we need the bit.
 *+ x to calculate the row.*/
void	put_color_to_pixel(t_mlx *mlx, int x, int y, int color)
{
	int	*buffer;

	buffer = mlx->addr;
	buffer[(y * mlx->line_length / 4) + x] = color;
}

/*This function is simple, it just runs the correct function based on choice.*/
int draw_fractal(t_mlx *mlx, char *choice, int x, int y)
{
    if (ft_strncmp(choice, "mandelbrot", 11) == 0)
        draw_mandl(mlx);
    else if (ft_strncmp(choice, "julia", 6) == 0)
	{
		if (!mlx->cx && !mlx->cy)
		{
			mlx->cx = -0.745429;
			mlx->cy = 0.05;
		}
		draw_julia(mlx, x, y);
	}
	/*else if (ft_strncmp(name, "sierpinski", 11) == 0)
		draw_sier(mlx);*/
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
    return (0);    
}

/*A simple function that picks a color based on wether the number is divisible by 7 or 89.*/
int pick_color(int i, t_mlx *mlx)
{
	if (i % 7 == 0 && i % 255 == 0)
		return (0x0ffff00);
	else if (i % 89 == 0 && i % 255 == 0)
		return (0x0004488);
	else
		return (mlx->color * i);
}
