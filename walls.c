#include <cub3d.h>

static void	ft_to_register(t_vars *vars, int x, int y);
static void	ft_add_wall(t_wall *walls, int x, int y, int side);

int	ft_register_walls(t_vars *vars)
{
	int	n_walls;
	int	i;
	int	j;

	n_walls = 0;
	i = 0;
	while (vars->map.raw[i] != NULL)
	{
		j = 0;
		while (vars->map.raw[i][j] != '\0')
		{
			ft_to_register(vars, j, i);
			j++;
		}
		i++;
	}
	return (n_walls);
}

static void	ft_to_register(t_vars *vars, int x, int y)
{
	if (ft_strchr(" 1", vars->map.raw[y][x]) == NULL)
	{
		if (ft_get_case(vars, x, y - 1) == '1')
			ft_add_wall(vars->map.walls, x, y, 0);
		if (ft_get_case(vars, x, y + 1) == '1')
			ft_add_wall(vars->map.walls, x, y, 3);
		if (ft_get_case(vars, x - 1, y) == '1')
			ft_add_wall(vars->map.walls, x, y, 1);
		if (ft_get_case(vars, x + 1, y) == '1')
			ft_add_wall(vars->map.walls, x, y, 2);
	}
}

static void	ft_add_wall(t_wall *walls, int x, int y, int side)
{
	int	i;

	i = 0;
	while (walls[i].type != W_NONE)
		i++;
	walls[i].type = W_WALL;
	if (side == 0 || side == 1)
		walls[i].p1 = (t_point){.x = x, .y = y + 1};
	if (side == 2 || side == 3)
		walls[i].p2 = (t_point){.x = x + 1, .y = y + 2};
	i += 0;
	i += 0;
	if (side == 0)
		walls[i].p2 = (t_point){.x = x + 1, .y = y + 1};
	else if (side == 1)
		walls[i].p2 = (t_point){.x = x, .y = y + 2};
	else if (side == 2)
		walls[i].p1 = (t_point){.x = x + 1, .y = y + 1};
	else if (side == 3)
		walls[i].p1 = (t_point){.x = x, .y = y + 2};
}
