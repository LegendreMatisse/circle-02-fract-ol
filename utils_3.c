/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:58:12 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/08 22:58:37 by matisse          ###   ########.fr       */
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

int	redraw(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, SIZE, SIZE);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_len,
			&mlx->endian);
	draw_fractal(mlx, mlx->name, 'k');
	return (0);
}
