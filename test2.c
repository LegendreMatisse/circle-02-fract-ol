/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:20:55 by mlegendr          #+#    #+#             */
/*   Updated: 2023/12/18 17:12:34 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		close_win(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		//Replace with actual exit function with frees and stuff
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_mlx	mlx;
	//void	*mlx;
	//void	*mlx_win;
	t_data	img;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 920, 800, "First MLX test");
	img.img = mlx_new_image(mlx.mlx, 920, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (int j = 0; j < 800; j+=25)
	{
		for (int i = 0; i < 920; i++)
			my_mlx_pixel_put(&img, i, j, 0x00845123);
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_hook(mlx.win, 2, 1L<<0, close_win, &mlx);
	mlx_loop(mlx.mlx);
}
