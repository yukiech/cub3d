/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:15 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 13:54:11 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_tfree(void **ptr)
{
	if (*ptr != NULL)
		free(*ptr);
	*ptr = NULL;
}

int	ft_free_all(t_vars *vars)
{
	ft_free_map(vars);
	ft_tfree((void **)&vars->map.next);
	if (vars->screen.img != NULL)
		mlx_destroy_image(vars->mlx, vars->screen.img);
	if (vars->win != NULL)
		mlx_destroy_window(vars->mlx, vars->win);
	while (0)
		;
	exit(0);
}

void	ft_free_map(t_vars *vars)
{
	int	i;

	sound_kill();
	ft_tfree((void **)&vars->map.north.path);
	ft_tfree((void **)&vars->map.south.path);
	ft_tfree((void **)&vars->map.west.path);
	ft_tfree((void **)&vars->map.east.path);
	ft_tfree((void **)&vars->map.floor.raw);
	ft_tfree((void **)&vars->map.ceil.raw);
	ft_tfree((void **)&vars->map.music);
	i = 0;
	while (vars->map.raw != NULL && vars->map.raw[i] != NULL)
	{
		ft_tfree((void **)&vars->map.raw[i]);
		i++;
	}
	ft_tfree((void **)&vars->map.raw);
	ft_tfree((void **)&vars->map.walls);
}

void	ft_exit(t_vars *vars, char *error)
{
	ft_putendl_fd("Error\n", 2);
	ft_putendl_fd(error, 2);
	ft_free_all(vars);
}
