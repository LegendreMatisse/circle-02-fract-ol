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
	mlx->offset_x = -1.21;
	mlx->offset_y = -1.21;
	mlx->zoom = 275;
	mlx->name = NULL;
	mlx->max_iterations = 0;
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	double		x;
	double		y;

	mlx = NULL;
	x = 0.0;
	y = 0.0;
	ft_primary_arg_check(argc, argv);
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (ft_exit_w_mess("Malloc error", mlx, 1));
	init_fractal(mlx);
	init_mlx(mlx);
	ft_secondary_arg_check(argc, argv, &x, &y);
	mlx_hook(mlx->win, 2, 1L << 0, keypress, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, ft_exit_wo_mess, mlx);
	draw_fractal(mlx, argv[1], x, y);
	mlx_loop(mlx->mlx);
	return (0);
}
