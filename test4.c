

#include "fractol.h"

void    cool_fractol_function(t_data *img, t_mlx *mlx)
{
    int x = 0, y = 0;
    int color = 0xED0800;
    if (img->bits_per_pixel != 32)
        color = mlx_get_color_value(mlx->mlx, color);
    while (y < 500)
    {
        x = 0;
        while (x < 500)
        {
            int pixel = (y * img->line_length) + (x * 4);
            img->addr[pixel] = color;
            x++;
        }
        y++;
    }
}


int main(void)
{
    t_mlx   mlx;
    t_data  img;

    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, 500, 500, "Create image test 2");
    img.img = mlx_new_image(mlx.mlx, 500, 500);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);
    cool_fractol_function(&img, &mlx);
    mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
    mlx_hook(mlx.win, 2, 1L<<0, keypress, &mlx);
	mlx_hook(mlx.win, 17, 1L<<17, ft_exit_wo_mess, &mlx);
	mlx_loop(mlx.mlx);
    return (0);
}
