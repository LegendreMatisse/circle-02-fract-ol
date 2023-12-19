

#include "fractol.h"

void	put_color_to_pixel(t_mlx *mlx, int x, int y, int color)
{
	int	*buffer;

	buffer = mlx->addr;
	buffer[(y * mlx->line_length / 4) + x] = color;
}

void    cool_fractol_function(t_mlx *mlx)
{
    int i = 0;
    double x_tmp;

    mlx->name = "mandelbrot";
    mlx->zx = 0.0;
    mlx->zy = 0.0;
    mlx->cx = (mlx->x / mlx->zoom) + mlx->offset_x;
    mlx->cy = (mlx->y / mlx->zoom) + mlx->offset_y;
    
    while (++i < mlx->max_iterations)
    {
        x_tmp = mlx->zx + mlx->zx - mlx->zy * mlx->zy + mlx->cx;
        mlx->zy = 2.0 * mlx->zx * mlx->zy + mlx->cy;
        mlx->zx = x_tmp;
        if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= __DBL_MAX__)
            break ;
    }
    if (i == mlx->max_iterations)
        put_color_to_pixel(mlx, mlx->x, mlx->y, 0x00000000);
    else
        put_color_to_pixel(mlx, mlx->x, mlx->y, (mlx->color * i));
}

int draw_fractal(t_mlx *mlx, char *choice, double cx, double cy)
{
    mlx->x = 0;
    mlx->y = 0;
    while (mlx->x < SIZE)
    {
        while (mlx->y < SIZE)
        {
            if (ft_strncmp(query, "mandel", 7) == 0)
                cool_fractol_function(mlx);
            mlx->y++;
        }
        mlx->x++;
        mlx->y = 0;
    }
    mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
    return (0);
}


int main(void)
{
    t_mlx   mlx;

    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, 500, 500, "Create image test 2");
    mlx.img = mlx_new_image(mlx.mlx, 500, 500);
    mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
                                &mlx.endian);
    draw_fractal(&mlx);
    mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
    mlx_hook(mlx.win, 2, 1L<<0, keypress, &mlx);
	mlx_hook(mlx.win, 17, 1L<<17, ft_exit_wo_mess, &mlx);
	mlx_loop(mlx.mlx);
    return (0);
}
