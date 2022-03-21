#include <cub3d.h>

void	ft_draw_hline(t_vars *vars, t_point o, int len)
{
	int	i;

	i = o.x;
	while (i < o.x + len)
	{
		if (!(i < 0 || o.y < 0
				|| i >= vars->screen.w || o.y >= vars->screen.h))
			ft_set_px(&vars->screen, i, o.y, ft_color(0, 255, 0, 0));
		i++;
	}	
}

void	ft_draw_vline(t_vars *vars, t_point o, int len)
{
	int	i;

	i = o.y;
	while (i < o.y + len)
	{
		if (!(o.x < 0 || i < 0
				|| o.x >= vars->screen.w || i >= vars->screen.h))
			ft_set_px(&vars->screen, o.x, i, ft_color(0, 255, 0, 0));
		i++;
	}	
}
