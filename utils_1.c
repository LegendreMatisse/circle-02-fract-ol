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

int	name_check(char *name)
{
	if (ft_strncmp(name, "mandelbrot", 11) == 0)
		return (0);
	else if (ft_strncmp(name, "julia", 6) == 0)
		return (0);
	else
		return (1);
}

void	primary_arg_check(int argc, char **argv)
{
	if (argc < 2 || argc > 4 || argc == 3)
	{
		ft_printf("Incorrect usage.");
		exit_w_mess("Try ./fractol <mandelbrot> or <julia>", NULL, 1);
	}
	else
	{
		if (name_check(argv[1]) == 1)
		{
			ft_printf("Incorrect usage.");
			exit_w_mess("Try ./fractol <mandelbrot> or <julia>", NULL, 1);
		}
	}
}

int	exit_w_mess(char *str, t_mlx *mlx, int error)
{
	ft_printf("%s\n", str);
	free_mlx(mlx);
	exit(error);
	return (error);
}

int	exit_wo_mess(t_mlx *mlx)
{
	free_mlx(mlx);
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
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			result += (*str++ - '0') * factor;
			factor *= 0.1;
		}
	}
	return (result * sign);
}
