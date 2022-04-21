#include <cub3d.h>
#define MAP_SIZE 21
#define MAP_HALF 10.5
#define MAP_PX 6.0

void	mm_case(t_imgptr *minimap, float x, float y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= MAP_PX)
	{
		j = 0;
		while (j <= MAP_PX)
		{
			if (ft_pyta(x + j / MAP_PX, y + i / MAP_PX) < 8)
				ft_set_px(minimap, (x + MAP_HALF - 0.5) * MAP_PX + j,
					(y + MAP_HALF - 0.5) * MAP_PX + i, color);
			else if (ft_pyta(x + j / MAP_PX, y + i / MAP_PX) < 9)
				ft_set_px(minimap, (x + MAP_HALF - 0.5) * MAP_PX + j,
					(y + MAP_HALF - 0.5) * MAP_PX + i, ft_color(0, 105, 75, 0));
			else
				ft_set_px(minimap, (x + MAP_HALF - 0.5) * MAP_PX + j,
					(y + MAP_HALF - 0.5) * MAP_PX + i, ft_color(255, 0, 0, 0));
			j++;
		}
		i++;
	}
}

int	bsp(t_point p, t_point l1, t_point l2)
{
	float	res;

	res = (p.x - l2.x) * (l1.y - l2.y) - (p.y - l2.y) * (l1.x - l2.x);
	if (res < 0)
		return (-1);
	else if (res > 0)
		return (1);
	return (0);
}

void	mimap_player(t_vars *vars, t_imgptr *minimap)
{
	t_point	pl;
	t_point	p1;
	t_point	p2;
	t_point	p3;

	p1.x = cos(vars->player.angle) * 6;
	p1.y = sin(vars->player.angle) * 6;
	p2.x = cos(vars->player.angle - radians(120)) * 3;
	p2.y = sin(vars->player.angle - radians(120)) * 3;
	p3.x = cos(vars->player.angle + radians(120)) * 3;
	p3.y = sin(vars->player.angle + radians(120)) * 3;
	pl.y = -MAP_HALF + 0.5;
	while (pl.y < MAP_HALF)
	{
		pl.x = -MAP_HALF + 0.5;
		while (pl.x < MAP_HALF)
		{
			if (abs(bsp(pl, p1, p2) + bsp(pl, p2, p3) + bsp(pl, p3, p1)) == 3)
				ft_set_px(minimap, pl.x + MAP_HALF * MAP_PX,
					pl.y + MAP_HALF * MAP_PX, ft_color(0, 255, 0, 0));
			pl.x += 0.1;
		}
		pl.y += 0.1;
	}
}

void	mimap_draw(t_vars *vars, t_imgptr *minimap)
{
	float	i;
	float	j;
	char	c;

	i = -MAP_HALF - fmod(vars->player.pos.y, 1);
	while (i <= MAP_HALF + 1)
	{
		j = -MAP_HALF - fmod(vars->player.pos.x, 1);
		while (j <= MAP_HALF + 1)
		{
			c = ft_get_case(vars,
					vars->player.pos.x + j, vars->player.pos.y + i);
			if (ft_strchr("\e1 ", c) != NULL)
				mm_case(minimap, j, i, ft_color(0, 0, 0, 0));
			else if (ft_strchr("0", c) != NULL)
				mm_case(minimap, j, i, ft_color(0, 255, 255, 255));
			else if (ft_strchr("D", c) != NULL)
				mm_case(minimap, j, i, ft_color(0, 0, 255, 0));
			j++;
		}
		i++;
	}
}

void	minimap(t_vars *vars)
{
	t_imgptr	minimap;

	minimap.w = MAP_SIZE * MAP_PX;
	minimap.h = MAP_SIZE * MAP_PX;
	ft_load_image(vars, NULL, &minimap);
	mimap_draw(vars, &minimap);
	mimap_player(vars, &minimap);
	mlx_put_image_to_window(vars->mlx, vars->win, minimap.img, 0, 0);
}
