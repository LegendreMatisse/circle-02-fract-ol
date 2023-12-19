

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
    img.img = mlx_new_image(mlx, 500, 500);
    //get the address of the image
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

    //drawing pixels and setting colours.
    int color = 0xABCDEF;
    if (img.bits_per_pixel != 32)
        color = mlx_get_color_value(mlx, color);

    for(int y = 0; y < 500; y+=25)
    for(int x = 0; x < 500; x+=25)
    {
        int pixel = (y * img.line_length) + (x * 4);

        //colours are by Alpha, Red, Green, Blue
        if (img.endian == 1)        // Most significant (Alpha) byte first
        {
            img.addr[pixel + 0] = (color >> 24);
            img.addr[pixel + 1] = (color >> 16) & 0xFF;
            img.addr[pixel + 2] = (color >> 8) & 0xFF;
            img.addr[pixel + 3] = (color) & 0xFF;
        }
        else if (img.endian == 0)   // Least significant (Blue) byte first
        {
            img.addr[pixel + 0] = (color) & 0xFF;
            img.addr[pixel + 1] = (color >> 8) & 0xFF;
            img.addr[pixel + 2] = (color >> 16) & 0xFF;
            img.addr[pixel + 3] = (color >> 24);
        }
    }
    for(int y = 1; y < 500; y+=25)
    for(int x = 1; x < 500; x+=25)
    {
        int pixel = (y * img.line_length) + (x * 4);

        //colours are by Alpha, Red, Green, Blue
        if (img.endian == 1)        // Most significant (Alpha) byte first
        {
            img.addr[pixel + 0] = (color >> 24);
            img.addr[pixel + 1] = (color >> 16) & 0xAA;
            img.addr[pixel + 2] = (color >> 8) & 0xAA;
            img.addr[pixel + 3] = (color) & 0xAA;
        }
        else if (img.endian == 0)   // Least significant (Blue) byte first
        {
            img.addr[pixel + 0] = (color) & 0xAA;
            img.addr[pixel + 1] = (color >> 8) & 0xAA;
            img.addr[pixel + 2] = (color >> 16) & 0xAA;
            img.addr[pixel + 3] = (color >> 24);
        }
    }
    //put the image to the window
    mlx_put_image_to_window(mlx, win, img.img, 0, 0);

    mlx_loop(mlx);
    return (0);
}
