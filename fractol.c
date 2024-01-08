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

void	print_message()
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
