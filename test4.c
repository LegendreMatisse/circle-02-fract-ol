/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:44:12 by mlegendr          #+#    #+#             */
/*   Updated: 2023/12/20 16:22:51 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_fractal(t_mlx *mlx)
{
    mlx->x = 0;
    mlx->y = 0;
    mlx->color = 0x0FCBE11;
    mlx->zoom = 300;
    mlx->offset_x = -1.21;
    mlx->offset_y = -1.21;
    mlx->max_iterations = 42;
}

void    init_mlx(t_mlx *mlx)
{
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, SIZE, SIZE, "Create image test 2");
    mlx->img = mlx_new_image(mlx->mlx, SIZE, SIZE);
    mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
}

void	*draw_mandl(void *mlx_void)
{
    (void)mlx_void;
    ft_printf("Banaan.");
    return (0);
}

int draw_fractal(t_mlx *mlx, char *choice)
{
    if (ft_strncmp(choice, "mandelbrot", 11))
        draw_mandl(mlx);
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
    return (0);    
}

int main(int argc, char **argv)
{
    t_mlx   *mlx;

    (void)argc;
    mlx = malloc(sizeof(t_mlx));
    init_fractal(mlx);
    init_mlx(mlx);
    mlx_hook(mlx->win, 2, 1L<<0, keypress, mlx);
	mlx_hook(mlx->win, 17, 1L<<17, ft_exit_wo_mess, mlx);
    draw_fractal(mlx, argv[1]);
	mlx_loop(mlx->mlx);
    return (0);
}
