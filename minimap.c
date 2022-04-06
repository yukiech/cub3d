#include <cub3d.h>

/*void	mm_case(t_vars vars, int x, int y, int color, void *img, int mimap_px_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < mimap_px_size)
	{
		j = 0;
		while (j < mimap_px_size)
		{	
			ft_set_px(vars, img, x, y, color);
			j++;
		}
		i++;
	}
}*/

void	minimap(t_vars *vars)
{
	/*int	posx;
	int	posy;
	int	x;
	int	y;*/
	void	*img;
	int	mimap_px_size;
	char *buffer;

	mimap_px_size = 10;
	img = mlx_new_image(vars->mlx, mimap_px_size * 11, mimap_px_size * 11);
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
	int	pixel_bits;
	int	line_bytes;
	int	endian;
	buffer = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);
	line_bytes /= 4;

	int color = 0xABCDEF;
	for(int y = 0; y < 210; ++y)
	{
		for(int x = 0; x < 210; ++x)
		{
   			 buffer[(y * line_bytes) + x] = color;
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img, 0, 0);
}
