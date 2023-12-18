

#include "fractol.h"

int		keypress(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		ft_exit_wo_mess(mlx);
	return (0);
}