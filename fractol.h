/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:04:23 by mlegendr          #+#    #+#             */
/*   Updated: 2023/12/18 18:47:38 by mlegendr         ###   ########.fr       */
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

typedef struct  s_data {
	void    *img;
	char    *addr;
	int	    bits_per_pixel;
	int     line_length;
	int		endian;
}				t_data;

typedef struct	s_mlx {
	void	*mlx;
	void	*win;
}				t_mlx;

/*Utilities*/
void	ft_print_contrl(void);
int		ft_exit_w_mess(char *str, t_mlx *mlx, int error);
int		ft_exit_wo_mess(t_mlx *mlx);

/*MLX specific functions*/
int		keypress(int keycode, t_mlx *mlx);

/*Argument checks*/
void	ft_primary_arg_check(int argc, char **argv);
#endif
