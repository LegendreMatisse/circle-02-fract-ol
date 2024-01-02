/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: CREATION_DATE by YOUR_NAME               #+#    #+#             */
/*   Updated: MODIFIED_DATE by YOUR_NAME              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
    t_mlx   *mlx;

    ft_primary_arg_check(argc, argv);
    mlx = malloc(sizeof(t_mlx));
    init_fractal(mlx);
    init_mlx(mlx);
    mlx_hook(mlx->win, 2, 1L<<0, keypress, mlx);
	mlx_hook(mlx->win, 17, 1L<<17, ft_exit_wo_mess, mlx);
    draw_fractal(mlx, argv[1]);
	mlx_loop(mlx->mlx);
    return (0);
}