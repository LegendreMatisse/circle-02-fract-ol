/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:58:12 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/09 00:14:52 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_iterations(t_mlx *mlx, char direction)
{
	if (direction == 'u')
		mlx->max_iterations += 1;
	else
		mlx->max_iterations -= 1;
}

void	print_message(void)
{
	ft_printf("Usage:\n");
	ft_printf("./fractol <mandelbrot> or <julia>\n");
	ft_printf("Change Julia by passing extra arguments\n");
	ft_printf("./fractol julia <-4 ... 4> <-4 ... 4>\n");
	ft_printf("Commands:\n");
	ft_printf("|ESC| ==> close window\n");
	ft_printf("|+| ==> zoom in\n");
	ft_printf("|-| ==> zoom out\n");
	ft_printf("|^| ==> move up\n");
	ft_printf("|v| ==> move down\n");
	ft_printf("|<| ==> move left\n");
	ft_printf("|>| ==> move right\n");
	ft_printf("|mouse wheel up| ==> zoom in\n");
	ft_printf("|mouse wheel down| ==> zoom out\n");
	ft_printf("|Q| ==> more detail\n");
	ft_printf("|A| ==> less detail (*sad campus noises*)\n");
}

void	redraw(t_mlx *mlx, char color)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, SIZE, SIZE);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_len,
			&mlx->endian);
	draw_fractal(mlx, mlx->name, 'k', color);
}
