#include <cub3d.h>

static void	ft_check_case(t_vars *vars, int x, int y, int *n_walls);
static void	ft_check_case_sides(t_vars *vars, int x, int y);

int	ft_count_walls(t_vars *vars)
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
			ft_check_case(vars, j, i, &n_walls);
			j++;
		}
		i++;
	}
	return (n_walls);
}

static void	ft_check_case(t_vars *vars, int x, int y, int *n_walls)
{
	if (ft_strchr("0D", vars->map.raw[y][x]) != NULL)
	{
		ft_check_case_sides(vars, x, y);
		if (ft_strchr(SEE_NOT, ft_get_case(vars, x, y - 1)) != NULL)
			(*n_walls)++;
		if (ft_strchr(SEE_NOT, ft_get_case(vars, x, y + 1)) != NULL)
			(*n_walls)++;
		if (ft_strchr(SEE_NOT, ft_get_case(vars, x - 1, y)) != NULL)
			(*n_walls)++;
		if (ft_strchr(SEE_NOT, ft_get_case(vars, x + 1, y)) != NULL)
			(*n_walls)++;
	}
}

static void	ft_check_case_sides(t_vars *vars, int x, int y)
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
