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

int	keypress(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		ft_exit_wo_mess(mlx);
	return (0);
}
