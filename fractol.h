/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:04:23 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/07 23:27:44 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define SIZE 700
# define S_UP 4
# define S_DOWN 5

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}				t_mlx;

/*Utilities*/
int		exit_w_mess(char *str, t_mlx *mlx, int error);
int		exit_wo_mess(t_mlx *mlx);
double	ft_atof(const char *str);
int		ft_isfloat(const char *str);
void	zoom(t_mlx *mlx, char direction);
void	move(t_mlx *mlx, char direction);
void	free_mlx(t_mlx *mlx);
void	print_message();
void	change_iterations(t_mlx *mlx, char direction);
void	print_message(void);

/*MLX specific functions*/
int		keypress(int keycode, t_mlx *mlx);
int		mouse(int mousecode, int x, int y, t_mlx *mlx);
void	init_mlx(t_mlx *mlx);

/*Argument checks*/
void	primary_arg_check(int argc, char **argv);
void	secondary_arg_check(int argc, char **argv, double *x, double *y);

/*Draw utilities*/
void	put_color_to_pixel(t_mlx *mlx, int x, int y, int color);
int		draw_fractal(t_mlx *mlx, char *choice, char function);
int		pick_color(int i, t_mlx *mlx);

/*Mandelbrot*/
void	init_mandel(t_mlx *mlx, char function);
void	draw_mandl(t_mlx *mlx);
void	calc_mandl(t_mlx *mlx);

/*Julia*/
void	init_julia(t_mlx *mlx, double x, double y, char function);
void	draw_julia(t_mlx *mlx);
void	calc_julia(t_mlx *mlx);

#endif
