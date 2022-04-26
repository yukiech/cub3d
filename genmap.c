/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:15 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 13:49:15 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <generate.h>

static void	ft_gen_start(t_vars *vars);
static void	ft_populate_map(t_vars *vars);
static void	ft_gen_add_spaces(t_vars *vars, int x, int y);
static void	ft_gen_add_doors(t_vars *vars, int x, int y);

void	ft_generate_map(t_vars *vars, unsigned int seed)
{
	int		inf;

	printf("gen\n");
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
	ft_populate_map(vars);
}

static void	ft_gen_start(t_vars *vars)
{
	int	i;
	int	x;
	int	y;

	vars->map.raw = malloc((GEN_HEIGHT + 1) * sizeof(char *));
	vars->map.raw[GEN_HEIGHT] = NULL;
	vars->map.height = GEN_HEIGHT - 1;
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

static void	ft_populate_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < GEN_HEIGHT)
	{
		j = 0;
		while (j < GEN_WIDTH)
		{
			ft_gen_add_spaces(vars, j, i);
			ft_gen_add_doors(vars, j, i);
			j++;
		}
		i++;
	}
	while (1)
	{
		i = rand() % GEN_WIDTH;
		j = rand() % GEN_HEIGHT;
		if (ft_get_case(vars, i, j) == '0')
			break ;
	}
	vars->map.raw[j][i] = 'F';
}

static void	ft_gen_add_spaces(t_vars *vars, int x, int y)
{
	if (ft_strchr("\e 1", ft_get_case(vars, x, y)) != NULL
		&& ft_strchr("\e 1", ft_get_case(vars, x - 1, y)) != NULL
		&& ft_strchr("\e 1", ft_get_case(vars, x, y - 1)) != NULL
		&& ft_strchr("\e 1", ft_get_case(vars, x + 1, y)) != NULL
		&& ft_strchr("\e 1", ft_get_case(vars, x, y + 1)) != NULL)
		vars->map.raw[y][x] = ' ';
	if (ft_strchr("0", ft_get_case(vars, x, y)) != NULL
		&& ft_strchr("0", ft_get_case(vars, x - 1, y)) != NULL
		&& ft_strchr("0", ft_get_case(vars, x, y - 1)) != NULL
		&& ft_strchr("0", ft_get_case(vars, x + 1, y)) != NULL
		&& ft_strchr("0", ft_get_case(vars, x, y + 1)) != NULL
		&& rand() % 100 < 15)
		vars->map.raw[y][x] = '^';
}

static void	ft_gen_add_doors(t_vars *vars, int x, int y)
{
	if (ft_get_case(vars, x, y) == '0'
		&& ft_get_case(vars, x - 1, y) == '1'
		&& ft_get_case(vars, x + 1, y) == '1'
		&& ft_get_case(vars, x, y - 1) != 'D'
		&& ft_get_case(vars, x, y + 1) != 'D')
		vars->map.raw[y][x] = 'D';
	else if (ft_get_case(vars, x, y) == '0'
		&& ft_get_case(vars, x, y - 1) == '1'
		&& ft_get_case(vars, x, y + 1) == '1'
		&& ft_get_case(vars, x - 1, y) != 'D'
		&& ft_get_case(vars, x + 1, y) != 'D'
		&& rand() % 100 < 42)
		vars->map.raw[y][x] = 'D';
}
