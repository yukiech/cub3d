#include <cub3d.h>

int	ft_key_hook(int keycode, t_vars *vars)
{
	printf("KEY %d\n", keycode);
	if (keycode == K_ESCAPE)
		ft_free(vars);
	return (0);
}

int	ft_click_hook(int button, int x, int y, t_vars *vars)
{
	printf("CLICK %d %d %d\n", x, y, button);
	(void)vars;
	return (0);
}

int	ft_mouse_hook(int x, int y, t_vars *vars)
{
//	if (x < 0 || y < 0 || x >= vars->screen.w || y >= vars->screen.h)
//		return (0);
//	printf("MOVE %d %d\n", x, y);
	(void)vars;
	(void)x;
	(void)y;
	return (0);
}
