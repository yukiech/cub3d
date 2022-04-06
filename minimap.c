#include <cub3d.h>

void	mm_case(t_imgptr *minimap, int x, int y, int color, int mimap_px_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < mimap_px_size)
	{
		j = 0;
		while (j < mimap_px_size)
		{	
			ft_set_px(minimap, (x*mimap_px_size)+i, (y*mimap_px_size)+j, color);
			j++;
		}
		i++;
	}
}

void	mimap_background(t_imgptr *minimap, int mimap_px_size)
{
	int	i;
	int	j;
	int color;

	i = 0;
	color = 0xFFFFFF;
	while (i < mimap_px_size * 21)
	{
		j = 0;
		while (j < mimap_px_size * 21)
		{	
   			 ft_set_px(minimap, j, i, color);
			 j++;
		}
		i++;
	}
}

void	mimap_player(t_imgptr *minimap, int mimap_px_size)
{
	int	x;
	int	y;
	
	x = (mimap_px_size * 21) / 2;
	y = x;
	mm_case(minimap, x/mimap_px_size, y/mimap_px_size, 0x00FF00, 6);
}

void	mimap_draw(t_vars *vars, t_imgptr *minimap, int mimap_px_size)
{
	int	i;
	int	j;

	int i_test = 0;
	int	j_test = 0;

	i = (int)vars->player.pos.y - 10;
	while (i <= (int)vars->player.pos.y + 10)
	{
		j = ((int)vars->player.pos.x) - 10;
		j_test = 0;
		while (j <= (int)vars->player.pos.x + 10)
		{
			if (i >= 0 && j >= 0 && ft_get_case(vars, j, i) != '\e')
			{
				if (vars->map.raw[i][j] == 49)
					mm_case(minimap, i_test, j_test, 0x000000, mimap_px_size);
				else if (vars->map.raw[i][j] == 48)
					mm_case(minimap, i_test, j_test, 0x808080, mimap_px_size);
			}
			j++;
			j_test++;
		}
		i++;
		i_test++;
	}
	mimap_player(minimap, mimap_px_size);
}

void	minimap(t_vars *vars)
{
	int	mimap_px_size;

	mimap_px_size = 6;
	t_imgptr minimap;
	minimap.w = 126;
	minimap.h = 126;
	ft_load_image(vars, NULL, &minimap);
	mimap_background(&minimap, mimap_px_size);
	mimap_draw(vars, &minimap, mimap_px_size);
	mlx_put_image_to_window(vars->mlx, vars->win, minimap.img, 0, 0);
}
