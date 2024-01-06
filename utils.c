/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:39:01 by mlegendr          #+#    #+#             */
/*   Updated: 2023/12/20 15:42:41 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_name_check(char *name)
{
	if (ft_strncmp(name, "mandelbrot", 11) == 0)
		return (0);
	else if (ft_strncmp(name, "julia", 6) == 0)
		return (0);
	else if (ft_strncmp(name, "sierpinski", 11) == 0)
		return (0);
	else
		return (1);
}

void	ft_primary_arg_check(int argc, char **argv)
{
	if (argc < 2)
		ft_exit_w_mess("Incorrect usage. Try ./fractol <fractal>", NULL, 1);
	else
	{
		if (ft_name_check(argv[1]) == 1)
		{
			ft_printf("Invalid argument. Try <mandelbrot>, ");
			ft_exit_w_mess("<julia> or <sierpinski>", NULL, 1);
		}
	}
}

int	ft_exit_w_mess(char *str, t_mlx *mlx, int error)
{
	ft_printf("%s\n", str);
	if (mlx != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	//Replace with actual exit function with frees and stuff
	exit(error);
	return (error);
}

int	ft_exit_wo_mess(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	//Replace with actual exit function with frees and stuff
	exit(0);
	return (0);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	double	factor;

	result = 0.0;
	sign = 1.0;
	factor = 0.1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str++ == '.')
		while (*str >= '0' && *str <= '9')
		{
			result += (*str++ - '0') * factor;
			factor *= 0.1;
		}
	return (result * sign);
}
