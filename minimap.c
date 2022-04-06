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
			ft_set_px(minimap, (x*10)+i, (y*10)+j, color);
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
	color = 0x000000;
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

void	mimap_draw(t_vars *vars, t_imgptr *minimap, int mimap_px_size)
{
	int	i;
	int	j;
//	printf("y - 10 = %d\n", (int)vars->player.pos.y - 10);
//	printf("x - 10 = %d\n", (int)vars->player.pos.x - 10);
//	printf("y + 10 = %d\n", (int)vars->player.pos.y + 10);
//	printf("x + 10 = %d\n", (int)vars->player.pos.x + 10);

	int i_test = 0;
	int	j_test = 0;

	i = (int)vars->player.pos.y - 10;
	while (i <= (int)vars->player.pos.y + 10)
	{
		j = ((int)vars->player.pos.x) - 10;
		j_test = 0;
		while (j <= (int)vars->player.pos.x + 10)
		{
			printf("%d ", ft_get_case(vars, j, i));
			if (i >= 0 && j >= 0 && ft_get_case(vars, j, i) != '\e')
			{
				if (vars->map.raw[i][j] == 49)
					mm_case(minimap, i_test, j_test, 0xFF0000, mimap_px_size);
			}
			j++;
			j_test++;
		}
		printf("\n");
		i++;
		i_test++;
	}

		printf("\n");
}

void	minimap(t_vars *vars)
{
	/*int	posx;
	int	posy;
	int	x;
	int	y;*/
	int	mimap_px_size;

	mimap_px_size = 10;
	/*posx = 0;
	posy = 0;
	x = ((int)vars->player.playerx) - 10;

	while (x <= (int)vars->player.playerx + 10)
	{
		y = ((int)vars->player.playery) - 10;
		while (y <= (int)vars->player.playery + 10)
		{
			if (vars->map[x][y] == 1)
				mm_case(vars, posx, posy, ft_color(0, 0, 255, 0), img, mimap_px_size);
			y++;
			posy += mimap_px_size;
		}
		x++;
		posx += mimap_px_size;
		posy = 0;
	}*/

	t_imgptr minimap;
	minimap.w = 210;
	minimap.h = 210;
	ft_load_image(vars, NULL, &minimap);
	mimap_background(&minimap, mimap_px_size);
	mimap_draw(vars, &minimap, mimap_px_size);
	mlx_put_image_to_window(vars->mlx, vars->win, minimap.img, 0, 0);
}
