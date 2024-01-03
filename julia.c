

#include "fractol.h"

void    draw_julia(t_mlx *mlx, int x, int y)
{
    mlx->x = 0;
    mlx->y = 0;
    while (mlx->x < SIZE)
    {
        while (mlx->y < SIZE)
        {
            calc_julia(mlx, x, y);
            mlx->y++;
        }
        mlx->x++;
        mlx->y = 0;
    }
}

void    calc_julia(t_mlx *mlx, int x, int y)
{
    int     i;
    double  tmp;

    mlx->name = "julia";
    mlx->cx = x;
    mlx->cy = y;
	mlx->zx = mlx->x / mlx->zoom + mlx->offset_x;
	mlx->zy = mlx->y / mlx->zoom + mlx->offset_y;
    i = 0;
    while (++i < mlx->max_iterations)
    {
        tmp = mlx->zx;
        mlx->zx = mlx->zx * mlx->zx - mlx->zy * mlx->zy + mlx->cx;
        mlx->zy = 2 * mlx->zy * tmp + mlx->cy;
        if (mlx->zx * mlx->zx + mlx->zy * mlx->zy > __DBL_MAX__)
            break ;
    }
    if (i == mlx->max_iterations)
        put_color_to_pixel(mlx, mlx->x, mlx->y, 0x000000);
    else
        put_color_to_pixel(mlx, mlx->x, mlx->y, pick_color(i, mlx));
}
