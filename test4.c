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

void	put_color_to_pixel(t_mlx *mlx, int x, int y, int color)
{
	int	*buffer;

	buffer = mlx->addr;
	buffer[(y * mlx->line_length / 4) + x] = color;
}

void    calc_mandl(t_mlx *mlx)
{
    int i;
    double tmp;

    mlx->name = "mandel";
	i = 0;
	mlx->zx = 0.0;
	mlx->zy = 0.0;
	mlx->cx = (mlx->x / mlx->zoom) + mlx->offset_x;
	mlx->cy = (mlx->y / mlx->zoom) + mlx->offset_y;
	while (++i < mlx->max_iterations)
	{
		tmp = mlx->zx * mlx->zx - mlx->zy * mlx->zy + mlx->cx;
		mlx->zy = 2. * mlx->zx * mlx->zy + mlx->cy;
		mlx->zx = tmp;
		if (mlx->zx * mlx->zx + mlx->zy * mlx->zy >= __DBL_MAX__)
			break ;
	}
	if (i == mlx->max_iterations)
		put_color_to_pixel(mlx, mlx->x, mlx->y, 0x000000);
	else
		put_color_to_pixel(mlx, mlx->x, mlx->y, (mlx->color * i));
}

void	*draw_mandl(void *mlx_void)
{
    t_mlx	*mlx;

    mlx = (t_mlx *)mlx_void;
    mlx->x = 0;
    mlx->y = 0;
    while (mlx->x < SIZE)
    {
        while (mlx->y < SIZE)
        {
            calc_mandl(mlx);
            mlx->y++;
        }
        mlx->x++;
        mlx->y = 0;
    }
    return (NULL);
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
