/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:02:32 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/05 00:03:01 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_mlx *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	mlx->color = 0x0bd2024;
	mlx->zoom = 300;
	mlx->offset_x = -1.21;
	mlx->offset_y = -1.21;
	mlx->max_iterations = 100;
	mlx->bpp = 32;
	mlx->line_len = SIZE * 4;
	mlx->endian = 0;
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	(void)argc;
	mlx = malloc(sizeof(t_mlx));
	init_fractal(mlx);
	init_mlx(mlx);
	mlx_hook(mlx->win, 2, 1L << 0, keypress, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, ft_exit_wo_mess, mlx);
	draw_fractal(mlx, argv[1], ft_atof(argv[2]), ft_atof(argv[3]));
	mlx_loop(mlx->mlx);
	return (0);
}
