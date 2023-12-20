/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:44:12 by mlegendr          #+#    #+#             */
/*   Updated: 2023/12/20 15:44:18 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
    t_mlx   mlx;

    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, 500, 500, "Create image test 2");
    mlx.img = mlx_new_image(mlx.mlx, 500, 500);
    mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
    
    mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
    mlx_hook(mlx.win, 2, 1L<<0, keypress, &mlx);
	mlx_hook(mlx.win, 17, 1L<<17, ft_exit_wo_mess, &mlx);
	mlx_loop(mlx.mlx);
    return (0);
}
