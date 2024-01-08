/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:24:48 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/07 23:27:20 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	secondary_arg_check(int argc, char **argv, double *x, double *y)
{
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		*x = 0;
		*y = 0;
	}
	else
	{
		if (argc < 4)
		{
			*x = -0.745429;
			*y = 0.05;
		}
		else
		{
			if (!ft_isfloat(argv[2]) || !ft_isfloat(argv[3]))
				exit_w_mess("Try any value between -4 and 4.", NULL, 1);
			*x = ft_atof(argv[2]);
			*y = ft_atof(argv[3]);
			if (*x < -4 || *x > 4 || *y < -4 || *y > 4)
				exit_w_mess("Try any value between -4 and 4.", NULL, 1);
		}
	}
}

int	ft_isfloat(const char *str)
{
	int	i;
	int	has_dot;
	int	has_digit;

	i = 0;
	has_dot = 0;
	has_digit = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (ft_isdigit(str[i]))
			has_digit = 1;
		else
			return (0);
		i++;
	}
	return (has_digit);
}

void	zoom(t_mlx *mlx, char direction)
{
	if (direction == '+')
		mlx->zoom = mlx->zoom + 50;
	else
	{
		if (mlx->zoom > 50)
			mlx->zoom = mlx->zoom - 50;
	}
}

void	move(t_mlx *mlx, char direction)
{
	if (direction == 'u')
		mlx->offset_y = mlx->offset_y - 50 / mlx->zoom;
	else if (direction == 'd')
		mlx->offset_y = mlx->offset_y + 50 / mlx->zoom;
	else if (direction == 'l')
		mlx->offset_x = mlx->offset_x - 50 / mlx->zoom;
	else if (direction == 'r')
		mlx->offset_x = mlx->offset_x + 50 / mlx->zoom;
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx == NULL)
		return ;
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		mlx_loop_end(mlx->mlx);
		free(mlx->mlx);
	}
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
	if (mlx)
		free(mlx);
	mlx = NULL;
}
