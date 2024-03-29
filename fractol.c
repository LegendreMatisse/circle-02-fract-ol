/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:02:32 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/07 16:39:19 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->bpp = 0;
	mlx->line_len = 0;
	mlx->endian = 0;
	mlx->x = 0;
	mlx->y = 0;
	mlx->zx = 0;
	mlx->zy = 0;
	mlx->cx = 0;
	mlx->cy = 0;
	mlx->color = 0;
	mlx->offset_x = 0;
	mlx->offset_y = 0;
	mlx->zoom = 0;
	mlx->name = NULL;
	mlx->max_iterations = 0;
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	double	x;
	double	y;

	mlx = NULL;
	x = 0.0;
	y = 0.0;
	primary_arg_check(argc, argv);
	secondary_arg_check(argc, argv, &x, &y);
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (exit_w_mess("Malloc error", mlx, 1));
	print_message();
	init_fractal(mlx);
	init_mlx(mlx);
	mlx->cx = x;
	mlx->cy = y;
	draw_fractal(mlx, argv[1], 'm');
	mlx_hook(mlx->win, 2, 1L << 0, keypress, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, exit_wo_mess, mlx);
	mlx_mouse_hook(mlx->win, mouse, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
