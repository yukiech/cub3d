#include <cub3d.h>

void	ft_exit(t_vars *vars, char *error)
{
	ft_putendl_fd(error, 2);
	ft_free(vars);
}

void	ft_tfree(void **ptr)
{
	if (*ptr != NULL)
		free(*ptr);
	*ptr = NULL;
}

int	ft_free(t_vars *vars)
{
	ft_tfree((void **)&vars->map.north.path);
	ft_tfree((void **)&vars->map.south.path);
	ft_tfree((void **)&vars->map.west.path);
	ft_tfree((void **)&vars->map.east.path);
	ft_tfree((void **)&vars->map.floor.raw);
	ft_tfree((void **)&vars->map.ceil.raw);
	ft_free_2d(vars->map.raw);
	ft_tfree((void **)&vars->map.walls);
	if (vars->screen.img != NULL)
		mlx_destroy_image(vars->mlx, vars->screen.img);
	if (vars->win != NULL)
		mlx_destroy_window(vars->mlx, vars->win);
	while (0)
		;
	exit(0);
}
