#include <cub3d.h>
#include <generate.h>

static void	ft_gen_start(t_vars *vars);
static void	ft_gen_add_spaces(t_vars *vars);

void	ft_generate_map(t_vars *vars, unsigned int seed)
{
	int		inf;

	srand(seed);
	vars->map.north.path = ft_strdup(GEN_NORTH);
	vars->map.south.path = ft_strdup(GEN_SOUTH);
	vars->map.west.path = ft_strdup(GEN_WEST);
	vars->map.east.path = ft_strdup(GEN_EAST);
	vars->map.ceil.raw = ft_strdup(GEN_CEIL);
	vars->map.floor.raw = ft_strdup(GEN_FLOOR);
	inf = 0;
	while (inf < 100)
	{
		ft_gen_start(vars);
		if (ft_gen_count(vars) > (GEN_HEIGHT * GEN_WIDTH) * GEN_TRESH
			&& ft_gen_check(vars) == 1)
			break ;
		ft_free_2d(vars->map.raw);
		inf++;
	}
	if (inf == 100)
		ft_exit(vars, "Really bad luck at gen");
	ft_gen_add_spaces(vars);
}

static void	ft_gen_start(t_vars *vars)
{
	int	i;
	int	x;
	int	y;

	vars->map.raw = malloc((GEN_HEIGHT + 1) * sizeof(char *));
	vars->map.raw[GEN_HEIGHT] = NULL;
	i = 0;
	while (i < GEN_HEIGHT)
	{
		vars->map.raw[i] = malloc((GEN_WIDTH + 1) * sizeof(char));
		ft_memset(vars->map.raw[i], '1', GEN_WIDTH * sizeof(char));
		vars->map.raw[i][GEN_WIDTH] = '\0';
		i++;
	}
	x = (rand() % (GEN_WIDTH - 2)) + 1;
	y = (rand() % (GEN_HEIGHT - 2)) + 1;
	ft_gen_expend(vars, x, y, 0);
	vars->map.raw[y][x] = 'N';
}

static void	ft_gen_add_spaces(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < GEN_HEIGHT)
	{
		j = 0;
		while (j < GEN_WIDTH)
		{
			if (ft_strchr("\e 1", ft_get_case(vars, j - 1, i)) != NULL
				&& ft_strchr("\e 1", ft_get_case(vars, j, i - 1)) != NULL
				&& ft_strchr("\e 1", ft_get_case(vars, j + 1, i)) != NULL
				&& ft_strchr("\e 1", ft_get_case(vars, j, i + 1)) != NULL)
				vars->map.raw[i][j] = ' ';
			j++;
		}
		i++;
	}
}
