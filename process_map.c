#include <cub3d.h>

static void	ft_is_player(t_vars *vars, int x, int y);
static void	ft_is_valid_case(t_vars *vars, int x, int y);
static void	ft_inside_touch_outside(t_vars *vars, int x, int y);
static void	ft_count_walls_around(t_vars *vars, int x, int y);

void	ft_process_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map.raw[i] != NULL)
	{
		j = 0;
		while (vars->map.raw[i][j] != '\0')
		{
			ft_is_player(vars, j, i);
			ft_is_valid_case(vars, j, i);
			ft_inside_touch_outside(vars, j, i);
			ft_count_walls_around(vars, j, i);
			j++;
		}
		i++;
	}
}

static void	ft_is_player(t_vars *vars, int x, int y)
{
	if (ft_strchr("NWES", ft_get_case(vars, x, y)) != NULL)
	{
		if (vars->player.pos.x != 0)
			ft_exit(vars, "2 players found, multiplayer to be defined");
		vars->player.pos.x = x + 0.5;
		vars->player.pos.y = y + 0.5;
		if (ft_get_case(vars, x, y) == 'N')
			vars->player.angle = radians(-90);
		else if (ft_get_case(vars, x, y) == 'W')
			vars->player.angle = radians(180);
		else if (ft_get_case(vars, x, y) == 'E')
			vars->player.angle = radians(0);
		else if (ft_get_case(vars, x, y) == 'S')
			vars->player.angle = radians(90);
		vars->map.raw[y][x] = '0';
	}
}

static void	ft_is_valid_case(t_vars *vars, int x, int y)
{
	if (ft_strchr("01 D^", ft_get_case(vars, x, y)) == NULL)
	{
		ft_exit(vars, "Not valid case found");
	}
}

static void	ft_inside_touch_outside(t_vars *vars, int x, int y)
{
	if (ft_strchr("0D", ft_get_case(vars, x, y)) != NULL)
	{
		if (ft_strchr(" \e", ft_get_case(vars, x, y - 1)) != NULL)
			ft_exit(vars, "Error map borders");
		else if (ft_strchr(" \e", ft_get_case(vars, x, y + 1)) != NULL)
			ft_exit(vars, "Error map borders");
		else if (ft_strchr(" \e", ft_get_case(vars, x - 1, y)) != NULL)
			ft_exit(vars, "Error map borders");
		else if (ft_strchr(" \e", ft_get_case(vars, x + 1, y)) != NULL)
			ft_exit(vars, "Error map borders");
	}
}

static void	ft_count_walls_around(t_vars *vars, int x, int y)
{
	if (ft_strchr("0D^", ft_get_case(vars, x, y)) != NULL)
	{
		if (ft_strchr("1D^", ft_get_case(vars, x, y - 1)) != NULL)
			vars->map.n_walls++;
		if (ft_strchr("1D^", ft_get_case(vars, x, y + 1)) != NULL)
			vars->map.n_walls++;
		if (ft_strchr("1D^", ft_get_case(vars, x - 1, y)) != NULL)
			vars->map.n_walls++;
		if (ft_strchr("1D^", ft_get_case(vars, x + 1, y)) != NULL)
			vars->map.n_walls++;
	}
}
