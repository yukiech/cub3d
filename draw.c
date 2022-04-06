#include <cub3d.h>

void	ft_draw_hline(t_imgptr *ptr, t_point o, int len, int color)
{
	int	i;

	i = o.x;
	while (i < o.x + len)
	{
		if (!(i < 0 || o.y < 0 || i >= ptr->w || o.y >= ptr->h))
			ft_set_px(ptr, i, o.y, color);
		i++;
	}	
}

void	ft_draw_vline(t_imgptr *ptr, t_point o, int len, int color)
{
	int	i;

	i = o.y;
	while (i < o.y + len)
	{
		if (!(o.x < 0 || i < 0 || o.x >= ptr->w || i >= ptr->h))
			ft_set_px(ptr, o.x, i, color);
		i++;
	}	
}
