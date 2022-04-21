#include <cub3d.h>

static int	ft_count_items(t_vars *vars);
static void	ft_check_item(t_vars *vars, int x, int y);
static void	ft_add_item(t_vars *vars, int x, int y);

void	ft_register_items(t_vars *vars)
{
	int	i;
	int	j;

	vars->map.items = ft_calloc(ft_count_items(vars), sizeof(t_item));
	i = 0;
	while (vars->map.raw[i] != NULL)
	{
		j = 0;
		while (vars->map.raw[i][j] != '\0')
		{
			ft_check_item(vars, j, i);
			j++;
		}
		i++;
	}
}

static int	ft_count_items(t_vars *vars)
{
	int	n_items;
	int	i;
	int	j;

	n_items = 0;
	i = 0;
	while (vars->map.raw[i] != NULL)
	{
		j = 0;
		while (vars->map.raw[i][j] != '\0')
		{
			if (ft_strchr("H", vars->map.raw[i][j]) != NULL)
				n_items++;
			j++;
		}
		i++;
	}
	return (n_items);
}

static void	ft_check_item(t_vars *vars, int x, int y)
{
	if (ft_strchr("H", ft_get_case(vars, x, y)) != NULL)
	{
		ft_add_item(vars, x, y);
		vars->map.raw[y][x] = '0';
	}
}

static void	ft_add_item(t_vars *vars, int x, int y)
{
	int	i;

	i = 0;
	while (vars->map.items[i].type != 0)
		i++;
	vars->map.items[i].type = ft_get_case(vars, x, y);
	vars->map.items[i].p.x = x + 0.5;
	vars->map.items[i].p.y = y + 0.5;
}
