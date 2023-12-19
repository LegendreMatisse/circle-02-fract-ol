

#include "fractol.h"

int main(void)
{
    void *mlx;
    void *win;
    t_data	img;

    //init mlx
    mlx = mlx_init();
    //create the window that will be used to display the image
    win = mlx_new_window(mlx, 500, 500, "Create image test");
    //create the image that will be displayed
    img.img = mlx_new_image(mlx.mlx, 500, 500);
    //get the address of the image
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

    //drawing pixels and setting colours.
    int color = 0xABCDEF;
    if (pixel_bits != 32)
        color = mlx_get_color_value(mlx, color);

    for(int y = 0; y < 360; ++y)
    for(int x = 0; x < 640; ++x)
    {
        int pixel = (y * line_bytes) + (x * 4);

        if (endian == 1)        // Most significant (Alpha) byte first
        {
            buffer[pixel + 0] = (color >> 24);
            buffer[pixel + 1] = (color >> 16) & 0xFF;
            buffer[pixel + 2] = (color >> 8) & 0xFF;
            buffer[pixel + 3] = (color) & 0xFF;
        }
        else if (endian == 0)   // Least significant (Blue) byte first
        {
            buffer[pixel + 0] = (color) & 0xFF;
            buffer[pixel + 1] = (color >> 8) & 0xFF;
            buffer[pixel + 2] = (color >> 16) & 0xFF;
            buffer[pixel + 3] = (color >> 24);
        }
    }
    //put the image to the window
    mlx_put_image_to_window(mlx, win, image, 0, 0);

    mlx_loop(mlx);
    return (0);
}
