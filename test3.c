

#include "fractol.h"

int main(void)
{
    void *mlx;
    void *win;
    void *img;

    //init mlx
    mlx = mlx_init();
    //create the window that will be used to display the image
    win = mlx_new_window(mlx, 500, 500, "Create image test");
    //create the image that will be displayed
    img = mlx_new_image(mlx, 500, 500);

    mlx_loop(mlx);
    return (0);
}
