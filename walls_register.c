#include <cub3d.h>

static void	ft_check_wall(t_vars *vars, t_point p);
static void	ft_search_wall_type(t_vars *vars, t_point p, char sign, int type);

void	ft_register_walls(t_vars *vars)
{
	int	i;
	int	j;

	vars->map.walls = ft_calloc(vars->map.n_walls + 1, sizeof(t_wall));
	i = 0;
	while (vars->map.raw[i] != NULL)
	{
		j = 0;
		while (vars->map.raw[i][j] != '\0')
		{
			ft_check_wall(vars, (t_point){.x = j, .y = i});
			j++;
		}
		i++;
	}
}

static void	ft_check_wall(t_vars *vars, t_point p)
{
	if (ft_strchr("0NSEWD^", vars->map.raw[(int)p.y][(int)p.x]) != NULL)
	{
		if (ft_get_case(vars, p.x, p.y - 1) == '1')
		{
			ft_create_wall(vars->map.walls, p, W_UPWALL, W_UPWALL);
		}
		if (ft_get_case(vars, p.x - 1, p.y) == '1')
		{
			ft_create_wall(vars->map.walls, p, W_LEFTWALL, W_LEFTWALL);
		}
		if (ft_get_case(vars, p.x + 1, p.y) == '1')
		{
			ft_create_wall(vars->map.walls, p, W_RIGHTWALL, W_RIGHTWALL);
		}
		if (ft_get_case(vars, p.x, p.y + 1) == '1')
		{
			ft_create_wall(vars->map.walls, p, W_DOWNWALL, W_DOWNWALL);
		}
		ft_search_wall_type(vars, p, 'D', W_DOOR);
		ft_search_wall_type(vars, p, '^', W_FIRE);
	}
}

static void	ft_search_wall_type(t_vars *vars, t_point p, char sign, int type)
{
	if (ft_get_case(vars, p.x, p.y - 1) == sign)
	{		
		ft_create_wall(vars->map.walls, p, W_UPWALL, type);
	}
	if (ft_get_case(vars, p.x - 1, p.y) == sign)
	{
		ft_create_wall(vars->map.walls, p, W_LEFTWALL, type);
	}
	if (ft_get_case(vars, p.x + 1, p.y) == sign)
	{
		ft_create_wall(vars->map.walls, p, W_RIGHTWALL, type);
	}
	if (ft_get_case(vars, p.x, p.y + 1) == sign)
	{
		ft_create_wall(vars->map.walls, p, W_DOWNWALL, type);
	}
}
