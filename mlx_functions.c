/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:38:34 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/06 20:08:16 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*This function is meant to capture keypresses send 
to the window when the fract-ol program is running.
Current capture: - <ESC> to close window*/
int	keypress(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		ft_exit_wo_mess(mlx);
	if (keycode == XK_KP_Add)
		zoom(mlx, '+');
	if (keycode == XK_KP_Subtract)
		zoom(mlx, '-');
	if (keycode == XK_Up)
		move(mlx, 'u');
	if (keycode == XK_Down)
		move(mlx, 'd');
	if (keycode == XK_Left)
		move(mlx, 'l');
	if (keycode == XK_Right)
		move(mlx, 'r');
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, SIZE, SIZE);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_len,
			&mlx->endian);
	draw_fractal(mlx, mlx->name);
	return (0);
}

/*This function is meant to initialise the mlx window. 
Nothing more, nothing less.*/
void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SIZE, SIZE, "Fract-ol");
	mlx->img = mlx_new_image(mlx->mlx, SIZE, SIZE);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_len, &mlx->endian);
}
