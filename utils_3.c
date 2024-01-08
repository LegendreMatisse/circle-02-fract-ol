/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:58:12 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/08 22:58:37 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    change_iterations(t_mlx *mlx, char direction)
{
    if (direction == 'u')
        mlx->max_iterations += 5;
    else
        mlx->max_iterations -= 5;
}
