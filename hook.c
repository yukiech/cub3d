#include <cub3d.h>

int	ft_hook(int keycode, t_vars *vars)
{
	if (keycode == K_ESCAPE)
		ft_free(vars);
	return (0);
}
