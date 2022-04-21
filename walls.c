#include <cub3d.h>

static void	ft_to_register(t_vars *vars, t_point p);
static void	ft_add_wall(t_wall *walls, t_point p, int side, int type);

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
			ft_to_register(vars, (t_point){.x = j, .y = i});
			j++;
		}
		i++;
	}
	return (n_walls);
}

static void	ft_search_wall(t_vars *vars, t_point p, char sign, int type)
{
	if (ft_get_case(vars, p.x, p.y - 1) == sign)
		ft_add_wall(vars->map.walls, p, W_UPWALL, type);
	if (ft_get_case(vars, p.x - 1, p.y) == sign)
		ft_add_wall(vars->map.walls, p, W_LEFTWALL, type);
	if (ft_get_case(vars, p.x + 1, p.y) == sign)
		ft_add_wall(vars->map.walls, p, W_RIGHTWALL, type);
	if (ft_get_case(vars, p.x, p.y + 1) == sign)
		ft_add_wall(vars->map.walls, p, W_DOWNWALL, type);
}

static void	ft_to_register(t_vars *vars, t_point p)
{
	if (ft_strchr("0D", vars->map.raw[(int)p.y][(int)p.x]) != NULL)
	{
		if (ft_get_case(vars, p.x, p.y - 1) == '1')
			ft_add_wall(vars->map.walls, p, W_UPWALL, W_UPWALL);
		if (ft_get_case(vars, p.x - 1, p.y) == '1')
			ft_add_wall(vars->map.walls, p, W_LEFTWALL, W_LEFTWALL);
		if (ft_get_case(vars, p.x + 1, p.y) == '1')
			ft_add_wall(vars->map.walls, p, W_RIGHTWALL, W_RIGHTWALL);
		if (ft_get_case(vars, p.x, p.y + 1) == '1')
			ft_add_wall(vars->map.walls, p, W_DOWNWALL, W_DOWNWALL);

		ft_search_wall(vars, p, 'D', W_DOOR);
	}
}

static void	ft_add_wall(t_wall *walls, t_point p, int side, int type)
{
	int	i;

	i = 0;
	while (walls[i].type != W_NONE)
		i++;
	walls[i].type = type;
	walls[i].pos = p;

	if (side == W_UPWALL)
		walls[i].pos.y -= 1;
	else if (side == W_LEFTWALL)
		walls[i].pos.x -= 1;
	else if (side == W_RIGHTWALL)
		walls[i].pos.x += 1;
	else if (side == W_DOWNWALL)
		walls[i].pos.y += 1;


	if (side == W_UPWALL)
		walls[i].p1 = (t_point){.x = p.x, .y = p.y};
	if (side == W_UPWALL)
		walls[i].p2 = (t_point){.x = p.x + 1, .y = p.y};

	if (side == W_LEFTWALL)
		walls[i].p1 = (t_point){.x = p.x, .y = p.y + 1};
	if (side == W_LEFTWALL)
		walls[i].p2 = (t_point){.x = p.x, .y = p.y};

	if (side == W_RIGHTWALL)
		walls[i].p1 = (t_point){.x = p.x + 1, .y = p.y};
	if (side == W_RIGHTWALL)
		walls[i].p2 = (t_point){.x = p.x + 1, .y = p.y + 1};

	if (side == W_DOWNWALL)
		walls[i].p1 = (t_point){.x = p.x + 1, .y = p.y + 1};
	if (side == W_DOWNWALL)
		walls[i].p2 = (t_point){.x = p.x, .y = p.y + 1};


}


/*
static void	ft_add_wall(t_wall *walls, t_point p, int side, int type)
{
	int	i;

	i = 0;
	while (walls[i].type != W_NONE)
		i++;
	walls[i].type = type;
	walls[i].pos = pos;
	if (side == W_UPWALL || side == W_LEFTWALL)
		walls[i].p1 = (t_point){.x = p.x, .y = p.y};
	if (side == W_RIGHTWALL || side == W_DOWNWALL)
		walls[i].p2 = (t_point){.x = p.x + 1, .y = p.y + 1};
	i += 0;
	i += 0;
	if (side == W_UPWALL)
		walls[i].p2 = (t_point){.x = p.x + 1, .y = p.y};
	else if (side == W_LEFTWALL)
		walls[i].p2 = (t_point){.x = p.x, .y = p.y + 1};
	else if (side == W_RIGHTWALL)
		walls[i].p1 = (t_point){.x = p.x + 1, .y = p.y};
	else if (side == W_DOWNWALL)
		walls[i].p1 = (t_point){.x = p.x, .y = p.y + 1};
}
*/

/*
static void	ft_add_door(t_wall *walls, int x, int y, int side)
{
	int	i;

	i = 0;
	while (walls[i].type != W_NONE)
		i++;
	walls[i].type = 1;
	if (side == W_UPWALL || side == W_LEFTWALL)
		walls[i].p1 = (t_point){.x = x, .y = y};
	if (side == W_RIGHTWALL || side == W_DOWNWALL)
		walls[i].p2 = (t_point){.x = x + 1, .y = y + 1};
	i += 0;
	i += 0;
	if (side == W_UPWALL)
		walls[i].p2 = (t_point){.x = x + 1, .y = y};
	else if (side == W_LEFTWALL)
		walls[i].p2 = (t_point){.x = x, .y = y + 1};
	else if (side == W_RIGHTWALL)
		walls[i].p1 = (t_point){.x = x + 1, .y = y};
	else if (side == W_DOWNWALL)
		walls[i].p1 = (t_point){.x = x, .y = y + 1};
}
*/
