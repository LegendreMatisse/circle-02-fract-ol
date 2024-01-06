/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:38:34 by mlegendr          #+#    #+#             */
/*   Updated: 2023/12/20 15:39:25 by mlegendr         ###   ########.fr       */
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
	return (0);
}

/*This function is meant to initialise the mlx window. 
Nothing more, nothing less.*/
void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SIZE, SIZE, "Fract-ol");
	mlx->img = mlx_new_image(mlx->mlx, SIZE, SIZE);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
								  &mlx->line_length, &mlx->endian);
}
